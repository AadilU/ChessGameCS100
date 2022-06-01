
#include "rook.hpp"
#include "game.hpp"
#include <iostream>

rook::rook(bool w,int pX, int pY){
    name = "rook";

    if(w)
        image_path = "images/whiteRook.bpm";
    else
        image_path = "images/blackRook.bpm";
    
    posX = pX;
    posY = pY;
    white = w;

    pieceRect.x = (posX*80)+10;
    pieceRect.y = (posY*80)+10;
    pieceRect.w = 60;
    pieceRect.h = 60;
}

std::vector<std::pair<int, int>> rook::possibleMoves(bool w, Game* game) {
    std::vector<std::pair<int, int>> moves;
    return moves;

}
