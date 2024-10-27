#include "Board.h"
#include <cassert>
#include <iostream>

void testBoardInitialization() {
    Board board;
    for (int i = 0; i < 9; i++) {
        assert(board.cells[i] == '0' + (i + 1));
    }
    std::cout << "testBoardInitialization passed\n";
}

void testMarkCell() {
    Board board;
    board.markCell(0, 'X');
    assert(board.getMark(0) == 'X');
    std::cout << "testMarkCell passed\n";
}

void testIsTaken() {
    Board board;
    board.markCell(0, 'X');
    assert(board.isTaken(0) == true);
    assert(board.isTaken(1) == false);
    std::cout << "testIsTaken passed\n";
}

void testCheckWinner() {
    Board board;
    board.markCell(0, 'X');
    board.markCell(1, 'X');
    board.markCell(2, 'X');
    assert(board.checkWinner() == true);
    std::cout << "testCheckWinner passed\n";
}

void testIsFull() {
    Board board;
    for (int i = 0; i < 9; i++) {
        board.markCell(i, 'X');
    }
    assert(board.isFull() == true);
    std::cout << "testIsFull passed\n";
}

int main() {
    testBoardInitialization();
    testMarkCell();
    testIsTaken();
    testCheckWinner();
    testIsFull();
   
    return 0;
}