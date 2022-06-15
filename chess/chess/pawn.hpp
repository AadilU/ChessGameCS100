

#ifndef pawn_hpp
#define pawn_hpp


#include <iostream>
#include <SDL2/SDL.h>
#include "piece.hpp"
#include "square.hpp"
#include "chessBoard.hpp"
#include <vector>
#include "game.hpp"

class pawn : public Piece {
public:
    pawn(bool isWhite, int pX, int pY);
    std::vector<std::pair<int, int>> possibleMoves(bool w, Game* game);
    void movePiece(SDL_Rect rendPiece);
};

#endif /* pawn_hpp */
