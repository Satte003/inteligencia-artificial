#include <stdbool.h>

typedef struct cancion {
    /*Estos son datos mas generales, en los que daremos importancia en algunos.*/
    
    char *track_name; //Puede que no haga falta
    char *artist_name; 
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
}ancion;