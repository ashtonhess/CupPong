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

class Game {

public:
    Cup homeCups[10];
    Cup awayCups[10];

//    void update();
    void printCupsHome();
    void printCupsAway();
    void printGame();

};




#endif //V1_GAME_H
