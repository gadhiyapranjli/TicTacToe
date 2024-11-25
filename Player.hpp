#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "Board.hpp"

class Player {
public:
    char mark;
    std::string archetype;
    Player(char m);
    int getMove(Board* board);
    bool pyromancerSpecialMove(Board* board);
};

#endif
