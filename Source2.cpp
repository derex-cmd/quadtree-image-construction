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
    bool is_leaf = false;
    int x, y, width, height, color;
    int xroot, yroot, widthroot, heightroot, colorroot;
    x = y = width = height = color = 0;
    xroot = yroot = widthroot = heightroot = colorroot = 0;
    //read from folder
    string folder_path = "E:/FAST BSCS/FAST S4/Data/OpenCV2/QuadTreeFolder t3";
    string filename_prefix = "node";
    string filename_extension = ".txt";

    //read from root
    string root = "root.txt";
    string root_path = folder_path + "/" + root;
    fstream file(root_path);
    if (file)
    {
        std::cout << "Reading file " << root << endl;
        if (file >> xroot)
        {
            cout << "x: " << xroot << endl;
        }
        if (file >> yroot)
        {
            cout << "y: " << yroot << endl;
        }
        if (file >> widthroot)
        {
            cout << "Width: " << widthroot << endl;
        }
        if (file >> heightroot)
        {
            cout << "Height: " << heightroot << endl;
        }
        if (file >> colorroot)
        {
            cout << "Color: " << colorroot << endl;
        }
        cout << endl << endl;
    }
    else
    {
        cout << "No files left" << endl;
        //break;
    }


    cout << "Height = " << heightroot << " Width = " << widthroot << endl;

    int** img = new int* [widthroot];
    for (int i = 0; i < widthroot; i++)
    {
        img[i] = new int[heightroot];
    }
    for (int i = 0; i < widthroot; i++)
    {
        for (int j = 0; j < heightroot; j++)
        {
            //cout << "Success" << endl;
            img[i][j] = 0;
            // cout << img[i][j] << "  ";
        }
        //cout << endl;
    }


    for (int i = 2; i <= 10000; i++)//begin from node2 till the end node (10000 is to get to the last file)
    {
        string s = to_string(i);
        string filename = filename_prefix + s + filename_extension;

        string file_path = folder_path + "/" + filename;
        fstream file(file_path);
        if (file)
        {
            //std::cout << "Reading file " << filename << endl;
            //double x, y, width, height, color;
            if (file >> x)
            {
               // cout << "x: " << x << endl;
            }
            if (file >> y)
            {
                //cout << "y: " << y << endl;
            }
            if (file >> width)
            {
               // cout << "Width: " << width << endl;
            }
            if (file >> height)
            {
                //cout << "Hieght: " << height << endl;
            }
            if (file >> color)
            {
               // cout << "Color: " << color << endl;
            }
            //cout << endl << endl;
        }
        else
        {
            cout << "No files left" << endl;
            break;
        }

        if (color == -999)
        {
            //cout << "This is grey color, skip this one" << endl;
            is_leaf = false;
        }
        else
        {
            is_leaf = true;
            if (is_leaf)
            {
                for (int i = x; i < width; i++)
                {
                    for (int j = y; j < height; j++)
                    {
                        img[i][j] = color;
                    }
                }

            }
        }

        x = y = width = height = color = 0;

    }


    //for (int i = 0; i < widthroot; i++)
    //{
    //    for (int j = 0; j < heightroot; j++)
    //    {
    //        //cout << "Success" << endl;
    //        cout << img[i][j] << "  ";
    //    }
    //    cout << endl;
    //}

    Mat imgf(widthroot, heightroot, CV_8UC1);

    for (int i = 0; i < widthroot; i++)
    {
        for (int j = 0; j < heightroot; j++)
        {
            imgf.at<uchar>(i, j) = img[i][j];
        }
    }


    std::string path = "E:/FAST BSCS/FAST S4/Data/Assignment 4/";
    std::string fileName = "t3_f.bmp";
    std::string filePath = path + fileName;

    imwrite(filePath, imgf);
    // Display the image
    imshow("Image", imgf);
    waitKey(0);


    //Mat obeject(row, column, CV_8UC1);

    return 0;
}
