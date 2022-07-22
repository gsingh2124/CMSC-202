/*****************************************
** File:    Farm.cpp
** Project: CMSC 202 Project 4, Spring 2021
** Author:  Gurjinder Singh
** Date:    4/15/2021
** Discussion-Section: 33
** E-mail:  gsingh10@umbc.edu
**
** Farm class for proj4
**
***********************************************/

#include "Farm.h"
using namespace std;

// Name: Farm (Default constructor)
// Desc: Creates a Farm (with 6 food, 0 money, season = 1)
// Preconditions:  None
// Postconditions: A farm is created
Farm::Farm() {
    m_food = 6;
    m_money = 0;
    m_season = 1;
}

// Name: Farm (Destructor)
// Desc: Deallocates everything in the farm
// Preconditions:  None
// Postconditions: The farm is cleared out
Farm::~Farm() {
    for (int i = m_farm.size(); i > 0; i--) {
        delete m_farm.at(i-1);
        m_farm.pop_back();
    }
}

// Name: ChooseItem
// Desc: Allows the user to choose either an animal, vegetable, or tree
// Preconditions:  None
// Postconditions: returns 1 (animal), 2 (vegetable), or 3 (tree) (reprompts for anything else)
int Farm::ChooseItem() {
    bool flag = true;
    int itemChoice;
    while (flag) {
        if (flag) {//to make sure no ghost outputs after correct input is given
            cout << "Which agricultural item are you interested in?" << endl
                 << "1. Animal" << endl
                 << "2. Vegetable" << endl
                 << "3. Tree" << endl;
            cin >> itemChoice;
            if (itemChoice > 0 && itemChoice <= 3) {//validate input is between 1 and 3
                AddItem(itemChoice, 1);
                flag = false;//flag for ending while loop of reasking for input validation
            }
        }
    }
    return itemChoice;
}

// Name: AddItem (int type, int quantity)
// Desc: Dynamically allocates new animals, vegetables, or trees and adds to m_farm
// Preconditions:  None
// Postconditions: Adds 1 (animal), 2 (vegetable), or 3 (tree) to m_farm
void Farm::AddItem(int type, int quantity) {
    for (int i = 0; i < quantity; i++) {//need to implement dynamic objects to pushback into m_farm vector
        if (type == 1) {
            Animal *myAnimal = new Animal();
            m_farm.push_back(myAnimal);
            cout << "New Animal added to the farm." << endl;
        } else if (type == 2) {
            Vegetable *myVegetable = new Vegetable();
            m_farm.push_back(myVegetable);
            cout << "New Vegetable added to the farm." << endl;
        } else if (type == 3) {
            Tree *myTree = new Tree();
            m_farm.push_back(myTree);
            cout << "New Tree added to the farm." << endl;
        }
    }
}

// Name: Tick (int season)
// Desc: Simulates a specific number of seasons
// For each season:
//               1. Calls Tick for each item in m_farm
//               2. Tries to harvest mature items (vegetables and fruit add food; animals money)
//               3. Removes anything harvested from m_farm
//               4. Displays the status automatically
// Preconditions:  None
// Postconditions: Time passes
void Farm::Tick(int ticks) {//loop everysingle item and tick it, then increment
    vector <int> itemsToErase;//Vector to store items to delete that were harvested.
    for (int i = 0; i < ticks; i++) {//make nestd forloop, season loop
        for (int j = m_farm.size(); j > 0; j--) {//vector loop
            int count = j-1;
            if (m_farm.at(count)->GetType() == "Vegetable") {//check to see what we type we are dealing with
                if (m_farm.at(count)->GetIsHarvestable()) {//if the vegetable is harvestable then add to food and delete it
                    m_food = m_food + m_farm.at(count)->Harvest();
                    delete m_farm.at(count);
                    m_farm.pop_back();
                } else {//if not, call tick with false
                    m_farm.at(count)->Tick(m_farm.at(count)->GetIsHarvestable());//bool isnt used for vegetables
                }
            } else if (m_farm.at(count)->GetType() == "Tree") {
                if (!m_farm.at(count)->GetIsHarvestable()) {//if tree is not harvestable, harvest for fruit
                    m_farm.at(count)->Tick(true);
                    m_food = m_food + m_farm.at(count)->Harvest();
                } else {//if tree is harvestable, or of age, then chop it down
                    m_food = m_food + m_farm.at(count)->Harvest();
                    delete m_farm.at(count);
                    m_farm.pop_back();
                }
            } else if (m_farm.at(count)->GetType() == "Animal") {//Problem: segfaults when animal is with tree
                if (!m_farm.at(count)->GetIsHarvestable()) {//check to see if animal is malnurished or an adult
                    if (m_food > 0) {
                        m_food--;
                        m_farm.at(count)->Tick(true);
                    } else {
                        m_farm.at(count)->Tick(false);//sets animal to false fed
                    }
                } else {//sell animal, than delete it
                    m_money = m_money + m_farm.at(count)->Harvest();
                    delete m_farm.at(count);
                    m_farm.pop_back();
                }
            }
        }
        Status();
        m_season++;//increment season for every tick
    }
}

// Name: Menu
// Desc: Displays a menu with the following:
//     1. Add Item to Farm (adds a single item to m_farm)
//     2. Add Two of Each Item to Farm (Adds two of each item to m_farm)
//     3. Simulate Time (Asks the user how many seasons to simulate)
//     4. Farm Status (Displays the status of the farm)
//     5. Quit (Quits the simulation)
// Preconditions:  None
// Postconditions:  If returns 5, quits
int Farm::Menu() {
    int input;
    cout << endl;
    cout << endl;
    cout << "1. Add Item to Farm" << endl
         << "2. Add Two for Each Item to Farm" << endl
         << "3. Simulate Time" << endl
         << "4. Farm Status" << endl
         << "5. Quit" << endl;//exit is handled in StartSimulation()
    cin >> input;
    cout << endl;
    cout << endl;
    return input;
}

// Name: StartSimulation
// Desc: Manages the introduction, menu, and quitting
// Preconditions:  Displays welcome message
// Postconditions: As long as menu doesn't return 5, keeps running
void Farm::StartSimulation() {
    int input;
    cout << "Welcome to Stardew Valley Simulator" << endl;
    while (input != 5) {
        if (input != 5) {//makes sure input isnt rerequested after exiting
            input = Menu();
            if (input == 1) {
                ChooseItem();
            } else if (input == 2) {
                AddItem(1,2);//2 Animals
                AddItem(2,2);//2 Vegetables
                AddItem(3,2);//2 Trees
            } else if (input == 3) {
                int num;//user in of how many seasons to simulate
                cout << "How many seasons to simulate?" << endl;
                cin >> num;
                Tick(num);
            } else if (input == 4) {
                Status();
            }
        }
    }
    if (input == 5) {//exit
        cout << "Thank you for simulating Stardew Valley!" << endl;
    }
}

// Name: Status
// Desc: Displays farm food, money, season, and each agricultural item
// Preconditions:  None
// Postconditions: Displays farm data
void Farm::Status() {
    cout << endl;
    cout << endl;
    cout << "**** Farm Status ****" << endl;
    cout << "Food: " << m_food << endl;
    cout << "Money: " << m_money << endl;
    cout << "Season: " << m_season << endl;
    cout << "Agricultural Items: " << endl;
    //implement forloop for items in farm
    for (unsigned int i = 0; i < m_farm.size(); i++) {
        (*m_farm.at(i)) << cout << endl;
    }
    cout << endl;
    cout << endl;
}