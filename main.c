#include <stdio.h>
#include <stdbool.h>
//ver cuales hacen falta
#include "cancion.h"
#include "cargarDatos.h"
#include "esExito.h"
#include "listaCancion.h"
#include "normalizar.h"

//función para usar el knn
// knn(datos, elem);

int main(){
    char respuesta;
    cancion cancion_prueba;
    bool exito;

    do{
        
        printf("BPM: ");
        scanf("%d",&cancion_prueba.bpm);
        printf("Danzabilidad (0-100): ");
        scanf("%d",&cancion_prueba.danceability);
        printf("Valencia (0-100): ");
        scanf("%d",&cancion_prueba.valence);
        printf("Energia (0-100): ");
        scanf("%d",&cancion_prueba.energy);
        printf("Acusticidad (0-100): ");
        scanf("%d",&cancion_prueba.acousticness);
        printf("Vividez (0-100): ");
        scanf("%d",&cancion_prueba.liveness);
        printf("Mes de lanzamiento (1-12): ");
        scanf("%d",&cancion_prueba.release_month);
        printf("Clave (): ");
        scanf("%s",cancion_prueba.key);
        printf("Modo (Major o Minor): ");
        scanf("%s",cancion_prueba.mode);

        exito = knn();
        //exito = true; // para probar

        if (exito){
            printf("La canción sera exitosa.");
        } else {
            printf("La canción no sera exitosa");
        }

        printf("¿Quieres repetir la ejecucion? (s/n)\n");
        scanf(" %c", &respuesta);
    } while(respuesta == 's');

    return 0;
}