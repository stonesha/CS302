/**
 * @brief  CS-485 PA2
 * @Author Stone Sha (stones@nevada.unr.edu)
 * @date   March 2020
 *
 * For normalizing the provided face images
 */
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//Struct to keep track of all data concerning images
struct Image {

	string imageName;
	
	Point2f leftEye, rightEye, noseTip, mouthCenter;
	
	Mat img = imread("S1/" + imageName, IMREAD_GRAYSCALE);
	
	
};

//for normalizing images, takes in a struct image
void normalize(Image &image);

int main(int argc, char** argv)
{
    //all pixel values initialized
	struct Image images[10] = {{"1.pgm", {25, 50}, {63, 50}, {45, 71}, {45, 89}},
                              {"2.pgm", {31, 45}, {75, 43}, {65, 66}, {59, 87}},
                              {"3.pgm", {24, 48}, {62, 44}, {46, 74}, {45, 89}},
                              {"4.pgm", {15, 45}, {54, 42}, {28, 63}, {32, 84}},
                              {"5.pgm", {36, 44}, {76, 43}, {67, 63}, {64, 84}},
                              {"6.pgm", {11, 47}, {51, 44}, {27, 67}, {30, 85}},
                              {"7.pgm", {24, 45}, {60, 43}, {43, 59}, {43, 81}},
                              {"8.pgm", {28, 46}, {65, 43}, {50, 66}, {40, 84}},
                              {"9.pgm", {30, 36}, {68, 35}, {53, 49}, {52, 73}},
                              {"10.pgm", {35, 52}, {75, 50}, {61, 77}, {56, 91}}};
    
    //loop through array of structs and normalizes all images
    //writes it to "results" directory
    cout << "Normalizing Images" << endl;
    for(int i = 0; i < 10; i++)
    {
        normalize(images[i]);
    }
	
	return 0;
}

//48 x 40
void normalize(Image &image)
{
    //matrices
    //CV_32F for float
    Mat P(4, 3, CV_32F);
    Mat c1(3, 1, CV_32F);
    Mat c2(3, 1, CV_32F);
    
    Mat A(2, 2, CV_32F);
    Mat b(2, 1, CV_32F);
    Mat Pf(2, 1, CV_32F);
    
    //actual locations for features
    static const Mat px({3.0f, 30.0f, 20.0f, 20.0f}), py({2.0f, 2.0f, 30.0f, 35.0f});
    
    //Temporary containers for results
    Mat Pi, pixel;
    
    //CV_8U for grayscale (0, 1)
    Mat dest(48, 40, CV_8U);
    //opencv already has a function for calculating svd
    SVD svd;
    
    //constructing matrix for P
    P.at<cv::Vec3f>(0) = cv::Vec3b(image.leftEye.x, image.leftEye.y, 1.0f);
	P.at<cv::Vec3f>(1) = cv::Vec3b(image.rightEye.x, image.rightEye.y, 1.0f);
	P.at<cv::Vec3f>(2) = cv::Vec3b(image.noseTip.x, image.noseTip.y, 1.0f);
	P.at<cv::Vec3f>(3) = cv::Vec3b(image.mouthCenter.x, image.mouthCenter.y, 1.0f);
	
	//calculate least squares for c1 and c2
	svd(P);
	
	svd.backSubst(px, c1);
	svd.backSubst(py, c2);
	
	//use c1 and c2 to build matrices for A and b
	//at (row, col)
	A.at<float>(0, 0) = c1.at<float>(0, 0);
	A.at<float>(0, 1) = c1.at<float>(1, 0);
	A.at<float>(1, 0) = c2.at<float>(0, 0);
	A.at<float>(1, 1) = c2.at<float>(1, 0);
    
    b.at<float>(0, 0) = c1.at<float>(2, 0);
    b.at<float>(1, 0) = c2.at<float>(2, 0);

    //Calculate Pf = AP + b
    for(int x = 0; x < dest.cols; x++)
    {
        for(int y = 0; y < dest.rows; y++)
        {
            Pf = Mat({(float) x, (float) y});
            //use inverse to calculate missing matrix
            Pi = A.inv() * Pf - b;
            pixel = Mat({(int) Pi.at<float>(0, 0), (int) Pi.at<float>(1, 0)});
            
            dest.at<uchar>(y, x) = image.img.at<uchar>(pixel.at<int>(1, 0), pixel.at<int>(0, 0));
        }
    }
    
    //named final_{number}.pgm in results folder
    imwrite("results/final_" + image.imageName, dest);
    
}
