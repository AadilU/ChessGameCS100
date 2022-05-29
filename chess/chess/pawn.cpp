
#include "pawn.hpp"
#include <iostream>

pawn::pawn(bool w,int pX, int pY){
    name = "pawn";

    if(w)
        image_path = "images/whitePawn.bpm";
    else
        image_path = "images/blackPawn.bpm";
    
    posX = pX;
    posY = pY;
    white = w;

    pieceRect.x = (posX*80)+10;
    pieceRect.y = (posY*80)+10;
    pieceRect.w = 60;
    pieceRect.h = 60;
}
