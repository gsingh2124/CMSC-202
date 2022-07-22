/**********
* File: Book.h
* Intended for Lab 5: Classes
**********/

#ifndef BOOK_H //Header or Include Guards
#define BOOK_H //Header or Include Guards

#include <iostream>
#include <string>
using namespace std;

class Book {
public:
  //Default constructor, already implemented.
  Book();
  
  //**Student Requirement**
  //Do the prototype for each of the functions described in the lab document
  
  //Returns name of the book
    string getBookName();
  
  //Sets name of the book
    void setBookName(string name);
  
  //Returns if book is hard cover or not
    bool isHardCover();
  //Sets hard cover boolean
    void setHardCover(bool hardcover);

  //Returns the number of check-outs
    int getCheckOuts();

  //Sets the number of check-outs 
    void setCheckOuts(int num);
  
  //Outputs whether the book is hard cover or not
    void checkHardcover();
  
  //Adds one check-out to number of check-outs
    bool addCheckout();

private:
  //**Student Requirement**
  //Create the member variables below as described in the lab document
    //name of book
    //hard cover or not
    //number of check-outs
    string m_bookName;
    int m_numCheckOuts;
    bool m_isHardcover;
};

#endif //End of Header Guard
