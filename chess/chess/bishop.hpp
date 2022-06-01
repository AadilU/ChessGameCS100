

#ifndef bishop_hpp
#define bishop_hpp


#include <iostream>
#include <SDL2/SDL.h>
#include "piece.hpp"
#include "square.hpp"
#include "chessBoard.hpp"
#include <vector>

class bishop : public Piece{
public:
    bishop(bool isWhite,int pX, int pY);
    std::vector<std::pair<int, int>> possibleMoves(bool w);
};

#endif /* pawn_hpp */
