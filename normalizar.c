#include "normalizar.h"


/*int normalizarFecha(int mes) {
    return((mes - 1) * (PI / 6));

}

float compararMeses(cancion cancion1, cancion cancion2) {
    float diferencia_angular = abs(cancion1.mes_radianes - cancion2.mes_radianes);
    
    if (diferencia_angular > PI) {
        diferencia_angular = 2 * PI - diferencia_angular;
    }

    return ((diferencia_angular / PI)*100);
}*/

int normalizarBPM(int bpm) {
    return((int)bpm*100/MaxBMP);
}

normalizarArtistCount

normalizarKey

normalizarMode