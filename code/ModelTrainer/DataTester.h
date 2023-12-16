#ifndef __DATATESTER_H__
#define __DATATESTER_H__

#include <opencv2/opencv.hpp>

/*
    Test the given output of the model and get the accuracy
*/
template <class Model>
double modelPredictTester(cv::Ptr<Model> model, cv::Mat testImageMat, cv::Mat testLabelMat);

#endif // __DATATESTER_H__