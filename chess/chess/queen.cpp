
#include "queen.hpp"
#include <iostream>

queen::queen(bool w,int pX, int pY){
    name = "queen";

    if(w)
        image_path = "images/whiteQueen.bpm";
    else
        image_path = "images/blackQueen.bpm";
    
    posX = pX;
    posY = pY;
    white = w;

    pieceRect.x = (posX*80)+10;
    pieceRect.y = (posY*80)+10;
    pieceRect.w = 60;
    pieceRect.h = 60;
}

std::vector<std::pair<int, int>> queen::possibleMoves(bool w) {
    
}
