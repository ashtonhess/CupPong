//SERVER
// Created by Ashton Hess on 3/25/22.
//

#include "User.h"

void User::setUsername(string username){
    username_=username;
}
void User::setPassword(string password){
    password_=password;
}
string User::getUsername(){
    return username_;
}
string User::getPassword(){
    return password_;
}