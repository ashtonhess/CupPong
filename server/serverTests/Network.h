//SERVER
// Created by Ashton Hess on 3/25/22.
//

#ifndef V1_NETWORK_H
#define V1_NETWORK_H

#include <iostream>
using namespace std;
#include <stdlib.h>
#include <stdio.h>

#include <string>
#include<vector>
#include <algorithm>
#include <cstring>

#include <sys/socket.h>
#include <netinet/in.h>//sockaddr_in

#include "User.h"
#include "Singleton.h"

#define SERVER_PORT 11328
#define MAX_PENDING 5
#define MAX_LINE 256

class Network {
private:
    //File descriptor for stocket.
    int serverFD;
    //stores the accepted socket connection
    int currentSocket;
    int opt=1;
    struct sockaddr_in addy;
public:
    Network(){}
    bool connect();
    int acceptConnection();
    bool sendMsg(int sock, string msg);
    int login(string username, string password);
    int newUser(string username, string password);
    string recvMsg(int sock);

};


#endif //V1_NETWORK_H
