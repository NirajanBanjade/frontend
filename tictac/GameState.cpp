/*
Assignment: 4
filename: GameState.cpp
Nirajan Banjade
Due: Nov 31,2023
*/

#include "GameState.h"
#include "Movestack.h"

using namespace std;

GameState ::GameState()
{
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            boardState[i][j]='_';
        }       
    }
}
Movestack& GameState::getmoveStack(){
    return moveStack;
}
int GameState::getCurrentPlayer(){

    return (moveStack.getSize()%2==0) ? 0:1;

}
int GameState:: addMove(Move move){
    if(moveStack.getSize()==9){
        return 0;
    }
    else{
    if((boardState[move.x][move.y] =='_')){
        if(getCurrentPlayer()==0){
            boardState[move.x][move.y]='o';
        }else{
            boardState[move.x][move.y]='x';
        }
        return 1;
    }
    else{
        return -1;
    }

}
}
bool GameState:: undoLast(){
    if(moveStack.isEmpty()){
        return false;
    }
    boardState[moveStack.top().x][moveStack.top().y]='_';
    moveStack.pop();
    
    return true;
}
void GameState:: displayBoardState(std::ostream &out){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<boardState[i][j]<<"  ";
        }
        cout<<endl;
    }

}
bool GameState:: checkLastPlayerWin(){
    char targetSymbol = getCurrentPlayer() ? 'x' : 'o';
    int sumHorizontal, sumVertical;
    for (int i = 0; i < 3; ++i){
        sumHorizontal = 0;
        sumVertical = 0;
        for (int j = 0; j < 3; ++j){
            sumHorizontal += boardState[i][j] == targetSymbol;
            sumVertical += boardState[j][i] == targetSymbol;
        }
        if (sumHorizontal == 3 || sumVertical == 3)
            return true;
    }
    int sumDiagonal1 = 0, sumDiagonal2 = 0;
    for (int i = 0; i < 3; ++i){
        sumDiagonal1 += boardState[i][i] == targetSymbol;
        sumDiagonal2 += boardState[i][2 - i] == targetSymbol;
    }
    if (sumDiagonal1 == 3 || sumDiagonal2 == 3)
        return true;

    return false;
}


