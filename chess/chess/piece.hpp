#ifndef piece_h
#define piece_h

#include <SDL2/SDL.h>
#include <string>

class Piece{
protected:
    bool white;
    bool alive;
    
public:
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
    //virtual bool canMove(square* moveSquare) = 0;
    
    void movePiece(SDL_Rect newPiece) {
    pieceRect.x = (posX*80)+10;
    pieceRect.y = (posY*80)+10;
    }

};

#endif /* piece_h */
