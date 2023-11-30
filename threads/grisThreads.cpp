// install opencv vtk hdf5 fmt (para archlinux)
// al parecer libopencv-dev es suficiente para Debian
//  g++ -Wall grisThreads.cpp -o grisThreads `pkg-config --cflags --libs opencv4` -lpthread

#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <opencv2/core/types.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

// Se cambia a como estaba originalmente en el ejemplo (usando punteros en vez de funciones de OpenCV)
// La diferencia es clara, pero la documentacion indica que esto es mas peligroso
void procesarImagen(Mat &original, Mat &output, int filaInicio, int filaFin)
{
    for (int r = filaInicio; r < filaFin; r++)
    {
        uchar *op = output.ptr<uchar>(r);

        for (int c = 0; c < original.cols; c++)
        {
            Point3_<uchar> *p = original.ptr<Point3_<uchar>>(r, c);
            // azul (B) -> x, verde(G) -> y, rojo(R) -> z
            uchar greyW = static_cast<uchar>(p->x * 0.114 + p->y * 0.587 + p->z * 0.299);

            op[c] = greyW;
        }
    }
}

// se crea esta funcion para asegurar que se ingrese un numero
bool checkNumber(char num[])
{
    for (int i = 0; num[i] != 0; i++)
    {
        if (!isdigit(num[i]))
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cerr << "Faltan argumentos (imagen original - nombre imagen output - numero de hebras)" << endl;
        return 1;
    }

    if (argv[3][0] == '-')
    {
        cerr << "No se permiten hebras negativas" << endl;
        return 1;
    }

    if (!checkNumber(argv[3]))
    {
        cerr << "Debe ingresar el numero de hebras" << endl;
        return 1;
    }

    // Se inicia el timer global
    auto inicioGlobal = chrono::steady_clock::now();

    // Se inicia el timer de carga de imagen
    auto inicioCarga = chrono::steady_clock::now();
    // Se carga la imagen original
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

    // Se crea el vector para la imagen final CV_8UC1 es el tipo para imagen con escalar de grises
    Mat output(imagen.rows, imagen.cols, CV_8UC1);

    cout << "Comienza conversion ..." << endl;

    // se crea un vector de hebras (vector es variable en tamaño)
    vector<thread> hebras;
    int numHebras = stoi(argv[3]);

    // se divide la imagen por hebra
    int filasPorHebra = imagen.rows / numHebras;
    int filaInicio = 0;

    // Se inicia el timer de proceso de imagen
    auto inicioProc = chrono::steady_clock::now();

    // se comienza el ciclo de asignacion
    for (int i = 0; i < numHebras; i++)
    {
        int filaFinal = (i == numHebras - 1) ? imagen.rows : filaInicio + filasPorHebra;
        hebras.emplace_back(procesarImagen, ref(imagen), ref(output), filaInicio, filaFinal);
        filaInicio = filaFinal;
    }

    // se cierran las hebras
    for (auto &hebra : hebras)
    {
        hebra.join();
    }

    // Se termina el timer de carga de imagen
    auto finProc = chrono::steady_clock::now();

    chrono::duration<double> tiempoProc = finProc - inicioProc;

    cout << "Finaliza conversion ..." << endl;

    cout << "Creando imagen ..." << endl;

    // Se inicia el timer de escritura de imagen
    auto inicioWrite = chrono::steady_clock::now();

    imwrite(static_cast<string>(argv[2]), output);
    cout << "Imagen lista ..." << endl;

    // Se termina el timer de escritura de imagen
    auto finWrite = chrono::steady_clock::now();

    chrono::duration<double> tiempoWrite = finWrite - inicioWrite;

    auto finGlobal = chrono::steady_clock::now();
    chrono::duration<double> tiempoGlobal = finGlobal - inicioGlobal;

    cout << "Tiempo de demora Global: " << tiempoGlobal.count() << " segundos" << endl;
    cout << "Tiempo de demora Carga de Imagen: " << tiempoCarga.count() << " segundos" << endl;
    cout << "Tiempo de demora Procesamiento de imagen: " << tiempoProc.count() << " segundos" << endl;
    cout << "Tiempo de demora Escritura de imagen: " << tiempoWrite.count() << " segundos" << endl;

    return 0;
}