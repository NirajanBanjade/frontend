#include "GameState.h"
#include <iostream>

using namespace std;

int main(){

    GameState gameState;
    Movestack& n1=gameState.getmoveStack();
    Move finalMove;

    char undo;
    while(!gameState.checkLastPlayerWin()){
        
        if(n1.getSize()==9){
            cout<<"The game is draw!!!!";
            return 0;
        }

        gameState.displayBoardState(cout);
        cout<<"Player "<<gameState.getCurrentPlayer()<<" make a turn!!"<<endl;

        cin>>finalMove.x>>finalMove.y;

        
        
        if (gameState.addMove(finalMove)==1){   
            if(gameState.checkLastPlayerWin()==true){
                gameState.displayBoardState(cout);
                cout<<"Player "<<gameState.getCurrentPlayer()<<" won the game !!!!!"<<endl;
                
    
                exit(1); 
            }else{        
                n1.push(finalMove);
            }
            
        }
        else if(gameState.addMove(finalMove)==-1){
            cout<<"Invalid move!!!"<<endl;
            continue;
        }

        
        gameState.displayBoardState(cout);

        cout<<"Want to undo? "<<endl;
        cin>>undo;
        if((undo =='y')||(undo=='Y')){
            gameState.undoLast();
          
            // gameState.displayBoardState(cout);
        }

    }
    


    return 0;
}


