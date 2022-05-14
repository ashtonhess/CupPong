//SERVER
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
    int wins_;
public:
    User(){}
    User(string username, string password, int wins){
        username_=username;
        password_=password;
        wins_=wins;
    }
    void setUsername(string username);
    void setPassword(string password);
    void setWins(int wins);
    string getUsername();
    string getPassword();
    int getWins();

};


#endif //V1_USER_H
