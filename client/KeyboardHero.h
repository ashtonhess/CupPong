//CLIENT
// Created by ahess on 4/13/22.
//

#ifndef CUPPONG_KEYBOARDHERO_H
#define CUPPONG_KEYBOARDHERO_H

#include <iostream>
using namespace std;
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctime>
#include <chrono>
#include <thread>

#define GAMESPEED 150

class KeyboardHero {
private:
public:
    KeyboardHero(){}
    int keypress();
    void printLetterLine(int letter);
    void printEmptyLine();
    int play();
};


#endif //CUPPONG_KEYBOARDHERO_H
