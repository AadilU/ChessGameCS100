
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

std::vector<std::pair<int, int>> king::possibleMoves(bool w, Game* game, bool select) {

    int x = posX;
    int y = posY;

    std::vector<std::pair<int, int>> moves;

    if(game->getAttackedPiece(x + 1, y + 1) == nullptr || 
    (game->getAttackedPiece(x + 1, y + 1) == nullptr && game->getAttackedPiece(x + 1, y + 1)->isWhite() != this->isWhite()))
        moves.push_back(std::pair(x + 1, y + 1));

    if(game->getAttackedPiece(x - 1, y + 1) == nullptr || 
    (game->getAttackedPiece(x - 1, y + 1) != nullptr && game->getAttackedPiece(x - 1, y + 1)->isWhite() != this->isWhite()))
        moves.push_back(std::pair(x - 1, y + 1));

    if(game->getAttackedPiece(x + 1, y - 1) == nullptr || 
    (game->getAttackedPiece(x + 1, y - 1) != nullptr && game->getAttackedPiece(x + 1, y - 1)->isWhite() != this->isWhite()))
        moves.push_back(std::pair(x + 1, y - 1));

    if(game->getAttackedPiece(x - 1, y - 1) == nullptr || 
    (game->getAttackedPiece(x - 1, y - 1) != nullptr && game->getAttackedPiece(x - 1, y - 1)->isWhite() != this->isWhite()))
        moves.push_back(std::pair(x - 1, y - 1));

    if(game->getAttackedPiece(x, y + 1) == nullptr || 
    (game->getAttackedPiece(x, y + 1) != nullptr && game->getAttackedPiece(x, y + 1)->isWhite() != this->isWhite()))
        moves.push_back(std::pair(x, y + 1));
    
    if(game->getAttackedPiece(x, y - 1) == nullptr || 
    (game->getAttackedPiece(x, y - 1) != nullptr && game->getAttackedPiece(x, y - 1)->isWhite() != this->isWhite()))
        moves.push_back(std::pair(x, y - 1));

    if(game->getAttackedPiece(x + 1, y) == nullptr || 
    (game->getAttackedPiece(x + 1, y) != nullptr && game->getAttackedPiece(x + 1, y)->isWhite() != this->isWhite()))
        moves.push_back(std::pair(x + 1, y));

    if(game->getAttackedPiece(x - 1, y) == nullptr || 
    (game->getAttackedPiece(x - 1, y) != nullptr && game->getAttackedPiece(x - 1, y)->isWhite() != this->isWhite()))
        moves.push_back(std::pair(x - 1, y));

    return moves;

}
