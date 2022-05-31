
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
void pawn::movePiece(SDL_Rect newPiece){
    
    pieceRect.x = (posX*80)+10;
    pieceRect.y = (posY*80)+10;

    //std::cout << "I am called";
}

std::vector<std::pair<int, int>> pawn::possibleMoves() {
    int x = posX;
    int y = posY;

    std::cout << x << endl;
    std::cout << y << endl;

    std::vector<std::pair<int, int>> moves;

    for(int i = 0;i < 8;i++) {
        for(int j = 0;j < 8;j++) {
            if(firstMove) {
                if(i == x) {
                    if(((j - y) > -3) && ((j - y) <= 0)) {
                        moves.push_back(std::make_pair(i, j));
                    }
                }
            }
            else {
                if(i == x) {
                    if(((j - y) > -2) && ((j - y) <= 0)) {
                        moves.push_back(std::make_pair(i, j));
                    }
                }
            }
        }
    }

    std::cout << "Test" << endl;

    std::cout << std::get<0>(moves.at(0));
    return moves;
}


