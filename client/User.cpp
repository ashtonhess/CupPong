//
// Created by Ashton Hess on 3/27/22.
//

#include "User.h"
//sets the username
void User::setUsername(string username){
    username_=username;
}
//returns the username
string User::getUsername(){
    return username_;
}
//logs in user with server and returns success or not
//bool User::loginUser(string userName, string password){
//    Network *network = new Network();
//    return true;
//}