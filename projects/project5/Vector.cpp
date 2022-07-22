//
//  Vector.cpp
//  Project 5 - Templates
//
//  Created by Nathenael Dereb on 2/8/21.
//
/*****************************************
** File:    Vector.cpp
** Project: CMSC 202 Project 5, Spring 2021
** Author:  Gurjinder Singh
** Date:    5/1/2021
** Discussion-Section: 33
** E-mail:  gsingh10@umbc.edu
**
** semi-completion of vector.cpp
**
***********************************************/

#ifndef VECTOR_CPP
#define VECTOR_CPP

#include <string>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

template <class T>
struct Node {
public:
    Node(T value) {
        m_value = value;
        next = nullptr;
    }

    Node(T value, Node* _next) {
        m_value = value;
        next = _next;
    }

    T getValue() {
        return m_value;
    }

    Node<T>* getNextNode() {
        return next;
    }

    void setNextNode(Node<T>* newNode) {
        next = newNode;
    }

private:
    T m_value;
    Node<T>* next;
};


template <class T>
class Vector {
public:
    // Name: Default Constructor
    // Precondition: None (Must be templated)
    // Postcondition: Creates a vector using a linked list
    Vector();

    // Name: Destructor
    // Desc: Frees memory
    // Precondition: Existing Vector
    // Postcondition: Destructs existing Vector
    ~Vector();

    // Name: Copy Constructor
    // Desc: Copies an existing vector
    // Precondition: Existing Vector
    // Postcondition: Two identical vectors (in separate memory spaces)
    // Hint: Utilize overloaded [] operator
    Vector (Vector<T>* const& source);

    // Name: Overloaded Assignment operator
    // Desc: Assingns a vector
    // Precondition: Existing Vector
    // Postcondition: Assigns a vector
    // Hint: Utilize overloaded [] operator
    Vector<T>* operator=(Vector<T>* source);

    // Name: Overloaded [] operator
    // Desc: to retrive use [indx]
    // Precondition: Existing Vector
    // Postcondition: Returns the value of the element at the given index
    T operator[](int indx);

    // Name: Insert
    // Desc: insert a node to the end of the vector
    // Precondition: Existing Vector
    // Postcondition: A vector with the newly added value
    void Insert(T);

    // Name: SortedInsert
    // Desc: Inserts a node into the vector at it's correct position (sorted ascendingly)
    // Precondition: Existing Vector
    // Postcondition: sorted vector (low to high)
    void SortedInsert(T);

    // Name: Remove
    // Desc: removes a node from the vector
    // Precondition: Existing Vector
    // Postcondition: A vector that holds the results of the vectors added
    void Remove(int indx);

    // Name: Overloaded + operator | Vector Addition
    // Desc: Adds two vectors and returns the result
    // Precondition: Existing Vector, vectors can be of different size
    // Postcondition: A vector that holds the results of the vectors added
    Vector<T>* operator+(Vector<T>& source);

    // Name: Overloaded * operator | Vector Multiplication
    // Desc: Multiplys two vectors and returns the result
    // Precondition: Existing Vector, vectors can be of different size
    // Postcondition: returns a vector that holds the results of the vectors multiplied
    Vector<T>* operator*(Vector<T>& other);

    // Name: Overloaded < operator | Vector Comparision
    // Desc: Compares two vectors [using the < operator] and returns the result
    // Precondition: Existing Vector -> vectors need to be of the same size
    // Postcondition: returns a vector that holds the boolean char (T or F) value of each node comparison
    Vector<char>* operator<(Vector<T>& other);

    // Name: Overloaded == operator | Vector Comparision
    // Desc: Compares two vectors [using the == operator] and returns the result
    // Precondition: Existing Vector, vectors need to be of the same size
    // Postcondition: returns a vector that holds the boolean char (T or F) value of each node comparison
    Vector<char>* operator==(Vector<T>& other);

    // Name: Size
    // Desc: number of nodes in Vector
    // Precondition: Existing Vector
    // Postcondition: returns the size of the vector
    int Size();

    // Name: Display
    // Desc: displays the contents of the vector
    // Precondition: Existing Vector
    // Postcondition: prints to console the contents of Vector
    void Display();

    // Name: median
    // Desc: Computes the median of the vector
    // Precondition: Existing Vector
    // Postcondition: returns the median value
    float Median();

    // Name: Mean
    // Desc: Computes the mean of the vector
    // Precondition: Existing Vector
    // Postcondition: returns the mean value
    float Mean();

