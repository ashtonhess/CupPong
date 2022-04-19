//
// Created by ahess on 4/19/22.
//

#ifndef CUPPONG_SGAME_H
#define CUPPONG_SGAME_H
#include <iostream>
using namespace std;
#include "SGameState.h"

class SGame: public SGameState {
private:
public:

    bool throwResult(int keyboardHeroResult);

    SGame(){
        //Game starts with player1
        p1Turn=true;
        //Initializing home and away cups' state to true. All cups on board to begin.
        for (int i = 0; i < 10; ++i) {
            homeCupsState[i]=true;
            awayCupsState[i]=true;
        }
    }


};


#endif //CUPPONG_SGAME_H
