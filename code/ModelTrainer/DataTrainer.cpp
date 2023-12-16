#include "DataTrainer.h"

cv::Ptr<cv::ml::KNearest> modelKnnTrainer(int k, cv::Mat trainImageMat, cv::Mat trainLabelMat)
{
    cv::Ptr<cv::ml::KNearest> knn = cv::ml::KNearest::create();

    knn->setDefaultK(k);
    knn->setIsClassifier(true);

    std::cout << std::endl
              << "Train Start, Method: [KNN], Parameter: [" << k << "] " << std::endl;
    cv::Ptr<cv::ml::TrainData> trainData = cv::ml::TrainData::create(trainImageMat, cv::ml::ROW_SAMPLE, trainLabelMat);
    knn->train(trainData);
    std::cout << "Train Done" << std::endl;
    return knn;
}