

#ifndef chessBoard_hpp
#define chessBoard_hpp

#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "square.hpp"
using namespace std;

class chessBoard : public square {
private:
    SDL_Rect board[8][8];
public:
    chessBoard();
    void generateBoard();
    void placeGreenSquares(int greenX,int greenY);
};

#endif /* chessBoard_hpp */
