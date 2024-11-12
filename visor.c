#include<stdio.h>
#include<stdlib.h>

#include "cargarDatos.h"

void imprimirElemento(tipoelemento);

int main(){
	listaCancion datos;
    tipoelemento elem;
    int opcion;
    bool exito;

	nuevaLista(&datos);
    cargarDatos(&datos);
	do
    {
		printf("--------MENU-------- \n");
		printf("1 - Saca el primer elemento.\n");
		printf("2 - Saca el ultimo elemento.\n");
        printf("3 - Sacar exito de elem.\n");
		printf("4 - Salir.\n");
		printf("Escoja una opcion: ");
		scanf("%d",&opcion);
		switch(opcion){           
            case 1:
				elem=primero(datos);
                imprimirElemento(elem);
				break;
            case 2:
                elem=ultimo(datos);
                imprimirElemento(elem);
				break;
            case 3:
                elem=introducirElemento();
                elem.bpm=normalizarBPM(elem.bpm);
                exito=buscarPorElemento(datos, elem);
                if(exito){
                    printf("La cancion introducida seria un exito.\n");
                } else {
                    printf("La cancion introducida NO seria un exito.\n");
                }
		}
	}while(opcion<4);
}

void imprimirElemento(tipoelemento elem){
    printf("BPM: %d\n", elem.bpm);
    printf("Danceability: %d\n", elem.danceability);
    printf("Valence: %d\n", elem.valence);
    printf("Energy: %d\n", elem.energy);
    printf("Acousticness: %d\n", elem.acousticness);
    printf("Liveness: %d\n", elem.liveness);

}