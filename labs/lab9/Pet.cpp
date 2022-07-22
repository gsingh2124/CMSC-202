#include "Pet.h"


Pet::Pet() {
    setName("");
    setColor("");
    setAge(0);
}
Pet::Pet(string name, string color, int age) {
    setName(name);
    setColor(color);
    setAge(age);
}
string Pet::getName() {
    return m_name;
}
string Pet::getColor() {
    return m_color;
}
int Pet::getAge() {
    return m_age;
}
void Pet::setName(string name) {
    m_name = name;
}
void Pet::setColor(string color) {
    m_color = color;
}
void Pet::setAge(int age) {
    m_age = age;
}
void Pet::speak() {
  cout << getName() << " the " << getColor() << " " << getAge() << " year old pet makes an animal noise!" << endl;
}

