#include <opencv2/opencv.hpp>
#pragma once

#define BASE_HALF_WIDTH     4.12310562561766 
#define POINTS_NO           500

void drawBox(cv::Mat& image, CvRect box, cv::Scalar color = cvScalarAll(255), int thick=1); 
void drawLove(cv::Mat& image, CvRect box, cv::Scalar color);
void drawPoints(cv::Mat& image, std::vector<cv::Point2f> points,cv::Scalar color=cv::Scalar::all(255));

cv::Mat createMask(const cv::Mat& image, CvRect box);

float median(std::vector<float> v);

std::vector<int> index_shuffle(int begin,int end);
