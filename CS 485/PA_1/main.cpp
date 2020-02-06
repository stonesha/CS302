#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void normalize(Mat &img);
double gauss1D(double x, double sigma);

int main(int argc, char* argv[]){

	return 0;
}

void normalize(Mat &img)
{
	img.convertTo(img, CV_32F, 1.0 / 255.0, 0);
}

double gauss1D(double x, double sigma)
{
	double expVal = -1 * (pow(x, 2) / (2 * pow(sigma, 2)));
    double divider = sqrt(2 * M_PI * pow(sigma, 2));
	return (1 / divider) * exp(expVal);
}