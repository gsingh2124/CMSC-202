#ifndef DOG_H
#define DOG_H


#include "Pet.h"

class Dog : public Pet {
public:
    Dog(string name, string color, int age, string breed);
    string getBreed();
    void setBreed(string breed);
    void speak();
private:
    string m_breed;
};



#endif // DOG_H


