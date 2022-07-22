#include "Book.h"

//Constructor -- Already Implemented
Book::Book() {
  cout << "Creating a book..." << endl;
  m_bookName = "book";
  m_isHardcover = false;
  m_numCheckOuts = 0;
}

//Here is an example for a getter and a setter

int Book::getCheckOuts() {
  return m_numCheckOuts;
}

void Book::setCheckOuts(int numTimes) {
  //If number of check-outs is greater than 6, set to 6.
  if (numTimes > 6){
    m_numCheckOuts = 6;
  } else {
    m_numCheckOuts = numTimes;
  }
}

//**Student Requirement**
//Implement getters and setters for bookName and isHardCover here
string Book::getBookName() {
    return m_bookName;
}

void Book::setBookName(string name) {
    m_bookName = name;
}

bool Book::isHardCover() {
    return m_isHardcover;
}

void Book::setHardCover(bool value) {
    m_isHardcover = value;
}

//**Student Requirement**
//Custom Functions -- Implement checkHardCover and addCheckOut
void Book::checkHardcover() {
    if (m_isHardcover) {
        cout << m_bookName << " is a hardcover book!";
    } else {
        cout << m_bookName << " is a paperback book!";
    }
}

bool Book::addCheckout() {
    if (m_numCheckOuts == 6) {
        return false;
    } else {
        m_numCheckOuts++;
        return true;
    }
}