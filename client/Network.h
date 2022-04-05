//CLIENT
// Created by Ashton Hess on 3/26/22.
//

#ifndef V1_NETWORK_H
#define V1_NETWORK_H

#include <iostream>
using namespace std;
#include <stdlib.h>
#include <stdio.h>

#include <string>
#include <cstring>
#include<vector>

#include <sys/socket.h>
#include <netinet/in.h>//sockaddr_in
#include <arpa/inet.h>
#include <netdb.h>


#define SERVER_PORT 11328
#define MAX_LINE 256
//#define MAX_PENDING 5

class Network {
private:
    int sock=0;
    //string addy="127.0.0.1";//setting addy to the local loopback IP addy
    //string addy="192.168.15.118";//local addy if on network...
    //string addy="35.129.56.107";//addy for outside of network...
    string addy="cuppong.hessdevelopments.com";//using hostname. Dynamic DNS is setup, so this will always
                                                //ensure we are getting the correct IP address for the server.
    const char *addyChar=addy.c_str();
    char ip[256];
    struct sockaddr_in sockAddy;
public:
    bool connect();
    bool sendMsg(string msg);
    int login(string username, string password);
    int signup(string username, string password);
    int hostname_to_ip(char *hostname , char *ip);
    string recvMsg();

};


#endif //V1_NETWORK_H
