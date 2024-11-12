#include <stdbool.h>

typedef struct cancion {
    /*Estos son datos mas generales, en los que daremos importancia en algunos.*/
    
    /*int release_month;
    int release_day;*/

    int bpm;
    int danceability;
    int valence;
    int energy;
    int acousticness;
    int liveness;
}cancion;

void nuevaCancion (cancion *);