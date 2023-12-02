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

- Procesador: **Intel i5-7200U (4) 3.1GHz**
- Memoria RAM: **8 GB**
- Número de hebras máxima: **4**
- Tipo de memoria secundaria: **SSD**
- Sistema operativo: **Ubuntu 22.04.3(Kernel: 6.2.0-37-generic)**

---

### Secuencial

| Tiempo promedio de          | Tiempo (s) |
| --------------------------- | ---------- |
| **Lectura de imagen**       | 3.707506   |
| **Procesamiento de imagen** | 1.428509   |
| **Escritura de imagen**     | 3.388152   |
| **Global**                  | 8.524363   |

### Threads

| Tiempo promedio de          | 2 hebras (s) | 4 hebras (s) |
| --------------------------- | ------------ | ------------ |
| **Lectura de imagen**       | 3.854473     | 3.922753     |
| **Procesamiento de imagen** | 0.950032     | 0.761235     |
| **Escritura de imagen**     | 3.237478     | 3.335088     |
| **Global**                  | 8.042322     | 8.019489     |

### OpenMP

| Tiempo promedio de          | 2 hebras (s) | 4 hebras |
| --------------------------- | ------------ | -------- |
| **Lectura de imagen**       | 3.912085     | 3.924639 |
| **Procesamiento de imagen** | 1.008288     | 0.829612 |
| **Escritura de imagen**     | 3.214152     | 3.239345 |
| **Global**                  | 8.134793     | 7.994240 |

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
| **Lectura de imagen**       | 2.999519   |
| **Procesamiento de imagen** | 1.165067   |
| **Escritura de imagen**     | 3.297892   |
| **Global**                  | 7.462545   |

### Threads

| Tiempo promedio de          | 2 hebras (s) | 4 hebras (s) | 8 hebras (s) | 16 hebras (s) |
| --------------------------- | ------------ | ------------ | ------------ | ------------- |
| **Lectura de imagen**       | 2.991088     | 2.988787     | 2.979088     | 2.993952      |
| **Procesamiento de imagen** | 0.636169     | 0.323762     | 0.272991     | 0.147039      |
| **Escritura de imagen**     | 3.314108     | 3.323026     | 3.321029     | 3.338988      |
| **Global**                  | 6.941457     | 6.635664     | 6.573193     | 6.480055      |

### OpenMP

| Tiempo promedio de          | 2 hebras (s) | 4 hebras (s) | 8 hebras (s) | 16 hebras (s) |
| --------------------------- | ------------ | ------------ | ------------ | ------------- |
| **Lectura de imagen**       | 2.980923     | 2.980787     | 1.551888     | 2.978872      |
| **Procesamiento de imagen** | 0.700944     | 0.367326     | 0.239978     | 0.153601      |
| **Escritura de imagen**     | 3.309351     | 3.306857     | 1.545978     | 3.279601      |
| **Global**                  | 6.991288     | 6.655043     | 3.337906     | 6.412150      |

## Conclusión:

Se concluye que para los tiempos de lectura y escritura de imagen, la versión del código no influye directamente en el desempeño final. Esto ya que son **funciones secuenciales** que vienen directamente de la biblioteca de **OpenCV**. Por otro lado, el **tipo de memoria secundaria** si influye directamente en los tiempos.

No obstante, el tiempo de **procesamiento de imagen** si depende de la versión del código, ya que en esta sección se encuentra la optimización a través de hebras. En los resultados se observa que a medida que aumentan las hebras, el tiempo disminuye. De secuencial a 2 hebras, el **tiempo disminuye casi en la mitad**, lo que presenta un buen nivel de eficiencia. Pero a medida que se aumentan las hebras, si bien el porcentaje se mantiene alto, los valores real ya no cambian de manera significativa. Es decir, aunque la variación entre 0.2399 segundos y 0.1958 sea de aprox. **1.22x**, el cambio es solamente **0.0441 segundos**, lo cual no se considera un cambio tan significativo. Finalmente se destaca, que a medida que aumentan las hebras, la razón de cambio va **disminuyendo**.

## Referencia

Se incluye el archivo Excel con todos los datos de las pruebas:
[Excel](https://ubiobiocl-my.sharepoint.com/:x:/g/personal/rafael_martinez1601_alumnos_ubiobio_cl/EViWaJPg8LBLsQuLZdHniacBha-vl9UKIM26knF1u41qzw?e=MjxeKx)
