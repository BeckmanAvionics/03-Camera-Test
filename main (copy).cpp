/*
  Workflow:
    1: Open camera
    2: Set parameters
    3: Start acquisition
    4: Display moving picture from camera feed
    5: Take a picture upon space button press, save it in "saved_image" folder with present date/time.
*/

#include <iostream>
#include <string>
#include <time.h>
#include <xiApiPlusOcv.hpp>
#include <sstream>

#define EXPOSURE 20000 // 10000 units = 10 ms
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
		printf("Opening camera...\n");
		cam.OpenFirst();

		cam.SetExposureTime(EXPOSURE);
		// Note: The default parameters of each camera might be different in different API versions

		printf("Starting acquisition...\n");
		cam.StartAcquisition();

		printf("First pixel value \n");
		XI_IMG_FORMAT format = cam.GetImageDataFormat();

		bool isRunning = true;
		while (isRunning)
		{
			Mat cv_mat_image = cam.GetNextImageOcvMat();

//			if (format == XI_RAW16 || format == XI_MONO16) {  // This may be able to be modified to get color images/different pixel values, doesn't work so commented out
//				cv::normalize(cv_mat_image, cv_mat_image, 0, 65536, NORM_MINMAX, -1, Mat()); // 0 - 65536, 16 bit unsigned integer range, doesn't work so commented out
				cv::imshow("Image from camera", cv_mat_image);
				cv::imwrite("saved_image/image.jpg", cv_mat_image);
//			}  // for previous if

			if (cv::waitKey(10) == 32) {
				cv::imwrite("saved_image/image" + get_filename(EXPOSURE, 0) + ".jpg", cv_mat_image);
//				printf("image saved under: " + get_filename(EXPOSURE, 0)); //doesn't work, commented out
			}
		}

		cam.StopAcquisition();
		cam.Close();
		printf("Done\n");

		cv::waitKey(500);

	}

	catch(xiAPIplus_Exception& exp) // displays error message
	{
		printf("Error:\n");
		exp.PrintError();
#ifdef WIN32
		Sleep(2000);
#endif
		cv::waitKey(2000);
		printf("big sad it no work\n");
		return -1;
	}
	return 0;
}

string get_string_time() // gets the current date and time
{
    time_t rawtime;
    struct tm * ptm;
    time (&rawtime);
    ptm = gmtime (&rawtime);

    int year = ptm->tm_year+1900, month = ptm->tm_mon+1, day = ptm->tm_mday, hour = (ptm->tm_hour+PDT)%24, min = ptm->tm_min, sec = ptm->tm_sec; // remember to change PST/PDT 

    string year_s = to_string(year);
    string month_s = to_string(month);
    string day_s = to_string(day);
    string hour_s = to_string(hour);
    string min_s = to_string(min);
    string sec_s = to_string(sec);

    return year_s + "-" + month_s + "-" + day_s + "_" + hour_s + "." + min_s + "." + sec_s;
}

string get_filename(int exposure, int gain) // sets filename to current date, time, and exposure (we don't have gain yet)
{
    string filename;
    filename += get_string_time() + "_exposure-" + to_string(exposure) + "_gain-" + to_string(gain);
    return filename;
}
