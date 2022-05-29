

#ifndef rook_hpp
#define rook_hpp


#include <iostream>
#include <SDL2/SDL.h>
#include "piece.hpp"
#include "square.hpp"
#include "chessBoard.hpp"

class rook : public Piece{
public:
    rook(bool isWhite,int pX, int pY);
    //virtual bool canMove(square* moveSquare) = 0;
};

#endif /* pawn_hpp */
