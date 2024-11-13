#include <stdbool.h>

typedef struct cancion{
    int bpm;
    int danceability;
    int valence;
    int energy;
    int acousticness;
    int liveness;
    char *key;
    char *mode;
    int release_month;
}cancion;

void nuevaCancion (cancion *);