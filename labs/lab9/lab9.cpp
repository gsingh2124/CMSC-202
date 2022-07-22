#include "Pet.h"
#include "Bird.h"
#include "Dog.h"


int main () {
    Pet myPet("Doug", "Brown", 10);
    Dog myDog("True Grit", "Brown", 3, "Chesapeake Bay Retriever");
    Bird myBird("Chuck", "Yellow", 4, "Canary");


    //Info about each pet using the accessors
    cout << "Pets:\n\n";

    cout << "Pet 1" << endl;
    cout << "Name: " << myPet.getName() << endl;
    cout << "Color: " << myPet.getColor() << endl;
    cout << "Age: " << myPet.getAge() << endl;

    cout << "\nPet 2" << endl;
    cout << "Name: " << myDog.getName() << endl;
    cout << "Color: " << myDog.getColor() << endl;
    cout << "Age: " << myDog.getAge() << endl;
    cout << "Breed: " << myDog.getBreed() << endl;

    cout << "\nPet 3" << endl;
    cout << "Name: " << myBird.getName() << endl;
    cout << "Color: " << myBird.getColor() << endl;
    cout << "Age: " << myBird.getAge() << endl;
    cout << "Species: " << myBird.getSpecies() << endl;

    //Making each pet speak()
    cout << "\n\nExample 1 - Each pet calls Speak()" << endl;
    myPet.speak(); //Calls speak() on Pet
    myDog.speak(); //Calls speak() on a Dog
    myBird.speak(); //Calls speak() on a Bird
    cout << endl;

    //Example 2 - Put all pets into a Pet array
    cout << "\nExample 2 - Using an array to display Speak()" << endl;
    Pet myPets[3]; //Create array for all Pets(Dogs and Birds ARE pets)
    myPets[0] = myPet; //Puts pet into the array
    myPets[1] = myDog; //Puts Dog into the array
    myPets[2] = myBird; //Puts Bird into the array
    for(Pet p : myPets) {
        p.speak(); //Call Speak on every item in array
    }
    return 0;
}





