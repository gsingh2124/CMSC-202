
/*****************************************
** File:    lab2.cpp
** Project: CMSC 202 Lab 2, Spring 2021
** Author:  Gurjinder Singh
** Date:    2/9/2021
** Discussion-Section: 33
** E-mail:  gsingh10@umbc.edu
**
** This program is for Lab 2, where we practice some basics of input and output,
** functions and more.
**
***********************************************/
#include <iostream>
using namespace std;

// FUNCTION PROTOYPES FOR sumOfInts() and greaterThanTen() GO HERE  *

// Function takes in a number
// Function prints out weather that number is greater than 12
//
// If number is not greater than 12 nothing is printed
void greaterThanTen(int num) {
    if (num > 10) {
        cout << num << " is greater than 10!" << endl;
    }
}


// Function takes no input, is called instead
// Function returns nothing
// function uses a while loop to get user input and sum it togeather
// Function then prints the sum, an calls greaterThanTen(int num)
int sumOfInts() {
    int flag = 0;
    int sum = 0;
    int current_num = 0;
    cout << "How many integers would you like to add together? " << endl;
    cin >> flag;
    while (flag > 0) {
        cout << "Enter an integer: " << endl;
        cin >> current_num;
        sum = sum + current_num;
        flag = flag - 1;
    }
    if (flag == 0) {
        cout << "Sum: " << sum << endl;
    }
    return sum;
}


//*******main********
//The user should enter their desired amount of numbers, and the program should display the final value after the operations, as well as if the total is greater than ten or not.
//This logic must be implemented in one line. This means that the main() function can have ONE statement (and the return 0).
//Implement main here:

int main() {
    greaterThanTen(sumOfInts());
    return 0;
}



//******sumOfInts*****
//The user should be prompted to enter how many integers they would like to add together
//Afterwards, the user should enter values until the number of specified integers is reached
//Print and return the sum
