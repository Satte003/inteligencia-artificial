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
    bool encontrado;

    encontrado=false;
    ant = (Nodo *)malloc(sizeof(Nodo));
    aux = (Nodo *)malloc(sizeof(Nodo));
    nuevaLista(&recorrido);
    recorrido=*c;
    
    if(esVaciaLista(*c)){
        printf("ERROR: Intentando eliminar un elemento de una lista vacia, dado el indice.\n");
        exit(-1);
    } else {
        while(!esVaciaLista(recorrido) && !encontrado){
            if(recorrido.ini->id!=id){
              ant=recorrido.ini;
             recorrido.ini=recorrido.ini->sig;  
            } else {
                encontrado=true;
            }
        }

        if(!esVaciaLista(recorrido)){
            if(encontrado){
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
                printf("ERROR: eliminarPorIndice no ha obtenido un id igual y no se ha acabado la lista\n");
                exit(-1);
            }
        } else {
            printf("No se ha encontrado ningun elemento con ese id.\n");
        }
    }

    if(esVaciaLista(*c)){
            c->fin=NULL;
    }
}

tipoelemento buscarPorIndice (listaCancion c, int id){
    Nodo *recorrido;
    tipoelemento nulo;
    bool encontrado;

    nulo=crearNulo(nulo);
    encontrado=false;
    recorrido = (Nodo *)malloc(sizeof(Nodo));
    recorrido=c.ini;

    if(esVaciaLista(c)){
        printf("ERROR: Intentando buscar un elemento de una lista vacia, dado el indice.\n");
        exit(-1);
    } else {
        while(recorrido!=NULL && !encontrado){
            if(recorrido->id!=id){
                recorrido=recorrido->sig;
            } else {
                encontrado=true;
            }
        }

        if(recorrido!=NULL){
            if(encontrado){
                return(recorrido->elem);
            } else {
                printf("ERROR: buscarPorIndice no ha obtenido un id igual y no se ha acabado la lista\n");
                exit(-1);
            }
        } else {
            printf("No existe ningun elemento con ese id.\n");
            return(nulo);
        }
    }
}

int buscarPorElemento (listaCancion c, tipoelemento elem){
    Nodo *recorrido;
    bool encontrado;

    encontrado=false;
    recorrido = (Nodo *)malloc(sizeof(Nodo));
    recorrido=c.ini;
    
    if(esVaciaLista(c)){
        printf("ERROR: Intentando buscar un elemento de una lista vacia, dado el elemento.\n");
        exit(-1);
    } else {
        while(recorrido!=NULL && !encontrado){
            if(!esMismaCancion(recorrido->elem, elem)){
               recorrido=recorrido->sig; 
            } else {
                encontrado = true;
            }
        }

        if(recorrido!=NULL){
            if(encontrado){
                return(recorrido->id);
            } else {
                printf("ERROR: buscarPorElemento no ha obtenido un id igual y no se ha acabado la lista\n");
                exit(-1);
            }
        } else {
            printf("No se ha encontrado ningun id de dicho elemento\n");
            return(-1);
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

tipoelemento crearNulo (tipoelemento elem){
    elem.acusticness=-1;
    elem.artist_count=-1;
    elem.bpm=-1;
    elem.danceability=-1;
    elem.energy=-1;
    elem.liveness=-1;
    elem.release_month=-1;
    elem.released_day=-1;
    elem.spotify_charts=-1;
    elem.spotify_playlists=-1;
    elem.streams=-1;
    elem.valence=-1;

    return(elem);
}

bool esIgualElemento (tipoelemento elem1, tipoelemento elem2){
    return(elem1.acusticness==elem2.acusticness && elem1.artist_count==elem2.artist_count && elem1.artist_name==elem2.artist_name && elem1.bpm==elem2.bpm && elem1.danceability==elem2.danceability && elem1.energy==elem2.energy && elem1.liveness==elem2.liveness && elem1.release_month==elem2.release_month && elem1.released_day==elem2.released_day && elem1.spotify_charts==elem2.spotify_charts && elem1.spotify_playlists==elem2.spotify_playlists && elem1.streams==elem2.streams && elem1.valence==elem2.valence);
}