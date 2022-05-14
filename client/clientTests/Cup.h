//
// Created by Ashton Hess on 3/24/22.
//

#ifndef V1_CUP_H
#define V1_CUP_H
#include <iostream>
using namespace std;
//This allows for underlining strings.
#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"

class Cup {

public:
    Cup(){
        //cups are active by default
        active=true;
    }
    Cup(bool active){
        //to set a cup to inactive.. also to set it to active
        this->active=active;
    }
    bool active;
    //int cupNum;
    //prints cups on other side of board
    void printCupAway(int cupNum);
    //prints cups on same side of board
    void printCupHome();
};


#endif //V1_CUP_H
