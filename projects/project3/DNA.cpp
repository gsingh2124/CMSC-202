/*****************************************
** File:    DNA.cpp
** Project: CMSC 202 Project 3, Spring 2021
** Author:  Gurjinder Singh
** Date:    4/3/2021
** Discussion-Section: 33
** E-mail:  gsingh10@umbc.edu
**
** DNA class for project 3
**
***********************************************/
#include "DNA.h"
// Name: DNA() - Default Constructor
// Desc: Used to build a new DNA sequence
// Preconditions: None
// Postconditions: Creates a new DNA where m_head and m_tail point to nullptr
DNA::DNA() {
    m_head = nullptr;
    m_tail = nullptr;
    m_name = "N/A";
}
// Name: DNA(string) - Overloaded Constructor
// Desc: Used to build a new DNA sequence with the name passed
// Preconditions: None
// Postconditions: Creates a new DNA where m_head and m_tail point to nullptr and name is passed
DNA::DNA(string name){
    m_head = nullptr;
    m_tail = nullptr;
    m_name = name;
}
// Name: ~DNA() - Destructor
// Desc: Used to destruct a strand of DNA
// Preconditions: There is an existing DNA strand with at least one node
// Postconditions: DNA is deallocated (including all dynamically allocated nodes)
//                 to have no memory leaks!
DNA::~DNA(){
    Node *curr = m_head;
    while(curr != nullptr){ //Iterates through and removes each node
        m_head = curr; //sets m_head to curr
        curr = curr ->m_next; //moves curr to next node
        delete m_head; //delete m_head;
    }
    //Resets all of the static linked list pointers
    m_name="";
    m_head = nullptr; //Sets the pointer to point at nothing
    m_tail = nullptr; //Sets the pointer to point at nothing
    m_size = 0; //Sets the size of the linked list to 0
    delete curr;
}
// Name: InsertEnd
// Preconditions: Takes in a char. Creates new node.
//                Requires a DNA strand
// Postconditions: Adds the new node to the end of the DNA strand.
void DNA::InsertEnd(char data){
    //initilize temp node with data and empty next (to assume first)
    Node *temp = new Node();
    temp->m_data = data;
    temp->m_next = nullptr;

    if (m_head == nullptr) {//if node being added is the first node, set head and tail to new node
        m_head = temp;
        m_tail = temp;
        m_size = 1;//first node scenario
    } else {//if node being added is not first, create a next with temp node for the tail, set new tail
        m_tail->m_next = temp;
        m_tail = m_tail->m_next;
        m_size++;//every nth node scenario
    }
}
// Name: GetName()
// Preconditions: Requires a DNA sequence
// Postconditions: Returns m_name;
string DNA::GetName(){
    return m_name;
}
// Name: GetSize()
// Preconditions: Requires a DNA sequence
// Postconditions: Returns m_size;
int DNA::GetSize(){
    return m_size;
}
// Name: ReverseSequence
// Preconditions: Reverses the DNA sequence
// Postconditions: DNA sequence is reversed in place; nothing returned
void DNA::ReverseSequence(){
    Node *head = m_head;
    Node *tail = m_tail;
    Node *current = m_head;
    Node *previous = nullptr;
    Node *next;
    while(current != nullptr) {
        next = current->m_next;
        current->m_next = previous;
        previous = current;
        current = next;
    }
    m_head = tail;
    m_tail = head;

}
// Name: CompareSequence
// Preconditions: Requires two DNA sequence (suspect and passed evidence DNA)
// Postconditions: Returns true if evidence sequence exists; else false
bool DNA::CompareSequence(DNA &evidence){
    Node* evid = evidence.m_head;
    Node* curr = m_head;
    Node* node1 = evid, *node2 = curr;
    bool flag = true;//determines when to continue looping in while and when to stop

    while (curr != nullptr) {//loop till the end of the current sequence(should a suspect sequence always)
        node2 = curr;//resets suspect node to the current evidence node to recheck on next pass
        flag = true;
        while (node1 != nullptr && flag)
        {

            if (node2 == nullptr) {//if you reach the end of the suspect list before the end of the evidence list its not a match
                return false;
            } else if (node1->m_data == node2->m_data) {//if the nodes are the same from the evidence and suspect list, move to the next nodes to check the next ones
                node1 = node1->m_next;
                node2 = node2->m_next;
            } else {
                flag = false;
            }
        }
        if (node1 == nullptr) {//if you are able to traverse evidence to its tail, then its a match
            return true;
        }
        node1 = evid;//reset node 1 with evidence node again
        curr = curr->m_next;//move to next node for next itteration
    }
    return false;
}
// Name: GetData
// Desc: Returns the data at a specific location in the DNA sequence
// Preconditions: Requires a DNA sequence
// Postconditions: Returns a single char from a node
char DNA::GetData(int nodeNum){
    Node *temp = m_head;//create temp node to itterate with
        for (int i = 0; i < nodeNum; i++) {//itterate until provided number of times
            if (i != 0) {
                temp = temp->m_next;//set temp to the next node until loop ends
            }
        }
        char out = temp->m_data;
        return out;//return whatever node landed on
}

ostream &operator<< (ostream &output, DNA &myDNA) {//output formatting for everyhting really
    output << myDNA.m_name << endl;
    for (int i = 0; i < myDNA.GetSize() + 1; i++) {
        if (i != 0) {
            output << myDNA.GetData(i) << "->";
        }
    }
    output << "END" << endl;
    return output;
}