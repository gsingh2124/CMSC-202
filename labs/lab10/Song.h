//
// Created by gsing on 4/13/2021.
//

#ifndef LAB10_SONG_H
#define LAB10_SONG_H

#include <iostream>
#include <string>

using namespace std;

class Song {
public:
    Song(string name, string artist);
    virtual void Play();
    virtual void Request();
    virtual void Playlist();
protected:
    string m_name;
    string m_artist;
};

class HipHop : public Song {
public:
    HipHop(string name, string artist);
    void Play();
    void Request();
    void Playlist();
};

class Pop : public Song {
public:
    Pop(string name, string artist);
    void Play();
    void Request();
    void Playlist();
};

#endif //LAB10_SONG_H
