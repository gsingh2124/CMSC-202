/*****************************************
** File:    Ship.cpp
** Project: CMSC 202 Project 2, Spring 2021
** Author:  Gurjinder Singh
** Date:    3/11/2021
** Discussion-Section: 33
** E-mail:  gsingh10@umbc.edu
**
** The ship class file for project 2
**
***********************************************/
#include "Ship.h"

using namespace std;


// Name: Ship() - Default Constructor
// Desc: Used to build a new Player Ship
// Preconditions - Requires default values
// Postconditions - Creates a new Player Ship
Ship::Ship() {
    m_shipName = "Ship";
    m_shipRank = 'D';
    m_numMaterials = 0;
}
// Name: Ship(name) - Overloaded constructor
// Desc - Used to build a new Player Ship
// Preconditions - Requires name
// Postconditions - Creates a new Player Ship
Ship::Ship(string name) {
    m_shipName = name;
    m_shipRank = 'D';
    m_numMaterials = 0;
    m_myMaterials[PROJ2_SIZE] = {};
}
// Name: GetName()
// Desc - Getter for the Player Ship's name
// Preconditions - Player Ship exists
// Postconditions - Returns the name of the Player Ship
string Ship::GetName() {
    return m_shipName;
}
// Name: SetName(string)
// Desc - Allows the user to change the name of the Player Ship
// Preconditions - Player Ship exists
// Postconditions - Sets name of Player Ship
void Ship::SetName(string name) {
    m_shipName = name;
}
// Name: CheckMaterial(Material)
// Desc - Checks to see if the Ship has a material
// Preconditions - Ship already has materials
// Postconditions - Returns index of material if the Ship has it else -1
int Ship::CheckMaterial(Material mat) {//i cant explain it better than ^^
    int flag = -1;
    for (int i = 0; i < PROJ2_SIZE; i++) {
        if (m_myMaterials[i].m_name == mat.m_name) {
            if (m_myMaterials[i].m_quantity > 0) {
                flag = i;
            }
        }
    }
    return flag;
}
// Name: AddMaterial(string)
// Desc - Inserts a material into the Ship's list of materials
// Preconditions - Ship exists
// Postconditions - Add a material to the Ship's m_myMaterials with a quantity of 0
void Ship::AddMaterial(Material mat) {
    m_myMaterials[m_numMaterials] = mat;
    m_numMaterials++;
}
// Name: IncrementQuantity(Material)
// Desc - Adds quantity to list of materials the Ship knows
// Preconditions - Ship exists
// Postconditions - Increases quantity of material for the Ship
void Ship::IncrementQuantity(Material mat) {
    for (int i = 0; i < PROJ2_SIZE; i++) {
        if (m_myMaterials[i].m_name == mat.m_name) {
            m_myMaterials[i].m_quantity++;
        }
    }
}
// Name: DecrementQuantity(Material)
// Desc - Reduces quantity from the Ship's inventory with true, if no quantity false
// Preconditions - A Ship exists
// Postconditions - Reduces quantity of material for the Ship
bool Ship::DecrementQuantity(Material mat) {
    bool out = true;
    for (int i = 0; i < PROJ2_SIZE; i++) {
        if (m_myMaterials[i].m_name == mat.m_name) {
            if (mat.m_quantity > 0) {//dont go negitive
                m_myMaterials[i].m_quantity--;
                out = true;
            } else {//return if decrementing would be negitive
                out = false;
            }
        }
    }
    return out;
}
// Name: CheckQuantity(Material)
// Desc - Checks to see if quantity of two merge materials are available
// Preconditions - Ship exists with materials
// Postconditions - Returns true if both are available (including two of same material)
bool Ship::CheckQuantity(Material mat1, Material mat2) {
    bool out = false;
    if (mat1.m_quantity > 0 && mat2.m_quantity > 0) {//just checks if both quantities are greater than 0
        out = true;
    }
    return out;
}
// Name: GetMaterial(int)
// Desc - Checks to see if the Ship has any materials
// Preconditions - The Ship already has materials
// Postconditions - Returns material at specific index
Material Ship::GetMaterial(int i) {
    Material out;
    if (m_numMaterials > 0) {
        out = m_myMaterials[i];
    } else {
        cout << "material not found" << endl;
    }
    return out;
}
// Name: IncRank()
// Desc - Increments the rank of the ship to the next rank.
// Preconditions - Ship exists and has a rank
// Postconditions - m_shipRank will move to the next character
void Ship::IncRank() {
    if (m_shipRank == 'D') {
        m_shipRank = 'C';
    } else if (m_shipRank == 'C') {
        m_shipRank = 'B';
    } else if (m_shipRank == 'B') {
        m_shipRank = 'A';
    } else if (m_shipRank == 'A') {
        m_shipRank = 'S';
    }
}
// Name: GetRank()
// Desc - Checks to see what the current ship's rank is
// Preconditions - The ship exists
// Postconditions - Returns the character indicating the rank of the ship
char Ship::GetRank() {
    return m_shipRank;
}
