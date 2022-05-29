

#ifndef king_hpp
#define king_hpp


#include <iostream>
#include <SDL2/SDL.h>
#include "piece.hpp"
#include "square.hpp"
#include "chessBoard.hpp"

class king : public Piece{
public:
    king(bool isWhite,int pX, int pY);
    //virtual bool canMove(square* moveSquare) = 0;
};

#endif /* pawn_hpp */
