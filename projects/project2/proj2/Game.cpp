/*****************************************
** File:    Game.cpp
** Project: CMSC 202 Project 2, Spring 2021
** Author:  Gurjinder Singh
** Date:    3/11/2021
** Discussion-Section: 33
** E-mail:  gsingh10@umbc.edu
**
** The game class file for project 2
**
***********************************************/
#include "Game.h"

using namespace std;
// Desc - Builds a new game by:
// 1. Loads all materials and their recipes into m_materials
// 2. Asks user for their Ship's name (store in m_myShip as m_myName)
// 3. Copies all materials from m_materials into the Ship's material array
// Preconditions - None
// Postconditions - m_materials is populated
Game::Game() {
    GameTitle();
    string shipName;
    LoadMaterials();
    cout << endl << "What is the name of your Ship?" << endl;
    cin >> shipName;
    m_myShip.SetName(shipName);
    for (int i = 0; i < PROJ2_SIZE; i++) {//loads all of game materials into ship
        m_myShip.AddMaterial(m_materials[i]);
    }
}
// Name: LoadMaterials
// Desc - Loads each material into m_materials from file
// Preconditions - Requires file with valid material data
// Postconditions - m_material is populated with material structs
void Game::LoadMaterials() {

    //possible data types from materials
    string name;
    string mat1;
    string mat2;
    string type;

    ifstream myfile;
    myfile.open(PROJ2_DATA); //Declares and opens a file
    int count = 0;
    if (myfile.is_open()) { //Checks to see if the file exists and was opened
        while(myfile && count != 62){ //Keeps reading a name as long as there is another line
            getline(myfile,name,',');
            getline(myfile,type,',');
            getline(myfile,mat1,',');
            getline(myfile,mat2,'\n');
            m_materials[count] = Material(name, type, mat1, mat2, 0);
            count = count + 1;
        }
    }else {
        cout << "Unable to open file"; //If the input file does not exist, notifies user
    }
    myfile.close();
    cout << count << " materials loaded";
}
// Name: StartGame()
// Desc - Manages the game itself including win conditions continually
//         calling the main menu
// Preconditions - Player is placed in game
// Postconditions - Continually checks to see if player has entered 5
void Game::StartGame() {
    bool flag = true;//to determine end of game
    int input;
    while (flag) {
        CalcScore();//updates rank every run
        input = MainMenu();
        if (input == 1) {//disp materials if input is 1
            DisplayMaterials();
        } else if (input == 2) {//search for materials
            SearchMaterials();
        } else if (input == 3) {//combine materials
            CombineMaterials();
        } else if (input == 4) {//displays ship rank
            cout << "***The Ship***" << endl;
            cout << "The Great Ship " << m_myShip.GetName() << endl;
            cout << "Ship Rank: " << m_myShip.GetRank() << endl;
        } else if (input == 5) { // loop ending condition
            flag = false;
        } else if (m_myShip.GetRank() == 'S') {//winner notice
            cout <<
            endl <<
            endl <<
            "Congrats! You made it to S rank with 4 unique items!" <<
            endl <<
            "You Win!!!" <<
            endl <<
            endl;
            flag = false;//ends game because you won
        }
    }
}
// Name: DisplayMyMaterials()
// Desc - Displays the Ship's materials (Uses GetMaterial)
// Preconditions - Player's Ship has materials
// Postconditions - Displays a numbered list of materials
void Game::DisplayMaterials() {
    for (int i = 0; i < PROJ2_SIZE; i++) {
        cout
        << endl
        << i + 1 << ". "
        << m_myShip.GetMaterial(i).m_name
        << ", " << m_myShip.GetMaterial(i).m_type
        << ", " << m_myShip.GetMaterial(i).m_quantity
        << endl;
    }
    cout << endl;
}
// Name: MainMenu()
// Desc - Displays and manages menu. Also checks win condition (Ship reaches S rank).
// Preconditions - Player has a Ship
// Postconditions - Returns number including exit
int Game::MainMenu() {
    int input = 0;
    cout << "1. Display your Ship's Materials" << endl;
    cout << "2. Search for Raw Materials" << endl;
    cout << "3. Attempt to Merge Materials" << endl;
    cout << "4. See Score" << endl;
    cout << "5. Quit" << endl;
    cin >> input;
    cout << endl;
    return input;
}
// Name: SearchMaterials()
// Desc - Attempts to search for raw materials (must be type "raw")
// Preconditions - Raw materials loaded
// Postconditions - Increases quantity in Ship's possession of materials
void Game::SearchMaterials() {
    bool flag = true;
    string foundName;
    while (flag) {
        srand(time(NULL));
        int num = rand() % (PROJ2_SIZE);//returns a random material aslong as its type is raw
        if (m_materials[num].m_type == "raw") {
            m_myShip.IncrementQuantity(m_materials[num]);
            foundName = m_materials[num].m_name;
            flag = false;
        }
    }
    cout << "Found " << foundName << "!!!" << endl;
}
// Name: CombineMaterials()
// Desc - Attempts to combine known materials. If combined, quantity of material decreased
// Preconditions - Ship is populated with materials
// Postconditions - Increments quantity of item "made", decreases quantity of source items
void Game::CombineMaterials() {
    int choice;
    int mat1Index = -1;
    int mat2Index = -1;
    bool flag = true;
    int result;

    while (flag) {
        cout << "Which materials would you like to merge?" << endl;
        cout << "To list known materials enter -1" << endl;
        cin >> choice;
        if (choice == -1) {//disp materials
            DisplayMaterials();
        } else {
            RequestMaterial(choice);//try to gather first material
            if (choice == -2) {//quantity check (loop so does both)
                cout << "error, not enough quantity for merge." << endl;
                flag = false;
            } else if (choice == -3) {//invalid input accomodation
                cout << "error, material not found." << endl;
                flag = false;
            } else if (mat1Index == -1){//sets this one first,
                mat1Index = choice;
            } else if (mat1Index != -1) {//sets this one second. a loop hole for loop ig
                mat2Index = choice;
                flag = false;
            }
        }

    }

    if (mat1Index > -1 && mat2Index > -1) {//makes sure the indexes are not the defaults
        //searches for a material requiring the 2 provided by the user
        result = SearchRecipes(m_materials[mat1Index].m_name, m_materials[mat2Index].m_name);
        if (result != -1) {// if it exists
            if (m_myShip.GetMaterial(result).m_type == "unique") {//check if its uniqu
                if (m_myShip.GetMaterial(result).m_quantity == 1) {//then check its quantity for the 1 limit rule
                    cout << "You already have this uniqe material. You may only carry 1 of this material" << endl;
                    cout << "Unique material: "<< m_myShip.GetMaterial(result).m_name << endl;
                } else {//if uniqe does not exist make it
                    m_myShip.DecrementQuantity(m_myShip.GetMaterial(mat1Index));
                    m_myShip.DecrementQuantity(m_myShip.GetMaterial(mat2Index));
                    m_myShip.IncrementQuantity(m_myShip.GetMaterial(result));
                    cout << "You just made " << m_myShip.GetMaterial(result).m_name << "!!!!" << endl;
                }
            } else {//make for non uniques
                m_myShip.DecrementQuantity(m_myShip.GetMaterial(mat1Index));
                m_myShip.DecrementQuantity(m_myShip.GetMaterial(mat2Index));
                m_myShip.IncrementQuantity(m_myShip.GetMaterial(result));
                cout << "You just made " << m_myShip.GetMaterial(result).m_name << "!!!!" << endl;
            }
        } else {//error for user to think about what they did
            cout << "Recipe does not exist. " << endl;
        }
    }
}
//check if they want to see list
//if not, attempt request of materials for choice 1
//if choice 1 is valid, do the same for choice 2
//check if choice 2 is valid
//else print an message saying no recipe for the given materials or not enough quantity
//same for outer if
//once you have 2 indexes from above, run the search recipe command.
//rest easy





