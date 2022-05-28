#ifndef piece_h
#define piece_h

#include <SDL2/SDL.h>

class Piece{
protected:
    bool white;
    bool alive;
    int posX;
    int posY;
    
public:
    SDL_Rect pieceRect;
    const char* image_path;
    void kill() {
        alive = false;
    }

    bool isDead() {
        return (!alive);
    }

    bool isWhite() {
        return white;
    }
    //virtual bool canMove(square* moveSquare) = 0;
    
    virtual void renderPiece(SDL_Rect newPiece) = 0;
    
};

#endif /* piece_h */