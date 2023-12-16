#include "DataSaver.h"

#include <iostream>
#include <fstream>

void modelDataRecoder(int k, double accuracyRate)
{
    std::cout << std::endl
              << "Recode Model Start, Path: [" << saveRecodePath << "]" << std::endl;

    std::ofstream file;
    file.open(saveRecodePath, std::ios::app);
    file << k << ", " << accuracyRate << std::endl;
    file.close();

    std::cout << "Recode Model Done" << std::endl;
}

void modelDataSaver(cv::Ptr<cv::ml::KNearest> model)
{
    std::cout << std::endl
              << "Save Model Start, Path: [" << saveModelPath << "]" << std::endl;

    model->save(saveModelPath);

    std::cout << "Save Model Done" << std::endl;
}
