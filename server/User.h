//
// Created by Ashton Hess on 3/25/22.
//

#ifndef V1_USER_H
#define V1_USER_H
#include <iostream>
using namespace std;
#include<string>

class User {
private:
    string username_;
    string password_;
public:
    User(){}
    User(string username, string password){
        username_=username;
        password_=password;
    }
    void setUsername(string username);
    void setPassword(string password);
    string getUsername();
    string getPassword();

};


#endif //V1_USER_H
