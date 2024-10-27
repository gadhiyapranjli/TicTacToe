#include <iostream>
#include <cassert>
#include <sstream>
#include "Player.h"
#include "Board.h"

class MockInput {
public:
    static void setInput(const std::string& input) {
        std::istringstream stream(input);
        std::cin.rdbuf(stream.rdbuf());
    }
};

void testValidMove() {
    Board board;
    Player player('X');

    MockInput::setInput("5\n"); 
    int move = player.getMove(&board);
    
    assert(move == 4); 
    assert(board.getMark(move) == 'X'); 
    std::cout << "testValidMove passed\n";
}

void testMoveOnTakenCell() {
    Board board;
    Player player('X');

    board.markCell(0, 'X'); 
    MockInput::setInput("1\n"); 
    int move = player.getMove(&board);
    
    assert(move == -1); 
    std::cout << "testMoveOnTakenCell passed\n";
}

void testInvalidInput() {
    Board board;
    Player player('X');

    MockInput::setInput("10\n"); 
    int move = player.getMove(&board);
    
    assert(move == -1); 
    std::cout << "testInvalidInput passed\n";
}

void testNoInput() {
    Board board;
    Player player('X');

    MockInput::setInput("\n"); 
    int move = player.getMove(&board);
    
    assert(move == -1); 
    std::cout << "testNoInput passed\n";
}

int main() {
    testValidMove();
    testMoveOnTakenCell();
    testInvalidInput();
    testNoInput();

    return 0;
}
