

#ifndef knight_hpp
#define knight_hpp


#include <iostream>
#include <SDL2/SDL.h>
#include "piece.hpp"
#include "square.hpp"
#include "chessBoard.hpp"

class knight : public Piece{
public:
    knight(bool isWhite,int pX, int pY);
    //virtual bool canMove(square* moveSquare) = 0;
};

#endif /* pawn_hpp */
