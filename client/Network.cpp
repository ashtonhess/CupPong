//
// Created by Ashton Hess on 3/26/22.
//

#include "Network.h"

bool Network::connect(){
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        cout<<"> Error: Socket initialization."<<endl;
        return false;
    }
    sockAddy.sin_family = AF_INET;
    sockAddy.sin_port = htons(SERVER_PORT);
    //Converting IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, addyChar, &sockAddy.sin_addr)<=0){
        cout<<"> Error: Invalid address."<<endl;
        return false;
    }
    if (::connect(sock, (struct sockaddr *)&sockAddy, sizeof(sockAddy)) < 0){
        cout<<"> Error: Connection Failed."<<endl;
        return false;
    }
    return true;
}
bool Network::sendMsg(string msg){
return true;
}
int Network::login(string username, string password){
return 0;
}
int Network::signup(string username, string password){
return 0;
}