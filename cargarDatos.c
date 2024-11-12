#include "cargarDatos.h"

void cargarDatos (listaCancion *lista){
    FILE *f;
    Nodo *cancion;

    cancion = (Nodo *)malloc(sizeof(Nodo));

    f=fopen("Spotify.csv", "r");

    printf("Cargando datos, por favor no detenga el programa...\n");

    cancion->sig=NULL;

    if(!feof(f)){
        saltarLinea(f);
    }

    while(!feof(f)){
        leerLinea(f,cancion);
        añadirFinal(lista, cancion->elem, cancion->exito);
    }

    free(cancion);
    fclose(f);

    printf("Datos cargados.\n");
    printf("\n");
}

void leerLinea(FILE *f, Nodo *cancion){
    int playlist=-1, chart=-1, stream=-1, i, lectura;
    bool exito;
    
    if(!feof(f)){
        leerHastaComa(f, &playlist); 
    }
    if(!feof(f)){
        leerHastaComa(f, &chart);
    }
    if(!feof(f)){
        leerHastaComa(f, &stream);
    }
    if(playlist!=-1 && chart!=-1 && stream!=-1){
        exito=esExito(playlist,chart,stream);
        cancion->exito=exito;
    } else {
        printf("ERROR: No se ha leido ningun valor del fichero o el fichero esta vacio.\n");
        fclose(f);
        exit(-1);
    }
    
    if(!feof(f)){
        leerHastaSalto(f, cancion);
    }
}

void leerHastaSalto (FILE *f, Nodo *cancion){
    char c;
    int i, lectura;

    i=0;
    c=fgetc(f);

    while(!feof(f)&&c!='\n'){
        lectura=0;
        while(!feof(f) && c!=',' && c!='\n'){
            lectura=lectura*10 + (c-'0');
            c=fgetc(f);
        }
        if(c!='\n'){
            c=fgetc(f);
        }

        if(i==0){
            lectura=normalizarBPM(lectura);
            cancion->elem.bpm=lectura;
        } else if (i==1) {
            cancion->elem.danceability=lectura;
        } else if (i==2) {
            cancion->elem.valence=lectura;
        } else if (i==3){
            cancion->elem.energy=lectura;
        } else if (i==4) {
            cancion->elem.acousticness=lectura;
        } else if (i==5) {
            cancion->elem.liveness=lectura;
        }

        i++;
    }
}

void leerHastaComa (FILE *f, int *lectura){
    char c;
    (*lectura)=0;

    c=fgetc(f);
    while(!feof(f) && c!=','){
        (*lectura)=(*lectura)*10 + (c-'0');
        c=fgetc(f);
    }
}

void saltarLinea(FILE *f){
    char c;

    c=fgetc(f);
    while(!feof(f) && c!='\n'){
        c=fgetc(f);
    }
}

artist count

key y Mode