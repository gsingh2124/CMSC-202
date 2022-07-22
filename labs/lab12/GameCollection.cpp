/*****************************************
** File:    GameCollection.cpp
** Project: CMSC 202 Lab 12, Spring 2021
**
** This is the cpp file for the GameCollection class in Lab 12. You will need to
** implement the Copy constructor, overloaded assignment operator, and
** the destructor in this file.
**
***********************************************/

#include "GameCollection.h"

//Constructor
GameCollection::GameCollection(string genre) {
  m_collectionGenre = genre;
  m_numGames = 0;
  m_videoGameCollection = nullptr;
}

//****IMPLEMENT COPY CONSTRUCTOR HERE*****
//Do not forget to iterate over the source collection and check for empty collection
GameCollection::GameCollection(const GameCollection& source) {
    m_collectionGenre = source.m_collectionGenre;
    m_numGames = 0;
    m_videoGameCollection = nullptr;
    m_videoGameCollection = new string[source.m_numGames];
    m_collectionGenre = source.m_collectionGenre;
    m_numGames = source.m_numGames;
    for (int i = 0; i < source.m_numGames; i++) {
        m_videoGameCollection[i] = source.m_videoGameCollection[i];
    }
}


//****IMPLEMENT OVERLOADED ASSIGNMENT OPERATOR HERE*****
//Do not forget to protect against self-assignment and clear the destination array
GameCollection& GameCollection::operator=(const GameCollection& source) {
    if (m_videoGameCollection != nullptr) {
        delete m_videoGameCollection;
    }
    if (this != &source) {
        m_videoGameCollection = new string[source.m_numGames];
        m_collectionGenre = source.m_collectionGenre;
        m_numGames = source.m_numGames;
        for (int i = 0; i < source.m_numGames; i++) {
            m_videoGameCollection[i] = source.m_videoGameCollection[i];
        }
    }
    return *this;
}

//****IMPLEMENT DESTRUCTOR HERE*****
//Only delete if something exists
GameCollection::~GameCollection() {
    m_collectionGenre = "";
    m_numGames = 0;
    delete[] m_videoGameCollection;
}




//GetSize function that returns number of games in collection
int GameCollection::GetSize() {
  return m_numGames;
}

string GameCollection::GetGenre() {
  return m_collectionGenre;
}

//Prints the collection array
void GameCollection::PrintCollection() {
  if(m_numGames == 0) {
    cout << "Collection is Empty!" << endl;
    return;
  }
  cout << GetGenre() << " Collection: (SIZE : " << GetSize() << ")" << endl;
  for(int i = 0; i < m_numGames; i ++) {
    cout << (i + 1) << ": " << m_videoGameCollection[i] << endl;
  }
}

//Inserts a new game into collection
//Resizes as needed
void GameCollection::Insert(string name) {
  string *collectionTemp = new string[m_numGames + 1];
  
  if(m_numGames == 0) {
    m_videoGameCollection = collectionTemp;
    m_videoGameCollection[0] = name;
  }else{
    for(int i = 0; i < m_numGames; i ++) {
      collectionTemp[i] = m_videoGameCollection[i];
    }
    delete[] m_videoGameCollection;
    m_videoGameCollection = nullptr;
    m_videoGameCollection = collectionTemp;
    m_videoGameCollection[m_numGames] = name;
  }
  m_numGames += 1; 
}

//Removes last item from collection
//Resizes as needed
void GameCollection::RemoveLast() {
  if(m_numGames == 0) {
    cout << "Collection is Empty!, nothing to remove!" << endl;
    return;
  }
  if(m_numGames == 1) {
    delete[] m_videoGameCollection;
    m_videoGameCollection = nullptr;
    m_numGames -= 1;
    return;
  } 
  string *collectionTemp = new string[m_numGames - 1];
  for(int i = 0; i < m_numGames - 1; i ++) {
    collectionTemp[i] = m_videoGameCollection[i];
  }
  delete[] m_videoGameCollection;
  m_videoGameCollection = nullptr;
  m_videoGameCollection = collectionTemp;
  m_numGames -= 1;
}
