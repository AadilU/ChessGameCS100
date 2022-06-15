#include "bishop.hpp"
#include "chessBoard.hpp"
#include "game.hpp"
#include "knight.hpp"
#include "pawn.hpp"
#include "piece.hpp"
#include "queen.hpp"
#include "square.hpp"
#include "window.hpp"
#include "king.hpp"

#include "gtest/gtest.h"

TEST(Bishop, testBishop){
    Piece* piece = new bishop(true, 2, 7);
    EXPECT_EQ(2, piece->posX);
    EXPECT_EQ(7, piece->posY);
    delete piece;
}

TEST(King, testKing){
    Piece* piece = new king(true, 4, 7);
    EXPECT_EQ(4, piece->posX);
    EXPECT_EQ(7, piece->posY);
    delete piece;
}

TEST(Knight, testKnight){
Piece* piece = new knight(true, 1, 7);
EXPECT_EQ(1, piece->posX);
EXPECT_EQ(7, piece->posY);
delete piece;
}

TEST(Pawn, testPawn){
Piece* piece = new pawn(true, 1, 6);
EXPECT_EQ(1, piece->posX);
EXPECT_EQ(6, piece->posY);
delete piece;
}

TEST(Queen, testQueen){
Piece* piece = new queen(true, 3, 7);
EXPECT_EQ(3, piece->posX);
EXPECT_EQ(7, piece->posY);
delete piece;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}