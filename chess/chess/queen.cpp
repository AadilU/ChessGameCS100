
#include "queen.hpp"
#include "game.hpp"
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

std::vector<std::pair<int, int>> queen::possibleMoves(bool w, Game* game, bool select) {
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
            if(!YDownPieceFound) {
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
            if(!YDownPieceFound) {
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
        }

        x = posX;

        for(int i = y;i <= indexOfYDownEnemy;i++) {
            moves.push_back(std::make_pair(x, i));
            x--;
        }

        x = posX;

        indexOfYUpEnemy = 0;
        YUpPieceFound = false;
        for(int i = y - 1;i >= 0;i--) {
            if(!YUpPieceFound) {
                if(game->getAttackedPiece(x, i) != nullptr) {
                    YUpPieceFound = true;
                    if(game->getAttackedPiece(x, i)->isWhite() == w)
                        indexOfYUpEnemy = i + 1;
                    else
                        indexOfYUpEnemy = i;
                }
            }
        }

        for(int i = y;i >= indexOfYUpEnemy;i--) {
            moves.push_back(std::make_pair(x, i));
        }

        indexOfYDownEnemy = 7;
        YDownPieceFound = false;
        for(int i = y + 1;i <= 7;i++) {
            if(!YDownPieceFound) {
                if(game->getAttackedPiece(x, i) != nullptr) {
                    YDownPieceFound = true;
                    if(game->getAttackedPiece(x, i)->isWhite() == w)
                        indexOfYDownEnemy = i - 1;
                    else
                        indexOfYDownEnemy = i;
                }
            }
        }

        for(int i = y;i <= indexOfYDownEnemy;i++) {
            moves.push_back(std::make_pair(x, i));
        }

        int indexOfXLeftEnemy = 0;
        bool XLeftPieceFound = false;
        for(int i = x - 1;i >= 0;i--) {
            if(!XLeftPieceFound) {
                if(game->getAttackedPiece(i, y) != nullptr) {
                    XLeftPieceFound = true;
                    if(game->getAttackedPiece(i, y)->isWhite() == w)
                        indexOfXLeftEnemy = i + 1;
                    else
                        indexOfXLeftEnemy = i;
                }
            }
        }

        for(int i = x;i >= indexOfXLeftEnemy;i--) {
            moves.push_back(std::make_pair(i, y));
        }

        int indexOfXRightEnemy = 7;
        bool XRightPieceFound = false;
        for(int i = x + 1;i <= 7;i++) {
            if(!XRightPieceFound) {
                if(game->getAttackedPiece(i, y) != nullptr) {
                    XRightPieceFound = true;
                    if(game->getAttackedPiece(i, y)->isWhite() == w)
                        indexOfXRightEnemy = i - 1;
                    else
                        indexOfXRightEnemy = i;
                }
            }
        }

        for(int i = x;i <= indexOfXRightEnemy;i++) {
            moves.push_back(std::make_pair(i, y));
        }

    return moves;

}
