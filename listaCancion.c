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

    nuevaLista(&recorrido);
    recorrido=*c;
    
    if(esVaciaLista(*c)){
        perror("ERROR: Intentando eliminar un elemento de una lista vacia, dado el indice.\n");
        exit(-1);
    } else {
        while(recorrido.ini->id!=id && !esVaciaLista(recorrido)){
            recorrido.ini=recorrido.ini->sig;
        }

        if(!esVaciaLista(recorrido)){
            if(recorrido.ini->id==id){
                desenlistarInicio(&recorrido);
            } else {
                perror("ERROR: eliminarPorIndice no ha obtenido un id igual y no se ha acabado la lista");
                exit(-1);
            }
        }
    }
}

tipoelemento buscarPorIndice (listaCancion c, int id){
    listaCancion recorrido;

    nuevaLista(&recorrido);
    recorrido=c;

    if(esVaciaLista(c)){
        perror("ERROR: Intentando buscar un elemento de una lista vacia, dado el indice.\n");
        exit(-1);
    } else {
        while(recorrido.ini->id!=id && !esVaciaLista(recorrido)){
            recorrido.ini=recorrido.ini->sig;
        }

        if(!esVaciaLista(recorrido)){
            if(recorrido.ini->id==id){
                return(recorrido.ini->elem);
            } else {
                perror("ERROR: buscarPorIndice no ha obtenido un id igual y no se ha acabado la lista");
                exit(-1);
            }
        }
    }
}

int buscarPorElemento (listaCancion c, tipoelemento elem){
    listaCancion *recorrido;
    nuevaLista(recorrido);
    recorrido=&c;
    
    if(esVaciaLista(c)){
        perror("ERROR: Intentando buscar un elemento de una lista vacia, dado el elemento.\n");
        exit(-1);
    } else {
        while(&recorrido->ini->elem!=&elem && !esVaciaLista(*recorrido)){
            recorrido->ini=recorrido->ini->sig;
        }

        if(!esVaciaLista(*recorrido)){
            if(&recorrido->ini->elem==&elem){
                return(recorrido->ini->id);
            } else {
                perror("ERROR: buscarPorElemento no ha obtenido un id igual y no se ha acabado la lista");
                exit(-1);
            }
        }
    }
}

void desenlistarInicio (listaCancion *c){
    Nodo *aux;
    if(esVaciaLista(*c)){
        perror("ERROR: Intentando desenlistar el primer elemento de una lista vacia.\n");
        exit(-1);
    } else {
        c->ini=aux;
        c->ini=c->ini->sig;
        free(aux);

        if(esVaciaLista(*c)){
            c->fin=NULL;
        }
    }
}

tipoelemento primero (listaCancion c){
    if(esVaciaLista(c)){
        perror("ERROR: Intentando sacar el primer elemento de una lista vacia.\n");
        exit(-1);
    } else {
        return(c.ini->elem);
    }
}

tipoelemento ultimo (listaCancion c){
    if(esVaciaLista(c)){
        perror("ERROR: Intentando sacar el ultimo elemento de una lista vacia.\n");
        exit(-1);
    } else {
        return(c.fin->elem);
    }
}

int sacaIdPrimero (listaCancion c){
    if(esVaciaLista(c)){
        perror("ERROR: Intentando sacar el primer id de una lista vacia.\n");
        exit(-1);
    } else {
        return(c.ini->id);
    }
}

int sacaIdFinal (listaCancion c){
    if(esVaciaLista(c)){
        perror("ERROR: Intentando sacar el ultimo id de una lista vacia.\n");
        exit(-1);
    } else {
        return(c.fin->id);
    }
}