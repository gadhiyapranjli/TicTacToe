#include "gtest/gtest.h"
#include "Board.hpp"

TEST(BoardTests, TestReset) {
    Board board;
    board.reset();
    for (int i = 0; i < 9; i++) {
        ASSERT_EQ(board.cells[i], '1' + i);
    }
}

TEST(BoardTests, TestIsTaken) {
    Board board;
    board.markCell(0, 'X');
    ASSERT_TRUE(board.isTaken(0));
    ASSERT_FALSE(board.isTaken(1));
}
