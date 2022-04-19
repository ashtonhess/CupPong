//
// Created by ahess on 4/19/22.
//

#include "SGameState.h"

string SGameState::getHomeState(){
    string returnString;
    //0 is false, 1 is true.
    for (int i = 0; i < 10; ++i) {
        if(!homeCupsState[i]){
            returnString+="0";
        }else{
            returnString+="1";
        }
    }
    return returnString;
}
string SGameState::getAwayState(){
    string returnString;
    //0 is false, 1 is true.
    for (int i = 0; i < 10; ++i) {
        if(!awayCupsState[i]){
            returnString+="0";
        }else{
            returnString+="1";
        }
    }
    return returnString;
}