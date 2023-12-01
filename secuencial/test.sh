#!/bin/bash
# Script para generar un txt con los tiempo de 10 pruebas

OUTPUT_FILE=tiempos.txt

NUM_TESTS=10

# Cambiar argumentos en caso de usar otra imagen
ARGUMENTS="weic2216b.tif salida.png"

> $OUTPUT_FILE

for ((i = 1; i <= NUM_TESTS; i++)); do
    echo "Prueba $i:" >> $OUTPUT_FILE
    ./grisSecuencial $ARGUMENTS >> $OUTPUT_FILE
    echo "" >> $OUTPUT_FILE 
    sleep 1
done
