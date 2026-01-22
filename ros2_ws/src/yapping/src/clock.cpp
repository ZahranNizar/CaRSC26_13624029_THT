#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <chrono>
#include <iomanip>
#include <sstream>

using namespace std::chrono_literals;

class TimePublisher : public rclcpp::Node
{
public:
    TimePublisher() : Node("time")
    {
        publisher_ = this->create_publisher<std_msgs::msg::String>("sent_time", 10);
        timer_ = this->create_wall_timer(1s, std::bind(&TimePublisher::publish_time, this));
    }

private:
    std::string now_iso8601()
    {
        using namespace std::chrono;

        auto now = system_clock::now();
        auto seconds = time_point_cast<std::chrono::seconds>(now);
        auto micros  = duration_cast<std::chrono::microseconds>(now - seconds);

        std::time_t tt = system_clock::to_time_t(seconds);
        std::tm tm = *gmtime(&tt);

        std::ostringstream oss;
        oss << std::put_time(&tm, "%Y-%m-%dT%H:%M:%S")
            << "." << std::setw(6) << std::setfill('0') << micros.count()
            << "Z";

        return oss.str();
    }

    void publish_time()
    {
        std_msgs::msg::String msg;
        msg.data = now_iso8601();

        publisher_->publish(msg);
        RCLCPP_INFO(this->get_logger(), "Mengirim Pesan: %s", msg.data.c_str());
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TimePublisher>());
    rclcpp::shutdown();
    return 0;
}
