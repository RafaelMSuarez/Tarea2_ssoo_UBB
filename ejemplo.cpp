//install vtk hdf5 fmt

#include <iostream>
#include <opencv2/core/types.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>


using namespace cv;
using namespace std;

int main() {

	Mat image = imread("imagen_a_color.jpg", IMREAD_COLOR);
	Mat3b output(image.rows, image.cols);

	for(int r = 0; r < image.rows; r ++) {
		for(int c = 0; c < image.cols; c++) {
			Point3_<uchar>* p = image.ptr<Point3_<uchar> >(r, c);
			output(r,c) = Vec3b(p->x, p->y, p->z);
		}
	}

	imwrite("output.jpg", output);
	return 0;
}