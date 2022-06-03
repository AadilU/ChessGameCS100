

#ifndef square_hpp
#define square_hpp

#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

class square{
private:
    SDL_Window* window;
    SDL_Renderer* render;
    int width;
    int height;
public:
    square();
    ~square();
    void create_BlueSquare(SDL_Rect squar);
    void create_WhiteSquare(SDL_Rect squar);
    void create_GreenSquare(SDL_Rect squar);
    void clearRender();
    SDL_Window* getWind();
    SDL_Renderer* getRend();
    
};

#endif /* square_hpp */
