/**************
 * File: lab5.cpp
 * The user creates this file to demonstrate use of a course.
 *************/

#include <iostream>
#include "Book.h"
using namespace std;

int main() {
    //**Student Requirement**
    //Part 1: Create 2 books by instantiating them
    Book book1;
    Book book2;

    //**Student Requirement**
    //Part 2: Set their values for book name, cover type, and amount of check-outs.
    book1.setBookName("Book 1");
    book1.setHardCover(true);
    book1.setCheckOuts(0);

    book2.setBookName("Book 2");
    book2.setHardCover(false);
    book2.setCheckOuts(6);

    //**Student Requirement**
    //Part 3: Output their information:  Name, cover type, and amount of check-outs
    cout << "Data of Book1:\n";
    cout << endl;
    cout << "Book Name: " << book1.getBookName() << endl;
    cout << "Number of Checkouts: " << book1.getCheckOuts() << endl;
    cout << "Hardcover/Paperback: " << book1.isHardCover() << endl;

    cout << endl;

    cout << "Data of Book2:\n";
    cout << endl;
    cout << "Book Name: " << book2.getBookName() << endl;
    cout << "Number of Checkouts: " << book2.getCheckOuts() << endl;
    cout << "Hardcover/Paperback: " << book2.isHardCover() << endl;

    cout << endl;

    //**Student Requirement**
    //Part 4: Call a custom function: Check if book is hard cover or not
    book1.checkHardcover();
    cout << endl;
    book2.isHardCover();
    cout << endl;


    //**Student Requirement**
    //Part 5: Update data members with custom function: Add 1 check-out to the amount of check-outs
    //Display updated amount of check-outs
    cout << endl;
    book1.addCheckout();
    cout << endl;
    book2.addCheckout();
    cout << endl;

    cout << "Number of Checkouts: " << book1.getCheckOuts() << endl;
    cout << "Number of Checkouts: " << book2.getCheckOuts() << endl;

    return 0;
}
