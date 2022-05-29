

#ifndef queen_hpp
#define queen_hpp


#include <iostream>
#include <SDL2/SDL.h>
#include "piece.hpp"
#include "square.hpp"
#include "chessBoard.hpp"

class queen : public Piece{
public:
    queen(bool isWhite,int pX, int pY);
    //virtual bool canMove(square* moveSquare) = 0;
};

#endif /* pawn_hpp */
