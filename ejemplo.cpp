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
	Mat output(image.rows, image.cols, CV_8UC1);
	uchar greyW;

	for(int r = 0; r < image.rows; r ++) {
		for(int c = 0; c < image.cols; c++) {
			Point3_<uchar>* p = image.ptr<Point3_<uchar> >(r, c);
			// azul (B) -> x, verde(G) -> y, rojo(R) -> z
			greyW = static_cast<uchar>((p->x) * 0.114 + (p->y) * 0.587 + (p->z) * 0.299);
			output.at<uchar>(r,c) = greyW;
		}
	}

	imwrite("output.jpg", output);
	return 0;
}