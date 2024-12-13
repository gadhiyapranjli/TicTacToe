#include <iostream>
#include <limits>  
#include "TicTacToe.hpp"

int main() {
    TicTacToe game;
    char mode;
    std::cout << "choose Game Mode\n"; 
    std::cout << "1) for Regular:\n";
    std::cout << "2) for Battle:\n";
    std::cin >> mode;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
    if (mode == '1') {
        game.regularPlay();
    } else if (mode == '2') {
        game.battlePlay();
    } else {
        std::cout << "Invalid option. Exiting...\n";
    }

    return 0;
}
