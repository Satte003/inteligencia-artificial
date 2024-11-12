#include <stdio.h>
#include <stdlib.h>

#include "listaCancion.h"

void nuevaLista (listaCancion * c){
    c->ini=NULL;
    c->fin=NULL;
}

bool esVaciaLista (listaCancion c){
    return(c.ini==NULL);
}

void añadirInicio (listaCancion *c, tipoelemento elem, bool exito){
    Nodo *aux;
    aux = (Nodo *)malloc(sizeof(Nodo));

    aux->elem=elem;
    aux->exito=exito;

    if(esVaciaLista(*c)){
        aux->sig=NULL;
        c->ini=aux;
        c->fin=aux;
    } else {
        aux->sig=c->ini;
        c->ini=aux;
    }
}

void añadirFinal (listaCancion *c, tipoelemento elem, bool exito){
    Nodo *aux;
    aux = (Nodo *)malloc(sizeof(Nodo));

    aux->elem=elem;
    aux->exito=exito;
    aux->sig=NULL; 

    if(esVaciaLista(*c)){
        c->ini=aux;
        c->fin=aux;
    } else {
        c->fin->sig=aux;
        c->fin=aux;
    }
}

void desenlistarInicio (listaCancion *c){
    Nodo *aux;
    if(esVaciaLista(*c)){
        printf("ERROR: Intentando desenlistar el primer elemento de una lista vacia.\n");
        exit(-1);
    } else {
        aux=c->ini;
        c->ini=c->ini->sig;
        free(aux);

        if(esVaciaLista(*c)){
            c->fin=NULL;
        }
    }
}

tipoelemento primero (listaCancion c){
    if(esVaciaLista(c)){
        printf("ERROR: Intentando sacar el primer elemento de una lista vacia.\n");
        exit(-1);
    } else {
        return(c.ini->elem);
    }
}

tipoelemento ultimo (listaCancion c){
    if(esVaciaLista(c)){
        printf("ERROR: Intentando sacar el ultimo elemento de una lista vacia.\n");
        exit(-1);
    } else {
        return(c.fin->elem);
    }
}

tipoelemento introducirElemento (){
    tipoelemento cancion;
	nuevaCancion(&cancion);
    bool existe;
    existe=false;

    do{
        do {
            printf("Introduce el mes en el que se saco: ");
            scanf("%d", &cancion.release_month);
        } while (cancion.release_month<=0 && cancion.release_month>12);
        
        do{
            printf("Introduce el dia en el que se saco: ");
            scanf("%d", &cancion.release_day);


        } while (cancion.release_day <=0 && cancion.release_month>31);

        if((cancion.release_month==2 && cancion.release_day<=29)||(cancion.release_month%2==0 && cancion.release_month<=6 && cancion.release_month!=2 && cancion.release_day<=30)||(cancion.release_month%2==1 && cancion.release_month>=9 && cancion.release_day<=30)||(cancion.release_month%2==1 && cancion.release_month<=7 && cancion.release_day<=31)||(cancion.release_month%2==0 && cancion.release_month>=8 && cancion.release_day<=31)){
            existe=true;
        }
    } while(existe==false);
    
    do{
        printf("Introduce los beats por minuto de la cancion (bpm): ");
        scanf("%d", &cancion.bpm);
    } while (cancion.bpm>0);

    do{
        printf("Introduce el porcentaje de bailabilidad de la cancion (danceability) ");
        scanf("%d", &cancion.danceability);
    } while (cancion.danceability>=0 && cancion.danceability<=100);

    do{
        printf("Introduce el porcentaje de positividad de la cancion (valence): ");
        scanf("%d", &cancion.valence);
    } while (cancion.valence>=0 && cancion.valence<=100);
    
    do{
        printf("Introduce el porcentaje de nivel de energia de la cancion (energy): ");
        scanf("%d", &cancion.energy);
    } while (cancion.energy>=0 && cancion.energy<=100);

    do{
        printf("Introduce el porcentaje de presencia acustica de la cancion (acusticness): ");
        scanf("%d", &cancion.acousticness);
    } while (cancion.acousticness>=0 && cancion.acousticness<=100);
    
    do{
        printf("Introduce el porcentaje de elementos en directo de la cancion (liveness): ");
        scanf("%d", &cancion.liveness);
    } while (cancion.liveness>=0 && cancion.liveness<=100);

    return(cancion);
}