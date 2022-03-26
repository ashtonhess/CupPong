//
// Created by Ashton Hess on 3/25/22.
//

#include "Network.h"

bool Network::connect(){
    //creating FD (file descriptor) for socket.
    if ((serverFD = socket(AF_INET,SOCK_STREAM,0)) == 0){
        perror("> Error: setting server file descriptor.\n");
        return false;
    }
    if(setsockopt(serverFD, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))){
        cout<<"> Error: setsockopt()"<<endl;
        return false;
    }
    addy.sin_family = AF_INET;
    addy.sin_addr.s_addr = INADDR_ANY;
    addy.sin_port = htons(SERVER_PORT);//host byte order->network byte order
    //Binding socket
    //Must use scope resolution operator '::' here to call bind() from the socket import,
    // since I'm using the std namespace. This is because std::bind() also exists.
    if (::bind(serverFD, (struct sockaddr *)&addy, sizeof(addy)) < 0 ){
        cout<<"> Error: binding socket."<<endl;
        return false;
    }
    //listening on the socket for a new connection. Next, accept a socket connection and store it
    if (listen(serverFD, MAX_PENDING) < 0) {
        cout<<"> Error: listening on socket."<<endl;
        return false;
    }
    //accepting and storing a socket connection
    if ((currentSocket = accept(serverFD, (struct sockaddr *) &addy, (socklen_t *) &addy)) < 0) {
        cout<<"> Error: accepting the socket."<<endl;
        return false;
    }else{
        return true;
    }
}

int Network::login(string username, string password){
    vector<User> allUsersVec;

    allUsersVec=FileIO().readUsers();
    for (auto it = begin (allUsersVec); it != end (allUsersVec); ++it) {
        if(it->getUsername()==username&&it->getPassword()==password){
            //cout<<it->getUserID()<<" login."<<endl;//---------------------------------------------------------------NEEDED--------------------------------------------------------------------------
            return 1;
        }else if(it->getUsername()==username&&it->getPassword()!=password){
            return 2;
        }
    }
    return 0;
}

int Network::newUser(string username, string password){

    return 0;
}