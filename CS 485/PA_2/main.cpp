#include <opencv2/opencv.hpp>
#include <iostream>

#include "svd.h"

using namespace cv;
using namespace std;

struct coord {
	//left eye
	int lx1, ly1, lx2, ly2;
	//right eye
	int rx1, ry1, rx2, ry2;
	//nose
	int nx1, nx2, ny1, ny2;
	//mouth
	int mx1, my1, mx2, my2;
};

int main(int argc, char** argv)
{
	
	return 0;
}