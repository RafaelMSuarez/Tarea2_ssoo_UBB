//install vtk hdf5 fmt

#include <iostream>
#include <opencv2/core/types.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <chrono>


using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {

	if(argc != 2) {
		cerr << "Debe agregar una imagen" << endl ;
		return 1;
	}
	cout << "Cargando imagen ..." << endl;	
	Mat imagen = imread(argv[1], IMREAD_COLOR);

	cout << "Filas (alto): " << imagen.rows << " Columnas (ancho): " << imagen.cols << endl;
	

	Mat output(imagen.rows, imagen.cols, CV_8UC1);

	uchar greyW;

	auto inicio = chrono::steady_clock::now();

	cout << "Comienza conversion ..." << endl;

	for(int r = 0; r < imagen.rows; r ++) {
		for(int c = 0; c < imagen.cols; c++) {
			Point3_<uchar>* p = imagen.ptr<Point3_<uchar> >(r, c);
			// azul (B) -> x, verde(G) -> y, rojo(R) -> z
			greyW = static_cast<uchar>((p->x) * 0.114 + (p->y) * 0.587 + (p->z) * 0.299);
			output.at<uchar>(r,c) = greyW;
		}
	}
	cout << "Finaliza conversion ..." << endl;

	imwrite("output.jpg", output);

	auto termino = chrono::steady_clock::now();

	chrono::duration<double> tiempo = termino - inicio;

	cout << "Tiempo de demora: " << tiempo.count() << " segundos" << endl;

	return 0;
}