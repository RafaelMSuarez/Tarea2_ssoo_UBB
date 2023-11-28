// install vtk hdf5 fmt
//  g++ grisSecuencial.cpp -o grisSecuencial `pkg-config --cflags --libs opencv4`

#include <iostream>
#include <opencv2/core/types.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <chrono>

using namespace cv;
using namespace std;

void procesarImagen(const Mat &original, Mat &output, int filaInicio, int filaFin)
{
    for (int r = filaInicio; r < filaFin; r++)
    {
        for (int c = 0; c < original.cols; c++)
        {
            Vec3b p = original.at<Vec3b>(r, c);
            // azul (B) -> x, verde(G) -> y, rojo(R) -> z
            uchar greyW = static_cast<uchar>(p[2] * 0.114 + p[1] * 0.587 + p[0] * 0.299);
            output.at<uchar>(r, c) = greyW;
        }
    }
}

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


    // AGREGAR HEBRAS

    procesarImagen(ref(imagen), ref(output), 0, imagen.rows);


    

    cout << "Finaliza conversion ..." << endl;

    imwrite(static_cast<string>(argv[2]), output);

    auto termino = chrono::steady_clock::now();

    chrono::duration<double> tiempo = termino - inicio;

    cout << "Tiempo de demora: " << tiempo.count() << " segundos" << endl;

    return 0;
}