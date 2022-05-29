

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
};

#endif /* pawn_hpp */
