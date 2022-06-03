
#include "knight.hpp"
#include <iostream>
#include "game.hpp"

knight::knight(bool w,int pX, int pY){
    name = "knight";

    if(w)
        image_path = "images/whiteKnight.bpm";
    else
        image_path = "images/blackKnight.bpm";
    
    posX = pX;
    posY = pY;
    white = w;

    pieceRect.x = (posX*80)+10;
    pieceRect.y = (posY*80)+10;
    pieceRect.w = 60;
    pieceRect.h = 60;
}

std::vector<std::pair<int, int>> knight::possibleMoves(bool w, Game* game) {
    int x = posX;
    int y = posY;

    std::vector<std::pair<int, int>> moves;

    if(game->getAttackedPiece(x + 1, y + 2) == nullptr || 
    (game->getAttackedPiece(x + 1, y + 2) != nullptr && game->getAttackedPiece(x + 1, y + 2)->isWhite() != this->isWhite()))
        moves.push_back(std::pair(x + 1, y + 2));

    if(game->getAttackedPiece(x - 1, y + 2) == nullptr || 
    (game->getAttackedPiece(x - 1, y + 2) != nullptr && game->getAttackedPiece(x - 1, y + 2)->isWhite() != this->isWhite()))
        moves.push_back(std::pair(x - 1, y + 2));

    if(game->getAttackedPiece(x + 1, y - 2) == nullptr || 
    (game->getAttackedPiece(x + 1, y - 2) != nullptr && game->getAttackedPiece(x + 1, y - 2)->isWhite() != this->isWhite()))
        moves.push_back(std::pair(x + 1, y - 2));

    if(game->getAttackedPiece(x - 1, y - 2) == nullptr || 
    (game->getAttackedPiece(x - 1, y - 2) != nullptr && game->getAttackedPiece(x - 1, y - 2)->isWhite() != this->isWhite()))
        moves.push_back(std::pair(x - 1, y - 2));

    if(game->getAttackedPiece(x + 2, y + 1) == nullptr || 
    (game->getAttackedPiece(x + 2, y + 1) != nullptr && game->getAttackedPiece(x + 2, y + 1)->isWhite() != this->isWhite()))
        moves.push_back(std::pair(x + 2, y + 1));

    if(game->getAttackedPiece(x - 2 , y + 1) == nullptr || 
    (game->getAttackedPiece(x - 2, y + 1) != nullptr && game->getAttackedPiece(x - 2, y + 1)->isWhite() != this->isWhite()))
        moves.push_back(std::pair(x - 2, y + 1));

    if(game->getAttackedPiece(x + 2, y - 1) == nullptr || 
    (game->getAttackedPiece(x + 2, y - 1) != nullptr && game->getAttackedPiece(x + 2, y - 1)->isWhite() != this->isWhite()))
        moves.push_back(std::pair(x + 2, y - 1));

    if(game->getAttackedPiece(x - 2, y - 1) == nullptr || 
    (game->getAttackedPiece(x - 2, y - 1) != nullptr && game->getAttackedPiece(x - 2, y - 1)->isWhite() != this->isWhite()))
        moves.push_back(std::pair(x - 2, y - 1));
    
    return moves;
}
