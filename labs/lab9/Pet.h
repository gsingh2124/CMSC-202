#ifndef PET_H
#define PET_H


#include <iostream>
#include <string>

using namespace std;

class Pet {

public:
    Pet();
    Pet(string name, string color, int age);
    string getName();
    string getColor();
    int getAge();
    void setName(string name);
    void setColor(string color);
    void setAge(int age);
    void speak();

private:
    string m_name;
    string m_color;
    int m_age;
};




#endif
