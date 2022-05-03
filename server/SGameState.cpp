//
// Created by ahess on 4/19/22.
//

#include "SGameState.h"

int SGameState::end(){

    bool homeCupsEnd = true;
    for (int i = 0; i < 9; ++i) {
        if(homeCupsState[i]){
            homeCupsEnd = false;
        }
    }
    bool awayCupsEnd = true;
    for (int i = 0; i < 9; ++i) {
        if (awayCupsState[i]){
            awayCupsEnd = false;
        }
    }
    if(homeCupsEnd){
        //if no home cups, then away team wins.
        return 1;
    }
    if(awayCupsEnd){
        //if no away cups, then home team wins.
        return 2;
    }
    return 0;
    //checks all cups in both home and away. If any cup is true, game is not over.
//    for (int i = 0; i < 9; ++i) {
//        if(homeCupsState[i]){
//            return false;
//        }
//        if(awayCupsState[i]){
//            return false;
//        }
//    }
    //if no cups are true, game is over.
  //  return true;
}

string SGameState::getHomeState(){
    string returnString;
    //0 is false, 1 is true.
    for (int i = 0; i < 10; ++i) {
        if(!homeCupsState[i]){
            returnString+="0 ";
        }else{
            returnString+="1 ";
        }
    }
    return returnString;
}
string SGameState::getAwayState(){
    string returnString;
    //0 is false, 1 is true.
    for (int i = 0; i < 10; ++i) {
        if(!awayCupsState[i]){
            returnString+="0 ";
        }else{
            returnString+="1 ";
        }
    }
    return returnString;
}
void SGameState::switchTurn(){
    if(p1Turn){
        p1Turn=false;
    }else{
        p1Turn=true;
    }
}
void SGameState::genTranslateMap() {
    //nums
    translateMap.insert(pair<string, int>("49", 0));//key 1 cup
    translateMap.insert(pair<string, int>("50", 1));//2
    translateMap.insert(pair<string, int>("51", 2));//3
    translateMap.insert(pair<string, int>("52", 3));//4
    //lowercase
    translateMap.insert(pair<string, int>("113", 4));//q
    translateMap.insert(pair<string, int>("119", 5));//w
    translateMap.insert(pair<string, int>("101", 6));//e
    translateMap.insert(pair<string, int>("97", 7));//a
    translateMap.insert(pair<string, int>("115", 8));//s
    translateMap.insert(pair<string, int>("122", 9));//z
    //uppercase
    translateMap.insert(pair<string, int>("81", 4));//q
    translateMap.insert(pair<string, int>("87", 5));//w
    translateMap.insert(pair<string, int>("69", 6));//e
    translateMap.insert(pair<string, int>("65", 7));//a
    translateMap.insert(pair<string, int>("83", 8));//s
    translateMap.insert(pair<string, int>("90", 9));//z
}
int SGameState::translate(string str){
    return translateMap[str];
}
/* cupInput keys:
                '1'=49
                '2'=50
                '3'=51
                '4'=52
                    ' '=lowercase=uppercase
                'q'=113=81
                'w'=119=87
                'e'=101=69
                'a'=97=65
                's'=115=83
                'z'=122=90
*/