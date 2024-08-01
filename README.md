# Quadtree Image Processing

## Overview

This project implements a Quadtree data structure to perform image processing tasks. A Quadtree is a tree data structure in which each internal node has exactly four children. It is used to partition a two-dimensional space by recursively subdividing it into four quadrants or regions.

### Features

- **Efficient Image Representation**: Decomposes images into regions of uniform color, providing a compact representation.
- **Image Comparison**: Calculates the accuracy of image processing by comparing original and processed images.
- **OpenCV Integration**: Utilizes OpenCV for image reading and processing.

## Files and Structure

- **Source.cpp**: Implements the core `QuadTreeNode` structure.
- **Source2.cpp**: Builds on the core structure, adding a `QuadTree` class to manage the tree.
- **Source3.cpp**: Demonstrates practical use, including image reading, quadtree construction, and accuracy calculation.

## Getting Started

### Prerequisites

- **OpenCV**: Make sure you have OpenCV installed. You can install it using the following command:
  ```sh
  sudo apt-get install libopencv-dev
  ```
or via pip for Python bindings:

```sh
pip install opencv-python
```
### Compilation

To compile the project, use the following command:

```sh
g++ Source.cpp Source2.cpp Source3.cpp -o quadtree `pkg-config --cflags --libs opencv4`
```
### Running the Program

After compilation, run the program with the following command:

```sh
./quadtree
```
### Input Images

The program expects two grayscale images located at specified paths in the code:

- `t3.bmp`
- `t3_f.bmp`

Modify the paths in `Source3.cpp` if your images are located elsewhere:

```cpp
Mat image = imread("path/to/your/image.bmp", IMREAD_GRAYSCALE);
Mat image_f = imread("path/to/your/image_f.bmp", IMREAD_GRAYSCALE);
```
### Usage

- **Read and Process Images**: The program reads the images and converts them into 2D arrays.
- **Construct Quadtree**: It builds the quadtree from the image data.
- **Calculate Accuracy**: Finally, it calculates the accuracy of the image processing by comparing the original and processed images.

### Code Explanation

- **Source.cpp**: This file contains the main implementation of a Quadtree:
  - `QuadTreeNode` Structure: Represents a node in the Quadtree.
  - Constructor: Initializes the node and checks for homogeneity.

- **Source2.cpp**: This file extends the implementation:
  - `QuadTree` Class: Manages the quadtree and includes methods to build and traverse it.
  - `Subdivide` Method: Divides the current node if it's not homogeneous.
  - `Build` Method: Recursively constructs the quadtree.

- **Source3.cpp**: This file demonstrates the practical application:
  - Image Reading: Uses OpenCV to read and convert an image to grayscale.
  - 2D Array Creation: Stores pixel values in a 2D array.
  - Quadtree Construction: Builds the quadtree from pixel data.
  - Accuracy Calculation: Computes the accuracy of image processing.

### Example Output

```sh
Image rows: 256
Image cols: 256
Accuracy of this image is = 98.76%
```
### Contributing

Contributions are welcome! Please open an issue or submit a pull request.

### Acknowledgements

- OpenCV for the image processing library.
- Inspiration from data structures and algorithms in image processing.

























  
