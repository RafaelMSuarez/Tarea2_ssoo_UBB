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
	// Se inicia el timer global
    auto inicioGlobal = chrono::steady_clock::now();

    // Se inicia el timer de carga de imagen
    auto inicioCarga = chrono::steady_clock::now();

	cout << "Cargando imagen ..." << endl;
	Mat imagen = imread(argv[1], IMREAD_COLOR);

	// Se termina el timer de carga de imagen
    auto finCarga = chrono::steady_clock::now();

	chrono::duration<double> tiempoCarga = finCarga - inicioCarga;

	if (imagen.empty())
	{
		cout << "Error al cargar la imagen" << endl;
		return 1;
	}

	cout << "Filas (alto): " << imagen.rows << " Columnas (ancho): " << imagen.cols << endl;

	Mat output(imagen.rows, imagen.cols, CV_8UC1);

	cout << "Comienza conversion ..." << endl;

	// Se inicia el timer de proceso de imagen
    auto inicioProc = chrono::steady_clock::now();

	// Se cambia a como estaba originalmente en el ejemplo (usando punteros en vez de funciones de OpenCV)
	// La diferencia es clara, pero la documentacion indica que esto es mas peligroso
	for (int r = 0; r < imagen.rows; r++)
	{
		uchar *op = output.ptr<uchar>(r);

		for (int c = 0; c < imagen.cols; c++)
		{
			Point3_<uchar> *p = imagen.ptr<Point3_<uchar>>(r, c);
			// azul (B) -> x, verde(G) -> y, rojo(R) -> z
			uchar greyW = static_cast<uchar>(p->x * 0.114 + p->y * 0.587 + p->z * 0.299);

			op[c] = greyW;
		}
	}
	// Se termina el timer de proceso de imagen
    auto finProc = chrono::steady_clock::now();

    chrono::duration<double> tiempoProc = finProc - inicioProc;

	cout << "Finaliza conversion ..." << endl;

	// Se inicia el timer de escritura de imagen
    auto inicioWrite = chrono::steady_clock::now();

	cout << "Creando imagen ..." << endl;
	imwrite(static_cast<string>(argv[2]), output);

	cout << "Imagen lista ..." << endl;

	// Se termina el timer de escritura de imagen
    auto finWrite = chrono::steady_clock::now();

    chrono::duration<double> tiempoWrite = finWrite - inicioWrite;

	// Termina el timer global
	auto finGlobal = chrono::steady_clock::now();

	chrono::duration<double> tiempoGlobal = finGlobal - inicioGlobal;

	cout << "Tiempo de demora Global: " << tiempoGlobal.count() << " segundos" << endl;
	cout << "Tiempo de demora Carga de Imagen: " << tiempoCarga.count() << " segundos" << endl;
	cout << "Tiempo de demora Procesamiento de imagen: " << tiempoProc.count() << " segundos" << endl;
	cout << "Tiempo de demora Escritura de imagen: " << tiempoWrite.count() << " segundos" << endl;

	return 0;
}