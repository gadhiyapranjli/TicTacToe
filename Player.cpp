#include "Player.hpp"
#include <iostream>
#include <limits>

Player::Player(char m) : mark(m), archetype("") {}

int Player::getMove(Board* board) {
    int move;
    while (true) {
        std::cout << "Player " << mark << ", enter your move (1-9): ";
        std::string input;
        std::getline(std::cin, input);

        try {
            move = std::stoi(input);
            if (move < 1 || move > 9 || board->isTaken(move - 1)) {
                std::cout << "Invalid move. Please enter a number between 1 and 9, that is already taken.\n";
            } else {
                return move - 1;
            }
        } catch (std::invalid_argument&) {
            std::cout << "Invalid input. Please enter a number between 1 and 9.\n";
        }
    }
}

bool Player::pyromancerSpecialMove(Board* board) {
    char confirm;
    std::cout << "As the Pyromancer, you can reset the board (destroy all marks). Are you sure? (y/n): ";
    std::cin >> confirm;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (confirm == 'y' || confirm == 'Y') {
        board->reset();
        std::cout << "The board has been reset!\n";
        return true;
    }
    return false;
}