    // Name: StDev
    // Desc: Computes the standard derivation of the vector
    // Precondition: Existing Vector
    // Postcondition: returns the standard derivation
    float StDev();

private:
    Node<T>* m_head;
};


// **** Add class definition below ****

// Name: Default Constructor
// Precondition: None (Must be templated)
// Postcondition: Creates a vector using a linked list
template <class T>
Vector<T>::Vector() {
    m_head = nullptr;
}

// Name: Destructor
// Desc: Frees memory
// Precondition: Existing Vector
// Postcondition: Destructs existing Vector
template <class T>
Vector<T>::~Vector() {//loop, derefernece and delete every node
    Node<T>* current = m_head;
    while (current != nullptr) {
        Node<T>* next = current->getNextNode();
        delete current;
        current = next;
    }
    m_head = nullptr;
}

// Name: Copy Constructor
// Desc: Copies an existing vector
// Precondition: Existing Vector
// Postcondition: Two identical vectors (in separate memory spaces)
// Hint: Utilize overloaded [] operator
template <class T>
Vector<T>::Vector(Vector<T>* const& source) {

}

// Name: Overloaded Assignment operator
// Desc: Assingns a vector
// Precondition: Existing Vector
// Postcondition: Assigns a vector
// Hint: Utilize overloaded [] operator
template <class T>
Vector<T>* Vector<T>::operator=(Vector<T>* source) {
    if (this != source) {
        for (int i = 0; i < source->Size(); i++) {//loops every item and adds it by using Sorted item
            SortedInsert(source->operator[](i));
        }
    }

    return this;


}

// Name: Overloaded [] operator
// Desc: to retrive use [indx]
// Precondition: Existing Vector
// Postcondition: Returns the value of the element at the given index
template <class T>
T Vector<T>:: operator[](int indx) {
    T out;
    int counter = 0;
    bool flag = true;
    Node<T>* current = m_head;
    while (current != nullptr && flag) {
        if (counter == indx) {// if index is = to current counter then you have your output
            out = current->getValue();
            flag = false;
        }
        current = current->getNextNode();
        counter++;
    }
    return out;
}

// Name: Insert
// Desc: insert a node to the end of the vector
// Precondition: Existing Vector
// Postcondition: A vector with the newly added value

template <class T>
void Vector<T>::Insert(T node) {//basically pushback
    Node<T>* newNode = new Node<T>(node);
    Node<T>* last = m_head;
    newNode->setNextNode(nullptr);

    if (m_head == nullptr) {
        m_head = newNode;//sets head to the new node
    } else {
        while (last->getNextNode() != nullptr) {//itterate last node until null
            last = last->getNextNode();
        }
    }
}

// Name: SortedInsert
// Desc: Inserts a node into the vector at it's correct position (sorted ascendingly)
// Precondition: Existing Vector
// Postcondition: sorted vector (low to high)
template <class T>
void Vector<T>::SortedInsert(T data) {
    Node<T>* newNode = new Node<T>(data);//make new node w data
    Node<T>* current = m_head;
    if (m_head == nullptr || m_head->getValue() >= newNode->getValue()) {
        newNode->setNextNode(m_head);//sets newnodes next node
        m_head = newNode;
        return;//exit if statement
    }
    while (current->getNextNode() != nullptr && current->getNextNode()->getValue() < newNode->getValue()) {//if not null, and current val is less than new value, put it infront of old val
        current = current->getNextNode();
    }
    newNode->setNextNode(current->getNextNode());
    current->setNextNode(newNode);
}

// Name: Remove
// Desc: removes a node from the vector
// Precondition: Existing Vector
// Postcondition: A vector that holds the results of the vectors added
template <class T>
void Vector<T>::Remove(int indx) {
    Node<T>* prev = m_head;
    Node<T>* next = nullptr;
    Node<T>* current = m_head;
    int count = 0;
    if (indx == 0) {//base statement
        if (m_head->getNextNode() == nullptr) {
            m_head = nullptr;
        }
    } else {
        count++;
        bool flag = true;
        while (flag) {
            if (current->getNextNode() == nullptr) {
                flag = false;
            }
            if (count == indx) {
                current = nullptr;
                delete current;
                prev->setNextNode(next);
                flag = false;
            }
            if (count == 1) {
                next = current->getNextNode();
                current = current->getNextNode();
            } else {
                prev = prev->getNextNode();
                next = current->getNextNode();
                current = current->getNextNode();
            }
            count++;
        }
    }
}

