//install vtk hdf5 fmt
// g++ grisSecuencial.cpp -o grisSecuencial `pkg-config --cflags --libs opencv4`

#include <iostream>
#include <opencv2/core/types.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <chrono>


using namespace cv;
using namespace std;


void procesarImagen(const Mat& original, Mat& output, int filaInicio, int filaFin) {
    for(int r = filaInicio; r < filaFin; r ++) {
		for(int c = 0; c < original.cols; c++) {
			Point3_<uchar>* p = imagen.ptr<Point3_<uchar> >(r, c);
			// azul (B) -> x, verde(G) -> y, rojo(R) -> z
			uchar greyW = static_cast<uchar>((p->x) * 0.114 + (p->y) * 0.587 + (p->z) * 0.299);
			output.at<uchar>(r,c) = greyW;
		}
	}
}

int main(int argc, char* argv[]) {

	if(argc != 2) {
		cerr << "Debe agregar una imagen" << endl ;
		return 1;
	}
	cout << "Cargando imagen ..." << endl;	
	Mat imagen = imread(argv[1], IMREAD_COLOR);

	if(imagen.empty()) {
		cout << "Error al cargar la imagen" << endl;
		return 1;
	}

	cout << "Filas (alto): " << imagen.rows << " Columnas (ancho): " << imagen.cols << endl;
	

	Mat output(imagen.rows, imagen.cols, CV_8UC1);

	auto inicio = chrono::steady_clock::now();

	cout << "Comienza conversion ..." << endl;


    // AGREGAR THREADS

    // VERIFICAR QUE ARGUMENTO ES INT Y NO CUALQUIER OTRA COSITA
	
	cout << "Finaliza conversion ..." << endl;

	imwrite("outputSecuencial.png", output);

	auto termino = chrono::steady_clock::now();

	chrono::duration<double> tiempo = termino - inicio;

	cout << "Tiempo de demora: " << tiempo.count() << " segundos" << endl;

	return 0;
}