#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

#include "DataLoader.h"
#include "DataTrainer.h"
#include "DataTester.h"
#include "DataSaver.h"

int main(int argc, char const *argv[])
{
    /*
        Loading data sets
    */
    cv::Mat trainImageMat = imageLoader(trainImageSet);
    cv::Mat trainLabelMat = labelLoader(trainLabelSet);
    cv::Mat testImageMat = imageLoader(testIamgeSet);
    cv::Mat testLabelMat = labelLoader(testLabelSet);

    /*
        Training the data and Saving the different performance with k values
    */
    cv::Ptr<cv::ml::KNearest> bestKnn;
    double bestAccuracyRate = 0;

    for (int k = 1; k <= 30; k++)
    {
        cv::Ptr<cv::ml::KNearest> knn = modelKnnTrainer(k, trainImageMat, trainLabelMat);
        double currentAccuracyRate = modelPredictTester(knn, testImageMat, testLabelMat);
        modelDataRecoder(k, currentAccuracyRate);
        if (bestAccuracyRate < currentAccuracyRate)
        {
            bestAccuracyRate = currentAccuracyRate;
            bestKnn = knn;
        }
    }

    /*
        Saving the knn value with the best performance in the default set
    */
    modelDataSaver(bestKnn);

    return 0;
}
