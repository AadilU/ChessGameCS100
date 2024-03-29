#include "window.hpp"
#include "piece.hpp"
#include "pawn.hpp"
#include "knight.hpp"
#include "game.hpp"
#include <string>
#include <iostream>
#include <algorithm>

void Window::create_window(){
    SDL_Window* wind = getWind();
    
    bool gameIsRunning = true;

    bool gameEnded = false;
    
    bool pieceSelected = false;
    int origPieceX = -1;
    int origPieceY = -1;

    bool check = false;

    std::vector<std::pair<int, int>> possibleMovesList;
    
    //error check
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "SDL could not be initialized" << SDL_GetError() << std::endl;
    }
    else{
        std::cout << "SDL video is ready to go " << std::endl;
    }

    const char* image_path = "images/whitePawn.bmp";
    SDL_Surface* surface = SDL_LoadBMP(image_path);
    SDL_Texture* wPawnTexture = SDL_CreateTextureFromSurface(getRend(), surface);

    surface = SDL_LoadBMP("images/blackPawn.bmp");
    SDL_Texture* bPawnTexture = SDL_CreateTextureFromSurface(getRend(), surface);

    surface = SDL_LoadBMP("images/whiteKnight.bmp");
    SDL_Texture* wKnightTexture = SDL_CreateTextureFromSurface(getRend(), surface);

    surface = SDL_LoadBMP("images/blackKnight.bmp");
    SDL_Texture* bKnightTexture = SDL_CreateTextureFromSurface(getRend(), surface);

    surface = SDL_LoadBMP("images/whiteRook.bmp");
    SDL_Texture* wRookTexture = SDL_CreateTextureFromSurface(getRend(), surface);

    surface = SDL_LoadBMP("images/blackRook.bmp");
    SDL_Texture* bRookTexture = SDL_CreateTextureFromSurface(getRend(), surface);

    surface = SDL_LoadBMP("images/whiteBishop.bmp");
    SDL_Texture* wBishopTexture = SDL_CreateTextureFromSurface(getRend(), surface);

    surface = SDL_LoadBMP("images/blackBishop.bmp");
    SDL_Texture* bBishopTexture = SDL_CreateTextureFromSurface(getRend(), surface);

    surface = SDL_LoadBMP("images/whiteQueen.bmp");
    SDL_Texture* wQueenTexture = SDL_CreateTextureFromSurface(getRend(), surface);

    surface = SDL_LoadBMP("images/blackQueen.bmp");
    SDL_Texture* bQueenTexture = SDL_CreateTextureFromSurface(getRend(), surface);

    surface = SDL_LoadBMP("images/whiteKing.bmp");
    SDL_Texture* wKingTexture = SDL_CreateTextureFromSurface(getRend(), surface);

    surface = SDL_LoadBMP("images/blackKing.bmp");
    SDL_Texture* bKingTexture = SDL_CreateTextureFromSurface(getRend(), surface);

    SDL_FreeSurface(surface);

    Game* game = new Game();

    Piece* selectedPiece = nullptr;
    while(gameIsRunning){
        SDL_Event event;
        clearRender();
        generateBoard();
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                gameIsRunning = false;
                std::cout << "game quit" << std::endl;
                //delete game;
            }
            if(event.type == SDL_MOUSEBUTTONDOWN){
                if(!pieceSelected) {
                int checkX = 0;
                int checkY = 0;
                SDL_GetMouseState(&checkX,&checkY);
                checkX = (checkX-10)/80;
                checkY = (checkY-10)/80;
                if(!gameEnded)
                    selectedPiece = game->getPieceFromPosition(checkX, checkY);
                //possibleMovesList.clear();
                if(selectedPiece != nullptr)
                    possibleMovesList = selectedPiece->possibleMoves(selectedPiece->isWhite(), game, true);
                }
                
                if(selectedPiece != nullptr && pieceSelected) {
                    int checkX = 0;
                    int checkY = 0;
                    SDL_GetMouseState(&checkX, &checkY);
                    Piece* attackedPiece = game->getAttackedPiece((checkX-10)/80, (checkY-10)/80);

                    std::pair<int, int> move = std::make_pair((checkX-10)/80, (checkY-10)/80);

                    if(std::find(possibleMovesList.begin(), possibleMovesList.end(), move) == possibleMovesList.end()) {
                        attackedPiece = nullptr;
                        selectedPiece = nullptr;
                    }

                    if(attackedPiece != nullptr) {
                        if(attackedPiece->isWhite() != game->whiteTurn) {
                            attackedPiece->posX = -10;
                            attackedPiece->posY = -10;
                            attackedPiece->movePiece(attackedPiece->pieceRect);
                        }
                        else
                            {
                                attackedPiece = nullptr;
                                selectedPiece = nullptr;
                            }
                    }

                    if(selectedPiece != nullptr) {
                        selectedPiece->posX = ((checkX)-10)/80;
                        selectedPiece->posY = ((checkY)-10)/80;
                        selectedPiece->movePiece(selectedPiece->pieceRect);

                        selectedPiece->firstMove = false;

                        if(!(selectedPiece->posX == origPieceX && selectedPiece->posY == origPieceY))
                            game->whiteTurn = !game->whiteTurn;

                        check = game->checkKingInDanger(nullptr);

                        if(check) {
                            std::cout << "Check" << endl;
                            Piece* king = nullptr;
                            for(int i = 0;i < 8;i++)
                                for(int j = 0;j < 8;j++) {
                                    Piece* possiblePiece = game->getAttackedPiece(i, j);
                                    if(possiblePiece != nullptr)
                                        if(possiblePiece->name == "king" && possiblePiece->isWhite() == game->whiteTurn)
                                            king = possiblePiece;
                                } 
                            if(king != nullptr) {
                                if(king->possibleMoves(king->isWhite(), game, true).empty()) {
                                    std::cout << "Check Mate" << endl;
                                    if(game->whiteTurn)
                                        std::cout << "Black wins" << endl;
                                    else
                                        std::cout << "White wins" << endl;
                                    gameEnded = true;
                                }
                            }
                        }

                        selectedPiece = nullptr;
                    }
                }
            }
            if(event.type == SDL_MOUSEBUTTONUP){
                
                if(selectedPiece != nullptr) {
                    pieceSelected = true;
                    origPieceX = selectedPiece->posX;
                    origPieceY = selectedPiece->posY;
                }
                else {
                    pieceSelected = false;
                    origPieceX = -1;
                    origPieceY = -1;
                    possibleMovesList.clear();
                }
            }
        }
        
        int projectX = 0;
        int projectY = 0;
        for(int i = 0; i < possibleMovesList.size();i++){
            projectX = possibleMovesList.at(i).first;
            projectY = possibleMovesList.at(i).second;
            //std::cout << "IM HERE also" << endl;
            placeGreenSquares(projectX, projectY);
        }
        
