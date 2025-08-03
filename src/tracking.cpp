#include "tracking.hpp"

void detectMarkerAndEstimatePose(cv::Mat &frame,
                                 const cv::Ptr<cv::aruco::Dictionary> &dictionary,
                                 cv::Vec3d &rvec,
                                 cv::Vec3d &tvec)
{
    std::vector<int> ids;
    std::vector<std::vector<cv::Point2f>> corners;
    cv::aruco::detectMarkers(frame, dictionary, corners, ids);

    if (ids.size() > 0)
    {
        cv::aruco::drawDetectedMarkers(frame, corners, ids);

        // Camera parameters for solvePnP
        cv::Mat cameraMatrix = cv::Mat::eye(3, 3, CV_64F);
        cv::Mat distCoeffs = cv::Mat::zeros(8, 1, CV_64F);

        // Dummy marker length in meters
        float markerLength = 0.05;

        cv::aruco::estimatePoseSingleMarkers(corners, markerLength, cameraMatrix, distCoeffs, rvec, tvec);
        for (int i = 0; i < ids.size(); i++)
        {
            cv::drawFrameAxes(frame, cameraMatrix, distCoeffs, rvec, tvec, 0.03);
        }
    }
}
