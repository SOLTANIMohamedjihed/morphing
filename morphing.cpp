#include <iostream>
#include <opencv2/opencv.hpp>

cv::Mat morphImages(const cv::Mat& sourceImage, const cv::Mat& targetImage, float alpha) {
    cv::Mat morphedImage;
    cv::addWeighted(sourceImage, alpha, targetImage, 1 - alpha, 0, morphedImage);
    return morphedImage;
}

int main() {
    std::string sourceImagePath = "path/to/source/image.jpg";
    std::string targetImagePath = "path/to/target/image.jpg";
    float alpha = 0.5; // Morphing parameter, ranging from 0 to 1

    cv::Mat sourceImage = cv::imread(sourceImagePath);
    cv::Mat targetImage = cv::imread(targetImagePath);

    if (sourceImage.empty() || targetImage.empty()) {
        std::cout << "Failed to load images!" << std::endl;
        return -1;
    }

    cv::Mat morphedImage = morphImages(sourceImage, targetImage, alpha);

    cv::imshow("Morphed Image", morphedImage);
    cv::waitKey(0);

    return 0;
}