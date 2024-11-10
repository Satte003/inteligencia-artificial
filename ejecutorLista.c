#include<stdio.h>
#include<stdlib.h>

#include "listaCancion.h"

int main(){
	tipoelemento elem, nulo;
	listaCancion lista;
	int opcion;
	bool exito;

	exito=false;
	nuevaLista(&lista);
	do
    {
		printf("--------MENU-------- \n");
		printf("1 - Insertar un elemento en la primera posicion de la lista.\n");
		printf("2 - Insertar un elemento en la ultima posicion de la lista.\n");
		printf("3 - Desenlistar al inicio.\n");
		printf("4 - Saca el primer elemento.\n");
		printf("5 - Saca el ultimo elemento.\n");
		printf("6 - Salir.\n");
		printf("Escoja una opcion: ");
		scanf("%d",&opcion);
		switch(opcion){           
			case 1: 
				elem=introducirElemento();
				añadirInicio(&lista,elem,exito);
				break;
			case 2: 
				elem=introducirElemento();
				añadirFinal(&lista,elem,exito);
				break;
			case 3:
				desenlistarInicio(&lista);
				break;
            case 4:
				elem=primero(lista);
                imprimirElemento(elem);
				break;
            case 5:
                elem=ultimo(lista);
                imprimirElemento(elem);
				break;
		}
	}while(opcion<6);
}
