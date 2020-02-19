#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <sstream>
#include "xiApiPlusOcv.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <typeinfo>
#include <ctime>

int main(void) {
using namespace cv;
xiAPIplusCameraOcv cam;
cam.OpenFirst();
int exposure=100000;//in us
cam.SetExposureTime(exposure);
cam.SetGain(15);
cam.StartAcquisition();
time_t timee;

while(1==1) {
//Read and convert a frame from the camera
Mat cv_mat_image = cam.GetNextImageOcvMat ();
//Show image on display
cv::imshow("Image from camera",cv_mat_image);
timee = time(0);
char* dt=ctime(&timee);
//char* exp = std::to_string(exposure);

if (cv::waitKey(10)==32){
	cv::imwrite(std::string(dt)+"exposure"+"100000"+".jpg", cv_mat_image);
}
}

cam.StopAcquisition();
cam.Close();
}
