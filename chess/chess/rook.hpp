

#ifndef rook_hpp
#define rook_hpp


#include <iostream>
#include <SDL2/SDL.h>
#include "piece.hpp"
#include "square.hpp"
#include "chessBoard.hpp"
#include <vector>

class rook : public Piece{
public:
    rook(bool isWhite,int pX, int pY);
    std::vector<std::pair<int, int>> possibleMoves();
};

#endif /* pawn_hpp */
