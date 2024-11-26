#include "abrirDataset.h"
#include "normalizar.h"
#include "cancion.h"

void guardarEnArray(cancion database[954]) {
    char tabla[954][13][100];
    abrirDataset(tabla);

    for (int i = 0; i < 954; i++) {
        database[i].cantidad_artistas = atoi(tabla[i][0]);
        database[i].release_month = atoi(tabla[i][1]);
        database[i].playlists = atoi(tabla[i][2]);
        database[i].charts = atoi(tabla[i][3]);
        database[i].streams = atoi(tabla[i][4]);
        database[i].bpm = atoi(tabla[i][5]);
        database[i].key = strdup(tabla[i][6]);
        database[i].mode = strdup(tabla[i][7]);
        database[i].danceability = atoi(tabla[i][8]);
        database[i].valence = atoi(tabla[i][9]);
        database[i].energy = atoi(tabla[i][10]);
        database[i].acousticness = atoi(tabla[i][11]);
        database[i].liveness = atoi(tabla[i][12]);
    }

    int maxBPM = 0;
    int maxNumArt = 0;
    for (int i = 0; i < 954; i++) {
        if (maxBPM < database[i].bpm)
            maxBPM = database[i].bpm;
        if (maxNumArt < database[i].cantidad_artistas)
            maxNumArt = database[i].cantidad_artistas;
    }

    for (int i = 0; i < 954; i++) {
        database[i].bpm = normalizarA1(database[i].bpm, maxBPM);
        database[i].cantidad_artistas = normalizarA1(database[i].cantidad_artistas, maxNumArt);
    }
}
