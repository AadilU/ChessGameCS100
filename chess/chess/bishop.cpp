
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
    int x = posX;
    int y = posY;

    std::vector<std::pair<int, int>> moves;

        int indexOfYUpEnemy = 0;
        bool YUpPieceFound = false;
        for(int i = y - 1;i >= 0;i--) {
            if(!YUpPieceFound) {
                x++;
                if(x == 7) {
                    YUpPieceFound = true;
                    indexOfYUpEnemy = i;
                }
                if(game->getAttackedPiece(x, i) != nullptr) {
                    YUpPieceFound = true;
                    if(game->getAttackedPiece(x, i)->isWhite() == w) {
                        indexOfYUpEnemy = i + 1;
                        x = x - 1;
                    }
                    else
                        indexOfYUpEnemy = i;
                }
            }
        }

        x = posX;

        for(int i = y;i >= indexOfYUpEnemy;i--) {
            moves.push_back(std::make_pair(x, i));
            x++;
        }

        x = posX;

        indexOfYUpEnemy = 0;
        YUpPieceFound = false;
        for(int i = y - 1;i >= 0;i--) {
            if(!YUpPieceFound) {
                x--;
                if(x == 0) {
                    YUpPieceFound = true;
                    indexOfYUpEnemy = i;
                }
                if(game->getAttackedPiece(x, i) != nullptr) {
                    YUpPieceFound = true;
                    if(game->getAttackedPiece(x, i)->isWhite() == w) {
                        indexOfYUpEnemy = i + 1;
                        x = x + 1;
                    }
                    else
                        indexOfYUpEnemy = i;
                }
            }
        }

        x = posX;

        for(int i = y;i >= indexOfYUpEnemy;i--) {
            moves.push_back(std::make_pair(x, i));
            x--;
        }

        x = posX;

        int indexOfYDownEnemy = 7;
        bool YDownPieceFound = false;
        for(int i = y + 1;i <= 7;i++) {
            if(!YDownPieceFound)
                x++;
                if(x == 7) {
                    YDownPieceFound = true;
                    indexOfYDownEnemy = i;
                }
                if(game->getAttackedPiece(x, i) != nullptr) {
                    YDownPieceFound = true;
                    if(game->getAttackedPiece(x, i)->isWhite() == w) {
                        indexOfYDownEnemy = i - 1;
                        x = x - 1;
                    }
                    else
                        indexOfYDownEnemy = i;
                }
        }

        x = posX;

        for(int i = y;i <= indexOfYDownEnemy;i++) {
            moves.push_back(std::make_pair(x, i));
            x++;
        }

        x = posX;

        indexOfYDownEnemy = 7;
        YDownPieceFound = false;
        for(int i = y + 1;i <= 7;i++) {
            if(!YDownPieceFound)
                x--;
                if(x == 0) {
                    YDownPieceFound = true;
                    indexOfYDownEnemy = i;
                }
                if(game->getAttackedPiece(x, i) != nullptr) {
                    YDownPieceFound = true;
                    if(game->getAttackedPiece(x, i)->isWhite() == w) {
                        indexOfYDownEnemy = i - 1;
                        x = x + 1;
                    }
                    else
                        indexOfYDownEnemy = i;
                }
        }

        x = posX;

        for(int i = y;i <= indexOfYDownEnemy;i++) {
            moves.push_back(std::make_pair(x, i));
            x--;
        }

        x = posX;

    return moves;
}
