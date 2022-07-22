#include "Dog.h"


Dog::Dog(string name, string color, int age, string breed):Pet(name,color,age) {
    setBreed(breed);
}
string Dog::getBreed() {
    return m_breed;
}
void Dog::setBreed(string breed) {
    m_breed = breed;
}
void Dog::speak() {
    cout << getName() << " the " << getColor() << " " << getAge() << " year old " << getBreed() << " barks!" << endl;
}




