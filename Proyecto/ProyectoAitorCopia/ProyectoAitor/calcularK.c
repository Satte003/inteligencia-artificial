#include "calcularK.h"

float porcentajeExito(cancion lista[954]) {
    int aciertos = 0;

    for (int i = 0; i < N; i++) {
        cancion cancion_prueba = lista[i];
        
        bool prediccion = knn(lista, cancion_prueba, i, false);

        if (prediccion == esExito(cancion_prueba.playlists, cancion_prueba.charts, cancion_prueba.streams)) {
            aciertos++;
        }
    }

    float porcentaje = ((float)aciertos / N) * 100.0;
    return porcentaje;
}

