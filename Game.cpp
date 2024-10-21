#include "Game.h"
#include <iostream>
#include <limits>

TicTacToe::TicTacToe() : playerX('X'), playerO('O') {}

void TicTacToe::play() {
    char currentPlayer = 'X';
    while (true) {
        board.display();
        int move;

        if (currentPlayer == 'X') {
            move = playerX.getMove(&board);
            board.markCell(move, 'X');
            if (board.checkWinner()) {
                board.display();
                std::cout << "Player X wins!\n";
                break;
            }
            currentPlayer = 'O';
        } else {
            move = playerO.getMove(&board);
            board.markCell(move, 'O');
            if (board.checkWinner()) {
                board.display();
                std::cout << "Player O wins!\n";
                break;
            }
            currentPlayer = 'X';
        }

        if (board.isFull()) {
            board.display();
            std::cout << "It's a draw!\n";
            break;
        }
    }

    char playAgain;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> playAgain;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (playAgain == 'y' || playAgain == 'Y') {
        TicTacToe newGame;
        newGame.play();
    } else {
        std::cout << "Thanks for playing TicTacToe! Have a nice day!\n";
    }
}
