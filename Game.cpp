#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Rooms.h"
#include "Enemy.h"
#include "Dungeon.h"
#include "Monk.h"
using namespace std;

// Function to print the text file.
void printTxt(const string& file) {
    ifstream inFile(file);
    if (!inFile) {
        cout << "Error! File not found!" << endl;
    }
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
}


int main(int option) {
    /// Present main menu
    printTxt("Menu.txt");
    cout << "[1] to Start Game\n[2] to Exit:\n" << endl;
    cout << "Input: ";

    // Get valid menu option
    while (!(cin >> option) || option < 1 || option > 2) {
        cout << "Invalid Selection. Please enter 1 or 2." << endl;
        cin.clear(); // Clear
        cin.ignore ('\n'); 
        cout << "Selection: ";
    }

    if (option == 1) {
        string monkName, monkDescription;
        system("CLS"); /// Clear the console
        printTxt("Menu.txt");

        /// Player inputs for creating their Monk character
        cout << "Create Your Monk:\n";
        cout << "Name: "; // Get Monk name
        cin.ignore(); 
        getline(cin, monkName);
        cout << "Description: "; //Get Monk Description
        getline(cin, monkDescription);
        Monk Monk(monkName, monkDescription); /// Create Monk object

        // Difficulty selection
        int difficulty;
        system("CLS"); 
        printTxt("Difficulty.txt");
        cout << "Input difficulty level: ";
        while (!(cin >> difficulty) || difficulty < 1 || difficulty > 3) {
            cout << "Invalid Difficulty. Please enter a number between 1 and 3." << endl;
            cin.clear(); 
            cin.ignore('\n'); 
            cout << "Difficulty Level (1-3): ";
        }

        system("CLS"); 

        /// Initialize dungeon with chosen difficulty
        Dungeon dungeonInstance(difficulty);
        vector<Rooms> dungeonRooms; // Using vector for rooms

        for (int i = 0; i < difficulty * 10; i++) {
            int room = dungeonInstance.getDungeonRoom(i);
            dungeonRooms.emplace_back(room, Monk, difficulty); 
        }
    }
    else {
        exit(1); 
    }

    return 0;
}
