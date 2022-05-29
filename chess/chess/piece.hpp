#ifndef piece_h
#define piece_h

#include <SDL2/SDL.h>

class Piece{
protected:
    bool white;
    bool alive;
    
public:
    int posX;
    int posY;
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
    
    virtual void movePiece(SDL_Rect newPiece) = 0;
    
};

#endif /* piece_h */
