# Tarea 2 - Sistemas Operativos - UBB

Transformación de imagen de color a escala de grises, utilizando un código secuencial, y dos paralelos (Thread & Openmp)

## Paquetes a utilizar

### Debian
```bash
sudo apt-get install libopencv-dev
```
### ArchLinux
```bash
sudo pacman -S opencv
sudo pacman -S vtk
sudo pacman -S hdf5
sudo pacman -S fmt
```
## Uso

```bash
# Utilizar makefile para compilar
make

# Ejecutar programa indicando nombre de imagen de entrada, y nombre de imagen de salida. Ejemplo:
./grisSecuencial nombre_imagen_a_color.png output.png

# Para versiones paralelas indicar al final el numero de hebras a utilizar. Ejemplo:
./grisThreads nombre_imagen_a_color.png output.png 4
```
## Referencias

**Valores método luminosidad:**
* [OpenCV](https://docs.opencv.org/2.4/modules/imgproc/doc/miscellaneous_transformations.html#void%20cvtColor%28InputArray%20src,%20OutputArray%20dst,%20int%20code,%20int%20dstCn%29)

**Documentacion OpenCV:**
* [OpenCV 4.8.0](https://docs.opencv.org/4.8.0/)
* [OpenCV: How to Scan Images](https://docs.opencv.org/4.8.0/db/da5/tutorial_how_to_scan_images.html)
* [OpenCV: Class Mat](https://docs.opencv.org/4.8.0/d3/d63/classcv_1_1Mat.html)
* [OpenCV: Class Vec](https://docs.opencv.org/4.8.0/d6/dcf/classcv_1_1Vec.html)

**Documentación Threads:**
* [C++: Thread](https://cplusplus.com/reference/thread/thread/)
* [C++: Vector](https://cplusplus.com/reference/vector/vector/)
* [C++: Stoi](https://cplusplus.com/reference/string/stoi/)

**Documentación OpenMP:**
* [OpenMP: RefCard](https://www.openmp.org/wp-content/uploads/OpenMPRefCard-5-2-web.pdf)
