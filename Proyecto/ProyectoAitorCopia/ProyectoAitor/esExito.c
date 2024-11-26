#include "esExito.h"

bool esExito (int playlists, int charts, int streams){
    bool esStreams, esCharts, esPlaylists;

    esStreams = streams >= Min_streams;
    esCharts = charts >= Min_charts;
    esPlaylists = playlists >= Min_playlists;

    return ((esPlaylists && esCharts) || (esPlaylists && esStreams) || (esStreams && esCharts));
}