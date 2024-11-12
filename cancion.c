#include <stdio.h>
#include <stdlib.h>

#include "cancion.h"

void nuevaCancion (cancion *c){
    c->release_month=0;
    c->release_day=0;

    c->bpm=-1;
    c->danceability=-1;
    c->valence=-1;
    c->energy=-1;
    c->acousticness=-1;
    c->liveness=-1;
}