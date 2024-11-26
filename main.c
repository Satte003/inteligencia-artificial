#include <stdio.h>
#include <stdbool.h>
#include "normalizar.h"
#include "guardarEnArray.h"
#include "calcularK.h"

int main(){
    char respuesta1, respuesta2;
    cancion cancion_prueba;
    bool exito;
    cancion dataset[N];
    float porcentaje;

    do{

        guardarEnArray(dataset);

        printf("Quieres calcular el porcentaje de acierto? (s/n): ");
        scanf(" %c", &respuesta2);

        if(respuesta2 == 's'){
            porcentaje = porcentajeExito(dataset);
            printf("Porcentaje de Acierto: %f\n",porcentaje);
        }

        printf("\n--- INSERTAR DATOS DE LA CANCION ---\n");
        printf("BPM (0-100): ");
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
        printf("Cantidad de artistas: ");
        scanf("%d",&cancion_prueba.cantidad_artistas);
        printf("Mes de lanzamiento (1-12): ");
        scanf("%d",&cancion_prueba.release_month);

        cancion_prueba.key = malloc(100 * sizeof(char)); 
        cancion_prueba.mode = malloc(100 * sizeof(char));

        printf("Clave (A..G#): ");
        scanf("%s",cancion_prueba.key);

        printf("Modo (Major/Minor): ");
        scanf("%s",cancion_prueba.mode); 

        exito = knn(dataset, cancion_prueba, 0, true); 

        printf("\n--- RESULTADO ---\n");
        if (exito){
            printf("La cancion sera exitosa.\n");
        } else {
            printf("La cancion NO sera exitosa.\n");
        }

        printf("\nQuieres repetir la ejecucion? (s/n): ");
        scanf(" %c", &respuesta1);
    } while(respuesta1 == 's');

    return 0;
}