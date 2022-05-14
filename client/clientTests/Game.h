//
// Created by Ashton Hess on 3/24/22.
//

#ifndef V1_GAME_H
#define V1_GAME_H
#include <iostream>
#include <string>
using namespace std;

#include "Cup.h"
#include "Network.h"
#include "KeyboardHero.h"

class Game: public KeyboardHero {

public:
    Game(){
        player=0;
        turn=false;
        for (int i = 0; i < 10; ++i) {
            homeCups[i].active=true;
            awayCups[i].active=true;
        }
    }
    int player;
    bool turn;
    Cup homeCups[10];
    Cup awayCups[10];

//    void update();
    void printCupsHome();
    void printCupsAway();
    void printGame();
    void switchTurn();

};




#endif //V1_GAME_H
