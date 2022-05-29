#include "game.hpp"
#include "piece.hpp"
#include "rook.hpp"
#include "pawn.hpp"
#include "knight.hpp"
#include "bishop.hpp"
#include "queen.hpp"
#include "king.hpp"

Game::Game() {
    for(int i = 0;i < 8;i++) {
        pieceList[i][1] = new pawn(false, i, 1);
        pieceList[i][6] = new pawn(true, i, 6);
    }

    pieceList[0][0] = new rook(false, 0, 0);
    pieceList[7][0] = new rook(false, 7, 0);
    pieceList[0][7] = new rook(true, 0, 7);
    pieceList[7][7] = new rook(true, 7, 7);

    pieceList[1][0] = new knight(false, 1, 0);
    pieceList[6][0] = new knight(false, 6, 0);
    pieceList[1][7] = new knight(true, 1, 7);
    pieceList[6][7] = new knight(true, 6, 7);

    pieceList[2][0] = new bishop(false, 2, 0);
    pieceList[5][0] = new bishop(false, 5, 0);
    pieceList[2][7] = new bishop(true, 2, 7);
    pieceList[5][7] = new bishop(true, 5, 7);

    pieceList[3][0] = new queen(false, 3, 0);
    pieceList[3][7] = new queen(true, 3, 7);

    pieceList[4][0] = new king(false, 4, 0);
    pieceList[4][7] = new king(true, 4, 7);
}