#include "window.hpp"
#include "piece.hpp"
#include "pawn.hpp"
#include "vector"

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

    const char* image_path = "project/finalProj/chess/chess/images/whitePawn.bmp";
    SDL_Surface* surface = SDL_LoadBMP(image_path);
    SDL_Texture* wPawnTexture = SDL_CreateTextureFromSurface(getRend(), surface);

    surface = SDL_LoadBMP("project/finalProj/chess/chess/images/blackPawn.bmp");
    SDL_Texture* bPawnTexture = SDL_CreateTextureFromSurface(getRend(), surface);
    SDL_FreeSurface(surface);

    vector<Piece*> blackPawns;
    for(int i = 0;i < 8;i++) {
        blackPawns.push_back(new pawn(false, i, 1));
    }

    vector<Piece*> whitePawns;
    for(int i = 0;i < 8;i++) {
        whitePawns.push_back(new pawn(true, i, 6));
    }

    while(gameIsRunning){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                gameIsRunning = false;
                std::cout << "game quit" << std::endl;
            }
            if(event.type == SDL_MOUSEBUTTONDOWN){
                int checkX = 0;
                int checkY = 0;
                int index;
                SDL_GetMouseState(&checkX,&checkY);
                checkX = (checkX-10)/80;
                checkY = (checkY-10)/80;
                for(int i = 0;i<whitePawns.size();i++){
                    if( checkX == whitePawns.at(i)->posX && checkY == whitePawns.at(i)->posY){
                        index = i;
                    }
                }
                
                SDL_GetMouseState(&(whitePawns.at(index))->pieceRect.x,&(whitePawns.at(index))->pieceRect.y);
                whitePawns.at(index)->posX = ((whitePawns.at(index)->pieceRect.x)-10)/80;
                whitePawns.at(index)->posY = ((whitePawns.at(index)->pieceRect.y)-10)/80;
                whitePawns.at(index)->movePiece(whitePawns.at(index)->pieceRect);
            }
        }
        clearRender();
        generateBoard();
        
        for(int i = 0;i < whitePawns.size();i++) {
            SDL_RenderCopy(getRend(), wPawnTexture, NULL, &(whitePawns.at(i))->pieceRect);
        }
        for(int i = 0;i < blackPawns.size();i++) {
            SDL_RenderCopy(getRend(), bPawnTexture, NULL, &(blackPawns.at(i))->pieceRect);
        }
        SDL_RenderPresent(getRend());
        
        
    }
    SDL_DestroyTexture(wPawnTexture);
    SDL_DestroyTexture(bPawnTexture);
    SDL_DestroyWindow(wind);
    
    SDL_Quit();
}
