#ifndef BOARD_H
#define BOARD_H

#include <iostream>

class Board {
public:
    char cells[9];
    Board();
    void display();
    bool isTaken(int index);
    void markCell(int index, char mark);
    char getMark(int index);
    bool checkWinner();
    bool isFull();
};

#endif 
