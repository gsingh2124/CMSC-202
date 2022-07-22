
/*****************************************
** File:    lab1.cpp
** Project: CMSC 202 Lab 1, Spring 2021
** Author:  Gurjinder Singh
** Date:    2/6/2021
** Discussion-Section: 33
** E-mail:  gsingh10@umbc.edu
**
** This program is for Lab 1, where we practice some basics of input and output,
** loops, and general c++ with a cat program.
**
***********************************************/


#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char name[80];
    int age;
    int count = 0;
    int choice;

    cout << "What is your cat's name?" << endl;
    cin.getline(name, 80);
    cout << "How old is your cat?" << endl;
    cin >> age;
    while(cin.fail() or age > 22 or age < 0) {
        cout << "Please enter your cat's age, it should be an integer between 0 and 22" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> age;
    }
    cin.clear();
    cout << "Cat name = " << name << endl;
    cout << "Cat's age = " << age << endl;

    while (count != 3) {
        cout << "What would you like to do?" << endl;
        cout << "1. Pet " << name << endl;
        cout << "2. Feed " << name << endl;
        cout << "3. Chase " << name << endl;
        cout << "Enter your choice: " << endl;

        cin >> choice;
        while(cin.fail() or choice > 3 or choice < 0) {
            cout << "Enter your choice (1-3): " << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> age;
        }

        if (choice == 1) {
            cout << "You pet " << name << " and they purr." << endl;
        } else if (choice == 2) {
            cout << name << " meows gently as you feed them." << endl;
        } else if (choice == 3) {
            cout << "You chase after " << name << " and they hiss and try to bite." << endl;
        }

        count = count + 1;
    }

    cout << "That is enough for today. Good-bye" << endl;

    return 0;
}