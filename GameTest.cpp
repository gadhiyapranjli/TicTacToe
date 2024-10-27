#include "Game.h"
#include <cassert>
#include <iostream>

void testGamePlay() {
    TicTacToe game;
    assert(game.playerX.mark == 'X');
    assert(game.playerO.mark == 'O');
    std::cout << "testGamePlay passed\n";
}

int main() {
    testGamePlay();
   
    return 0;
}