#ifndef SONG_H
#define SONG_H

#include<iostream>
using namespace std;

// song struct: has band name and song name
struct song
{
    string bn;
    string sn;

    song(string bandname = "", string songname = "")
    {
        bn = bandname;
        sn = songname;
    }

    // this is prob unnecessary
    bool is_empty(){
        return ((sn=="") & (bn==""));
    }
};

#endif