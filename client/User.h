//
// Created by Ashton Hess on 3/27/22.
//

#ifndef V1_USER_H
#define V1_USER_H
#include <iostream>
using namespace std;
#include<string>

class User {
private:
    string username_;
    int wins;
    int losses;

public:
    User(){}
    User(string username){
        username_=username;
        wins=0;
        losses=0;

    }
    void setUsername(string username);
    string getUsername();

    bool loginUser(string username, string password);

};

#endif //V1_USER_H
