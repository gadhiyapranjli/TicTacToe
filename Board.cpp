#include "Board.h"

Board::Board() {
    for (int i = 0; i < 9; i++) {
        cells[i] = '0' + (i + 1);
    }
}

void Board::display() {
    std::cout << "\n";
    for (int i = 0; i < 3; i++) {
        std::cout << " " << cells[i * 3] << " | " << cells[i * 3 + 1] << " | " << cells[i * 3 + 2] << "\n";
        if (i < 2) {
            std::cout << "---|---|---\n";
        }
    }
    std::cout << "\n";
}

bool Board::isTaken(int index) {
    return cells[index] == 'X' || cells[index] == 'O';
}

void Board::markCell(int index, char mark) {
    cells[index] = mark;
}

char Board::getMark(int index) {
    return cells[index];
}

bool Board::checkWinner() {
    const int winPatterns[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };

    for (const auto& pattern : winPatterns) {
        if (cells[pattern[0]] == cells[pattern[1]] && cells[pattern[1]] == cells[pattern[2]] &&
            (cells[pattern[0]] == 'X' || cells[pattern[0]] == 'O')) {
            return true;
        }
    }
    return false;
}

bool Board::isFull() {
    for (int i = 0; i < 9; i++) {
        if (!isTaken(i)) return false;
    }
    return true;
}
