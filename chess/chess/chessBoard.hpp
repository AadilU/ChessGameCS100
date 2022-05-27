

#ifndef chessBoard_hpp
#define chessBoard_hpp

#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "square.hpp"
using namespace std;

class chessBoard : public square {
private:
    SDL_Rect board[64];
public:
    chessBoard();
    void generateBoard();
    
};

#endif /* chessBoard_hpp */
