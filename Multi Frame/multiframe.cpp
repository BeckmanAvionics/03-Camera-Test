#include <stdio.h>
#include "xiApiPlusOcv.hpp" 
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include "imgproc.hpp"
#define NUM_OF_PICS 10

using namespace cv;
using namespace std;

int main (void)
{
 try
 {
   xiAPIplusCameraOcv cam;
   cam.OpenFirst();
   cam.SetExposureTime(5000); //10000 us = 10 ms
//   xiSetParamInt(cam, XI_PRM_IMAGE_DATA_FORMAT, XI_RGB64);
   cam.StartAcquisition();
   printf("here 4\n");
   for (;;) 
   {
	// Read and convert a frame from the camera
	Mat cv_mat_image = cam.GetNextImageOcvMat();
	// Show image on display
   	cv::imshow("Image from camera",cv_mat_image);
   	cv::imwrite("image.jpg", cv_mat_image);
   	cv::waitKey(12);
   }
   cam.StopAcquisition();
   cam.Close();
   printf("here 3\n");
   
 }
 catch(xiAPIplus_Exception& exp)
 {
   printf("here 2 \n");
   exp.PrintError(); // report error if some call fails
 }
}
