/*
Assignment: 4
filename: GameState.h
Nirajan Banjade
Due: Nov 31,2023
*/

#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <iostream>
#include "Movestack.h"


class GameState {
    char boardState[3][3];
    Movestack moveStack;
    public:

    GameState();
    Movestack& getmoveStack();
    int getCurrentPlayer();
    int addMove(Move move);
    bool undoLast();
    void displayBoardState(std::ostream& out);
    bool checkLastPlayerWin();
};

#endif 