//
// Created by Ashton Hess on 3/26/22.
//

#ifndef V1_NETWORK_H
#define V1_NETWORK_H

#include <iostream>
using namespace std;
#include <stdlib.h>
#include <stdio.h>

#include <string>
#include<vector>

#include <sys/socket.h>
#include <netinet/in.h>//sockaddr_in

#define SERVER_PORT 11328
#define MAX_LINE 256
//#define MAX_PENDING 5

class Network {
private:
    int sock=0;
    char* addy="127.0.0.1";//setting addy to the local loopback IP addy
    struct sockaddr_in sockAddy;
public:
};


#endif //V1_NETWORK_H
