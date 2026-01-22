#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <chrono>
#include <iomanip>
#include <sstream>

class TimeSubscriber : public rclcpp::Node
{
public:
    TimeSubscriber() : Node("time")
    {
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "sent_time", 10,
            std::bind(&TimeSubscriber::callback, this, std::placeholders::_1));
    }

private:
    std::chrono::system_clock::time_point parse_iso8601(const std::string & s)
    {
        std::tm tm{};
        char dot;
        int micros;

        std::istringstream ss(s);
        ss >> std::get_time(&tm, "%Y-%m-%dT%H:%M:%S");
        ss >> dot >> micros; // .ffffffZ

        auto tp = std::chrono::system_clock::from_time_t(timegm(&tm));
        return tp + std::chrono::microseconds(micros);
    }

    void callback(const std_msgs::msg::String::SharedPtr msg)
    {
        auto sent = parse_iso8601(msg->data);
        auto now = std::chrono::system_clock::now();

        auto latency = std::chrono::duration<double, std::milli>(now - sent).count();

        RCLCPP_INFO(this->get_logger(),
            "Menerima Pesan: %s | Latency: %.3f ms",
            msg->data.c_str(), latency);
    }

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TimeSubscriber>());
    rclcpp::shutdown();
    return 0;
}
