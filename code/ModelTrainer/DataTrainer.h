#ifndef __DATATRAINER_H__
#define __DATATRAINER_H__

#include <opencv2/opencv.hpp>

/*
    Train the KNN model through given data set
*/
cv::Ptr<cv::ml::KNearest> modelKnnTrainer(int k, cv::Mat trainImageMat, cv::Mat trainLabelMat);

#endif // __DATATRAINER_H__