

#ifndef knight_hpp
#define knight_hpp


#include <iostream>
#include <SDL2/SDL.h>
#include "piece.hpp"
#include "square.hpp"
#include "chessBoard.hpp"
#include <vector>
#include "game.hpp"

class knight : public Piece{
public:
    knight(bool isWhite,int pX, int pY);
    std::vector<std::pair<int, int>> possibleMoves(bool w, Game* game, bool select);
};

#endif /* pawn_hpp */
