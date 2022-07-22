
/*****************************************
** File:    project1.cpp
** Project: CMSC 202 Project 1, Spring 2021
** Author:  Gurjinder Singh
** Date:    2/25/2021
** Discussion-Section: 33
** E-mail:  gsingh10@umbc.edu
**
** Hangman game, not extra credit but yea its the thought that counts.
**
***********************************************/





#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int GUESS_LIMIT = 6;//guess limit for like 1 computation why did i even make this a constant

//Input, String letter that the user is guessing
//Input, String word to look in
//Output, true/false based on if the letter exists in the word
int guessLetter(char letter, string word) {
    int flag = 0;
    int len = word.length();
    for (int i = 0; i < len; i++) {
        if (int(word[i]) == int(letter)) {
            flag = 1;
        }
    }
    return flag;
}

//Input, String word that needs to be worked on
//Input, String letter that needs to be removed from the word
//Output, String with letter removed from word (works in conjunction with guessLetter())
string removeLetter(char letter, string word) {
    string out = word;
    int indexArray[word.length()];
    int len = word.length();
    for (int i = 0; i < len; i++) {
        if (int(word[i]) == int(letter)) {
            indexArray[i] = 2;
        }
    }
    for (int i = 0; i < len; i++) {
        if (indexArray[i] == 2) {
            out[i] = '*';
        }
    }
    return out;
}
//Input, modWord that replaces correct guesses with *
//output, true or false
//logic returns true or false based on weather all of the letters are asteriks (indicating competion)
bool checkComplete(string modWord) {
    bool flag = true;
    int len = modWord.length();
    for (int i = 0; i < len; i++) {
        if (modWord[i] != '*') {
            flag = false;
        }
    }
    return flag;
}

//Input, modWord that replaces correct guesses with *
//Output, the number of letters remaining to guess
int getRemainingCount(string modWord) {
    int count = 0;
    int len = modWord.length();
    for (int i = 0; i < len; i++) {
        if (modWord[i] != '*') {
            count = count + 1;
        }
    }
    return count;
}

//input, modWord that replaces correct guesses with *
//input, word is the original word unmodified
//output replaces asteriks with letters, and letters with ___'s for visuals
string generateDispWord(string modWord, string word) {
    string out = "";
    int len = modWord.length();
    for (int i = 0; i < len; i++) {
        if (int(modWord[i]) == int('*')) {
            out = out + word[i];
        } else {
            out = out + "_";
        }
    }
    out = out + "\n";
    return out;
}

//Input, none
//Output, word to use for the current game
//Function loads the words.txt file from the local directory and then returns a randomly chosen word
string loadFile() {
    srand(time(NULL));
    int countWords = 0;
    string currentLine;
    ifstream words;

    words.open("words.txt");

    if(words.is_open()) {
        while(words >> currentLine) {
            countWords = countWords + 1;
        }
        words.close();
        string wordsList[countWords];
        words.open("words.txt");

        cout << "Your file was imported!" << endl;
        cout << countWords << " words imported." << endl;

        countWords = 0;
        while(words >> currentLine) {
            wordsList[countWords] =  currentLine;
            countWords = countWords + 1;
        }
        return wordsList[rand() % (countWords)];//returns random word from array of all possible words imported from ^^
    } else {
        cout << "File was unable to be imported, make sure its named words.txt" << endl;
        string error = "error";
        return error;
    }
}

//Function that runs the game
void playGame() {
    char userIn;//store user input
    string word = "";//word from list
    cout << "Welcome to UMBC Word Guess" << endl;
    word = loadFile();//assigning a random word
    string dispWord;//string that shows the underscores and found letters
    string modWord = word;//word stored internally that gets the letters replaced with * if guessed correctly.
    int incorrectGuesses = 0;

    while (userIn != '0') {
        dispWord = generateDispWord(modWord, word); // updating the lines after each pass


        cout << getRemainingCount(modWord) << " letters remain" << endl;
        cout << dispWord;
        cout << "Ok. I am thinking of a word with " << word.length() << " letters." << endl;
        cout << "What letter would you like to guess?" << endl;
        cin >> userIn;


        if (isupper(userIn)) {//input validation for user guesses (all lower)
            do {
                cout << "What letter would you like to guess?" << endl;
                cin >> userIn;
            } while (isupper(userIn));
        }


        if (userIn != '0') {//guesses the user makes, applies logic and modifies modword and incorrect guesses for the next moves
            if (guessLetter(userIn, modWord) == 1) {
                modWord = removeLetter(userIn, modWord);
            } else {
                cout << "There are no " << userIn << " in the puzzle" << endl;
                incorrectGuesses = incorrectGuesses + 1;
                cout << "You have " << GUESS_LIMIT-incorrectGuesses << " bad guesses left." << endl;
            }
        } else {//exit case
            userIn = '0';
        }

        if (checkComplete(modWord)) {//congrats message for winning
            userIn = '8';
            cout << "Congrats! You guessed the word " << word << " correctly!" << endl;
            cout << "It took " << incorrectGuesses << " bad guesses to get it right!" << endl;

            do {//replay game loop
                cout << "\n\n\n" << "Would you like to play again y/n?" << endl;
                cin >> userIn;
                if (userIn == 'n') {
                    userIn = '0';
                } else if (userIn == 'y') {
                    incorrectGuesses = 0;
                    word = loadFile();
                    modWord = word;
                    userIn = '9';
                }
            } while (userIn != '9' && userIn != '0');
        } else if (incorrectGuesses == 6) {//message for losing the game
            userIn = '8';
            cout << "You guessed incorrectly 6 times. Game over." << endl;

            do {//replay game loop
                    cout << "\n\n\n" << "Would you like to play again y/n?" << endl;
                    cin >> userIn;
                    if (userIn == 'n') {
                    userIn = '0';
                } else if (userIn == 'y') {
                    incorrectGuesses = 0;
                    word = loadFile();
                    modWord = word;
                    userIn = '9';
                }
            } while (userIn != '9' && userIn != '0');
        }
    }

}

int main() {
    playGame();
    return 0;
}


