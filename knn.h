    #include <stdio.h>
    #include <math.h>
    #include "guardarEnArray.h"
    #include "esExito.h"

    #define K 5
    #define N 954
    typedef cancion lista[N];

    typedef struct vecino {
        float distancia;  
        bool exito;
    } vecino;

    float calcularDistancia(cancion, cancion);

    bool knn(cancion[954], cancion, int, bool);

    void escojerDistanciasMenores(vecino[N], vecino[K]);