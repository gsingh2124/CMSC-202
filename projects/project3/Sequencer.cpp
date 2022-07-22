/*****************************************
** File:    Sequencer.cpp
** Project: CMSC 202 Project 3, Spring 2021
** Author:  Gurjinder Singh
** Date:    4/3/2021
** Discussion-Section: 33
** E-mail:  gsingh10@umbc.edu
**
** Sequencer class for project 3
**
***********************************************/
#include "Sequencer.h"
// Name: Sequencer (constructor)
// Desc: Creates a Sequencer to hold multiple DNA strands from a file
// Preconditions:  None
// Postconditions: A sequencer created to populate m_suspects and m_evidence
Sequencer::Sequencer(string fileName) {
    m_fileName = fileName;
    ReadFile();
    MainMenu();
}
// Name:  Sequencer (destructor)
// Desc: Deallocates all dynamic aspects of a Sequencer
// Preconditions: There is an existing DNA strand (linked list)
// Postconditions: All vectors are cleared of DNA strands
Sequencer::~Sequencer(){
    cout << "Deleting evidence" << endl;
    for (long unsigned int i = 0; i < m_evidence.size(); i++) {
        delete m_evidence[i];
    }
    cout << "Deleteing suspects" << endl;
    for (long unsigned int i = 0; i < m_suspects.size(); i++) {
        delete m_suspects[i];
    }
}
// Name:  DisplayStrands
// Desc: Displays each strand in both m_suspects and m_evidence
// Preconditions: At least one linked list is in either m_suspects or m_evidence
// Postconditions: Displays DNA strand from one of the vectors
void Sequencer::DisplayStrands(){
    if (m_suspects.size() > 0) {
        for (long unsigned int i = 0; i < m_suspects.size(); i++) {
            cout << *m_suspects[i];
        }
    }
    if (m_evidence.size() > 0) {
        for (long unsigned int i = 0; i < m_evidence.size(); i++) {
            cout << *m_evidence[i];
        }
    }
}
// Name:  ReadFile
// Desc: Reads in a file that has the name on one line then the sequence on the next
//       All sequences will be an indeterminate length. There are an indeterminate number of
//       sequences in a file. Hint: Read in the entire sequence into a string then go char
//       by char until you hit a new line break. Then insert to the correct vector
// Preconditions: Valid file name of characters (Either A, T, G, or C)
// Postconditions: Populates each DNA strand and puts in either m_suspects or m_evidence
void Sequencer::ReadFile(){
    ifstream myfile;
    myfile.open(m_fileName); //Declares and opens a file
    string name = "";
    string sequence = "";
    int count = 0;
    int suspectCount = 0;
    int evidenceCount = 0;
    if (myfile.is_open()) { //Checks to see if the file exists and was opened
        while(getline(myfile,name,'\n')){ //Keeps reading as long as there is another line
            count++;
            getline(myfile,sequence,'\n');
            DNA *suspect = new DNA(name);
            DNA *evidence = new DNA(name);
            if (name[0] == 'S') {
                for (long unsigned int i = 0; i < sequence.size(); i++) {
                    if (sequence[i] == 'A' || sequence[i] == 'T' || sequence[i] == 'G' || sequence[i] == 'C') {
                        suspect->InsertEnd(sequence[i]);
                    }
                }
                suspectCount++;
                m_suspects.push_back(suspect);
                name = "";
                sequence = "";
            } else if (name[0] == 'E') {
                for (long unsigned int i = 0; i < sequence.size(); i++) {
                    if (sequence[i] == 'A' || sequence[i] == 'T' || sequence[i] == 'G' || sequence[i] == 'C') {
                        evidence->InsertEnd(sequence[i]);
                    }
                }
                evidenceCount++;
                m_evidence.push_back(evidence);
                name = "";
                sequence = "";
            }
        }
    } else {
        cout << "Unable to open file"; //If the input file does not exist, notifies user
    }
    myfile.close();
    cout << "File opened" << endl;
    cout << count << " strands loaded" << endl;
}
// Name:  MainMenu
// Desc: Displays the main menu and manages exiting
// Preconditions: Populated m_suspects and m_evidence
// Postconditions: None
void Sequencer::MainMenu(){
    int input = 0;
    bool flag = true;
    while (flag) {
        cout << "What would you like to do?: " << '\n'
             << "1. Display Strand" << '\n'
             << "2. Reverse Sequence" << '\n'
             << "3. Check Suspects" << '\n'
             << "4. Exit" << endl;
        cin >> input;
        switch (input){

            case 1:

                cout << endl;
                DisplayStrands();
                cout << endl;
                break;

            case 2:
                ReverseSequence();
                break;

            case 3:
                cout << endl;
                CheckSuspects();
                cout << endl;
                break;

            case 4:

                cout << endl;
                cout << "Exiting...";
                cout << endl;
                flag = false;
                break;

        }
    }
}
// Name:  CheckSuspects
// Desc: Iterates through each DNA strand in m_suspects to see if there is a match from
//       m_evidence. Displays each suspect strand where the evidence matches
// Preconditions: Populated m_suspects and m_evidence
// Postconditions: Displays each suspect that has a match
void Sequencer::CheckSuspects(){
    long unsigned int count;
    for (long unsigned int i = 0; i < m_suspects.size(); i++) {
        count = 0;
        for (long unsigned int j = 0; j < m_evidence.size(); j++) {
            if (m_suspects[i]->CompareSequence(*m_evidence[j]) == true) {
                count++;
                cout << "Suspect" << i+1 << " matchs Evidence" << j+1 << endl;
            }
            if (m_suspects[i]->CompareSequence(*m_evidence[j]) == false) {
                cout << "Suspect" << i+1 << " does NOT match with Evidence" << j+1 << endl;
            }
            if (count == m_evidence.size()) {
                cout << "Suspect" << i+1 << " matches ALL Evidence!" << endl;
            }
        }
    }
}
// Name: ReverseSequence
// Desc: User chooses a sequence from m_suspects or m_evidence and the sequence is reversed
// Preconditions: Populated m_suspects and m_evidence
// Postconditions: Reverses a specific sequence replacing in place
void Sequencer::ReverseSequence(){
    long unsigned int reverseInput = 0;
    long unsigned int suspectInput = 0;
    long unsigned int evidenceInput = 0;
    bool reverseFlag = true;
    bool suspectFlag = true;
    bool evidenceFlag = true;
    while (reverseFlag) {
        cout << endl;
        cout << "Which type of sequence to reverse?" << endl;
        cout << "1. Suspect" << endl;
        cout << "2. Evidence" << endl;
        cin >> reverseInput;
        cout << endl;

        if (reverseInput == 1) {
            if (m_suspects.size() == 1) {
                m_suspects[0]->ReverseSequence();
                reverseFlag = false;
            } else {
                while (suspectFlag) {
                    cout << endl;
                    cout << "Which sequence to reverse?" << endl;
                    cout << "Choose 1 - " << m_suspects.size() << endl;
                    cin >> suspectInput;
                    cout << endl;
                    if (suspectInput >= 1 || suspectInput <= m_suspects.size()) {
                        m_suspects[suspectInput-1]->ReverseSequence();
                        suspectFlag = false;
                        reverseFlag = false;
                    }
                }
            }
        } else if (reverseInput == 2) {
            if (m_evidence.size() == 1) {
                m_evidence[0]->ReverseSequence();
                reverseFlag = false;
            } else {
                while (evidenceFlag) {
                    cout << endl;
                    cout << "Which sequence to reverse?" << endl;
                    cout << "Choose 1 - " << m_evidence.size() << endl;
                    cin >> evidenceInput;
                    cout << endl;
                    if (evidenceInput >= 1 || evidenceInput <= m_evidence.size()) {
                        m_evidence[evidenceInput-1]->ReverseSequence();
                        evidenceFlag = false;
                        reverseFlag = false;
                    }
                }
            }
        }
    }
    //just an interface over dna reversesequence function
}