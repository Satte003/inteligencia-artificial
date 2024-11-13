#include <stdio.h>
#include <math.h>
#include "knn.h"

float calcularDistancia(cancion c1, tipoelemento c2) {
    float distancia = 0.0;
    
    distancia += pow(compararB1(c1.key,c2.key),2);                           // 
    distancia += pow(compararB1(c1.mode,c2.mode),2);                         // IMPORTANCIA VARIABLE (en la funcion)
    distancia += pow(compararMeses1(c1.release_month, c2.release_month),2);  //  
    distancia += pow(c1.bpm - c2.bpm, 2);  
    distancia += pow(c1.danceability - c2.danceability, 2);  
    distancia += pow(c1.valence - c2.valence, 2);  
    distancia += pow(c1.energy - c2.energy, 2);  
    distancia += pow(c1.acousticness - c2.acousticness, 2);  
    distancia += pow(c1.liveness - c2.liveness, 2);  
    return sqrt(distancia);
}

bool knn(listaCancion *lista, cancion cancionBuscar) {
    Nodo *actual = lista->ini;  
    vecino vecinos[K];  // Lista de vecinos para almacenar las distancias y el éxito de las canciones más cercanas acorde al tamaño de K 

    // Inicializamos los vecinos con una distancia muy grande (para que cualquier canción sea más cercana)
    for (int i = 0; i < K; i++) {
        vecinos[i].distancia = 100000000;  
    }

    // Recorre la lista de canciones
    while (actual != NULL) {

        float distancia = calcularDistancia(cancionBuscar, actual->elem);
        
        // Recorre los vecinos para encontrar el lugar adecuado donde insertar la nueva canción
        for (int i = 0; i < K; i++) {
            // Si la distancia calculada es menor que la distancia de un vecino lo desplaza para hacer espacio para el nuevo
            if (distancia < vecinos[i].distancia) {
                for (int j = K - 1; j > i; j--) {
                    vecinos[j] = vecinos[j - 1];
                }
                vecinos[i].distancia = distancia;
                vecinos[i].exito = actual->exito;
                break;
            }
        }
        actual = actual->sig;
    }

    // Cuenta cuántos de los K vecinos son éxitos (exito = true)
    int exitoCount = 0;
    for (int i = 0; i < K; i++) {
        if (vecinos[i].exito) {
            exitoCount++; 
        }
    }
    return (exitoCount > K / 2);  // Si más de la mitad de los vecinos son éxitos, es un éxito
}