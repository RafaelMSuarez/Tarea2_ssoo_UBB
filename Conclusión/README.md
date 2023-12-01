# Desarrollo
Se llevó a cabo el siguiente desarrollo por equipo:
* Se especifican los datos principales (Procesador, Memoria RAM, si posee SSD o Disco Duro y Sistema Operativo)
* Se obtiene el número de hebras disponibles utilizando la función **std::thread::hardware_concurrency();**
---------------------------------------------------
* Se realizan 10 pruebas de la versión secuencial.
---------------------------------------------------
* Se realizan 10 pruebas de la versión Threads utilizando 2 hebras.
* Se realizan 10 pruebas de la versión Threads utilizando 4 hebras.
* Se realizan 10 pruebas de la versión Threads utilizando 8 hebras (Equipo 2 y 3).
---------------------------------------------------
* Se realizan 10 pruebas de la versión OpenMP utilizando 2 hebras.
* Se realizan 10 pruebas de la versión OpenMP utilizando 4 hebras.
* Se realizan 10 pruebas de la versión OpenMP utilizando 8 hebras (Equipo 2 y 3).
---------------------------------------------------
* Por cada versión del código, se realiza un promedio.

A continuación los detalles por equipo:

## Equipo 1:

* Procesador:
* Memoria RAM:
* Número de hebras máxima:
* Tipo de memoria secundaria:
* Sistema operativo:
---------------------------------------------------
### Secuencial
| Tiempo promedio de  | Tiempo |
| ------------- | ------------- |
| **Lectura de imagen**  | |
| **Procesamiento de imagen**  | |
| **Escritura de imagen**  | |
| **Promedio Global** | |

### Threads
| Tiempo promedio de  | 2 hebras | 4 hebras |
| ------------- | ------------- | ------------- |
| **Lectura de imagen**  | | |
| **Procesamiento de imagen**  | | |
| **Escritura de imagen**  | | |
| **Promedio Global** | | |

### OpenMP
| Tiempo promedio de  | 2 hebras | 4 hebras |
| ------------- | ------------- | ------------- |
| **Lectura de imagen**  | | |
| **Procesamiento de imagen**  | | |
| **Escritura de imagen**  | | |
| **Promedio Global** | | |

## Equipo 2:
* Procesador: **Intel i5-10300H (8) 4.5GHz**
* Memoria RAM: **32 GB**
* Número de hebras máxima: **8**
* Tipo de memoria secundaria: **SSD**
* Sistema operativo: **ArcoLinux (Kernel: 6.6.3-arch1-1)**
---------------------------------------------------
### Secuencial
| Tiempo promedio de  | Tiempo |
| ------------- | ------------- |
| **Lectura de imagen**  | |
| **Procesamiento de imagen**  | |
| **Escritura de imagen**  | |
| **Promedio Global** | |

### Threads
| Tiempo promedio de  | 2 hebras | 4 hebras | 8 hebras |
| ------------- | ------------- | ------------- | ------------- |
| **Lectura de imagen**  | | | |
| **Procesamiento de imagen**  | | | |
| **Escritura de imagen**  | | | |
| **Promedio Global** | | | |

### OpenMP
| Tiempo promedio de  | 2 hebras | 4 hebras | 8 hebras |
| ------------- | ------------- | ------------- | ------------- |
| **Lectura de imagen**  | | | |
| **Procesamiento de imagen**  | | | |
| **Escritura de imagen**  | | | |
| **Promedio Global** | | | |


## Equipo 3:

* Procesador: **Intel Xeon Silver 4210R (20) 3.2GHz**
* Memoria RAM: **64 GB**
* Número de hebras máxima: **20**
* Tipo de memoria secundaria: **HDD**
* Sistema operativo: **Debian GNU/Linux 11 (Kernel: 5.10.0-23-amd64)**
---------------------------------------------------
### Secuencial
| Tiempo promedio de  | Tiempo |
| ------------- | ------------- |
| **Lectura de imagen**  | |
| **Procesamiento de imagen**  | |
| **Escritura de imagen**  | |
| **Promedio Global** | |

### Threads
| Tiempo promedio de  | 2 hebras | 4 hebras | 8 hebras |
| ------------- | ------------- | ------------- | ------------- |
| **Lectura de imagen**  | | | |
| **Procesamiento de imagen**  | | | |
| **Escritura de imagen**  | | | |
| **Promedio Global** | | | |

### OpenMP
| Tiempo promedio de  | 2 hebras | 4 hebras | 8 hebras |
| ------------- | ------------- | ------------- | ------------- |
| **Lectura de imagen**  | | | |
| **Procesamiento de imagen**  | | | |
| **Escritura de imagen**  | | | |
| **Promedio Global** | | | |
## Conclusión:

Se concluye que para los tiempos de lectura y escritura de imagen, la versión del código no influye directamente en el desempeño final. Esto ya que son **funciones secuenciales** que vienen directamente de la biblioteca de **OpenCV**. Por otro lado, el **tipo de memoria secundaria** influye directamente en los tiempos.

No obstante, el tiempo de **procesamiento de imagen** si depende de la versión del código, ya que en esta sección se encuentra la optimización a través de hebras.