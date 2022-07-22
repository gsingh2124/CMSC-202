//
//  Runner.cpp
//  Project 5 - Templates
//
//  Created by Nathenael Dereb
//
/*****************************************
** File:    Runner.cpp
** Project: CMSC 202 Project 5, Spring 2021
** Author:  Gurjinder Singh
** Date:    5/1/2021
** Discussion-Section: 33
** E-mail:  gsingh10@umbc.edu
**
** implementation of runner.cpp
**
***********************************************/
#ifndef RUNNER_CPP
#define RUNNER_CPP

#include <cstdlib>
#include "Vector.cpp"
using namespace std;


template <class T>
class Runner {
public:
    // Name: Default Constructor
    // Precondition: None
    // Postcondition: Initiates state/environment
    Runner(Vector<T>*, Vector<T>*);
    
    // Name: mainMenu
    // Desc: Main Menu
    // Precondition: Existing Vectors
    // Postcondition: Handles various menu commands
    int mainMenu();
    
private:
    Vector<T> m_vector1;
    Vector<T> m_vector2;
};

// **** Add class definition below ****
template <class T>
Runner<T>::Runner(Vector<T>* vec1, Vector<T>* vec2) {
    m_vector1 = vec1;
    m_vector2 = vec2;
    mainMenu();
}


template <class T>
int Runner<T>::mainMenu() {
    bool flag = true;
    int input = 0;
    while (flag) {
        cout << "Chooser an option" << endl;
        cout << "1. Display Vectors" << endl;
        cout << "2. Vector comparison (<)" << endl;
        cout << "3. Vector comparison (==)" << endl;
        cout << "4. Vector addition" << endl;
        cout << "5. Vector multiplication" << endl;
        cout << "6. Compute median" << endl;
        cout << "7. Compute mean" << endl;
        cout << "8. Compute Standard Derivation" << endl;
        cout << "9. Exit" << endl;
        cin >> input;
        if (input == 1) {
            cout << "Vector1: ";
            m_vector1.Display();
            cout << endl;
            cout << "Vector2: ";
            m_vector2.Display();
            cout << endl;
        } else if (input == 2) {
            cout << "Not implemented/working :(" << endl;
        } else if (input == 3) {
            cout << "Not implemented/working :(" << endl;
            //Vector<char> output = (m_vector1==m_vector2);
            //cout << "Vector1 == Vector2: " << endl;
            //output.Display();
        } else if (input == 4) {
            Vector<T> output = (m_vector1+m_vector2);
            output.Display();
        } else if (input == 5) {
            cout << "Not implemented/working :(" << endl;
        } else if (input == 6) {
            cout << "vector 1 median: " << m_vector1.Median() << endl;
            cout << endl;
            cout << "vector 2 median: " << m_vector2.Median() << endl;
        } else if (input == 7) {
            cout << "Vector 1 mean: " << m_vector1.Mean() << endl;
            cout << "Vector 2 mean: " << m_vector2.Mean() << endl;
        } else if (input == 8) {
            cout << "Not implemented/working :(" << endl;
        } else if (input == 9) {
            flag = false;
        } else if (input == 10) {
            cout << "before removal of index 2: ";
        } else if (input == 11) {
            cout << "Not implemented/working :(" << endl;
        } else if (input == 12) {
            cout << "Not implemented/working :(" << endl;
        }
    }
    return 0;
}




#endif /* Runner_h */


