#include <stdio.h>
#include <stdlib.h>

#include "esExito.h"
#include "listaCancion.h"
#include "normalizar.h"

void cargarDatos(listaCancion *);

void leerLinea(FILE *, Nodo *);

void leerHastaComa(FILE *, int*);

void saltarLinea(FILE *);

void leerHastaSalto(FILE *, Nodo *);