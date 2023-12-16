#ifndef __DATALOADER_H__
#define __DATALOADER_H__

#include <opencv2/opencv.hpp>
#include <string>

const std::string trainImageSet = "..\\data\\train-images.idx3-ubyte";
const std::string trainLabelSet = "..\\data\\train-labels.idx1-ubyte";
const std::string testIamgeSet = "..\\data\\t10k-images.idx3-ubyte";
const std::string testLabelSet = "..\\data\\t10k-labels.idx1-ubyte";

/*
    Parse data set integer
*/
int parseInteger(int rawInteger);

/*
    Load the image set from the given filename
*/
cv::Mat imageLoader(const std::string fileName);

/*
    Load the label set from the given filename
*/
cv::Mat labelLoader(const std::string fileName);

#endif // __DATALOADER_H__
