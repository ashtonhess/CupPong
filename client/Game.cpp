//
// Created by Ashton Hess on 3/24/22.
//

#include "Game.h"

//void update(){
//    string msg;
//    Network*net;
//    net = new Network;
//    msg=net->recvMsg();
//
//}

void Game::printGame(){
    printCupsAway();
    cout<<endl<<"\t\t-------------"<<endl<<endl;
    printCupsHome();
    cout<<endl;
    cout<<"Use the keyboard to choose your shot and press enter!"<<endl;
}
//Prints cup tower for AWAY team. (Underlined letters and nums so player can choose cup)
void Game::printCupsAway() {
    int c = 0;
    int offsetX = 22;
    for (int i = 4; i > 0; --i) {
        int s = offsetX - (i * 2);//Note: Good offset formula.
        for (int k = 0; k < s; ++k) {
            cout << " ";
        }
        for (int j = 0; j < i; ++j) {
            homeCups[(c-9)*-1].printCupAway(c);
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
void Game::switchTurn(){
    if(turn){
        turn=false;
    }else{
        turn=true;
    }
}


//    for (int i = 0; i < 10; ++i) {
//        if (cups[i].active==true){
//            cups[i].printCup();
//        }
//    }
