#include <stdio.h>
#include "xiApiPlusOcv.hpp" 
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include "imgproc.hpp"

using namespace cv;
using namespace std;

int main (void)
{
 try
 {
   xiAPIplusCameraOcv cam;
   cam.OpenFirst();
   cam.SetExposureTime(100029); //10000 us = 10 ms
   cam.StartAcquisition();

   // Read and convert a frame from the camera
   Mat cv_mat_image = cam.GetNextImageOcvMat();
   // Show image on display
   cv::imshow("Image from camera",cv_mat_image);
   cv::imwrite("image.jpg",cv_mat_image);
   cv::waitKey(0);
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
