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

void añadir (listaCancion *, tipoelemento);

void eliminarPorIndice (listaCancion *, int);

void buscarPorIndice (listaCancion *, int);

void eliminarPorElemento (listaCancion *, tipoelemento);

void buscarPorElemento (listaCancion *, tipoelemento);

void desenlistar (listaCancion *);

tipoelemento primero (listaCancion);

tipoelemento ultimo (listaCancion);