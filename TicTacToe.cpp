#include "TicTacToe.hpp"
#include <iostream>
#include <limits>

TicTacToe::TicTacToe() : playerX('X'), playerO('O') {}

void TicTacToe::regularPlay() {
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
        std::cout << "Thanks for playing! Goodbye!\n";
    }
}

void TicTacToe::battleDescription() {
    std::cout << "\n--- Battle Tic-Tac-Toe ---\n";
    std::cout << "In Battle Tic-Tac-Toe, each player chooses an Archetype with a special ability.\n";
    std::cout << "The Swarm can win by filling all four corners, and the Pyromancer can reset the board once.\n";
}

bool TicTacToe::validArchetype(const std::string& archetype) {
    return archetype == "Swarm" || archetype == "Pyromancer";
}

void TicTacToe::battleChooseArchetypes() {
    std::string archetypeX, archetypeO;
    while (true) {
        std::cout << "Player X, choose your archetype (Swarm/Pyromancer): ";
        std::getline(std::cin, archetypeX);
        if (validArchetype(archetypeX)) {
            playerX.archetype = archetypeX;
            break;
        } else {
            std::cout << "Invalid archetype. Please choose either Swarm or Pyromancer.\n";
        }
    }

    while (true) {
        std::cout << "Player O, choose your archetype (Swarm/Pyromancer): ";
        std::getline(std::cin, archetypeO);
        if (validArchetype(archetypeO)) {
            playerO.archetype = archetypeO;
            break;
        } else {
            std::cout << "Invalid archetype. Please choose either Swarm or Pyromancer.\n";
        }
    }
}

bool TicTacToe::swarmWinCondition() {
    char currentPlayerMark = (playerX.mark == 'X') ? playerX.mark : playerO.mark;
    return (board.getMark(0) == currentPlayerMark &&
            board.getMark(2) == currentPlayerMark &&
            board.getMark(6) == currentPlayerMark &&
            board.getMark(8) == currentPlayerMark);
}

void TicTacToe::battlePlay() {
    battleDescription();
    battleChooseArchetypes();

    char currentPlayer = 'X';
    bool pyromancerUsed = false;

    while (true) {
        board.display();
        int move;

        if (currentPlayer == 'X') {
            if (playerX.archetype == "Pyromancer" && !pyromancerUsed) {
                std::cout << "Player X, choose your move:\n";
                std::cout << "1. Regular move\n";
                std::cout << "2. Special move (reset board)\n";
                int choice;
                std::cin >> choice;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if (choice == 1) {
                    move = playerX.getMove(&board);
                    board.markCell(move, 'X');
                } else if (choice == 2) {
                    if (playerX.pyromancerSpecialMove(&board)) {
                        pyromancerUsed = true;
                    }
                }
            } else {
                move = playerX.getMove(&board);
                board.markCell(move, 'X');
            }

            if (board.checkWinner() || swarmWinCondition()) {
                board.display();
                std::cout << "Player X wins!\n";
                break;
            }
            currentPlayer = 'O';
        } else {
            if (playerO.archetype == "Pyromancer" && !pyromancerUsed) {
                std::cout << "Player O, choose your move:\n";
                std::cout << "1. Regular move\n";
                std::cout << "2. Special move (reset board)\n";
                int choice;
                std::cin >> choice;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if (choice == 1) {
                    move = playerO.getMove(&board);
                    board.markCell(move, 'O');
                } else if (choice == 2) {
                    if (playerO.pyromancerSpecialMove(&board)) {
                        pyromancerUsed = true;
                    }
                }
            } else {
                move = playerO.getMove(&board);
                board.markCell(move, 'O');
            }

            if (board.checkWinner() || swarmWinCondition()) {
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
        std::cout << "Thanks for playing! Goodbye!\n";
    }
}

void TicTacToe::play() {
    std::cout << "Welcome to Tic-Tac-Toe!\n";
    std::cout << "Choose game mode:\n1. Regular Tic-Tac-Toe\n2. Battle Tic-Tac-Toe\n";
    int choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (choice == 1) {
        regularPlay();
    } else if (choice == 2) {
        battlePlay();
    } else {
        std::cout << "Invalid choice. Exiting.\n";
    }
}
