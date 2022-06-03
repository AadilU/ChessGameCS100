#ifndef GAME_HPP
#define GAME_HPP

#include "piece.hpp"

class Game {
    private:
    public:
        Piece* pieceList[8][8] = {nullptr};
        bool whiteTurn = true;
        Game();
        ~Game();
        Piece* getPieceFromPosition(int x, int y);
        Piece* getAttackedPiece(int x, int y);
        bool checkKingInDanger(Piece* king1);

};
#endif