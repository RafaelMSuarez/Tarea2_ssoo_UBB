// install vtk hdf5 fmt
//  g++ -Wall grisSecuencial.cpp -o grisSecuencial `pkg-config --cflags --libs opencv4`

#include <iostream>
#include <opencv2/core/types.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <chrono>

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{

	if (argc != 3)
	{
		cerr << "Faltan argumentos (imagen original y nombre de output)" << endl;
		return 1;
	}

	cout << "Cargando imagen ..." << endl;
	Mat imagen = imread(argv[1], IMREAD_COLOR);

	if (imagen.empty())
	{
		cout << "Error al cargar la imagen" << endl;
		return 1;
	}

	cout << "Filas (alto): " << imagen.rows << " Columnas (ancho): " << imagen.cols << endl;

	Mat output(imagen.rows, imagen.cols, CV_8UC1);

	auto inicio = chrono::steady_clock::now();

	cout << "Comienza conversion ..." << endl;

	for (int r = 0; r < imagen.rows; r++)
	{
		for (int c = 0; c < imagen.cols; c++)
		{
			Vec3b p = imagen.at<Vec3b>(r, c);
			// azul (B) -> x, verde(G) -> y, rojo(R) -> z
			uchar greyW = static_cast<uchar>(p[2] * 0.114 + p[1] * 0.587 + p[0] * 0.299);
			output.at<uchar>(r, c) = greyW;
		}
	}
	cout << "Finaliza conversion ..." << endl;

	imwrite(static_cast<string>(argv[2]), output);

	auto termino = chrono::steady_clock::now();

	chrono::duration<double> tiempo = termino - inicio;

	cout << "Tiempo de demora: " << tiempo.count() << " segundos" << endl;

	return 0;
}