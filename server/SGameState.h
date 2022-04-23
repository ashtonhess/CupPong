//
// Created by ahess on 4/19/22.
//

#ifndef CUPPONG_SGAMESTATE_H
#define CUPPONG_SGAMESTATE_H
#include <iostream>
using namespace std;
#include <string>
#include <map>

class SGameState {
public:
    bool p1Turn;
    bool homeCupsState[10];
    bool awayCupsState[10];
    map<string, int> translateMap;
    string getHomeState();
    string getAwayState();
    void switchTurn();
    void genTranslateMap();
    bool end();
    int translate(string str);

};


#endif //CUPPONG_SGAMESTATE_H
