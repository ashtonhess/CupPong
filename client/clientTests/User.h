//
// Created by Ashton Hess on 3/27/22.
//

#ifndef V1_USER_H
#define V1_USER_H
#include <iostream>
using namespace std;
#include<string>

#include "Network.h"

class User {
private:
    //bool loggedIn=false;
    string username_="";
    int wins=0;
    int losses=0;

public:
    User(){}
    User(string username_, int wins, int losses){
        this->username_=username_;
        this->wins=wins;
        this->losses=losses;
    }
//    User(string username){
//        loggedIn = false;
//        username_=username;
//        wins=0;
//        losses=0;
//
//    }
    void setUsername(string username);
    string getUsername();

    //bool loginUser(string username, string password);

};

#endif //V1_USER_H
