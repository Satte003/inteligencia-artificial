#include<stdio.h>
#include<stdlib.h>

#include "listaCancion.h"

tipoelemento introducirElemento ();
void imprimirElemento (tipoelemento);

int main(){
	tipoelemento elem;
	listaCancion lista;
	int opcion,id;
	
	nuevaLista(&lista);
	do
    {
		printf("--------MENU-------- \n");
		printf("1 - Insertar un elemento en la primera posicion de la lista.\n");
		printf("2 - Insertar un elemento en la ultima posicion de la lista.\n");
		printf("3 - Eliminar por el indice.\n");
		printf("4 - Buscar por un indice. \n");
		printf("5 - Buscar por elemento.\n");
		printf("6 - Desenlistar al inicio.\n");
		printf("7 - Saca el primer elemento.\n");
		printf("8 - Saca el ultimo elemento.\n");
        printf("9 - Saca el id del primer elemento.\n");
        printf("10 - Saca el id del ultimo elemento.\n");
		printf("11 - Salir.\n");
		printf("Escoja una opcion: ");
		scanf("%d",&opcion);
		switch(opcion){           
			case 1: 
				elem=introducirElemento();
                printf("Introduce un id: ");
                scanf("%d", &id);
				añadirInicio(&lista,elem,id);
				break;
			case 2: 
				elem=introducirElemento();
                printf("Introduce un id: ");
                scanf("%d", &id);
				añadirFinal(&lista,elem,id);
				break;    
			case 3: 
				printf("Introduce un id: ");
                scanf("%d", &id);
				eliminarPorIndice(&lista, id);
				break;
			case 4: 
                printf("Introduce un id: ");
                scanf("%d", &id);
				elem=buscarPorIndice(lista,id);
                imprimirElemento(elem);
				break;
			case 5:
                elem=introducirElemento();
				id=buscarPorElemento(lista,elem);
                printf("El id del elemento es: %d\n",id);
				break;
			case 6:
				desenlistarInicio(&lista);
				break;
            case 7:
				elem=primero(lista);
                imprimirElemento(elem);
				break;
            case 8:
                elem=ultimo(lista);
                imprimirElemento(elem);
            case 9:
                id=sacaIdPrimero(lista);
                printf("El id del elemento es: %d\n",id);
            case 10:
                id=sacaIdFinal(lista);
                printf("El id del elemento es: %d\n",id);
		}
	}while(opcion<11);
}


tipoelemento introducirElemento (){
    tipoelemento *cancion;

    cancion->track_name="Hola";
    cancion->artist_name="Pepe";
    printf("Introduce el numero de artistas: ");
    scanf("%d", cancion->artist_count);
    printf("Introduce el mes en el que se saco: ");
    scanf("%d", cancion->release_month);
    printf("Introduce el dia en el que se saco: ");
    scanf("%s", cancion->released_day);

    return(*cancion);
}

void imprimirElemento (tipoelemento elem){
    printf("Nombre de la cancion: %s\n", elem.track_name);
    printf("Nombre del artista: %s\n", elem.artist_name);
    printf("Numero de artistas: %d\n", elem.artist_count);
    printf("Mes en el que salio: %d\n", elem.release_month);
    printf("Dia en el que se saco: %s\n", elem.released_day);
}