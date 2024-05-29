#include <iostream>
#include <algorithm> 
#include "Dungeon.h"
#include <ctime> 
#include <vector>
using namespace std;

Dungeon::Dungeon(int difficulty) {
    static bool seeded = false; // Should only be called once
    if (!seeded) {
        srand(time(nullptr));
        seeded = true;
    }

    //Available rooms for each difficulty level
    vector<int> availableRooms;
    // Assign the rooms based on the difficulty level
    switch (difficulty) {
    case 1:
        availableRooms = { 1, 2, 1, 2, 3, 1, 2, 1, 2, 3 }; // 10 rooms
        break;
    case 2:
        availableRooms = { 1, 2, 2, 2, 2, 2, 1, 1, 2, 3, 1, 2, 2, 2, 2, 2, 1, 1, 2, 3 }; /// 20 rooms
        break;
    case 3:
        availableRooms = { 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 }; // 30 rooms
        break;
    default:
        cerr << "Invalid difficulty level." << endl;
        break;
    }

    // Shuffle the available rooms
    random_shuffle(availableRooms.begin(),availableRooms.end());

    /// Assign the shuffled rooms directly to roomVector
    roomVector = availableRooms;
}

//  Get the number of rooms in the dungeon
int Dungeon::getDungeonRoom(int rooms) const {
    if (rooms >= 0 && rooms < roomVector.size()) {
        return roomVector[rooms];
    }
    else {

        cerr << "Invalid room" <<  endl;
        return -1; 
    }
}
 

