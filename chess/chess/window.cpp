#include "window.hpp"


void Window::create_window(){
    SDL_Window* wind = getWind();
    
    bool gameIsRunning = true;
    

    
    //error check
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "SDL could not be initialized" << SDL_GetError() << std::endl;
    }
    else{
        std::cout << "SDL video is ready to go " << std::endl;
    }
    const char* image_path = "images/pawn.bmp";
    SDL_Surface* surface = SDL_LoadBMP(image_path);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(getRend(), surface);
    SDL_FreeSurface(surface);
    
    SDL_Rect test;
    test.x = 90;
    test.y = 10;
    test.w = 60;
    test.h = 60;
    
    while(gameIsRunning){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                gameIsRunning = false;
                std::cout << "game quit" << std::endl;
            }
        }
        clearRender();
        generateBoard();
        
        
        SDL_RenderCopy(getRend(), texture, NULL, &test);
        SDL_RenderPresent(getRend());
        
        
    }
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(wind);
    
    SDL_Quit();
}