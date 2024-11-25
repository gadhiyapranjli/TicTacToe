#include "gtest/gtest.h"
#include "Player.hpp"
#include "Board.hpp"

TEST(PlayerTests, TestGetMove) {
    Board board;
    Player player('X');
    player.getMove(&board); 
}
