#include <string.h>
#define PI 3.141592653589793238

int compararB1(char *palabra1, char *palabra2) {                    // INCLUIR STRING.H
    int importancia = 100;
    if(palabra1 == NULL || palabra2 == NULL)                        // Comprobamos que no es nulo
        return importancia;
    return (strcmp(palabra1, palabra2) == 0) ? 0 : importancia;     // Devuelve 0 si es la misma palabra y 'importancia' si no
}

void normalizarA1(int vector[], int longitudVector) {
    int max = vector[0];
    for (int i = 1; i < longitudVector; i++) {   // Calculamos el valor máximo del vector
        if (vector[i] > max) {
            max = vector[i];
        }
    }

    for (int i = 0; i < longitudVector; i++) {  
        vector[i] = (vector[i] * 100) / max;    // Normalizamos cada vector de 0 a 100 linealmente siendo 100 el valor maximo de este
    }
}

int compararMeses1(int mes1, int mes2){        // DEFINIR PI
    float mes1_rad, mes2_rad, diferencia_angular, importancia;

    mes1_rad = (mes1 - 1) * (2 * PI / 12);      // Convertimos los meses en radianes de 0 a 11pi/6
    mes2_rad = (mes2 - 1) * (2 * PI / 12);
    importancia = 1.0;

    diferencia_angular = mes1_rad - mes2_rad;   // Calculamos la diferencia angular

    if (diferencia_angular < 0)
        diferencia_angular = -diferencia_angular;  // Aplicamos valor absoluto

    if (diferencia_angular > PI)
        diferencia_angular = 2 * PI - diferencia_angular;  // Escojemos la diferencia angular mas pequeña

    return (int)((diferencia_angular * importancia / PI) * 100); // Devuelve la diferencia angular convertida a una escala del 0 a 99

}