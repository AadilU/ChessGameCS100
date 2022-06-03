#ifndef piece_h
#define piece_h

#include <SDL2/SDL.h>
#include <string>

#include <vector>
#include <iostream>

class Game;

class Piece{
protected:
    bool white;
    bool alive;
    
public:
    bool firstMove = true;
    int posX;
    int posY;
    SDL_Rect pieceRect;
    const char* image_path;
    std::string name;

    void kill() {
        alive = false;
    }

    bool isDead() {
        return (!alive);
    }

    bool isWhite() {
        return white;
    }

    virtual ~Piece() = default;


    virtual std::vector<std::pair<int, int>> possibleMoves(bool w, Game* game, bool select) = 0;
    
    void movePiece(SDL_Rect newPiece) {
    pieceRect.x = (posX*80)+10;
    pieceRect.y = (posY*80)+10;

    this->firstMove = false;

    }

};

#endif /* piece_h */
