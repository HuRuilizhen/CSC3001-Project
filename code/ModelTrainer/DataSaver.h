#ifndef __DATASAVER_H__
#define __DATASAVER_H__

#include <opencv2/opencv.hpp>
#include <string>

/*
    Defaut path of saving
*/
const std::string saveRecodePath = "../recode/performance.csv";
const std::string saveModelPath = "../model/minst.xml";

/*
    Record the permance of knn model with different k
*/
void modelDataRecoder(int k, double accuracyRate);

/*
    Save the given model in the default path
*/
void modelDataSaver(cv::Ptr<cv::ml::KNearest> model);

#endif // __DATASAVER_H__