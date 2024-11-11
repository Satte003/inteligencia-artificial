#include <stdbool.h> 
#include "esExito.h"
#define Min_streams 500000
#define Min_charts 50
#define Min_playlists 15000

bool esExito (int streams, int charts, int playlists){
    bool esStreams = false, esCharts = false, esPlaylists = false;

    if(streams >= Min_streams){
        esStreams = true;
    }

    if(charts >= Min_charts){
        esCharts = true;
    }

    if(playlists >= Min_playlists){
        esPlaylists = true;
    }

    return (esPlaylists && esCharts || esPlaylists && esStreams ||esStreams && esCharts || esPlaylists && esCharts && esStreams);
}