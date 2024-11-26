#ifndef CANCION_H
#define CANCION_H

typedef struct cancion {
    int bpm;
    int danceability;
    int valence;
    int energy;
    int acousticness;
    int liveness;  
    int streams;
    int playlists;
    int charts;
    int cantidad_artistas;
    char *key;
    char *mode;
    int release_month;
} cancion;

#endif
