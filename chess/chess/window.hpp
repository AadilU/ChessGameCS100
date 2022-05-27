
#ifndef window_hpp
#define window_hpp

#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "chessBoard.hpp"

class Window : public chessBoard{
public:
    void create_window();    
};

#endif /* window_hpp */
