#include <stdbool.h>

typedef struct cancion {
    /*Estos son datos mas generales, en los que daremos importancia en algunos.*/
    
    char artist_name [100]; 
    int artist_count;
    int release_month;
    int released_day;

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

bool esMismaCancion (cancion, cancion);