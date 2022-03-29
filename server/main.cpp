//
// Created by Ashton Hess on 3/25/22.
//

#include <iostream>
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
            sock=networkObj.acceptConnection();
            if (sock==-1){
                cout<<"> Error: Network::acceptConnection().";
            }else{
                //add this socket to list for matchmaking...

                //once match is found, add both users into a thread of a game instance...

            }


            isActive=false;
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
