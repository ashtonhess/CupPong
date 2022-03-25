//
// Created by Ashton Hess on 3/24/22.
//

#include "Cup.h"
// ‾
void Cup::printCupAway() {
    if (this->active){
        cout<<" /‾\\";
    }else{
        cout<<"\t";
    }
}
void Cup::printCupHome() {
    if (this->active){
        cout<<" \\_/";
    }else{
        cout<<"\t";
    }
}