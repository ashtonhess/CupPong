//
// Created by Ashton Hess on 3/24/22.
//

#ifndef V1_CUP_H
#define V1_CUP_H
#include <iostream>
using namespace std;

class Cup {

public:
    Cup(){
        active=true;
    }
    bool active;
    void printCup();
};


#endif //V1_CUP_H
