#include "knn.h"

float calcularDistancia(cancion c1, cancion c2) {
    float distancia = 0.0;
    
<<<<<<< HEAD
    distancia += pow(compararB1(c1.key,c2.key),2);                               
    distancia += pow(compararB1(c1.mode,c2.mode),2);                             
    distancia += pow(compararMeses1(c1.release_month, c2.release_month),2);       
=======
    distancia += pow(compararB1(c1.key,c2.key), 2);                           // 
    distancia += pow(compararB1(c1.mode,c2.mode), 2);                         // IMPORTANCIA VARIABLE (en la funcion)
    distancia += pow(compararMeses1(c1.release_month, c2.release_month), 2);  //  
>>>>>>> ded7c5e1f9631213d512732d7bbfd75b17296cbc
    distancia += pow(c1.bpm - c2.bpm, 2);  
    distancia += pow(c1.danceability - c2.danceability, 2);
    distancia += pow(c1.valence - c2.valence, 2); 
    distancia += pow(c1.energy - c2.energy, 2);  
    distancia += pow(c1.acousticness - c2.acousticness, 2);
    distancia += pow(c1.liveness - c2.liveness, 2);
    distancia += pow(c1.cantidad_artistas - c2.cantidad_artistas, 2);
    return sqrt(distancia);
}

void escojerDistanciasMenores(vecino lista_todos_vecinos[N], vecino distancias_mas_cortas[K]) {
    for (int i = 0; i < K; i++) {
        distancias_mas_cortas[i].distancia = INFINITY;
    }
    
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < K; i++) {
            if (lista_todos_vecinos[j].distancia < distancias_mas_cortas[i].distancia) {
                for (int k = K - 1; k > i; k--) {
                    distancias_mas_cortas[k] = distancias_mas_cortas[k - 1];
                }
                distancias_mas_cortas[i] = lista_todos_vecinos[j];
            }
            break;
        }
    }
}

bool knn(cancion lista[954], cancion cancionBuscar, int cancion_prueba, bool definitivo) {
    vecino vecinos_cercanos[K];  
    vecino lista_vecinos[N];  

    for(int i = 0; i < N; i++){
        lista_vecinos[i].distancia = calcularDistancia(cancionBuscar, lista[i]);
        lista_vecinos[i].exito = esExito(lista[i].playlists, lista[i].charts, lista[i].streams);
    }
    
    if(!definitivo){
        lista_vecinos[cancion_prueba].distancia = INFINITY;
    }

    escojerDistanciasMenores(lista_vecinos,vecinos_cercanos);

    int exitoCount = 0;
    for (int i = 0; i < K; i++) {
        if (vecinos_cercanos[i].exito) {
            exitoCount++; 
        }
    }
<<<<<<< HEAD
    return (exitoCount > (K / 2)); 
=======
    return (exitoCount > K/2);  // Si más de la mitad de los vecinos son éxitos, es un éxito
>>>>>>> ded7c5e1f9631213d512732d7bbfd75b17296cbc
}