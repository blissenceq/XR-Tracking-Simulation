#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include "tracking.hpp"

int main()
{
    cv::VideoCapture cap(0);
    if (!cap.isOpened())
    {
        std::cerr << "ERROR: Cannot open camera" << std::endl;
        return -1;
    }

    cv::Mat frame;
    cv::Ptr<cv::aruco::Dictionary> dictionary =
        cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_50);

    while (true)
    {
        cap >> frame;
        if (frame.empty())
            break;

        cv::Vec3d rvec, tvec;
        detectMarkerAndEstimatePose(frame, dictionary, rvec, tvec);

        cv::imshow("XR Tracking Sim", frame);
        if (cv::waitKey(10) == 27)
            break; // ESC to quit
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}