//        clearRender();
//        generateBoard();

        vector<SDL_Texture*> textureList;
        
        for(int i = 0;i < 8;i++) {
            for(int j = 0;j < 8;j++) {
                if(game->pieceList[i][j] != nullptr) {
                    std::string pieceName = game->pieceList[i][j]->name;
                    if(pieceName == "pawn") {
                        if(game->pieceList[i][j]->isWhite())
                            SDL_RenderCopy(getRend(), wPawnTexture, NULL, &(game->pieceList[i][j]->pieceRect));
                        else
                            SDL_RenderCopy(getRend(), bPawnTexture, NULL, &(game->pieceList[i][j]->pieceRect));
                    }
                    else
                        if(pieceName == "rook") {
                        if(game->pieceList[i][j]->isWhite())
                            SDL_RenderCopy(getRend(), wRookTexture, NULL, &(game->pieceList[i][j]->pieceRect));
                        else
                            SDL_RenderCopy(getRend(), bRookTexture, NULL, &(game->pieceList[i][j]->pieceRect));
                    }
                    else
                        if(pieceName == "knight") {
                        if(game->pieceList[i][j]->isWhite())
                            SDL_RenderCopy(getRend(), wKnightTexture, NULL, &(game->pieceList[i][j]->pieceRect));
                        else
                            SDL_RenderCopy(getRend(), bKnightTexture, NULL, &(game->pieceList[i][j]->pieceRect));
                    }
                    else
                        if(pieceName == "bishop") {
                        if(game->pieceList[i][j]->isWhite())
                            SDL_RenderCopy(getRend(), wBishopTexture, NULL, &(game->pieceList[i][j]->pieceRect));
                        else
                            SDL_RenderCopy(getRend(), bBishopTexture, NULL, &(game->pieceList[i][j]->pieceRect));
                    }
                    else
                        if(pieceName == "queen") {
                        if(game->pieceList[i][j]->isWhite())
                            SDL_RenderCopy(getRend(), wQueenTexture, NULL, &(game->pieceList[i][j]->pieceRect));
                        else
                            SDL_RenderCopy(getRend(), bQueenTexture, NULL, &(game->pieceList[i][j]->pieceRect));
                    }
                    else
                        if(pieceName == "king") {
                        if(game->pieceList[i][j]->isWhite())
                            SDL_RenderCopy(getRend(), wKingTexture, NULL, &(game->pieceList[i][j]->pieceRect));
                        else
                            SDL_RenderCopy(getRend(), bKingTexture, NULL, &(game->pieceList[i][j]->pieceRect));
                    }
            }
        }
    }

        //SDL_RenderCopy(getRend(), bPawnTexture, NULL, &(blackPawns.at(i))->pieceRect);
        SDL_RenderPresent(getRend());
        
        
    }
    SDL_DestroyTexture(wPawnTexture);
    SDL_DestroyTexture(bPawnTexture);
    SDL_DestroyTexture(wKnightTexture);
    SDL_DestroyTexture(bKnightTexture);
    SDL_DestroyTexture(wBishopTexture);
    SDL_DestroyTexture(bBishopTexture);
    SDL_DestroyTexture(wRookTexture);
    SDL_DestroyTexture(bRookTexture);
    SDL_DestroyTexture(wQueenTexture);
    SDL_DestroyTexture(bQueenTexture);
    SDL_DestroyTexture(wKingTexture);
    SDL_DestroyTexture(bKingTexture);
    SDL_DestroyWindow(wind);
    
    SDL_Quit();
}
