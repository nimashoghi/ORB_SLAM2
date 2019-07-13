#include <opencv2/core/core.hpp>

inline auto transform_frame(const cv::Mat &frame) -> cv::Mat
{
    // cv::Mat lab;
    // cv::cvtColor(frame, lab, cv::COLOR_BGR2Lab);

    // cv::Mat output[3];
    // cv::split(lab, output);

    // const auto &l = output[0];
    // const auto &a = output[1];
    // const auto &b = output[2];

    // const auto clahe = cv::createCLAHE(3.0, cv::Size(8, 8));

    // cv::Mat cl;
    // clahe->apply(l, cl);

    // cv::Mat limg;
    // cv::Mat inputImages[3] = {cl, a, b};
    // cv::merge(inputImages, 3, limg);

    // cv::Mat final;
    // cv::cvtColor(limg, final, cv::COLOR_Lab2BGR);

    // cv::Mat copy;
    // cv::GaussianBlur(frame, copy, cv::Size(0, 0), 3);
    // cv::addWeighted(frame, 1.5, copy, -0.5, 0, copy);
    // cv::Canny(frame, copy, 100., 200.);
    cv::Mat image;
    frame.convertTo(image, -1, 7.0, 0);
    return frame;
}
