#include <stdbool.h>

typedef struct cancion {
    /*Estos son datos mas generales, en los que daremos importancia en algunos.*/
    
    int release_month;
    int release_day;

    int spotify_playlists;
    int spotify_charts;
    int streams;

    int bpm;
    int danceability;
    int valence;
    int energy;
    int acusticness;
    int liveness;
}cancion;

void nuevaCancion (cancion *);