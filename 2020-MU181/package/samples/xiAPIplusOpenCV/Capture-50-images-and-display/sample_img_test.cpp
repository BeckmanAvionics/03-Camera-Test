#include <iostream>
#include "xiApiPlusOcv.hpp"
#include <opencv2/imgproc.hpp>

using namespace cv;

 int main(int argc, char*argv[]){
	Mat image; //chosen image
	Mat dst; //blurred clone of image
	image = cv::imread("saved_image/image2021-10-7_15.49.18_exposure-35000_gain-0.jpg");
	if (argc != 2 || !image.data) {
		printf("No image data \n");
		return -1;
	}
	dst = image.clone();

	for (int i = 1; i < 31; i = i + 2){
		cv::medianBlur(image, dst, i); //i stands for ksize (aperture size)
	} 

	cv::namedWindow("Display Image", cv::WINDOW_NORMAL);
	cv::imshow("Display Image", dst);

	cv::waitKey(0);

	return 0;
}


