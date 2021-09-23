/*
  This is the reference example application code for XIMEA cameras.
  You can use it to simplify development of your camera application.
  
  Sample name: 
    xiAPIplusOpenCV / Capture-50-images-and-display

  Description: 
    Open camera, capture 50 images while displaying each on the screen

  Workflow:
    1: Open camera
    2: Set parameters
    3: Start acquisition
    4: For each image captured - display on screen
*/

#include <iostream>
#include <string>
#include <time.h>
#include <xiApiPlusOcv.hpp>
#include <sstream>

#define EXPECTED_IMAGES 500
#define EXPOSURE 20000
#define PST (-8)
#define PDT (-7)

using namespace cv;
using namespace std;

string get_string_time();
string get_filename(int exposure, int gain);

template <typename T>
std::string to_string(const T& value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

int main(int argc, char* argv[])
{
	try
	{
		// Sample for XIMEA OpenCV
		xiAPIplusCameraOcv cam;

		// Retrieving a handle to the camera device
		printf("Opening first camera...\n");
		cam.OpenFirst();
		
		// Set exposure
		cam.SetExposureTime(EXPOSURE); //10000 us = 10 ms
		// Note: The default parameters of each camera might be different in different API versions
		
		printf("Starting acquisition...\n");
		cam.StartAcquisition();
		
		printf("First pixel value \n");
		XI_IMG_FORMAT format = cam.GetImageDataFormat();
		// for (int images=0;images < EXPECTED_IMAGES;images++)

		for (;;) // this loop goes forever
		{
			Mat cv_mat_image = cam.GetNextImageOcvMat();
			if (format == XI_RAW16 || format == XI_MONO16) // This may be able to be modified to get color images/different pixel values
				normalize(cv_mat_image, cv_mat_image, 0, 65536, NORM_MINMAX, -1, Mat()); // 0 - 65536, 16 bit unsigned integer range
			cv::imshow("Image from camera", cv_mat_image);
			
			// cvWaitKey(20);
			int keyboard_input = cv::waitKey(20);
			string s_filename = get_filename(EXPOSURE, 100);
			const char* filename = const_cast<char*>(s_filename.c_str())
			// char* filename = &get_filename(EXPOSURE, 100);
			if (keyboard_input == 32) {
				cv::imwrite(std::string(filename), cv_mat_image);
				printf("image saved under: " + &filename);
			} 
			// printf("\t%d\n",cv_mat_image.at<unsigned char>(0,0));
		}
	
		cam.StopAcquisition();
		cam.Close();
		printf("Done\n");
		
		cvWaitKey(500);
	}
	catch(xiAPIplus_Exception& exp)
	{
		printf("Error:\n");
		exp.PrintError();
#ifdef WIN32
		Sleep(2000);
#endif
		cvWaitKey(2000);
		return -1;
	}
	return 0;
}


string get_string_time()
{
    time_t rawtime;
    struct tm * ptm;
    time (&rawtime);
    ptm = gmtime (&rawtime);

    int year = ptm->tm_year+1900, month = ptm->tm_mon+1, day = ptm->tm_mday, hour = (ptm->tm_hour+PST)%24, min = ptm->tm_min, sec = ptm->tm_sec;

    string year_s = to_string(year);
    string month_s = to_string(month);
    string day_s = to_string(day);
    string hour_s = to_string(hour);
    string min_s = to_string(min);
    string sec_s = to_string(sec);

    return year_s + "-" + month_s + "-" + day_s + "_" + hour_s + "." + min_s + "." + sec_s;
}

string get_filename(int exposure, int gain)
{
    string filename;
    filename += get_string_time() + "_exposure-" + to_string(exposure) + "_gain-" + to_string(gain);
    return filename;
}

