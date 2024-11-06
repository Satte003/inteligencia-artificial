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

void añadirInicio (listaCancion *c, tipoelemento elem, int id){
    Nodo *aux;
    aux = (Nodo *)malloc(sizeof(Nodo));

    aux->elem=elem;
    aux->id=id;

    if(esVaciaLista(*c)){
        aux->sig=NULL;
        c->ini=aux;
        c->fin=aux;
    } else {
        aux->sig=c->ini;
        c->ini=aux;
    }
}

void añadirFinal (listaCancion *c, tipoelemento elem, int id){
    Nodo *aux;
    aux = (Nodo *)malloc(sizeof(Nodo));

    aux->elem=elem;
    aux->id=id;
    aux->sig=NULL; 

    if(esVaciaLista(*c)){
        c->ini=aux;
        c->fin=aux;
    } else {
        c->fin->sig=aux;
        c->fin=aux;
    }
}

void eliminarPorIndice (listaCancion * c, int id){
    listaCancion recorrido;
    Nodo *ant, *aux;

    ant = (Nodo *)malloc(sizeof(Nodo));
    aux = (Nodo *)malloc(sizeof(Nodo));
    nuevaLista(&recorrido);
    recorrido=*c;
    
    if(esVaciaLista(*c)){
        printf("ERROR: Intentando eliminar un elemento de una lista vacia, dado el indice.\n");
        exit(-1);
    } else {
        while(recorrido.ini->id!=id || !esVaciaLista(recorrido)){
            ant=recorrido.ini;
            recorrido.ini=recorrido.ini->sig;
        }

        if(!esVaciaLista(recorrido)){
            if(recorrido.ini->id==id){
                aux=recorrido.ini;
                if (recorrido.ini==c->ini && recorrido.ini==c->fin){
                    c->ini=NULL;
                    c->fin=NULL;
                    free(aux);
                } else if(recorrido.ini->sig==NULL){
                    ant->sig=NULL;
                    c->fin=ant;
                    free(aux);
                } else {
                    ant->sig=recorrido.ini->sig;
                    free(aux);
                }              
            } else {
                printf("ERROR: eliminarPorIndice no ha obtenido un id igual y no se ha acabado la lista");
                exit(-1);
            }
        }
    }

    if(esVaciaLista(*c)){
            c->fin=NULL;
    }
}

tipoelemento buscarPorIndice (listaCancion c, int id){
    Nodo *recorrido;

    recorrido = (Nodo *)malloc(sizeof(Nodo));
    recorrido=c.ini;

    if(esVaciaLista(c)){
        printf("ERROR: Intentando buscar un elemento de una lista vacia, dado el indice.\n");
        exit(-1);
    } else {
        while(recorrido->id!=id || recorrido!=NULL){
            recorrido=recorrido->sig;
        }

        if(recorrido!=NULL){
            if(recorrido->id==id){
                return(recorrido->elem);
            } else {
                printf("ERROR: buscarPorIndice no ha obtenido un id igual y no se ha acabado la lista");
                exit(-1);
            }
        }
    }
}

int buscarPorElemento (listaCancion c, tipoelemento elem){
    Nodo *recorrido;

    recorrido = (Nodo *)malloc(sizeof(Nodo));
    recorrido=c.ini;
    
    if(esVaciaLista(c)){
        printf("ERROR: Intentando buscar un elemento de una lista vacia, dado el elemento.\n");
        exit(-1);
    } else {
        while(esMismaCancion(recorrido->elem, elem) || recorrido!=NULL){
            recorrido=recorrido->sig;
        }

        if(recorrido!=NULL){
            if(esMismaCancion(recorrido->elem, elem)){
                return(recorrido->id);
            } else {
                printf("ERROR: buscarPorElemento no ha obtenido un id igual y no se ha acabado la lista");
                exit(-1);
            }
        }
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

int sacaIdPrimero (listaCancion c){
    if(esVaciaLista(c)){
        printf("ERROR: Intentando sacar el primer id de una lista vacia.\n");
        exit(-1);
    } else {
        return(c.ini->id);
    }
}

int sacaIdFinal (listaCancion c){
    if(esVaciaLista(c)){
        printf("ERROR: Intentando sacar el ultimo id de una lista vacia.\n");
        exit(-1);
    } else {
        return(c.fin->id);
    }
}