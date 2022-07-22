/*****************************************
** File:    Tree.cpp
** Project: CMSC 202 Project 4, Spring 2021
** Author:  Gurjinder Singh
** Date:    4/15/2021
** Discussion-Section: 33
** E-mail:  gsingh10@umbc.edu
**
** Tree class for proj4
**
***********************************************/
#include "Tree.h"

using namespace std;

// Name: Tree (Default constructor)
// Desc: Creates a tree with size 0 and age of 0
// Preconditions:  Uses AgItem default constructor
// Postconditions: A tree is created.
Tree::Tree():AgItem() {
    m_age = 0;
}

// Name: ~Tree
// Desc: Destructor for tree (and importantly fruit)
// Preconditions:  Tree exists
// Postconditions: All fruit is purged from tree.
Tree::~Tree() {
    for (int i = m_fruit.size(); i > 0; i--) {//deletes all of fruit vector
        delete m_fruit.at(i);
        m_fruit.pop_back();
    }
}

// Name: Tick
// Desc: A season passes is the tree's life (always fed)
// Preconditions: Tree exists
// Postconditions: Returns amount of fruit harvested each season.
// One of the following occurs:
//    1. Tree is not Mature yet and ages. Every 4 seasons, size increases til age 12 when fruits
//    2. Tree is Mature and grows a one fruit a season. Fruit is harvested every season.
//    3. Tree is 60 seasons old and is cut down (IsHarvesteable)
void Tree::Tick(bool harvestable) {
    if (harvestable) {
        if (m_age <= SEASONS_TO_HARVEST) {//keeps harvestable false until
            m_age++;
            SetIsHarvestable(false);
        } else if (m_age >= SEASONS_TO_FRUIT && m_age < SEASONS_TO_HARVEST) {
            m_age++;
            SetIsHarvestable(false);
        }
        if (m_age == SEASONS_TO_HARVEST) {
            SetIsHarvestable(true);
        }
    }
}

// Name: Harvest
// Desc: If there is fruit, removes last fruit and returns 1. If 60 seasons old, returns 0
// Preconditions:  Tree exists
// Postconditions: Fruit is returned(1 farm food) or dead tree (0 worth and 0 farm food)
int Tree::Harvest() {
    int output = 0;
    int count = 0;
    if (m_age >= SEASONS_TO_FRUIT && m_age < SEASONS_TO_HARVEST) {//check to make sure within fruiting
        //makes sure there isnt already something in the vector, if there is then output is set to 1 for farm to add to food
        //and then the fruit is deleted right after
        Fruit *myFruit = new Fruit();
        m_fruit.push_back(myFruit);
        output = 1;
        count++;
        delete m_fruit.at(m_fruit.size()-1);
        m_fruit.pop_back();
    }
    if (m_age == SEASONS_TO_HARVEST) {//to use in farm for logic
        if (GetIsHarvestable()) {
            for (int i = m_fruit.size(); i > 0; i--) {
                delete m_fruit.at(i-1);
                m_fruit.pop_back();
            }
            cout << "The Tree was harvested" << endl;
            //output = 1;
        }
    }
    if (m_fruit.size() > 0) {
        for (int i = m_fruit.size(); i > 0; i--) {
            delete m_fruit.at(i-1);
            m_fruit.pop_back();
        }
    }
    return output;
}

// Name: GetType
// Desc: Returns the name of the subtype (Tree)
// Preconditions:  None
// Postconditions: Returns string name of the subtype (Tree)
string Tree::GetType() {
    return "Tree";
}

// Name: overloaded operator<<
// Desc: Allows Tree objects to be outputted
// Preconditions:  None
// Postconditions: Returns output stream with this format:
//                 Tree  | Seedling | Not Harvestable | Not Fruiting | Fruit Count: 0
ostream& Tree::operator<<(ostream &output) {
    string type = GetType();
    string fruiting;
    string isHarvestable;
    string size;
    int fruitcount = 0;//always 0
    if (m_age >= 0 && m_age <= 3) {
        size = TREE_SIZE[0];
    } else if (m_age >= 4 && m_age <= 7) {
        size = TREE_SIZE[1];
    } else if (m_age >= 8 && m_age <= 11) {
        size = TREE_SIZE[2];
    } else if (m_age >= 12) {
        size = TREE_SIZE[3];
    }
    if (m_age >= SEASONS_TO_FRUIT) {
        fruiting = "Fruiting";
    } else {
        fruiting = "Not Fruiting";
    }
    if (GetIsHarvestable()) {
        isHarvestable = "Harvestable";
    } else {
        isHarvestable = "Not Harvestable";
    }
    output << type << CONCAT << size << CONCAT << isHarvestable << CONCAT << fruiting << CONCAT << fruitcount << endl;
    return output;
}