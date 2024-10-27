#include "Player.h"
#include <iostream>
#include <limits>
#include <stdexcept>
#include <cctype>

Player::Player(char m) : mark(m) {}

int Player::getMove(Board* board) {
    int move;
    while (true) {
        std::cout << "Player " << mark << ", enter your move (1-9): ";
        std::string input;
        std::getline(std::cin, input);

        if (input.empty()) {
            std::cout << "invalid: No input (just pressing enter).\n";
            continue;
        }

        bool isSymbol = false;
        bool isDecimal = false;
        bool isChar = false;
        for (char c : input) {
            if (!isdigit(c) && c != '.') {
                if (isspace(c)) {
                    continue;
                } else if (isalpha(c)) {
                    isChar = true;
                } else {
                    isSymbol = true;
                }
            }
            if (c == '.') {
                isDecimal = true;
            }
        }

        if (isSymbol) {
            std::cout << "invalid: Random or unexpected symbols: Please enter a number between 1 and 9.\n";
            continue;
        }

        if (isChar) {
            std::cout << "invalid: A string or char input instead of an integer (or vice versa): Please enter a number between 1 and 9.\n";
            continue;
        }

        if (isDecimal) {
            std::cout << "invalid: A decimal number instead of an integer for the cell input: Please enter a number between 1 and 9.\n";
            continue;
        }

        try {
            move = std::stoi(input);
        } catch (std::invalid_argument&) {
            std::cout << "invalid: A string or char input instead of an integer (or vice versa): Please enter a number between 1 and 9.\n";
            continue;
        } catch (std::out_of_range&) {
            std::cout << "invalid: Random or unexpected symbols: Please enter a number between 1 and 9.\n";
            continue;
        }

        if (move < 1 || move > 9) {
            std::cout << "invalid: Random or unexpected symbols: Please enter a number between 1 and 9.\n";
            continue;
        }

        move--;
        if (board->getMark(move) == 'X' || board->getMark(move) == 'O') {
            std::cout << "invalid: A cell is already taken.\n";
        } else {
            board->markCell(move, mark);
            return move;
        }
    }
}
