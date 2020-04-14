#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace cv;
using namespace std;

#define PI   3.1415926535

void performOperation(string inFile, string outFile, int radius, int max_circles, int threshold);
void houghDetect(Mat src, Mat& dst, int radius, int max_circles, int threshold);
void removeBelowThreshold(vector<vector<int>>& vec, int threshold);

int main(int argc, const char** argv)
{
	if (argc < 6)
	{
		cout << "Expected: main [radius] [maximum # of circles] [threshold] [input filename] [output filename]" << endl;
		return -1;
	}
		

	int radius = atoi(argv[1]);
	int max_circles = atoi(argv[2]);
	int threshold = atoi(argv[3]);
	string inFile = argv[4];
	string outFile = argv[5];

	performOperation(inFile, outFile, radius, max_circles, threshold);

	return 0;
}

void performOperation(string inFile, string outFile, int radius, int max_circles, int threshold)
{
	Mat src = imread("circles/" + inFile, IMREAD_GRAYSCALE); //read in grayscale version of image
	Mat final_dst;
	cvtColor(src, final_dst, COLOR_GRAY2BGR);

	Mat src_blur = src.clone();
	GaussianBlur(src, src_blur, Size(5, 5), 1, 1, BORDER_DEFAULT); //apply gaussian blur to denoise

	Mat src_edges = src.clone();
	Canny(src_blur, src_edges, 200, 250, 3);

	houghDetect(src_edges, final_dst, radius, max_circles, threshold);
	
	imwrite("final/" + outFile, final_dst);
}

//assuming the radius of circles is not known
void houghDetect(Mat src, Mat& dst, int radius, int max_circles, int threshold)
{

	//initialize 3d vector with 0's
	//vector<vector<vector<int>>> acc(src.rows, vector<vector<int>>(src.cols, vector<int>(radius)));
	vector<vector<int> > acc_cells(src.rows, vector<int>(src.cols, 0));

	//iterate through image
	for (int r = 0; r < radius; r++)
	{
		for (int i = 0; i < src.rows; i++)
		{
			for (int j = 0; j < src.cols; j++)
			{
				//if hard edge is detected
				if (src.at<uchar>(i, j) == 255)
				{
					//theta
					for (int t = 0; t < 360; t++)
					{
						int b = i - round(r * sin(t * PI / 180));
						int a = j - round(r * cos(t * PI / 180));
						if (a >= 0 && a < src.rows &&
							b >= 0 && b < src.cols)
						{
							acc_cells[a][b] += 1;
						}
					}
				}
			}
		}
	}

	vector<int> one_dim_acc;
	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			one_dim_acc.push_back(acc_cells[i][j]);
		}
	}

	vector<Point2i> circles;
	vector<int> radii;
	for (int r = 0; r < radius; r++)
	{
		int max_acc_cell = *max_element(one_dim_acc.begin(), one_dim_acc.end());
		cout << "maximum accumulator cell value is: " << max_acc_cell << endl;

		if (max_acc_cell > threshold)
		{
			//initial threshold
			removeBelowThreshold(acc_cells, threshold);

			for (int i = 0; i < src.rows; i++)
			{
				for (int j = 0; j < src.cols; j++)
				{
					if (i > 0 && j > 0 && i < src.rows - 1 && j < src.cols - 1 && acc_cells[i][j] >= 150)
					{
						circles.push_back(Point(i, j));
						radii.push_back(r);
					}
				}
			}
		}
	}
	//circle(dst, Point(i, j), radius, Scalar(0, 0, 255));
	//draw circles
	for (int i = 0; i < circles.size(); i++)
	{
		circle(dst, circles[i], radii[i], Scalar(0, 0, 255));
	}

	

}

void removeBelowThreshold(vector<vector<int>>& vec, int threshold)
{
	for (auto& i : vec)
	{
		for (auto& j : i)
		{
			if (j < threshold)
			{
				j = 0;
			}
		}
	}
}