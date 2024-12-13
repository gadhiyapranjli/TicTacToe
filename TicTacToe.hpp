#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include "Board.hpp"
#include "Player.hpp"
#include <string>

class TicTacToe {
private:
    Board board;
    Player playerX, playerO;
    static int gamesPlayed;
    static int playerOneWins;
    static int playerTwoWins;
    static int ties;

public:
    TicTacToe();

    void regularPlay();
    void battleDescription();
    bool validArchetype(const std::string& archetype);
    void battleChooseArchetypes();
    bool swarmWinCondition();
    void battlePlay();
    void play();

    static void printGameReport();  
};

#endif 
