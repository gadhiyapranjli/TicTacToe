#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include "Board.hpp"
#include "Player.hpp"

class TicTacToe {
public:
    Board board;
    Player playerX;
    Player playerO;

    TicTacToe();
    void play();
    void regularPlay();
    void battlePlay();
    void battleDescription();
    void battleChooseArchetypes();
    bool swarmWinCondition();
    bool validArchetype(const std::string& archetype);
};

#endif
