//
// Created by Ashton Hess on 3/25/22.
//

#include <iostream>
#include <pthread.h>
#include "Singleton.h"
#include "Network.h"

//comment
int main(int argc, char*argv[]){
    FileIO *f = new FileIO();
    f->setFilename("users.txt");
    Singleton::getInstance()->setFile(*f);
    Singleton*singler = Singleton::getInstance();
    cout<<"Filename: " <<singler->getFile().getFilename()<<endl;

    Network networkObj = Network();
    bool isActive=false;

    //1 is connected
    //cout<<"Network connect result: "<<(bool)networkObj.connect()<<endl;
    if(networkObj.connect()){
        isActive=true;
        int sock;
        while(isActive){
            bool acceptingPair=true;
            int numOfConnections=0;
            int s1;
            int s2;
            while (acceptingPair){
                sock=networkObj.acceptConnection();
                if (sock==-1){
                    cout<<"> Error: Network::acceptConnection().";
                    //return -1;//returning

                }else if (sock==-2){
                    isActive=false;//THIS ELSE IF IS TO MAKE INF LOOP HIGHLIGHT GO AWAY.
                }else{
                    //add this socket to list for matchmaking...

                    numOfConnections++;
                    if(numOfConnections==2){
                        s2=sock;
                        cout<<"s2 "<<s2<<endl;
                        acceptingPair=false;
                    }else{
                        s1=sock;
                        cout<<"s1: "<<s1<<endl;
                    }
                    networkObj.sendMsg("Welcome to Cup Pong!\n");



                    //once match is found, add both users into a thread of a game instance...

                }
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
