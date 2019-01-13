#include <opencv2/opencv.hpp>

void place_icons(cv::Size size)
{
    std::vector<std::string> icon_name = {
        "rect", "circle", "eclipe", "line", "brush", "eraser",
        "open", "save", "clear", "plus", "minus", "color"
    };

    int btn_rows = (int)cvCeil(icon_name.size() / 2.0);

    for(int i = 0, k = 0; i < btn_rows; i++) {
        for(int j = 0; j < 2; j++,k++) {

            cv::Point pt(j * size.width, i * size.height);

            icons.push_back(cv::Rect(pt,size));

            cv::Mat icon = cv::Mat(70, 70, CV_8UC3, cv::Scalar(255,255,255));
            cv::putText(icon, icon_name[k], cv::Point(10,10), 1, 1, cv::Scalar(200,55,55));

            if(icon.empty())
                continue;

            resize(icon, icon, size);

            icon.copyTo(image(icons[k]));
        }
    }
}