// Name: Overloaded + operator | Vector Addition
// Desc: Adds two vectors and returns the result
// Precondition: Existing Vector, vectors can be of different size
// Postcondition: A vector that holds the results of the vectors added
template <class T>
Vector<T>* Vector<T>::operator+(Vector<T>& source) {
    Vector<T>* output = new Vector<T>();
    for (int i = 0; i < source.Size(); i++) {//loops and adds to vector
        T first = this->operator[](i);
        T second = source.operator[](i);
        T result = first + second;
        cout << result;
        output->SortedInsert(result);
    }
    return output;
}

// Name: Overloaded * operator | Vector Multiplication
// Desc: Multiplys two vectors and returns the result
// Precondition: Existing Vector, vectors can be of different size
// Postcondition: returns a vector that holds the results of the vectors multiplied
template <class T>
Vector<T>* Vector<T>::operator*(Vector<T>& source) {
    Vector<T>* output = new Vector<T>();
    for (int i = 0; i < source.Size(); i++) {//loops and adds to vector
        T first = this->operator[](i);
        T second = source.operator[](i);
        T result = first * second;
        cout << result;
        output->SortedInsert(result);
    }
    return output;
}

// Name: Overloaded < operator | Vector Comparision
// Desc: Compares two vectors [using the < operator] and returns the result
// Precondition: Existing Vector -> vectors need to be of the same size
// Postcondition: returns a vector that holds the boolean char (T or F) value of each node comparison
template <class T>
Vector<char>* Vector<T>::operator<(Vector<T>& other) {
    return nullptr;
}

// Name: Overloaded == operator | Vector Comparision
// Desc: Compares two vectors [using the == operator] and returns the result
// Precondition: Existing Vector, vectors need to be of the same size
// Postcondition: returns a vector that holds the boolean char (T or F) value of each node comparison
template <class T>
Vector<char>* Vector<T>::operator==(Vector<T>& other){
    Vector<char>* output;
    int m_size = Size();
    int other_size = other.Size();
    Node<T>* m_current = m_head;
    Node<T>* other_current = other.m_head;
    if (m_size == other_size) {
        while (m_current->getNextNode() != nullptr && other_current->getNextNode() != nullptr) {//loops and adds t/f if both of the values are the same until nullptr
            if (m_current == other_current) {
                output->Insert('T');
            } else {
                output->Insert('F');
            }
            m_current = m_current->getNextNode();
            other_current = other_current->getNextNode();
        }
    }
    m_current = nullptr;
    other_current = nullptr;
    return output;
}

// Name: Size
// Desc: number of nodes in Vector
// Precondition: Existing Vector
// Postcondition: returns the size of the vector
template <class T>
int Vector<T>::Size(){
    int count = 1;
    Node<T>* current = m_head;
    while (current->getNextNode() != nullptr) {//while the temp variable isnt = to nullptr, size will = 0 if head is null
        current = current->getNextNode();
        count++;
    }
    current = nullptr;
    delete current;
    return count;
}

// Name: Display
// Desc: displays the contents of the vector
// Precondition: Existing Vector
// Postcondition: prints to console the contents of Vector
template <class T>
void Vector<T>::Display(){
    Node<T>* current = m_head;
    while (current != nullptr) {//loop and print each
        cout << current->getValue() << ", ";
        current = current->getNextNode();
    }
    cout << endl;
}

// Name: median
// Desc: Computes the median of the vector
// Precondition: Existing Vector
// Postcondition: returns the median value
template <class T>
float Vector<T>::Median(){
    float output = 0;
    T first;
    T second;
    int size = Size();
    if (this->Size()%2 == 0) {
        output = this->operator[](size/2);
    } else {
        first = this->operator[]((size-1)/2);
        second = this->operator[](size/2);
        output = (first + second) / 2.0;
    }
    return output;
}

// Name: Mean
// Desc: Computes the mean of the vector
// Precondition: Existing Vector
// Postcondition: returns the mean value
template <class T>
float Vector<T>::Mean(){
    float output = 0;
    for (int i = 0; i < this->Size(); i++) {//loop every number, add it, then divide by its size
        output = output + this->operator[](i);
    }
    output = output/this->Size();

    return output;
}

// Name: StDev
// Desc: Computes the standard derivation of the vector
// Precondition: Existing Vector
// Postcondition: returns the standard derivation
template <class T>
float Vector<T>::StDev(){
    float output = 0;
    Node<T>* current = m_head;
    return 0;
}








#endif /* VECTOR_CPP */
