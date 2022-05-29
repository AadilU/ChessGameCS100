

#ifndef bishop_hpp
#define bishop_hpp


#include <iostream>
#include <SDL2/SDL.h>
#include "piece.hpp"
#include "square.hpp"
#include "chessBoard.hpp"

class bishop : public Piece{
public:
    bishop(bool isWhite,int pX, int pY);
    //virtual bool canMove(square* moveSquare) = 0;
};

#endif /* pawn_hpp */
