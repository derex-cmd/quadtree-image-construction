#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <fstream>
#include <iostream>
#include <string>
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <experimental/filesystem>


using namespace cv;
using namespace std;
namespace fs = std::experimental::filesystem;
struct node
{
    int v;
    int row;
    node* next;
    node* down;
    node()
    {
        v = 0;
        row = 0;
        next = nullptr;
        down = nullptr;
    }
    node(int vl, int r)
    {
        v = vl;
        row = r;
        next = nullptr;
        down = nullptr;
    }
   
};

struct SLinkedList
{

public:
	node* head;

	SLinkedList()
	{
		head = NULL;
	}

	void insert(int v = 0, int r = 0)
    {
		node* n = new node(v, r);

		if (head == NULL)
        {
			head = n;
		}
		else
        {
			node* temp = head;
			while (temp->down != NULL)
            {
				temp = temp->down;
			}
			temp->down = n;
		}
	}


    void insertnext(int v = 0, int r = 0)
    {
        node* n = new node(v, r);

        if (head == NULL)
        {
            head = n;
        }
        else
        {
            node* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
        }
    }

};


node* convertTo2dLL(int** img, int rows, int cols)
{
    //first row of the 2d ling list
    SLinkedList obj;
    for (int i = 0; i < rows; i++)
    {
        obj.insert(0, i + 1);
    }

    bool white = false;
    bool whitefound = false;
    bool whiteS = true;
    int j = 0;
    int wStart = 0;
    int wEnd = 0;
    int tempcol = 0;
    bool tempcolcheck = true;
    bool colend=false;

    //This loop is used to set white pixels
    for (int i = 0; i < rows; i++)
    {
        SLinkedList tempp = obj;
        while (tempp.head->row != i + 1)
        {
            tempp.head = tempp.head->down;
        }

        while (tempcolcheck)
        {
            if (img[i][tempcol] == 255 && tempcol < cols)
            {
                wStart = tempcol + 1;
                whitefound = true;
                while (img[i][tempcol] != 0 && tempcol < cols)
                {
                    tempcol++;
                }
                wEnd = tempcol;
                if (tempcol >= cols)
                {
                    tempcolcheck = false;
                }
                tempp.insertnext(wStart, i + 1);
                tempp.insertnext(wEnd, i + 1);
                wStart = 0;
                wEnd = 0;
            }
            if (img[i][tempcol] == 0)
            {
                wStart = tempcol + 1;
                while (img[i][tempcol] != 255 && tempcol < cols)
                {
                    tempcol++;
                }
                if (img[i][tempcol] == 255)
                {
                    whitefound = true;
                }
                if (tempcol >= cols)
                {
                    tempcolcheck = false;
                }
            }
        }

        /*if (tempcol == cols - 1 )
        {
            white = true;
            tempp.insertnext(-2, i + 1);
            tempcolcheck = false;
        }*/
        tempp.insertnext(-2, i + 1);
   
        tempcolcheck = true;
        bool whitefound = false;
        tempcol = 0;
        wStart = 0;
        wEnd = 0;
    }

    white = false;
    whitefound = false;
    whiteS = true;
    j = 0;
    wStart = 0;
    wEnd = 0;
    tempcol = 0;
    tempcolcheck = true;
    colend = false;

    //This loop is used to set nigga pixels
    for (int i = 0; i < rows; i++)
    {
        SLinkedList tempp = obj;
        while (tempp.head->row != i + 1)
        {
            tempp.head = tempp.head->down;
        }

        while (tempcolcheck)
        {
            if (img[i][tempcol] == 0 && tempcol < cols)
            {
                wStart = tempcol + 1;
                whitefound = true;
                while (img[i][tempcol] != 255 && tempcol < cols)
                {
                    tempcol++;
                }
                wEnd = tempcol;
                if (tempcol >= cols)
                {
                    tempcolcheck = false;
                }
                tempp.insertnext(wStart, i + 1);
                tempp.insertnext(wEnd, i + 1);
                wStart = 0;
                wEnd = 0;
            }
            if (img[i][tempcol] == 255)
            {
                wStart = tempcol + 1;
                while (img[i][tempcol] != 0 && tempcol < cols)
                {
                    tempcol++;
                }
                if (img[i][tempcol] == 0)
                {
                    whitefound = true;
                }
                if (tempcol >= cols)
                {
                    tempcolcheck = false;
                }
            }
        }

        /*if (tempcol == cols - 1 )
        {
            white = true;
            tempp.insertnext(-2, i + 1);
            tempcolcheck = false;
        }*/
        tempp.insertnext(-1, i + 1);

        tempcolcheck = true;
        whitefound = false;
        tempcol = 0;
        wStart = 0;
        wEnd = 0;
    }




    /*node* s = obj.head;
    while (s != NULL)
    {
        node* col = s->next;
        cout << s->row << "  ";
        while (col != NULL)
        {
            cout << col->v << "  ";
            col = col->next;
        }
        cout << endl;
        s = s->down;
    }*/



    return obj.head;
 } 





 //class Quadtree
 //{
 //    int x, y, length, height, color = -999;
 //    Quadtree* children[4];
 //public:
 //    //Quadtree(int x, int y, int width, int height, node* n)
 //    //{
 //    //    bool isHomogeneous = true;
 //    //    bool W = false;
 //    //    bool B = false;
 //    //    cout << "New Iteration" << endl << endl;
 //    //    node* tempcol = n;
 //    //    node* temprow = n;
 //    //    for (int i = 0; i < y ; i++)
 //    //    {
 //    //        if (temprow->down != nullptr)
 //    //        {
 //    //            temprow = temprow->down;
 //    //        }
 //    //    }
 //    //    int l = (width + x);
 //    //    int h = (height + y);
 //    //    cout << "Length = " << l << "  Height = " << h << endl;
 //    //    while (temprow != nullptr)
 //    //    {
 //    //        /*if (l == 0 || h == 0)
 //    //        {
 //    //            break;
 //    //        }*/
 //    //        tempcol = temprow;
 //    //        tempcol = tempcol->next;
 //    //        while (tempcol != nullptr && tempcol->v != -2)
 //    //        {
 //    //            if (tempcol->v == -2)
 //    //            {
 //    //                W = false;
 //    //                cout << "No white -2" << endl;
 //    //                break;
 //    //            }
 //    //            cout << "White begin  " << tempcol->v << "  White end  " << tempcol->next->v << endl;
 //    //            if ((tempcol->v>=x && tempcol->v<=width)||(tempcol->next->v >= x && tempcol->next->v <= width))
 //    //            {
 //    //                W = true;
 //    //                cout << "White" << endl;
 //    //                break;
 //    //            }
 //    //            else
 //    //            {
 //    //                W = false;
 //    //                cout << "No white" << endl;
 //    //            }
 //    //            tempcol = tempcol->next->next;
 //    //        }
 //    //        tempcol = tempcol->next; // start from the bleck column

 //    //        while (tempcol != nullptr && tempcol->v != -1) // check for tempcol != nullptr to avoid nullptr exception
 //    //        {
 //    //            if (tempcol->v == -1)
 //    //            {
 //    //                B = false;
 //    //                cout << "No bleck minus" << endl;
 //    //                break;
 //    //            }
 //    //            cout << "Bleck begin  " << tempcol->v << "  Bleck end  " << tempcol->next->v << endl;
 //    //            if ((tempcol->v >= x && tempcol->v <= width) || (tempcol->next->v >= x && tempcol->next->v <= width))
 //    //            {
 //    //                B = true;
 //    //                cout << "Bleck" << endl;
 //    //                break;
 //    //            }
 //    //            else
 //    //            {
 //    //                B = false;
 //    //                cout << "No bleck" << endl;
 //    //            }
 //    //            tempcol = tempcol->next->next;
 //    //            if (W && B)
 //    //            {
 //    //                isHomogeneous = false;
 //    //                cout << "No HOMO" << endl;
 //    //                break;
 //    //            }
 //    //        }

 //    //        if (W && B)
 //    //        {
 //    //            isHomogeneous = false;
 //    //            cout << "No HOMO" << endl;
 //    //            break;
 //    //        }

 //    //        temprow = temprow->down;
 //    //        if (temprow && temprow->row == y + height)
 //    //        { // add check to break out of loop if temprow is nullptr or if row is equal to height
 //    //            break;
 //    //        }

 //    //        
 //    //    }

 //    //    if (isHomogeneous)
 //    //    {
 //    //        if (W)
 //    //        {
 //    //            color = 255;
 //    //        }
 //    //        else if (B)
 //    //        {
 //    //            color = 0;
 //    //        }
 //    //    }

 //    //    else if (!isHomogeneous)
 //    //    {
 //    //        this->color = -999;//grey color
 //    //    }

 //    //    this->x = x;
 //    //    this->y = y;
 //    //    this->height = y + height;
 //    //    this->length = x + width;



 //    //    if (!isHomogeneous) 
 //    //    {
 //    //        int midLength = width / 2;
 //    //        int midHeight = height / 2;
 //    //        cout << "We will now divide the image" << endl << endl;

 //    //        // First child
 //    //        children[0] = new Quadtree(x, y, midLength, midHeight, n);
 //    //        cout << "Let's move to 2nd child" << endl;

 //    //        // Second child
 //    //        children[1] = new Quadtree(x + midLength, y, midLength, midHeight, n);
 //    //        node* temp = n;
 //    //        // Traverse to the bottom left node of the quadtree
 //    //        for (int i = y; i < y + height; i++)
 //    //        {
 //    //            if (temp->down != nullptr) {
 //    //                temp = temp->down;
 //    //            }
 //    //        }
 //    //        cout << "Let's move to 3rd child" << endl;
 //    //        // Third child
 //    //        children[2] = new Quadtree(x, y + midHeight, midLength, midHeight, temp);
 //    //        cout << "Let's move to 4th child" << endl;
 //    //        // Fourth child
 //    //        children[3] = new Quadtree(x + midLength, y + midHeight, midLength, midHeight, temp);
 //    //    }
 //    //    else
 //    //    {
 //    //        cout << "This part is Homogeneous" << endl;
 //    //        if (W)
 //    //        {
 //    //            this->color = 255;
 //    //            cout << "Color for this part is White" << endl;
 //    //        }
 //    //        else if (B)
 //    //        {
 //    //            this->color = 0;
 //    //            cout << "Color for this part is Bleck" << endl;
 //    //        }
 //    //        for (int i = 0; i < 4; i++)
 //    //        {
 //    //            children[i] = nullptr;
 //    //        }
 //    //        cout << endl << endl;
 //    //    }
 //    //}
 //};





 struct QuadTreeNode
 {
     bool is_leaf;
     int value;//color
     int x, y, width, height;
     static int counter;
     QuadTreeNode* children[4];
     
     QuadTreeNode(bool leaf, int val)
     {
         is_leaf = leaf;
         value = val;
         for (int i = 0; i < 4; i++)
         {
             children[i] = nullptr;
         }
     }


     QuadTreeNode(int** img, int x, int y, int width, int height)
     {

         // Check if all the pixels in the block are the same
         int val = img[x][y];
         bool is_leaf = true;
         bool is_leaf_grey = true;
         for (int i = x; i < x + width; i++)
         {
             for (int j = y; j < y + height; j++)
             {
                 if (img[i][j] != val)
                 {
                     if ((img[i][j] != 0) || (img[i][j] != 255))
                     {
                         is_leaf_grey = false;
                         value = -999;
                         is_leaf = false;
                         break;
                     }
                     is_leaf = false;
                     break;
                 }
             }
             if (!is_leaf)
             {
                 break;
             }
         }

         // Create a leaf node if all the pixels are the same
         if (is_leaf)
         {
             this->x = x;
             this->y = y;
             this->height = height+y;
             this->width = width+x;
             value = val;
             counter++;
             //QuadTreeNode* node = new QuadTreeNode(true, val);
             if (counter == 1)
             {
                 std::string folder = "QuadTreeFolder t3";
                 fs::create_directory(folder);

                 std::string filename = folder + "/root.txt"; // create filename
                 std::ofstream outfile(filename); // create output file stream
                 outfile << this->x << std::endl;
                 outfile << this->y << std::endl;
                 outfile << this->width << std::endl;
                 outfile << this->height << std::endl;
                 outfile << value << std::endl;
                 outfile.close(); // close file stream
                 cout << "Root Node color = " << this->value << " starts from (" << this->x << "," << this->y << ") & ends at (" << this->width << "," << this->height << ")" << endl;
             }
             else
             {
                 std::string folder = "QuadTreeFolder t3";
                 fs::create_directory(folder);

                 std::string filename = folder + "/node" + std::to_string(counter) + ".txt"; // create filename
                 std::ofstream outfile(filename); // create output file stream
                 outfile << this->x << std::endl;
                 outfile << this->y << std::endl;
                 outfile << this->width << std::endl;
                 outfile << this->height << std::endl;
                 outfile << value << std::endl;
                 outfile.close(); // close file stream
                 cout << counter;
                 cout << " Node color = " << this->value << " starts from (" << this->x << "," << this->y << ") & ends at (" << this->width << "," << this->height << ")" << endl;
             }
             //cout << counter;
             //cout << " Node color = " << this->value << " starts from (" << this->x << "," << this->y << ") & ends at (" << this->width << "," << this->height << ")" << endl;
             //return node;
         }

         // Otherwise, recursively divide the block into 4 quadrants and construct quadtree for each quadrant
         else
         {
             if (is_leaf_grey == false)
             {
                 this->x = x;
                 this->y = y;
                 this->height = height+y;
                 this->width = width+x;
                 counter++;
                 //QuadTreeNode* node = new QuadTreeNode(true, val);
                 //cout << "Leaf node number " << counter << endl;
                 val = -999;
                 value = val;
                 //cout << "Not homogeneous, therefore img will be now divided" << endl;
                 if (counter == 1)
                 {
                     std::string folder = "QuadTreeFolder t3";
                     fs::create_directory(folder);

                     std::string filename = folder + "/root.txt"; // create filename
                     std::ofstream outfile(filename); // create output file stream
                     outfile << this->x << std::endl;
                     outfile << this->y << std::endl;
                     outfile << this->width << std::endl;
                     outfile << this->height << std::endl;
                     outfile << value << std::endl;
                     outfile.close(); // close file stream


                     cout << "Root Node color = " << this->value << " starts from (" << this->x << "," << this->y << ") & ends at (" << this->width << "," << this->height << ")" << endl;
                 }
                 else
                 {
                     std::string folder = "QuadTreeFolder t3";
                     fs::create_directory(folder);

                     std::string filename = folder + "/node" + std::to_string(counter) + ".txt"; // create filename
                     std::ofstream outfile(filename); // create output file stream
                     outfile << this->x << std::endl;
                     outfile << this->y << std::endl;
                     outfile << this->width << std::endl;
                     outfile << this->height << std::endl;
                     outfile << value << std::endl;
                     outfile.close(); // close file stream



                     cout << counter;
                     cout << " Node color = " << this->value << " starts from (" << this->x << "," << this->y << ") & ends at (" << this->width << "," << this->height << ")" << endl;
                 }
                 //cout << counter;
                 //cout << " Node color = " << this->value << " starts from (" << this->x << "," << this->y << ") & ends at (" << this->width << "," << this->height << ")" << endl;
                 //cout << "Leaf node created with value " << value << " at position (" << this->x << ", " << this->y << ")" << endl;
             } 
            
             //cout << "Internal node created" << endl;
             children[0] = new QuadTreeNode(img, x, y, width / 2, height / 2);
             //cout << "Top left child created at position (" << x << ", " << y << /*") with value " << children[0].value <<*/ endl;
             children[1] = new QuadTreeNode(img, x, y + height / 2, width / 2, height / 2);
             //cout << "Top right child created at position (" << x << ", " << y + height / 2 << /*") with value " << children[1].value <<*/ endl;
             children[2] = new QuadTreeNode(img, x + width / 2, y, width / 2, height / 2);
             //cout << "Bottom left child created at position (" << x + width / 2 << ", " << y << /*") with value " << children[2].value <<*/ endl;
             children[3] = new QuadTreeNode(img, x + width / 2, y + height / 2, width / 2, height / 2);
             //cout << "Bottom right child created at position (" << x + width / 2 << ", " << y + height / 2 << /*") with value " << children[3].value <<*/ endl;
         }
         
        // return node;
     }
 }; 
 

 int QuadTreeNode::counter = 0;

 //output files

 //cout << "Internal node created at position (" << x << ", " << y << ")" << endl;
 //children[0] = new QuadTreeNode(img, x, y, width / 2, height / 2);
 //cout << "Top left child created at position (" << x << ", " << y << /*") with value " << children[0].value <<*/ endl;
 //children[1] = new QuadTreeNode(img, x, y + height / 2, width / 2, height / 2);
 //cout << "Top right child created at position (" << x << ", " << y + height / 2 << /*") with value " << children[1].value <<*/ endl;
 //children[2] = new QuadTreeNode(img, x + width / 2, y, width / 2, height / 2);
 //cout << "Bottom left child created at position (" << x + width / 2 << ", " << y << /*") with value " << children[2].value <<*/ endl;
 //children[3] = new QuadTreeNode(img, x + width / 2, y + height / 2, width / 2, height / 2);
 //cout << "Bottom right child created at position (" << x + width / 2 << ", " << y + height / 2 << /*") with value " << children[3].value <<*/ endl;












 //QuadTreeNode* construct_quadtree(int** img, int x, int y, int width, int height) 
 //{
 //    // Check if all the pixels in the block are the same
 //    int val = img[x][y];
 //    bool is_leaf = true;
 //    for (int i = x; i < x + width; i++)
 //    {
 //        for (int j = y; j < y + height; j++) 
 //        {
 //            if (img[i][j] != val) {
 //                is_leaf = false;
 //                break;
 //            }
 //        }
 //        if (!is_leaf) break;
 //    }

 //    // Create a leaf node if all the pixels are the same
 //    if (is_leaf)
 //    {
 //        QuadTreeNode* node = new QuadTreeNode(true, val);
 //        cout << "Leaf node created with value " << val << " at position (" << x << ", " << y << ")" << endl;
 //        return node;
 //    }

 //    // Otherwise, recursively divide the block into 4 quadrants and construct quadtree for each quadrant
 //    QuadTreeNode* node = new QuadTreeNode(false, -1);
 //    cout << "Internal node created at position (" << x << ", " << y << ")" << endl;
 //    node->children[0] = construct_quadtree(img, x, y, width / 2, height / 2);
 //    cout << "Top left child created at position (" << x << ", " << y << ") with value " << node->children[0].value << endl;
 //    node->children[1] = construct_quadtree(img, x, y + height / 2, width / 2, height / 2);
 //    cout << "Top right child created at position (" << x << ", " << y + height / 2 << ") with value " << node->children[1].value << endl;
 //    node->children[2] = construct_quadtree(img, x + width / 2, y, width / 2, height / 2);
 //    cout << "Bottom left child created at position (" << x + width / 2 << ", " << y << ") with value " << node->children[2].value << endl;
 //    node->children[3] = construct_quadtree(img, x + width / 2, y + height / 2, width / 2, height / 2);
 //    cout << "Bottom right child created at position (" << x + width / 2 << ", " << y + height / 2 << ") with value " << node->children[3].value << endl;
 //    return node;
 //}



 










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
    int** img = new int*[rows];
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
    //pixel display
    // 
    // 
    //first run this to check pixels stored inside 2d dma
    /*for (int i = 0; i < rows; i++)
    {
        cout << "Row " << i + 1 << endl << endl;
        for (int j = 0; j < cols; j++)
        {
            cout << img[i][j]<<" ";
        }
        cout << endl;
    }*/

    //then comment the above code and uncomment next line to tally the answers
    node* n = convertTo2dLL(img, rows, cols);

    //bool W = false, B = false, G = false, isHomogeneous = false;

    QuadTreeNode* root = new QuadTreeNode(img, 0, 0, rows, cols);
    //Img display
    /*cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE);
    cv::imshow("Display window", image);
    cv::waitKey(0);*/
    return 0;
}



















