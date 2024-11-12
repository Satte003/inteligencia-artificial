#include <stdbool.h>

#include "cancion.h"

typedef struct cancion tipoelemento;
typedef struct Nodo{
    bool exito;
    tipoelemento elem;
    struct Nodo * sig;
}Nodo;

typedef struct listaCancion{
    Nodo * ini; //Señala la primera celda de la Lista
    Nodo * fin;  //Señala la última celda de la Lista
}listaCancion;

void nuevaLista (listaCancion *);

bool esVaciaLista (listaCancion);

void añadirInicio (listaCancion *, tipoelemento, bool);

void añadirFinal (listaCancion *, tipoelemento, bool);

void desenlistarInicio (listaCancion *);

tipoelemento primero (listaCancion);

tipoelemento ultimo (listaCancion);

tipoelemento introducirElemento ();

bool buscarPorElemento (listaCancion, tipoelemento);

tipoelemento buscarPorPosicion (listaCancion, int);