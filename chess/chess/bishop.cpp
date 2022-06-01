
#include "bishop.hpp"
#include <iostream>
#include "game.hpp"

bishop::bishop(bool w,int pX, int pY){
    name = "bishop";

    if(w)
        image_path = "images/whiteBishop.bpm";
    else
        image_path = "images/blackBishop.bpm";
    
    posX = pX;
    posY = pY;
    white = w;

    pieceRect.x = (posX*80)+10;
    pieceRect.y = (posY*80)+10;
    pieceRect.w = 60;
    pieceRect.h = 60;
}

std::vector<std::pair<int, int>> bishop::possibleMoves(bool w, Game* game) {
    std::vector<std::pair<int, int>> moves;
    return moves;
}
