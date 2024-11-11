#include "normalizar.h"
#define PI 3.14159265358979323846

void normalizarFecha(Cancion tabla_datos[], int num_canciones) {
    for (int i = 0; i < num_canciones; i++) {
        int mes = tabla_datos[i].mes_lanzamiento;
        
        tabla_datos[i].mes_radianes = (mes - 1) * (2 * PI / 12);
    }
}

float compararMeses(Cancion cancion1, Cancion cancion2) {
    float diferencia_angular = abs(cancion1.mes_radianes - cancion2.mes_radianes);
    
    if (diferencia_angular > PI) {
        diferencia_angular = 2 * PI - diferencia_angular;
    }

    return (diferencia_angular / PI);
}

void normalizarBPM(int bpm[], int bpmNormalizado[], int numCanciones) {
    int maxBPM = bpm[0];
    for (int i = 1; i < numCanciones; i++) {
        if (bpm[i] > maxBPM) {
            maxBPM = bpm[i];
        }
    }

    for (int i = 0; i < numCanciones; i++) {
        bpmNormalizado[i] = bpm[i] / maxBPM;
    }
}
