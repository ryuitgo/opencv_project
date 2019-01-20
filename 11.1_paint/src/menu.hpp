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

void create_hueIndex(cv::Rect rect) {
    cv::Mat m_hueIdx = image(rect);
    float ratio = 180.f / rect.height;

    for(int i = 0; i < rect.height; i++) {
        cv::Scalar hue_color(i * ratio, 255, 255);
        m_hueIdx.row(i).setTo(hue_color);
    }
    cv::cvtColor(m_hueIdx, m_hueIdx, cv::COLOR_HSV2BGR);
}

void create_palette(int pos_y, cv::Rect rect_pale) {
    cv::Mat m_palette = cv::image(rect_pale);
    float ratio1 = 180.0f / rect_pale.height;
    float ratio2 = 256.0f / rect_pale.width;
    float ratio3 = 256.0f / rect_pale.height;

    hue = cvRound((pos_y - rect_pale.y) * ratio1);
}

//614p부터읽고코드진행
