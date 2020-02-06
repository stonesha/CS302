/*
To do: add matplotlib functionality, perhaps in a separate file?
*/

#define _USE_MATH_DEFINES

#include <iostream>
#include <fstream>
#include <cmath>
#include <opencv2/opencv.hpp>
#include <vector>
#include <algorithm>

using namespace std;
using namespace cv;

inline void normalize(Mat &img);
inline double gauss1D(double x, double sigma);

int main(int argc, char* argv[]){
	ifstream fp("Rect_128.txt");
	vector<double> fileNums;

	for(string line; getline(fp, line);)
	{
		fileNums.push_back(stod(line));
	}

	vector<double> sigma1;
	vector<double> sigma5;
	vector<double> sigma11;

	for(double i : fileNums)
	{
		sigma1.push_back(gauss1D(i, 1));
		sigma5.push_back(gauss1D(i, 5));
		sigma11.push_back(gauss1D(i, 11));
	}





	return 0;
}

inline void normalize(Mat &img)
{
	img.convertTo(img, CV_32F, 1.0 / 255.0, 0);
}

inline double gauss1D(double x, double sigma)
{
	double expVal = -1 * (pow(x, 2) / (2 * pow(sigma, 2)));
    double divider = sqrt(2 * M_PI * pow(sigma, 2));
	return (1 / divider) * exp(expVal);
}