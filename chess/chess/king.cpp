
#include "king.hpp"
#include <iostream>
#include "game.hpp"

king::king(bool w,int pX, int pY){
    name = "king";

    if(w)
        image_path = "images/whiteKing.bpm";
    else
        image_path = "images/blackKing.bpm";
    
    posX = pX;
    posY = pY;
    white = w;

    pieceRect.x = (posX*80)+10;
    pieceRect.y = (posY*80)+10;
    pieceRect.w = 60;
    pieceRect.h = 60;
}

std::vector<std::pair<int, int>> king::possibleMoves(bool w, Game* game) {
    std::vector<std::pair<int, int>> moves;
    return moves;

}
