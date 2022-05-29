#ifndef piece_h
#define piece_h

#include <SDL2/SDL.h>
#include <string>

class Piece{
protected:
    bool white;
    bool alive;
    int posX;
    int posY;
    
public:
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
    
    void movePiece(int x, int y) {
    posX = x;
    posY = y;
    
    pieceRect.x = (posX*80)+10;
    pieceRect.y = (posY*80)+10;
    pieceRect.w = 60;
    pieceRect.h = 60;
    }
    
};

#endif /* piece_h */