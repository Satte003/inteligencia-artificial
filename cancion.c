#include <stdio.h>
#include <stdlib.h>

#include "cancion.h"

void nuevaCancion (cancion *c){
    c->release_month=0;
    c->release_day=0;

    c->spotify_playlists=-1;
    c->spotify_charts=-1;
    c->streams=-1;

    c->bpm=-1;
    c->danceability=-1;
    c->valence=-1;
    c->energy=-1;
    c->acusticness=-1;
    c->liveness=-1;
}