//
// Created by ahess on 4/19/22.
//

#ifndef CUPPONG_SGAMESTATE_H
#define CUPPONG_SGAMESTATE_H
#include <iostream>
using namespace std;
#include <string>

class SGameState {
public:
    bool p1Turn;
    bool homeCupsState[10];
    bool awayCupsState[10];
    string getHomeState();
    string getAwayState();
};


#endif //CUPPONG_SGAMESTATE_H
