#include <iostream>
#include <opencv2/opencv.hpp>
#include <filesystem>

using namespace std;

int main() {

    std::filesystem::path source_path = __FILE__;
    std::filesystem::path source_dir  = source_path.parent_path();
    std::filesystem::path img_path    = source_dir / "../../../images/B_ConCept/patrick.jpg";

    cv::Mat image = cv::imread(img_path.string());
    if (image.empty()) {
        cerr << "Could not open or find the image!" << endl;
        std::cout << img_path.string() << std::endl;
        return -1;
    }

    // Vocoded Image
    cv::Mat gray, edges;
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    cv::Canny(gray, edges, 80, 160);

    cv::Mat bigEdges;
    cv::resize(edges, bigEdges, cv::Size(), 3.0, 3.0, cv::INTER_NEAREST);

    cv::Mat colored;
    cv::cvtColor(bigEdges, colored, cv::COLOR_GRAY2BGR);
    colored.setTo(cv::Scalar(0,255,255), bigEdges);

    cv::imshow("Vocoded Image", colored);
    
    // Pixelated Image
    
    cv::Mat small, pixelated;
    cv::resize(image, small, cv::Size(), 0.1, 0.1);
    cv::resize(small, pixelated, cv::Size(image.cols * 3, image.rows * 3), 0, 0, cv::INTER_NEAREST);
    cv::imshow("Pixelated Image", pixelated);
    
    // Original Image
    cv::Mat resized;
    cv::resize(image, resized, cv::Size(image.cols * 3, image.rows * 3), 0.5, 0.5, cv::INTER_CUBIC);
    cv::imshow("Original Image", resized);

    cv::waitKey(0);
    
    return 0;
}