

#ifndef queen_hpp
#define queen_hpp


#include <iostream>
#include <SDL2/SDL.h>
#include "piece.hpp"
#include "square.hpp"
#include "chessBoard.hpp"
#include <vector>
#include "game.hpp"

class queen : public Piece{
public:
    queen(bool isWhite,int pX, int pY);
    std::vector<std::pair<int, int>> possibleMoves(bool w, Game* game);
};

#endif /* pawn_hpp */
