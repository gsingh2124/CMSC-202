#include "GameCollection.h"

int main() {
  //Copy Constructor Test   
  cout << "Starting Copy Constructor Test" << endl;
  GameCollection firstCollection("RPG"); //Creates a new GameCollection
  firstCollection.Insert("Genshin Impact"); //Inserts Game
  firstCollection.Insert("CyberPunk 2077"); //Inserts Game
  firstCollection.Insert("Final Fantasy 17 "); //Inserts Game
  firstCollection.Insert("Dark Souls 3"); //Inserts Game
  firstCollection.Insert("Persona"); //Inserts Game

  //Copy of 'firstCollection' made via copy constructor and 2 items are removed using RemoveLast
  //This next line creates a new GameCollection using the copy constructor
  GameCollection firstCollectionCopy(firstCollection); //Copy Constructor
  cout << "worked1" << endl;
  firstCollectionCopy.RemoveLast(); //Removes last game
  cout << "worked2" << endl;
  firstCollectionCopy.RemoveLast(); //Removes last game
  cout << "COLLECTION 1: " << endl;
  firstCollection.PrintCollection(); //Displays source collection
  cout << "COLLECTION 1 COPY (copy constructor) with 2 items deleted: " << endl;
  firstCollectionCopy.PrintCollection(); //Displays copied collection
  cout << "End of Copy Constructor Test" << endl << endl;
  
  //Assignment Operator Test
  cout << "Start of Overloaded Assignment Operator Test" << endl;
  GameCollection secondCollection("FPS"); //Creates a new GameCollection
  secondCollection.Insert("Modern Warfare"); //Inserts Game
  secondCollection.Insert("Cold War"); //Inserts Game
  secondCollection.Insert("Black Ops 2"); //Inserts Game
  secondCollection.Insert("Black Ops 3"); //Inserts Game
  secondCollection.Insert("World at War"); //Inserts Game
  
  //This next line creates a new GameCollection then uses the assignment operator
  GameCollection secondCollectionAssign = secondCollection;
  secondCollectionAssign.Insert("MW2"); //Inserts Game
  secondCollectionAssign.Insert("Battlefield 3"); //Inserts Game
  cout << "COLLECTION 2: " << endl;
  secondCollection.PrintCollection(); //Displays source collection
  cout << "COLLECTION 2 COPY (assignment operator) with 2 extra items inserted: " << endl;
  secondCollectionAssign.PrintCollection(); //Displays assigned collection
  cout << "End of Overloaded Assignment Operator Test" << endl << endl;
  
  cout << "Test your code running 'make val' so that it does a memory test" << endl;
  //If you have no leaks and mem errors then your code + destructor are functioning optimally :)
  GameCollection test1("Test1");

  //This tests to make sure that you made a deep copy from your copy constructor
  //Checks to make sure they are in different memory locations
  cout << "Deep Copy Test for Copy Constructor" << endl;
  cout << "firstCollection Address: " << &firstCollection << endl;
  cout << "firstCollectionCopy Address: " << &firstCollectionCopy << endl;
  cout << "Copy Constructor "
       << (&firstCollection != &firstCollectionCopy?"Passed":"Did NOT Pass") << endl << endl;

  //This tests to make sure that you made a deep copy from your assignment operator
  //Checks to make sure they are in different memory locations
  cout << "Deep Copy Test for Assignment Operator" << endl;
  cout << "secondCollection Address: " << &secondCollection << endl;
  cout << "secondCollectionAssign Address: " << &secondCollectionAssign << endl;
  cout << "Assignment Operator "
       << (&secondCollection != &secondCollectionAssign?"Passed":"Did NOT Pass") << endl << endl;

  return 0;
}
