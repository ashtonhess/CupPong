//
// Created by Ashton Hess on 3/25/22.
//

#include <iostream>
#include<unistd.h>
#include <pthread.h>
#include "Singleton.h"
#include "Network.h"



//disabling inf loop inspection for this file in CLion. Perm fix. Comment out to make work with -Werror.
#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
//comment

void *func(void*arg){
    cout<<"This is a thread running func()"<<endl;
    bool boolV=true;
    while (true){
        Network network = Network();
        if(boolV){
            if(network.connect()){
                cout<<"Network connected."<<endl;
                boolV=false;
            }
        }

        int sock;
        sock=network.acceptConnection();
        cout<<"sock accepted: "<<sock<<endl;
        sleep(3);


    }

    pthread_exit(NULL);
}

int main(int argc, char*argv[]){
    FileIO *f = new FileIO();
    f->setFilename("users.txt");
    Singleton::getInstance()->setFile(*f);
    Singleton*singler = Singleton::getInstance();
    cout<<"Filename: " <<singler->getFile().getFilename()<<endl;
    singler->getFile().readUsers();


    vector<pthread_t> threads;
    pthread_t t1;
    int res;
    //Network networkObj = Network();
    //if (networkObj.connect()) {
        res=pthread_create(&t1, NULL, &func, NULL);
        if (res!=0){
            cout<<"> Error creating thread."<<endl;
        }

        cout<<"After thread"<<endl;
        pthread_exit(NULL);
    //}else{
    //    cout<<"> Error connecting to network."<<endl;
    //}

//    Network networkObj = Network();
//    if (networkObj.connect()) {
//
//    }


    /*
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


                break;
            }

            //isActive=false;
        }

    }else{
        cout<<"Network is not connected"<<endl;
    }
     */

}

#pragma clang diagnostic pop




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