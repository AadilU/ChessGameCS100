

#ifndef pawn_hpp
#define pawn_hpp


#include <iostream>
#include <SDL2/SDL.h>
#include "piece.hpp"
#include "square.hpp"
#include "chessBoard.hpp"

class pawn : public Piece{
public:
    pawn(bool isWhite,int pX, int pY);
    //virtual bool canMove(square* moveSquare) = 0;
    void renderPiece(SDL_Rect rendPiece);
};

#endif /* pawn_hpp */
