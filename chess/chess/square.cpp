
#include "square.hpp"

square::square(){
    window = SDL_CreateWindow("Chess", 0, 0, 640, 640, SDL_WINDOW_SHOWN);
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    width = 80;
    height = 80;
}

square::~square(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(render);
}

void square::create_BlueSquare(SDL_Rect squar){
    
    squar.w = width;
    squar.h = height;
    
    SDL_SetRenderDrawColor(render,135,206,250,SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(render,&squar);
    SDL_RenderFillRect(render, &squar);
    
    
    
}

void square::create_WhiteSquare(SDL_Rect squar){

    squar.w = width;
    squar.h = height;
    
    SDL_SetRenderDrawColor(render,245,245,220,SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(render,&squar);
    SDL_RenderFillRect(render,&squar);
    
    
}

SDL_Window* square::getWind(){
    return this->window;
}

SDL_Renderer* square::getRend(){
    return this->render;
}

void square::clearRender(){
    SDL_SetRenderDrawColor(render,0,0,0,SDL_ALPHA_OPAQUE);
    SDL_RenderClear(render);
}
