
#include "chessBoard.hpp"

chessBoard::chessBoard(){

    int newX = 0;
    int newY = 0;
    for(int i = 0; i<8;i++){
        for(int j = 0; j<8;j++){
            if(i == 0 && j ==0){
                board[i][j].x = 0;
                board[i][j].y = 0;
            }
            else if(i == 1 && j==0){
                newX = 0;
                newY += 80;
                board[i][j].x = 0;
                board[i][j].y = 80;
            }
            else if(i == 2 && j==0){
                newX = 0;
                newY += 80;
                board[i][j].x = 0;
                board[i][j].y = 160;
            }
            else if(i == 3 && j==0){
                newX = 0;
                newY += 80;
                board[i][j].x = 0;
                board[i][j].y = 240;
            }
            else if(i == 4 && j==0){
                newX = 0;
                newY += 80;
                board[i][j].x = 0;
                board[i][j].y = 320;
            }
            else if(i == 5 && j==0){
                newX = 0;
                newY += 80;
                board[i][j].x = 0;
                board[i][j].y = 400;
            }
            else if(i == 6 && j==0){
                newX = 0;
                newY += 80;
                board[i][j].x = 0;
                board[i][j].y = 480;
            }
            else if(i == 7 && j==0){
                newX = 0;
                newY += 80;
                board[i][j].x = 0;
                board[i][j].y = 560;
            }
            else{
                newX +=80;
                board[i][j].x = newX;
                board[i][j].y = newY;
                
            }
        }
    }
}


void chessBoard::generateBoard(){
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            if((i+j)%2==0){
                create_WhiteSquare(board[i][j]);
            }
            else{
                //cout << "works";
                create_BlueSquare(board[i][j]);
            }
        }
    }
}

void chessBoard::placeGreenSquares(int greenX, int greenY){
    for(int i = 0; i< 8; i++){
        for(int j = 0; j < 8; j++){
            if((board[i][j].x == greenX*80) && (board[i][j].y == greenY*80)){
                if((i+j)%2==0){
                    create_GreenSquare(board[i][j]);
                }
                else{
                    create_OtherGreenSquare(board[i][j]);
                }
            }
        }
    }
}
