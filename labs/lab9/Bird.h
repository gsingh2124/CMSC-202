//
// Created by gsing on 4/6/2021.
//

#ifndef LAB9_BIRD_H
#define LAB9_BIRD_H

#include "Pet.h"

class Bird : public Pet {
public:
    Bird(string name, string color, int age, string breed);
    string getSpecies();
    void setSpecies(string type);
    void speak();
private:
    string m_type;
};

#endif //LAB9_BIRD_H
