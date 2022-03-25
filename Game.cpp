//
// Created by Ashton Hess on 3/24/22.
//

#include "Game.h"

//1
//2
//3
//4

void Game::printCups() {
    int c=0;
    int offsetX=7;
    for (int i = 0; i < 4; ++i) {

        int s=offsetX-(i*2);//Note: Good offset formula.
        //changes the offset of the cups
//        if(s==4){
//            s--;
//        }
        for (int k = 0; k < s; ++k) {
            cout<<" ";
        }
        for (int j = 0; j <= i; ++j) {
            cups[c].printCup();
            c++;
        }
        cout<<endl;
    }

}

//    for (int i = 0; i < 10; ++i) {
//        if (cups[i].active==true){
//            cups[i].printCup();
//        }
//    }
