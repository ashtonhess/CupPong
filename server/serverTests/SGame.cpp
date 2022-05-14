//
// Created by ahess on 4/19/22.
//

#include "SGame.h"

bool SGame::throwResult(int keyboardHeroResult){
    if(keyboardHeroResult==0){
        return false;
    }
    if(keyboardHeroResult==10){
        return true;
    }
    srand((unsigned) time(0));
    int randNum;
    randNum = (rand() % 10 + 1);//generates a random number from 1-10
    if(randNum<=keyboardHeroResult){//if the random number is less than or = to result, it is a make.
        //cout<<"THROW MAKE"<<endl;
        return true;
    }else{
        //cout<<"THROW MISS"<<endl;
        return false;
    }
}


