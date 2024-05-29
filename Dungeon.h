#pragma once
#include <string>
#include <vector>
using namespace std;

class Dungeon {
private:
    vector<int> roomVector;

public:
    Dungeon(int difficulty);
    int getDungeonRoom(int rooms) const;
};
