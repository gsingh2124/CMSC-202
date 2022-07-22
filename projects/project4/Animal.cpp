/*****************************************
** File:    Animal.cpp
** Project: CMSC 202 Project 4, Spring 2021
** Author:  Gurjinder Singh
** Date:    4/15/2021
** Discussion-Section: 33
** E-mail:  gsingh10@umbc.edu
**
** Animal class for proj4
**
***********************************************/
#include "Animal.h"
using namespace std;

// Name: Animal (Default constructor)
// Desc: Creates an Animal with size 0
// Preconditions:  Uses AgItem default constructor
// Postconditions: An animal (chicken) is created.
Animal::Animal():AgItem() {
    m_name = "Chicken";
    SetWorth(BASE_WORTH);
}

// Name: Tick
// Desc: A season passes is the animal's life (passed boolean if it was fed - eats "farm's food")
// Preconditions: If farm has food, animal is automatically fed
// Postconditions: One of the following occurs
//    1. Animal is fed and size increases (not max yet)
//    2. Animal is fed hits max size and is made harvestable
//    3. Animal is not fed. Size does not increase. If second no feed, is harvested (small).
void Animal::Tick(bool fed) {

    if (fed) {
        m_IsHungry = false;
        if (GetSize() < ANIMAL_MAX_SIZE) {//make sure animal cant go past max size
            SetSize(GetSize()+1);
            SetIsHarvestable(false);
        } else if (GetSize() == ANIMAL_MAX_SIZE){//if the animal is adult, make harvesrable
            SetIsHarvestable(true);
        }
    } else {
        if (m_IsHungry) {//if already hungry set to harvestable
            SetIsHarvestable(true);
        }
        m_IsHungry = true;//set to hungry
    }
}

// Name: Harvest
// Desc: If the animal is harvestable (adult), returns worth * size to increase farm's money
// Preconditions:  IsHarvestable
// Postconditions: Animal harvested and money is gained (worth * size)
int Animal::Harvest() {
    int output = 0;
    if (GetIsHarvestable()) {
        cout << "The Animal was harvested" << endl;
        output = GetWorth()*GetSize();
    }
    return output;
}

// Name: GetType
// Desc: Returns the name of the subtype (Animal)
// Preconditions:  None
// Postconditions: Returns string name of the subtype (Animal)
string Animal::GetType() {
    return "Animal";
}

// Name: overloaded operator<<
// Desc: Allows Animal objects to be outputted
// Preconditions:  None
// Postconditions: Returns output stream with this format:
//                 Animal | Chicken | Not Harvestable | Born | Fed
ostream& Animal::operator<<(ostream &output) {
    string type = GetType();
    string animalName = m_name;
    string isHarvestable;
    string size = ANIMAL_SIZE[AgItem::GetSize()];
    string fed;
    if (GetIsHarvestable()) {
        isHarvestable = "Harvestable";
    } else {
        isHarvestable = "Not Harvestable";
    }
    if (m_IsHungry) {
        fed = "Not Fed";
    } else {
        fed = "Fed";
    }

    output << type << CONCAT << animalName << CONCAT << isHarvestable << CONCAT << size << CONCAT << fed << endl;
    return output;
}