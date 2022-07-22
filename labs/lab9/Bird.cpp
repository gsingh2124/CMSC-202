//
// Created by gsing on 4/6/2021.
//

#include "Bird.h"
Bird::Bird(string name, string color, int age, string breed):Pet(name,color,age) {
    setSpecies(breed);
}

string Bird::getSpecies() {
    return m_type;
}

void Bird::setSpecies(string type) {
    m_type = type;
}

void Bird::speak() {
    cout << getName() << " the " << getColor() << " " << getAge() << " year old " << getSpecies() << " chirps!" << endl;
}