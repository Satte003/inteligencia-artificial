#include "normalizar.h"

int compararB1(char *palabra1, char *palabra2) {
    int importancia = 20;
    if(palabra1 == NULL || palabra2 == NULL)
        return importancia;
    return (strcmp(palabra1, palabra2) == 0) ? 0 : importancia;
}

int normalizarA1(int valor, int max) {
    return (valor * 100) / max;
}

int compararMeses1(int mes1, int mes2){
    float mes1_rad, mes2_rad, diferencia_angular, importancia;

    mes1_rad = (mes1 - 1) * (2 * PI / 12);
    mes2_rad = (mes2 - 1) * (2 * PI / 12);
    importancia = 50;

    diferencia_angular = mes1_rad - mes2_rad;

    if (diferencia_angular < 0)
        diferencia_angular = -diferencia_angular;

    if (diferencia_angular > PI)
        diferencia_angular = 2 * PI - diferencia_angular;

<<<<<<< HEAD
    return (int)((diferencia_angular / PI) * importancia);

=======
    return (int)((diferencia_angular / PI) * importancia); // Devuelve la diferencia angular convertida a una escala del 0 a importancia
>>>>>>> ded7c5e1f9631213d512732d7bbfd75b17296cbc
}