// Name: RequestMaterial()
// Desc - Requests material to use to merge
// Preconditions - Ship has materials to try and merge
// Postconditions - Returns integer of item selected by user
void Game::RequestMaterial(int &choice) {
    if (choice >= 1 && choice <= PROJ2_SIZE) {
        if (m_myShip.GetMaterial(choice-1).m_quantity > 0) {//if the users material choice has quantity
            choice = choice-1;//modify choice to be in index
        } else {
            choice = -2;//sets as not enough quantity
        }
    } else {//sets as out of bounds
        choice = -3;
    }

}
// Name: SearchRecipes()
// Desc - Searches recipes for two strings (name of item)
// Preconditions - m_materials is populated
// Postconditions - Returns int index of matching recipe
int Game::SearchRecipes(string mat1Name, string mat2Name) {
    int out = -1;
    for (int i = 0; i < PROJ2_SIZE; i++) {
        if (m_materials[i].m_material1 == mat1Name) {//condition to check if the provided materials match
            if (m_materials[i].m_material2 == mat2Name) {
                out = i;
            }
        } else if (m_materials[i].m_material1 == mat2Name) {//reverse of above because of 2 orientations of inputs
            if (m_materials[i].m_material2 == mat1Name) {
                out = i;
            }
        }
    }
    return out;
}
// Name: CalcScore()
// Desc - Displays current score for Ship
// Preconditions - Ship is populated with materials
// Postconditions - Displays total
void Game::CalcScore() {
    int uniqeCount = 0;
    for (int i = 0; i < PROJ2_SIZE; i++) {//recounts unique everytime calcscore is called
        if (m_myShip.GetMaterial(i).m_type == "unique") {
            if (m_myShip.GetMaterial(i).m_quantity == 1) {
                uniqeCount++;
            }
        }
    }
    if (m_myShip.GetRank() == 'D' && uniqeCount == 1) {//basic rank upgrading
        m_myShip.IncRank();
    } else if (m_myShip.GetRank() == 'C' && uniqeCount == 2) {
        m_myShip.IncRank();
    } else if (m_myShip.GetRank() == 'B' && uniqeCount == 3) {
        m_myShip.IncRank();
    } else if (m_myShip.GetRank() == 'A' && uniqeCount == 4) {
        m_myShip.IncRank();
        cout << "You win! You acquired 4 unique materials. Your ship is now rank S!!!" << endl;//winner message
    } else if (m_myShip.GetRank() == 'S' && uniqeCount == 5) {//test
        cout << "How did you manage to get 5?!?!?" << endl;
    }
}