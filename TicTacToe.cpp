#include "TicTacToe.hpp"
#include <iostream>
#include <limits>
#include <algorithm>

int TicTacToe::gamesPlayed = 0;
int TicTacToe::playerOneWins = 0;
int TicTacToe::playerTwoWins = 0;
int TicTacToe::ties = 0;

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
                playerOneWins++;
                break;
            }
            currentPlayer = 'O';
        } else {
            move = playerO.getMove(&board);
            board.markCell(move, 'O');
            if (board.checkWinner()) {
                board.display();
                std::cout << "Player O wins!\n";
                playerTwoWins++;
                break;
            }
            currentPlayer = 'X';
        }

        if (board.isFull()) {
            board.display();
            std::cout << "It's a draw!\n";
            ties++;
            break;
        }
    }

    gamesPlayed++;
    char playAgain;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> playAgain;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (playAgain == 'y' || playAgain == 'Y') {
        TicTacToe newGame;
        newGame.play();
    } else {
        printGameReport();
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
                while (true) {
                    std::string input;
                    std::cout << "Enter your choice (1 or 2): ";
                    std::getline(std::cin, input);

                    
                    input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());

                    try {
                        choice = std::stoi(input); 
                        if (choice == 1 || choice == 2) {
                            break; 
                        } else {
                            std::cout << "Invalid choice. Please enter 1 or 2.\n";
                        }
                    } catch (std::invalid_argument&) {
                        std::cout << "Invalid input. Please enter a number (1 or 2).\n";
                    }
                }

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
                playerOneWins++;
                break;
            }
            currentPlayer = 'O';
        } else {
            if (playerO.archetype == "Pyromancer" && !pyromancerUsed) {
                std::cout << "Player O, choose your move:\n";
                std::cout << "1. Regular move\n";
                std::cout << "2. Special move (reset board)\n";
                int choice;
                while (true) {
                    std::string input;
                    std::cout << "Enter your choice (1 or 2): ";
                    std::getline(std::cin, input);

                    input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());

                    try {
                        choice = std::stoi(input); 
                        if (choice == 1 || choice == 2) {
                            break; 
                        } else {
                            std::cout << "Invalid choice. Please enter 1 or 2.\n";
                        }
                    } catch (std::invalid_argument&) {
                        std::cout << "Invalid input. Please enter a number (1 or 2).\n";
                    }
                }

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
                playerTwoWins++;
                break;
            }
            currentPlayer = 'X';
        }

        if (board.isFull()) {
            board.display();
            std::cout << "It's a draw!\n";
            ties++;
            break;
        }
    }

    gamesPlayed++;
    char playAgain;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> playAgain;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (playAgain == 'y' || playAgain == 'Y') {
        TicTacToe newGame;
        newGame.play();
    } else {
        printGameReport();
        std::cout << "Thanks for playing! Goodbye!\n";
    }
}

void TicTacToe::printGameReport() {
    std::cout << "\n--- Game Report ---\n";
    std::cout << "Total games played: " << gamesPlayed << "\n";
    std::cout << "Player 1 (X) wins: " << playerOneWins << "\n";
    std::cout << "Player 2 (O) wins: " << playerTwoWins << "\n";
    std::cout << "Ties: " << ties << "\n";
}

void TicTacToe::play() {
    std::cout << "Welcome to Tic-Tac-Toe!\n";
    std::cout << "Choose game mode:\n";
    std::cout << "1. Regular Tic-Tac-Toe\n";
    std::cout << "2. Battle Tic-Tac-Toe\n";
    int choice;
    while (true) {
        std::string input;
        std::cout << "Enter your choice (1 or 2): ";
        std::getline(std::cin, input);

        input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());

        try {
            choice = std::stoi(input); 
            if (choice == 1 || choice == 2) {
                break; 
            } else {
                std::cout << "Invalid choice. Please enter 1 or 2.\n";
            }
        } catch (std::invalid_argument&) {
            std::cout << "Invalid input. Please enter a number (1 or 2).\n";
        }
    }

    if (choice == 1) {
        regularPlay();
    } else if (choice == 2) {
        battlePlay();
    } else {
        std::cout << "Invalid choice. Exiting.\n";
    }
}
