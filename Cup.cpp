//
// Created by Ashton Hess on 3/24/22.
//

#include "Cup.h"

void Cup::printCup() {
    if (this->active){
        cout<<" \\_/";
    }else{
        cout<<"\t";
    }
}