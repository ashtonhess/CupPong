//
// Created by Ashton Hess on 3/24/22.
//

#include "Game.h"


void Game::printGame(){
    printCupsAway();
    cout<<endl<<"\t\t-------------"<<endl<<endl;
    printCupsHome();
}
//Prints cup tower for AWAY team.
void Game::printCupsAway() {
    int c = 0;
    int offsetX = 22;
    for (int i = 4; i > 0; --i) {
        int s = offsetX - (i * 2);//Note: Good offset formula.
        for (int k = 0; k < s; ++k) {
            cout << " ";
        }
        for (int j = 0; j < i; ++j) {
            homeCups[(c-9)*-1].printCupAway();//Change this to printCupAway to change style of cup
            c++;
        }
        cout << endl;
    }
}

//Prints cup tower for HOME team.
void Game::printCupsHome() {
    int c=0;
    int offsetX=20;
    for (int i = 0; i < 4; ++i) {
        int s=offsetX-(i*2);//Note: Good offset formula.
        for (int k = 0; k < s; ++k) {
            cout<<" ";
        }
        for (int j = 0; j <= i; ++j) {
            homeCups[c].printCupHome();
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
