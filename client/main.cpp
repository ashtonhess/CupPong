#include <iostream>
using namespace std;
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#include <string>
#include "Game.h"
#include "Cup.h"
#include "User.h"
#include<vector>
#include <sstream>

//Returns ASCII int value of key pressed.
int keypress();
//Prints welcome message at beginning of prog. Time until clear can be changed in the
//sleep function within.
void printWelcome();
//This function splits a string by a delimiter and places each piece in a string vector.
vector<string> split (const string &inputString, char delim);

int main(int argc, char*argv[]){
    printWelcome();
    /* Rough template...?
        if(connected to server){
            try to login...
            if(loggedIn){
                find match...
                if(match found){
                    start game...
                }
            }
        }
    */
    //KEY LISTENER
//    bool active=true;
//    do {
//        int key = keypress();
////std::cout << (char)key << std::endl;
//        if((char)key=='k'){//setting 'k' as the kill switch.
//            active=false;
//        }
//    } while (active);

    char userInput[50];//max input size 50.
    bool serverConnected=true;
    Network* network = new Network();
    serverConnected=network->connect();
    if(serverConnected){
        bool receivedMsgBool=false;
        while(!receivedMsgBool){
            string rMsg= network->recvMsg();
            if(rMsg!=""){
                cout<<"Received Msg: "<<rMsg<<endl;
                receivedMsgBool=true;
            }
        }

        bool loggedIn=false;
        while(!loggedIn){
            cout<<"> Please login or signup. (h for help)"<<endl;
            //cout<<"> Type 'help' for user manual."<<endl;
            cout<<"> ";
            cin.getline(userInput,50,'\n');
            string stringUserInput = userInput;
            vector<string> delimitVector;
            delimitVector = split(stringUserInput,' ');
            switch (delimitVector.size()) {
                case 1:
                    if(delimitVector.at(0)=="h"){
                        cout<<"> Help message here."<<endl;
                    }
                    break;
                case 3:
                    //cout<<"case 3"<<endl;
                    if (delimitVector.at(0)=="login"){
                        if(delimitVector.at(1).size()>10||delimitVector.at(2).size()>10){
                            cout<<"> login failed. Username or password input too long. 10 character max."<<endl;
                        }else{
                            Network *network = new Network();
                            if(network->login(delimitVector.at(1),delimitVector.at(2))==1){
                                loggedIn=true;
                                cout<<"> login successful."<<endl;
                            }else{
                                cout<<"> login failed."<<endl;
                            }
//                            User *userLoggingIn = new User();
//                            if (userLoggingIn->loginUser(delimitVector.at(1), delimitVector.at(2))){
//                                cout<<"> login success."<<endl;
//                                loggedIn=true;
//                            }else{
//                                cout<<"> login failed. Incorrect username or password."<<endl;
//                            }
                        }
                    }
                    break;
                default:
                    cout<<"Invalid command. (h for help)"<<endl;
                    break;
            }
        }
        //USER IS LOGGED IN HERE
        while(loggedIn){
            cout<<"> ";
            cin.getline(userInput,50,'\n');
            string stringUserInput = userInput;
            vector<string> delimitVector;
            delimitVector = split(stringUserInput,' ');
            switch (delimitVector.size()) {
                case 1:
                    if(delimitVector.at(0)=="logout"){
                        loggedIn=false;
                        break;
                    }else if(delimitVector.at(0)=="h"){
                        cout<<"> Help message here."<<endl;
                        break;
                    }else if(delimitVector.at(0)=="quickplay"){
                        Game game = Game();
                        game.printGame();
                        break;
                    }
                default: cout<<"> Type 'h' for user manual."<<endl;;
            }
            //Game game = Game();
            //game.printGame();
        }

    }
    //game.homeCups[0].active=false;// 0 based, homeCups[0]=POINT
    //game.awayCups[9].active=false;// 0 based, awayCups[9]=POINT
    return 0;
}



vector<string> split (const string &inputString, char delim) {
    stringstream stringStream (inputString);
    string piece;
    vector<string> result;
    while (getline (stringStream, piece, delim)) {
        result.push_back (piece);
    }
    return result;
}
void printWelcome(){
    cout<<" ____      ____ ________ _____      ______   ___  ____    ____ ________  \n"<<
        "|_  _|    |_  _|_   __  |_   _|   .' ___  |.'   `|_   \\  /   _|_   __  | \n"<<
        "  \\ \\  /\\  / /   | |_ \\_| | |    / .'   \\_/  .-.  \\|   \\/   |   | |_ \\_| \n"<<
        "   \\ \\/  \\/ /    |  _| _  | |   _| |      | |   | || |\\  /| |   |  _| _  \n"<<
        "    \\  /\\  /    _| |__/ |_| |__/ \\ `.___.'\\  `-'  _| |_\\/_| |_ _| |__/ | \n"<<
        " ____\\/__\\/  __|________|________|`.____ .'`.___.|_____||_____|________| \n"<<
        "                          |  _   _  |.'   `.                                 \n"<<
        "                          |_/ | | \\_/  .-.  \\                            \n"<<
        "                              | |   | |   | |                         \n"<<
        "                             _| |_  \\  `-'  /                           \n"<<
        "                            |_____|  `.___.'                          \n"<<
        "   ______ _____  _____ _______    _______    ___  ____  _____  ______    \n"<<
        " .' ___  |_   _||_   _|_   __ \\  |_   __ \\ .'   `|_   \\|_   _.' ___  |   \n"<<
        "/ .'   \\_| | |    | |   | |__) |   | |__) /  .-.  \\|   \\ | |/ .'   \\_|   \n"<<
        "| |        | '    ' |   |  ___/    |  ___/| |   | || |\\ \\| || |   ____   \n"<<
        "\\ `.___.'\\  \\ \\__/ /   _| |_      _| |_   \\  `-'  _| |_\\   |\\ `.___]  |  \n"<<
        " `.____ .'   `.__.'   |_____|    |_____|   `.___.|_____|\\____`._____.'   \n"<<
        "                                                                         ";
    sleep(1);
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

}

//KEY LISTENER
/*
//KEY LISTENER FUNCTION
//int keypress() {
//    system ("/bin/stty raw");
//    int c;
//    system("/bin/stty -echo");
//    c = getc(stdin);
//    system("/bin/stty echo");
//    system ("/bin/stty cooked");
//    return c;
//}
//KEY LISTENER MAIN

bool active=false;
do {
int key = keypress();
//std::cout << (char)key << std::endl;
if((char)key=='k'){//setting 'k' as the kill switch.
active=false;
}
} while (active);
*/

//Main for thread testing.
/*
pthread_t  t1, t2;
//ARGS: reference to thread, attributes regarding thread customization, function that executes
if(pthread_create(&t1, NULL, &routine, NULL)!=0){
return 1;
}
if(pthread_create(&t2, NULL, &routine, NULL)!=0){
return 2;
}
if(pthread_join(t1, NULL)!=0){
return 3;
}
if(pthread_join(t2, NULL)!=0){
return 4;
}
*/
//Func for thread testing.
/*
void* routine(void* arg){
    cout<<"Test from threads"<<endl;
    sleep(2);
    cout<<"Ending thread"<<endl;
    return NULL;
}
*/