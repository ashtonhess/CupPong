//
// Created by Ashton Hess on 3/25/22.
//

#include <iostream>
#include <pthread.h>
#include "Singleton.h"
#include "Network.h"

//disabling inf loop inspection for this file in CLion. Perm fix.
#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
//comment
int main(int argc, char*argv[]){
    FileIO *f = new FileIO();
    f->setFilename("users.txt");
    Singleton::getInstance()->setFile(*f);
    Singleton*singler = Singleton::getInstance();
    cout<<"Filename: " <<singler->getFile().getFilename()<<endl;

    Network networkObj = Network();
    bool isActive=false;

    if(networkObj.connect()){
        isActive=true;
        int sock;
        int numOfConnections=0;
        bool acceptingPair=true;
        while(isActive){
            //store socket connection values for pair
            int s1;
            int s2;
            while (acceptingPair){
                sock=networkObj.acceptConnection();
                if (sock==-1){
                    cout<<"> Error: Network::acceptConnection().";
                    //return -1;//returning
                }else if (sock==-2){
                    isActive=false;//THIS ELSE IF IS TO MAKE INF LOOP HIGHLIGHT GO AWAY IN CLION. NOT ACTUALLY USED.
                                    //ended up disabling inf loop inspection for this file in CLion. Perm fix. This is not needed anymore.
                }else{
                    //add this socket to list for matchmaking...
                    numOfConnections++;
                    if(numOfConnections==2){//if we have a pair of sockets, stop accepting new connections.
                        s2=sock;//store value of second socket connected.
                        cout<<"s2: "<<s2<<endl;
                        cout<<"Pair of sockets accepted:"<<endl<<"\ts1: "<<s1<<endl<<"\ts2: "<<s2<<endl;
                        acceptingPair=false;
                    }else{
                        s1=sock;//store value of first socket connected.
                        cout<<"s1: "<<s1<<endl;
                    }
                    networkObj.sendMsg("Welcome to Cup Pong!\n");
                    //once match is found, add both users into a thread of a game instance...

                }
            }
            while(true){


            }

            //isActive=false;
        }

    }else{
        cout<<"Network is not connected"<<endl;
    }
//    bool isConnected = false;
//    while(!isConnected){
//        isConnected=networkObj.connect();
//    }
//    while(isConnected){
//
//
//
//        isConnected=false;
//    }


}

#pragma clang diagnostic pop