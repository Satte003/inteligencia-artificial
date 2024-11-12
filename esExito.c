#include "esExito.h"

bool esExito (int playlists, int charts, int streams){
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

    return ((esPlaylists && esCharts) || (esPlaylists && esStreams) || (esStreams && esCharts) || (esPlaylists && esCharts && esStreams));
}