/*****************************************
** File:    Vegetable.cpp
** Project: CMSC 202 Project 4, Spring 2021
** Author:  Gurjinder Singh
** Date:    4/15/2021
** Discussion-Section: 33
** E-mail:  gsingh10@umbc.edu
**
** Vegetable class for proj4
**
***********************************************/
#include "Vegetable.h"

using namespace std;

// Name: Vegetable (Default constructor)
// Desc: Creates a vegetable with size 0
// Preconditions:  Uses AgItem default constructor
// Postconditions: A vegetable is created.
Vegetable::Vegetable():AgItem() {
    SetSize(0);
}

// Name: Harvest
// Desc: If the vegetable is harvestable (fully mature), returns size to increase farm's food
// Preconditions:  IsHarvestable
// Postconditions: Returns integer size of vegetable for food
int Vegetable::Harvest() {
    int output = 0;
    if (GetIsHarvestable()) {
        cout << "The Vegetable was harvested" << endl;
        output = GetSize();
    }
    return output;
}

// Name: Tick
// Desc: A season passes in the vegetable's life if they are fully mature, IsHarvestable flipped
// Preconditions:  If the size is less than the maximum vegetable size, increases size
// Postconditions: Vegetable either grows or becomes harvestable
// Assume that a vegetable is always fed.
void Vegetable::Tick(bool harvestable) {
    if (!harvestable) {
        if (GetSize() < MAX_VEG_SIZE) {//make sure size cant go higher than max
            SetSize(GetSize()+1);
        }
        if (GetSize() == MAX_VEG_SIZE) {//if adult set harvestable to true
            SetIsHarvestable(true);
        }
    }
}

// Name: GetType
// Desc: Returns the name of the subtype (Vegetable)
// Preconditions:  None
// Postconditions: Returns string name of the subtype (Vegetable)
string Vegetable::GetType() {
    return "Vegetable";
}

// Name: overloaded operator<<
// Desc: Allows Vegetable objects to be outputted
// Preconditions:  None
// Postconditions: Returns output stream with this format
//                 Vegetable | Not Harvestable | Seedling
ostream& Vegetable::operator<<(ostream &output) {
    string type = GetType();
    string harvestable;
    string size;

    if (GetIsHarvestable()) {
        harvestable = "Is Harvestable";
    } else {
        harvestable = "Not Harvestable";
    }
    if (GetSize() <= MAX_VEG_SIZE) {
        size = Veg_Size[GetSize()];
    }
    output << type << CONCAT << harvestable << CONCAT << size << endl;
    return output;
}