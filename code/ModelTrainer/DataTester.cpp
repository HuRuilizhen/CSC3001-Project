#include "DataTester.h"

#include <iostream>

template <>
double modelPredictTester(cv::Ptr<cv::ml::KNearest> model, cv::Mat testImageMat, cv::Mat testLabelMat)
{
    std::cout << std::endl
              << "Predict Start" << std::endl;

    cv::Mat predictMat;
    model->predict(testImageMat, predictMat);

    predictMat.convertTo(predictMat, CV_8UC1);
    testLabelMat.convertTo(testLabelMat, CV_8UC1);

    /*
        Counting the matching results between trained model output of [test image set] and [test lable set]
    */
    double accuracyCount = 0;
    for (int i = 0; i < predictMat.rows; i++)
        if (predictMat.at<uchar>(i, 0) == testLabelMat.at<uchar>(i, 0))
            accuracyCount++;
    double accuracyRate = accuracyCount / predictMat.rows;
    std::cout << "Predict Accuracy Rate: [" << accuracyRate * 100 << "%]" << std::endl;
    std::cout << "Predict Done" << std::endl;

    return accuracyRate;
}