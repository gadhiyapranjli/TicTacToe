#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"

class TicTacToe {
public:
    Board board;
    Player playerX;
    Player playerO;

    TicTacToe();
    void play();
};

#endif 
