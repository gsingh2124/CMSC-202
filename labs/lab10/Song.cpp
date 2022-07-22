//
// Created by gsing on 4/13/2021.
//

#include <iostream>
#include <string>
#include "Song.h"
using namespace std;

class Song {
public:
    Song(string name, string artist) {
        m_name = name;
        m_artist = artist;
    }
    virtual void Play() {
        cout << "I know exactly what you are in the mood for, " << m_name << " by " << m_artist << endl;
    }
    virtual void Request() {
        cout << "No one asked for it but here it is, " << m_name << " by " << m_artist << "." << endl;
    }
    virtual void Playlist() {
        cout << "Since you liked " << m_name << " by " << m_artist << " so much, we are adding it to your playlist." << endl;
    }
protected:
    string m_name;
    string m_artist;
};

class HipHop : public Song {
public:
    HipHop(string name, string artist):Song(name, artist){}
    void Play() {
        cout << "Here is a song for you hip-hop lovers out there, up next playing " << m_name << " by " << m_artist << endl;
    }
    void Request() {
        cout << "I'm hearing the people want more hip-hop." << endl;
    }
    void Playlist() {
        cout << "We're gonna add " << m_name << " by " << m_artist << " to your hip-hop playlist." << endl;
    }
};

class Pop : public Song {
public:
    Pop(string name, string artist):Song(name, artist){}
    void Play() {
        cout << "Here is a song for you Pop lovers out there, up next playing " << m_name << " by " << m_artist << endl;
    }
    void Request() {
        cout << "I'm hearing the people want more pop music." << endl;
    }
    void Playlist() {
        cout << "We're gonna add " << m_name << " by " << m_artist << " to your pop playlist." << endl;
    }
};