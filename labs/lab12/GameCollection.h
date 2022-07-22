/*****************************************
** File:    GameCollection.h
** Project: CMSC 202 Lab 12, Spring 2021
**
** This is the header file for the GameCollection class in Lab 12.
**
***********************************************/

#ifndef GAMECOLLECTION_H
#define GAMECOLLECTION_H

#include <string>
#include <iostream>

using namespace std;

//Rule of Three Lab
//For this lab, you must implement copy constructor, overloaded assignment operator and destructor

class GameCollection {
public:
  GameCollection(string genre); //Constructor (PROVIDED)
  GameCollection(const GameCollection& source); //Copy Constructor (REQUIRED)
  GameCollection& operator=(const GameCollection& source); //Assignment Operator (REQUIRED)
  ~GameCollection(); //Destructor (REQUIRED)
  int GetSize(); //Function that returns size of video game collection (PROVIDED)
  string GetGenre(); // Function that returns genre of video game collection (PROVIDED)
  void PrintCollection(); //Function that prints the video game collection (PROVIDED)
  void Insert(string name); //Function that inserts a video game to the end of the array (PROVIDED)
  void RemoveLast(); //Function that removes the last video game from the collection (PROVIDED)
private:
  string *m_videoGameCollection; //Dynamic array that stores collection of video games which are strings (their names)
  int m_numGames; //Integer member variable that stores number of video games in collection
  string m_collectionGenre; //String member variable that stores the genre of the video game collection (e.g RPG)
};

#endif //GAME_COLLECTION
