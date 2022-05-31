

#ifndef pawn_hpp
#define pawn_hpp


#include <iostream>
#include <SDL2/SDL.h>
#include "piece.hpp"
#include "square.hpp"
#include "chessBoard.hpp"
#include <vector>

class pawn : public Piece{
private:
    bool firstMove = true;
public:
    pawn(bool isWhite, int pX, int pY);
    std::vector<std::pair<int, int>> possibleMoves();
    void movePiece(SDL_Rect rendPiece);
};

#endif /* pawn_hpp */
