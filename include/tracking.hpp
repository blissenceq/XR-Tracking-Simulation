#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <opencv2/calib3d.hpp>

void detectMarkerAndEstimatePose(cv::Mat &frame,
                                 const cv::Ptr<cv::aruco::Dictionary> &dictionary,
                                 cv::Vec3d &rvec,
                                 cv::Vec3d &tvec);
