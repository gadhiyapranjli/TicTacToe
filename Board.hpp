#ifndef BOARD_HPP
#define BOARD_HPP

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
    void reset();
};

#endif
