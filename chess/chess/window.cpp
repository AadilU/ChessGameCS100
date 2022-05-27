
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
        SDL_RenderPresent(getRend());
        
        
    }
    
    SDL_DestroyWindow(wind);
    
    SDL_Quit();
}

