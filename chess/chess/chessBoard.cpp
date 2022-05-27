
#include "chessBoard.hpp"

chessBoard::chessBoard(){

    int newX = 0;
    for(int i = 0; i<64;i++){
        if(i%8 == 0){
            board[i].x = 0;

            newX = 0;
        }
        else{
            newX += 80;
            board[i].x = newX;
        }
        if(i <= 8){
            board[i].y = 0;
        }
        if(i >= 8 && i < 16){
            board[i].y = 80;
        }
        if(i >= 16 && i < 24){
            board[i].y = 160;
        }
        if(i >= 24 && i < 32){
            board[i].y = 240;
        }
        if(i >= 32 && i < 40){
            board[i].y = 320;
        }
        if(i >= 40 && i < 48){
            board[i].y = 400;
        }
        if(i >= 48 && i < 56){
            board[i].y = 480;
        }
        if(i >= 56){
            board[i].y = 560;
        }
    }
}


void chessBoard::generateBoard(){
    int index = 0;
    for(int i = 0; i<8; i++){
        for(int j =0; j<8; j++){
            if((i+j)%2==0){
                create_WhiteSquare(board[index]);
            }
            else{
                create_BlueSquare(board[index]);
            }
            index++;
        }
    }
}
