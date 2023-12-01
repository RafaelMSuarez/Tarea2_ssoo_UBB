# Desarrollo

Se llevó a cabo el siguiente desarrollo por equipo:

- Se especifican los datos principales (Procesador, Memoria RAM, si posee SSD o Disco Duro y Sistema Operativo)
- Se obtiene el número de hebras disponibles utilizando la función **std::thread::hardware_concurrency();**

---

- Se realizan 10 pruebas de la versión secuencial.
- Se realizan 10 pruebas de la versión Threads y OpenMP utilizando 2, 4, 8 (Equipo 2 y 3) y 16 (Equipo 3) hebras.

---

- Por cada versión del código, se realiza un promedio del tiempo en segundos (s).

A continuación los detalles por equipo:

## Equipo 1:

- Procesador:
- Memoria RAM:
- Número de hebras máxima:
- Tipo de memoria secundaria:
- Sistema operativo:

---

### Secuencial

| Tiempo promedio de          | Tiempo (s) |
| --------------------------- | ---------- |
| **Lectura de imagen**       |            |
| **Procesamiento de imagen** |            |
| **Escritura de imagen**     |            |
| **Global**                  |            |

### Threads

| Tiempo promedio de          | 2 hebras (s) | 4 hebras (s) |
| --------------------------- | ------------ | ------------ |
| **Lectura de imagen**       |              |              |
| **Procesamiento de imagen** |              |              |
| **Escritura de imagen**     |              |              |
| **Global**                  |              |              |

### OpenMP

| Tiempo promedio de          | 2 hebras (s) | 4 hebras |
| --------------------------- | ------------ | -------- |
| **Lectura de imagen**       |              |          |
| **Procesamiento de imagen** |              |          |
| **Escritura de imagen**     |              |          |
| **Global**                  |              |          |

## Equipo 2:

- Procesador: **Intel i5-10300H (8) 4.5GHz**
- Memoria RAM: **32 GB**
- Número de hebras máxima: **8**
- Tipo de memoria secundaria: **SSD**
- Sistema operativo: **ArcoLinux (Kernel: 6.6.3-arch1-1)**

---

### Secuencial

| Tiempo promedio de          | Tiempo (s) |
| --------------------------- | ---------- |
| **Lectura de imagen**       | 1.554290   |
| **Procesamiento de imagen** | 0.872540   |
| **Escritura de imagen**     | 1.783190   |
| **Global**                  | 4.210074   |

### Threads

| Tiempo promedio de          | 2 hebras (s) | 4 hebras (s) | 8 hebras (s) |
| --------------------------- | ------------ | ------------ | ------------ |
| **Lectura de imagen**       | 1.557578     | 1.552790     | 1.552344     |
| **Procesamiento de imagen** | 0.438897     | 0.206879     | 0.185908     |
| **Escritura de imagen**     | 1.709784     | 1.875609     | 2.231251     |
| **Global**                  | 3.706330     | 3.635341     | 3.969575     |

### OpenMP

| Tiempo promedio de          | 2 hebras (s) | 4 hebras (s) | 8 hebras (s) |
| --------------------------- | ------------ | ------------ | ------------ |
| **Lectura de imagen**       | 1.554792     | 1.551888     | 1.556881     |
| **Procesamiento de imagen** | 0.526387     | 0.239978     | 0.195848     |
| **Escritura de imagen**     | 1.725189     | 1.545978     | 1.522228     |
| **Global**                  | 3.806442     | 3.337906     | 3.275020     |

## Equipo 3:

- Procesador: **Intel Xeon Silver 4210R (20) 3.2GHz**
- Memoria RAM: **64 GB**
- Número de hebras máxima: **20**
- Tipo de memoria secundaria: **HDD**
- Sistema operativo: **Debian GNU/Linux 11 (Kernel: 5.10.0-23-amd64)**

---

### Secuencial

| Tiempo promedio de          | Tiempo (s) |
| --------------------------- | ---------- |
| **Lectura de imagen**       |            |
| **Procesamiento de imagen** |            |
| **Escritura de imagen**     |            |
| **Global**                  |            |

### Threads

| Tiempo promedio de          | 2 hebras (s) | 4 hebras (s) | 8 hebras (s) | 16 hebras (s) |
| --------------------------- | ------------ | ------------ | ------------ | ------------- |
| **Lectura de imagen**       |              |              |              |               |
| **Procesamiento de imagen** |              |              |              |               |
| **Escritura de imagen**     |              |              |              |               |
| **Global**                  |              |              |              |               |

### OpenMP

| Tiempo promedio de          | 2 hebras (s) | 4 hebras (s) | 8 hebras (s) | 16 hebras (s) |
| --------------------------- | ------------ | ------------ | ------------ | ------------- |
| **Lectura de imagen**       |              |              |              |               |
| **Procesamiento de imagen** |              |              |              |               |
| **Escritura de imagen**     |              |              |              |               |
| **Global**                  |              |              |              |               |

## Conclusión:

Se concluye que para los tiempos de lectura y escritura de imagen, la versión del código no influye directamente en el desempeño final. Esto ya que son **funciones secuenciales** que vienen directamente de la biblioteca de **OpenCV**. Por otro lado, el **tipo de memoria secundaria** influye directamente en los tiempos.

No obstante, el tiempo de **procesamiento de imagen** si depende de la versión del código, ya que en esta sección se encuentra la optimización a través de hebras.
