#include "Rooms.h"
#include "Monk.h"
#include "Enemy.h"
#include "Goblin.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


// Function to print the text file.
void printRoom(const string& file) {
    ifstream inFile(file);
     if (!inFile) {
        cout << "Error! File not found!" << endl;
    }
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
}

//Function to handle the different rooms
Rooms::Rooms(int room, Monk& m, int difficulty)
{
    switch (room) {
    case 1:
        EmptyRoom(m);
        break;
    case 2:
        MonsterRoom(m, difficulty);
        break;
    case 3:
        TreasureRoom();
        break;
    }
}

    ///Generates a Goblin for the Monk to engage in combat with
    //This is based on the users selected difficulty
    Goblin goblinGenerator(int difficulty) {
        srand(time(0));
        int randomGoblin = rand() % 3 + 1;
        //Different types of Goblins
        switch (randomGoblin) {
        case 1:
            return Goblin("Goblin", 10, 2);
        case 2:
            return Goblin("Green Goblin", 12, 3);
        case 3:
            return Goblin("Giant Goblin", 15, 5);
        default:
            return Goblin("Goblin", 10, 2);
        }
    }

    // Checks the probability of an action's success
    bool actionCheck() {
        return rand() % 2 == 0;
    }


/// Handles the scenario when the Monk enters an empty room
	void Rooms::EmptyRoom(Monk& m) {
		auto promptForAction = [&]() {
            printRoom("EmptyRoom.txt");
			cout << "Player Details:\nName: " << m.getName() << " | HP: " << m.getCurrentHP() << "/"
				<< m.getMaxHP() << " | AP: " << m.getMonkAP() << "\n";
			cout << "Input: ";
		};

		promptForAction();

		int input;
		cin >> input;
		// Input validation loop
		while (cin.fail() || input > 2 || input < 1) {
			cout << "Wrong Input!" << endl;
			cin.clear();
			cin.ignore('\n');
			promptForAction();
			cin >> input;
		}
		/// Handling the player's decision
		while (input != 2) {
			if (input == 1) {
				if (m.getCurrentHP() != m.getMaxHP()) {
					m.setCurrentHP(m.getMaxHP());
					cout << "HP restored!" << endl;
				}
				else {
					cout << "Unable to Use! Already at Max HP!" << endl;
				}
				promptForAction();
				cin >> input;
			}
		}
		system("CLS");
	}
    
	
	/// Handles the scenario when a Monk enters a room with a monster
    void Rooms::MonsterRoom(Monk& m, int difficulty) {
        //Enemy e = Goblin("Goblin", 10, 2); // alt to goblinGenerator
        Enemy e = goblinGenerator(difficulty); //Retrieves a Goblin object from goblinGenerator
        printRoom("MonsterRoom.txt");
        cout << "You entered a room with a " << e.getName() << " inside!\nYou have to defeat it before you can proceed to the next room!\n" << endl;
        // Displaying details of the player and the enemy
        cout << "Player Details:\nName: " << m.getName() << " | HP: " << m.getCurrentHP() << "/" << m.getMaxHP() << " | AP: " << m.getMonkAP() << "\n" << endl;
        cout << "Enemy Details:\nName: " << e.getName() << " | HP: " << e.getEnemyCurrentHP() << "/" << e.getEnemyMaxHP() << " | AP: " << e.getEnemyAP() << "\n" << endl;

        int turn = 0;

        /// Combat loop
        do {
            if (turn == 0) {
                cout << "It is the" << e.getName() << "'s turn!" << endl;
                if (e.getEnemyCurrentHP() > round(e.getEnemyMaxHP() * 0.75)) {
                    cout << e.getName() << " tries to attack you!" << endl;
                    if (actionCheck()) {
                        m.setCurrentHP(m.getCurrentHP() - e.getEnemyAP());
                        cout << e.getName() << " hit you for " << e.getEnemyAP() << " damage!" << endl;
                    }
                    else {
                        cout << e.getName() << " tried to attack you, but missed!" << endl;
                    }
                }
                else {
                    srand(time(0));
                    int action = rand() % 4;
                    if (action < 2) {
                        cout << e.getName() << " tries to attack you!" << endl;
                        if (actionCheck()) {
                            m.setCurrentHP(m.getCurrentHP() - e.getEnemyAP());
                            cout << e.getName() << " hit you for " << e.getEnemyAP() << " damage!" << endl;
                        }
                        else {
                            cout << e.getName() << " tried to attack you, but missed!" << endl;
                        }
                    }
                    else {
                        cout << e.getName() << " tries to heal itself!" << endl;
                        if (actionCheck()) {
                            e.setEnemyCurrentHP(e.getEnemyCurrentHP() + 1);
                            cout << e.getName() << " healed itself for 1 HP!" << endl;
                        }
                        else {
                            cout << e.getName() << " tried to heal itself, but failed!" << endl;
                        }
                    }
                }
                system("pause");
                system("CLS");
                printRoom("MonsterRoom.txt");
                cout << "Player Details:\nName: " << m.getName() << " | HP: " << m.getCurrentHP() << "/" << m.getMaxHP() << " | AP: " << m.getMonkAP() << "\n" << endl;
                cout << "Enemy Details:\nName: " << e.getName() << " | HP: " << e.getEnemyCurrentHP() << "/" << e.getEnemyMaxHP() << " | AP: " << e.getEnemyAP() << "\n" << endl;
                turn = 1;
            }

            // Player's turn
            if (turn == 1 && m.getCurrentHP() > 0) {
                int input;
                cout << "It is your turn!" << endl;
                cout << "1: Attack     2: Defence (restore 1 HP)" << endl;
                cout << "Input: ";
                cin >> input;
                while (cin.fail() || input > 2 || input < 1) {
                    cout << "Wrong Input!" << endl;
                    cin.clear();
                    cin.ignore('\n');
                    cout << "Input: ";
                    cin >> input;
                }
                while (input == 2 && m.getCurrentHP() == m.getMaxHP()) {
                    cout << "Unable to heal! Character already at full health!" << endl;
                    cin.clear();
                    cin.ignore('\n');
                    cout << "Input: ";
                    cin >> input;
                }

                // Handling the player's decision
                if (input == 1) {
                    cout << "You try to attack " << e.getName() << endl;
                    if (actionCheck()) {
                        e.setEnemyCurrentHP(e.getEnemyCurrentHP() - m.getMonkAP());
                        cout << "You hit " << e.getName() << " for " << m.getMonkAP() << " damage!" << endl;
                    }
                    else {
                        cout << "You tried to hit " << e.getName() << ", but missed!" << endl;
                    }
                }
                else if (input == 2 && m.getCurrentHP() != m.getMaxHP()) {
                    cout << "You tried to heal yourself!" << endl;
                    if (actionCheck()) {
                        m.setCurrentHP(m.getCurrentHP() + 1);
                        cout << "You have restored 1 HP!" << endl;
                    }
                    else {
                        cout << "You tried to heal, but failed!" << endl;
                    }
                }

                // Displaying player and enemy's details
                turn = 0;
                system("pause");
                system("CLS");
                printRoom("MonsterRoom.txt");
                cout << "Player Details:\nName: " << m.getName() << " | HP: " << m.getCurrentHP() << "/" << m.getMaxHP() << " | AP: " << m.getMonkAP() << "\n" << endl;
                cout << "Enemy Details:\nName: " << e.getName() << " | HP: " << e.getEnemyCurrentHP() << "/" << e.getEnemyMaxHP() << " | AP: " << e.getEnemyAP() << "\n" << endl;
            }
        } while (e.getEnemyCurrentHP() > 0 && m.getCurrentHP() > 0);


        // Check if the player or the enemy has lost
        if (e.getEnemyCurrentHP() <= 0) {
            cout << "You have defeated " << e.getName() << "! Now you can move to the next room!" << endl;
            system("pause");
            system("CLS");
        }
        else if (m.getCurrentHP() <= 0) {
            system("CLS");
            printRoom("Death.txt");
            exit(1);
        }
    }

    /// Monk enters the TreasureRoom/end of the game
    void Rooms::TreasureRoom() {
        printRoom("TreasureRoom.txt");
        exit(1);
    }

	
		