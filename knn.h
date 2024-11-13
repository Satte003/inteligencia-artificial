#include "listaCancion.h"
#include "cancion.h"

#define K 5  // Aquí defines el valor de K, el número de vecinos más cercanos que se tomarán en cuenta

// Estructura para almacenar la distancia y la clasificación (éxito) de cada canción
typedef struct vecino {
    float distancia;  // Distancia de la canción al vecino
    bool exito;      // Si la canción es un éxito o no (true si es éxito, false si no lo es)
} vecino;

// Función para calcular la distancia Euclidiana entre dos canciones
float calcularDistancia(cancion, tipoelemento);

// Función que implementa el algoritmo KNN
bool knn(listaCancion *, cancion);