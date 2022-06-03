

#ifndef bishop_hpp
#define bishop_hpp


#include <iostream>
#include <SDL2/SDL.h>
#include "piece.hpp"
#include "square.hpp"
#include "chessBoard.hpp"
#include <vector>
#include "game.hpp"

class bishop : public Piece{
public:
    bishop(bool isWhite,int pX, int pY);
    std::vector<std::pair<int, int>> possibleMoves(bool w, Game* game, bool select);
    void push_back_sim(std::pair<int, int> p, std::vector<std::pair<int, int>> &moves, Game* game);
};

#endif /* pawn_hpp */
