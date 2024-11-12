#include<stdio.h>
#include<stdlib.h>

#include "cargarDatos.h"

int main(){
	listaCancion datos;
	nuevaLista(&datos);
    cargarDatos(&datos);
}
