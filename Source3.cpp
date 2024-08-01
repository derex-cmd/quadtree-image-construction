#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>


using namespace cv;
using namespace std;

int main()
{
	//image reading
	Mat image = imread("E:/FAST BSCS/FAST S4/Data/Assignment 4/t3.bmp", IMREAD_GRAYSCALE);
	if (image.empty())
	{
		cout << "Failed to load image" << endl;
		return -1;
	}

	int rows = image.rows;
	int cols = image.cols;

	cout << "Image rows: " << rows << endl;
	cout << "Image cols: " << cols << endl;

	//declaring new 2d array
	int** img = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		img[i] = new int[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			img[i][j] = 0;
		}
	}
	//Populating the array with pixels value
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			img[i][j] = (int)image.at<uchar>(i, j);
		}
	}
		





	Mat image_f = imread("E:/FAST BSCS/FAST S4/Data/Assignment 4/t3_f.bmp", IMREAD_GRAYSCALE);
	if (image_f.empty())
	{
		cout << "Failed to load image" << endl;
		return -1;
	}

	int rows_f = image_f.rows;
	int cols_f = image_f.cols;

	cout << "Image rows: " << rows_f << endl;
	cout << "Image cols: " << cols_f << endl;
	
	//declaring new 2d array
	int** img_f = new int* [rows_f];
	for (int i = 0; i < rows_f; i++)
	{
		img_f[i] = new int[cols_f];
	}

	for (int i = 0; i < rows_f; i++)
	{
		for (int j = 0; j < cols_f; j++)
		{
			img_f[i][j] = 0;
		}
	}
	//Populating the array with pixels value
	for (int i = 0; i < rows_f; i++)
	{
		for (int j = 0; j < cols_f; j++)
		{
			img_f[i][j] = (int)image_f.at<uchar>(i, j);
		}
	}




	int n = rows * cols;
	double temp = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			temp += ((img[i][j] - img_f[i][j]) * (img[i][j] - img_f[i][j]));
		}
	}

	double X = 0;
	X = temp / n;

	double Y = 100 * (1 - (X / (255 * 255)));

	cout << "Accuracy of this image is = " << Y << endl;
		   

	

}