
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
}

std::vector<std::pair<int, int>> pawn::possibleMoves(bool w, Game* game) {
    int x = posX;
    int y = posY;

    std::vector<std::pair<int, int>> moves;

    if(w) {
        for(int i = 0;i < 8;i++) {
            for(int j = 0;j < 8;j++) {
                if(firstMove) {
                    if(i == x) {
                        if(((j - y) > -3) && ((j - y) < 0)) {
                                if(game->getAttackedPiece(i, j) == nullptr && game->getAttackedPiece(x, y - 1) == nullptr)
                                    moves.push_back(std::make_pair(i, j));
                        }
                    }
                }
                else {
                    if(i == x) {
                        if(((j - y) > -2) && ((j - y) <= 0)) {
                            if(game->getAttackedPiece(i, j) == nullptr && game->getAttackedPiece(x, y - 1) == nullptr)
                                moves.push_back(std::make_pair(i, j));
                        }
                    }
                }
            }
        }
        if(game->getAttackedPiece(x + 1, y - 1) != nullptr) {
            moves.push_back(std::make_pair(x + 1, y - 1));
        }
        if(game->getAttackedPiece(x - 1, y - 1) != nullptr) {
            moves.push_back(std::make_pair(x - 1, y - 1));
        }
    }
    else {
        for(int i = 0;i < 8;i++) {
            for(int j = 0;j < 8;j++) {
                if(firstMove) {
                    if(i == x) {
                        if(((j - y) < 3) && ((j - y) >= 0)) {
                            if(game->getAttackedPiece(i, j) == nullptr && game->getAttackedPiece(x, y + 1) == nullptr)
                                    moves.push_back(std::make_pair(i, j));
                        }
                    }
                }
                else {
                    if(i == x) {
                        if(((j - y) < 2) && ((j - y) >= 0)) {
                            if(game->getAttackedPiece(i, j) == nullptr && game->getAttackedPiece(x, y + 1) == nullptr)
                                    moves.push_back(std::make_pair(i, j));
                        }
                    }
                }
            }
        }
        if(game->getAttackedPiece(x + 1, y + 1) != nullptr) {
            moves.push_back(std::make_pair(x + 1, y + 1));
        }
        if(game->getAttackedPiece(x - 1, y + 1) != nullptr) {
            moves.push_back(std::make_pair(x - 1, y + 1));
        }
    }
    return moves;
}


