//
// Created by kenne on 1/30/2021.
//

#include "Song.h"
#include <iostream>
#include <string>
using namespace std;


int main () {

    Song newSong ("Can I", "Kehlani");
    HipHop hiphop1("DNA.", "Kendrick Lamar");
    Pop pop1("Can't Move On", "Wild Youth");

    Song * song1 = &newSong;
    Song * song2 = &hiphop1;
    Song * song3 = &pop1;

    cout << "Welcome to M&M Radio, where we bring you the best in Madness and Music!" << endl;
    cout << "This is your DJ, Soul speaking." << endl;
    song1->Play();
    song1->Playlist();

    cout << endl << "And I'm back, we are now live on M&M Radio.";
    cout << "We are now taking requests for songs, hit me up at (281) 993-4465." << endl;
    song2->Request();
    song2->Play();
    song2->Playlist();

    cout << endl;
    cout << "Ladies and gentlemen, you heard it here first, M&M Radio live." << endl;
    song3->Request();
    song3->Play();
    song3->Playlist();

    cout << endl << "Once again, this is your DJ Soul E" << endl;
    cout << "For those of you who can figure out my last name, you got a good chance to pass with flying colors" << endl;
    cout << "Good luck with this class, I'm sure you will do great!" << endl;
    cout << "A sound soul, dwells within a sound body, and a sound mind." << endl;

    return 0;
}