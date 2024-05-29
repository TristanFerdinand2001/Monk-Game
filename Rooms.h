#pragma once
#include "Monk.h"
#include <string>

class Rooms {
private:
    int room;
    int difficulty;

public:
    void EmptyRoom(Monk& m);
    void TreasureRoom();
    void MonsterRoom(Monk& m, int difficulty);
	// Function to handle the different rooms
    Rooms(int room, Monk& m, int difficulty);

};


