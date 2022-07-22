/*****************************************
** File:    proj2.cpp
** Project: CMSC 202 Project 2, Spring 2021
** Author:  Gurjinder Singh
** Date:    3/11/2021
** Discussion-Section: 33
** E-mail:  gsingh10@umbc.edu
**
** This program is a simple game of alchemy
**
***********************************************/
#include "Game.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

int main () {
    srand(time(NULL));
    Game newGame;
    newGame.StartGame();
    return 0;
}
