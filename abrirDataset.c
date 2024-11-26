#include "abrirDataset.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void abrirDataset(char tabla[FILAS][COLUMNAS][100]) {
    FILE *archivo = fopen("C:\\Users\\Usuario\\Desktop\\vscode_aitor\\Algoritmia\\ProyectoAitor\\Spotify4.csv", "r");
    if (archivo == NULL) {
        perror("No se puede abrir el archivo");
        return;
    }
    
    char linea[1024];
    int fila = 0;
    
    while (fgets(linea, sizeof(linea), archivo) != NULL && fila < FILAS) {
        char *token = strtok(linea, ",");
        int columna = 0;

        while (token != NULL && columna < COLUMNAS) {
            strncpy(tabla[fila][columna], token, sizeof(tabla[fila][columna]) - 1);
            tabla[fila][columna][sizeof(tabla[fila][columna]) - 1] = '\0';
            token = strtok(NULL, ",");
            columna++;
        }
        fila++;
    }

    fclose(archivo);
}

