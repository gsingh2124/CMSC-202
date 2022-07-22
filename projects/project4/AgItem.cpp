/*****************************************
** File:    AgItem.cpp
** Project: CMSC 202 Project 4, Spring 2021
** Author:  Gurjinder Singh
** Date:    4/15/2021
** Discussion-Section: 33
** E-mail:  gsingh10@umbc.edu
**
** AgItem class for proj4
**
***********************************************/

#include "AgItem.h"

using namespace std;


// Name: AgItem (Default constructor)
// Desc: Creates an AgItem with size 0, Base_Worth of 1 and not harvestable
// Preconditions:  Abstract class
// Postconditions: Abstract class so used with child classes only.
AgItem::AgItem() {
    m_size = 0;
    m_worth = BASE_WORTH;
    m_isHarvestable = false;
}

// Name: AgItem (Overloaded constructor)
// Desc: Creates an AgItem with size, worth, and IsHarvestable passed
// Preconditions:  Abstract class
// Postconditions: Abstract class so used with child classes only.
AgItem::AgItem(int size, int worth, bool isHarvestable){
    m_size = size;
    m_worth = worth;
    m_isHarvestable = isHarvestable;
}

// Name: ~AgItem (Destructor
// Desc: Deletes anything dynamically allocated
// Preconditions:  AgItem
// Postconditions: Can be trivially implemented but required for subclass (tree)
AgItem::~AgItem(){

}

//Accessors

// Name: GetSize
// Desc: Returns m_size
// Preconditions:  None
// Postconditions: None
int AgItem::GetSize(){
    return m_size;
}

// Name: GetWorth
// Desc: Returns m_worth
// Preconditions:  None
// Postconditions: None
int AgItem::GetWorth(){
    return m_worth;
}

// Name: GetIsHarvestable
// Desc: Returns m_isHarvestable
// Preconditions:  None
// Postconditions: None
bool AgItem::GetIsHarvestable(){
    return m_isHarvestable;
}

// Name: SetSize
// Desc: Sets the size of an AgItem
// Preconditions:  None
// Postconditions: m_size is set
void AgItem::SetSize(int size){
    m_size = size;
}

// Name: SetIsHarvestable
// Desc: Sets m_isHarvestable
// Preconditions:  None
// Postconditions: m_isHarvestable is set
void AgItem::SetIsHarvestable(bool isAlive){
    m_isHarvestable = isAlive;
}

// Name: SetWorth
// Desc: Sets m_worth
// Preconditions:  None
// Postconditions: m_worth is set
void AgItem::SetWorth(int worth){
    m_worth = worth;
}