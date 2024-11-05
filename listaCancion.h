#include <stdbool.h>

#include "cancion.h"

typedef struct cancion tipoelemento;
typedef struct Nodo{
    int id;
    tipoelemento elem;
    struct Nodo * sig;
}Nodo;

typedef struct listaCancion{
    Nodo * ini; //Señala la primera celda de la Lista
    Nodo * fin;  //Señala la última celda de la Lista
}listaCancion;

void nuevaLista (listaCancion *);

bool esVaciaLista (listaCancion);

void añadirInicio (listaCancion *, tipoelemento, int);

void añadirFinal (listaCancion *, tipoelemento, int);

void eliminarPorIndice (listaCancion *, int);

tipoelemento buscarPorIndice (listaCancion, int);

int buscarPorElemento (listaCancion, tipoelemento);

void desenlistarInicio (listaCancion *);

tipoelemento primero (listaCancion);

tipoelemento ultimo (listaCancion);

int sacaIdPrimero (listaCancion);

int sacaIdFinal (listaCancion);