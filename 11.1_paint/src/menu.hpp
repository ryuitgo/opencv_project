#include <opencv2/opencv.hpp>

void place_icons(cv::Size size)
{
    std::vector<std::string> icon_name = {
        "rect", "circle", "eclipe", "line", "brush", "eraser",
        "open", "save", "clear", "plus", "minus", "color"
    };

    int btn_rows = (int)cvCeil(icon_name.size() / 2.0);

    for(int i = 0, k = 0; i < btn_rows; ++i) {
        for(int j = 0; j < 2; ++j,++k) {
            cv::Point pt(j * size.width, i * size.height);
            icons.push_back(cv::Rect(pt,size));

            cv::Mat icon = cv::imread("../images/icon/" + icon_name[k] + ".png", 0);
            if(icon.empty())
                continue;

            resize(icon, icon, size);
            icon.copyTo(image(icons[k]));
        }
    }
}
