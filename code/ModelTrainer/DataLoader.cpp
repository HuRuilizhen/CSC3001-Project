#include "DataLoader.h"

#include <string>
#include <fstream>
#include <iostream>

int parseInteger(int rawInteger)
{
    /*
        Perform data end conversion, Adjust byte position
    */
    int resultInteger = 0;
    for (int i = 0; i < 4; i++)
    {
        int temp = rawInteger & 0xff;
        rawInteger >>= 8;
        resultInteger <<= 8;
        resultInteger |= temp;
    }
    return resultInteger;
}

cv::Mat imageLoader(const std::string fileName)
{
    cv::Mat dataMat;
    std::ifstream file(fileName, std::ios::binary);

    int format = 0;
    int imageNUm = 0;
    int rowNum = 0;
    int colNum = 0;

    if (file.is_open())
    {
        file.read((char *)&format, sizeof(format));
        file.read((char *)&imageNUm, sizeof(imageNUm));
        file.read((char *)&rowNum, sizeof(rowNum));
        file.read((char *)&colNum, sizeof(colNum));

        format = parseInteger(format);
        imageNUm = parseInteger(imageNUm);
        rowNum = parseInteger(rowNum);
        colNum = parseInteger(colNum);

        std::cout << std::endl
                  << "Load Image Set: [" << fileName << "], "
                  << "Counts: [" << imageNUm << "], "
                  << "Size: [" << rowNum << "*" << colNum << "]" << std::endl;

        /*
            The picture data was written into Mat and normalized
        */
        dataMat = cv::Mat::zeros(imageNUm, rowNum * colNum, CV_32FC1);
        for (int i = 0; i < imageNUm; i++)
        {
            for (int j = 0; j < rowNum * colNum; j++)
            {
                unsigned char temp = 0;
                file.read((char *)&temp, sizeof(temp));
                float pixel_value = float(temp);
                dataMat.at<float>(i, j) = pixel_value / 255;
            }
        }
    }

    std::cout << "Load Done" << std::endl;

    file.close();
    return dataMat;
}

cv::Mat labelLoader(const std::string fileName)
{
    cv::Mat dataMat;
    std::ifstream file(fileName, std::ios::binary);

    int format = 0;
    int labelNum = 0;

    if (file.is_open())
    {
        file.read((char *)&format, sizeof(format));
        file.read((char *)&labelNum, sizeof(labelNum));

        format = parseInteger(format);
        labelNum = parseInteger(labelNum);

        std::cout << std::endl
                  << "Load Lable Set: [" << fileName << "], "
                  << "Counts: [" << labelNum << "]" << std::endl;

        /*
            Write label data to Mat
        */
        dataMat = cv::Mat::zeros(labelNum, 1, CV_32SC1);
        for (int i = 0; i < labelNum; i++)
        {
            unsigned char temp = 0;
            file.read((char *)&temp, sizeof(temp));
            dataMat.at<unsigned int>(i, 0) = (unsigned int)temp;
        }
    }

    std::cout << "Load Done" << std::endl;

    file.close();
    return dataMat;
}
