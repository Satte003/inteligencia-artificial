#include <stdio.h>
#include <stdlib.h>

#include "cancion.h"

void nuevaCancion (cancion *c){
    c->artist_count=0;
    c->release_month=0;
    c->released_day=0;

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

bool esMismaCancion(cancion c1, cancion c2){
    bool esIgual;

    esIgual=true;

    if(c1.track_name!=c2.track_name || c1.artist_name!=c2.artist_name || c1.artist_count!=c2.artist_count || c1.release_month!=c2.release_month || c1.released_day!=c2.released_day){
        esIgual=false;
    }

    return(esIgual);

}