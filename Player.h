#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
#include <string>

class Player {
public:
    char mark;
    Player(char m);
    int getMove(Board* board);
};

#endif
