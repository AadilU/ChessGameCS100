

#ifndef king_hpp
#define king_hpp


#include <iostream>
#include <SDL2/SDL.h>
#include "piece.hpp"
#include "square.hpp"
#include "chessBoard.hpp"
#include <vector>
#include "game.hpp"

class king : public Piece{
public:
    king(bool isWhite,int pX, int pY);
    std::vector<std::pair<int, int>> possibleMoves(bool w, Game* game);
};

#endif /* pawn_hpp */
