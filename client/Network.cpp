//CLIENT
// Created by Ashton Hess on 3/26/22.
//

#include "Network.h"

bool Network::connect(){

    //This function resolves the hostname into an ip address. So, instead of using a hardcoded IP,
    //which could change and fail, we will now always get the current IP for the domain name. This along with
    //dynamic DNS should ensure server is always found.
    if(hostnameToIP(const_cast<char*>(addyChar), ip)==1){
        cout<<"> Error: Resolving hostname."<<endl;
        return false;
    }
    //cout<<ip<<endl;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        cout<<"> Error: Socket initialization."<<endl;
        return false;
    }
    sockAddy.sin_family = AF_INET;
    sockAddy.sin_port = htons(SERVER_PORT);
    //Converting IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, ip, &sockAddy.sin_addr)<=0){
        cout<<"> Error: Invalid address."<<endl;
        return false;
    }
    //Connecting to the server, :: is used to specify that connect will be used from import
    if (::connect(sock, (struct sockaddr *)&sockAddy, sizeof(sockAddy)) < 0){
        cout<<"> Error: Connection Failed."<<endl;
        return false;
    }
    return true;
}
bool Network::sendMsg(string msg){
    if(send(sock, msg.c_str(), msg.length(), 0) < 0){
        cout<<"> Error: Message sending failed."<<endl;
        return false;
    }
    return true;
}
//return 1 if successful, 0 if not
int Network::login(string username, string password){
    if (sendMsg("LOGIN " + username + " " + password)){
        string response = recvMsg();
        if (response == "LOGIN_SUCCESS"){
            cout<<"> Login Successful."<<endl;
            return 1;
        }
        else if (response == "LOGIN_FAILURE"){
            cout<<"> Login Failed. response=='LOGIN_FAILURE'."<<endl;
            return 0;
        }
        else{
            cout<<"> Error: Invalid response."<<endl;
            return 0;
        }
    }
    else{
        cout<<"> Error: Message sending failed."<<endl;
        return 0;
    }

return 0;
}
int Network::signup(string username, string password){
    if (sendMsg("SIGNUP " + username + " " + password)){
        string response = recvMsg();
        if (response == "SIGNUP_SUCCESS"){
            cout<<"> Signup Successful."<<endl;
            return 1;
        }
        else if (response == "SIGNUP_FAILURE"){
            cout<<"> Signup Failed."<<endl;
            return 0;
        }
        else{
            cout<<"> Error: Invalid response."<<endl;
            return 0;
        }
    }
    else{
        cout<<"> Error: Message sending failed."<<endl;
        return 0;
    }
}
string Network::recvMsg(){
    char buffer[256] = {0};
    if (recv(sock, buffer, 256, 0) < 0){
        cout<<"> Error: Message receiving failed."<<endl;
        return "";
    }
    return buffer;
}
int Network::hostnameToIP(char *hostname , char *ip){
    struct addrinfo hints;
    struct addrinfo *serverInfo;
    struct addrinfo *addrPtr;
    struct sockaddr_in *h;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC; //AF_INET6 to force IPv6, AF_INET for IPv4, and use AF_UNSPEC to not force...
    hints.ai_socktype = SOCK_STREAM;
    int res;
    if ((res = getaddrinfo( hostname , "http" , &hints , &serverInfo))!=0){
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(res));
        return 1;
    }
    // loop through results...
    for(addrPtr = serverInfo; addrPtr != NULL; addrPtr = addrPtr->ai_next){
        //cout<<"for loop"<<endl;
        h = (struct sockaddr_in *) addrPtr->ai_addr;
        strcpy(ip , inet_ntoa( h->sin_addr ) );
    }
    freeaddrinfo(serverInfo); //free mem for serverInfo, not needed anymore.
    return 0;
}