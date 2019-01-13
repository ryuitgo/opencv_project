#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;

std::vector<cv::Rect> icons;
cv::Mat image;

#include "menu.hpp"

int main()
{
    image = cv::Mat(500, 800, CV_8UC3, cv::Scalar(255,255,255));
    place_icons(cv::Size(60,60));

    cv::Rect last_icon = *(icons.end() -1);
    cv::Point start_pale = cv::Point(0, last_icon.br().y + 5);

    icons.push_back(cv::Rect(start_pale, cv::Size(100, 100)));
    icons.push_back(cv::Rect(start_pale + cv::Point(105,0), cv::Size(15,100)));

    cv::imshow("image", image);
    cv::waitKey(0);
    return 0;
}
