//CLIENT
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
#include <ctime>
#include <chrono>
#include <thread>

#define GAMESPEED 150

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

//Returns ASCII int value of key pressed.
int keypress();
//Prints welcome message at beginning of prog. Time until clear can be changed in the
//sleep function within.
void printWelcome();
//This function splits a string by a delimiter and places each piece in a string vector.
vector<string> split (const string &inputString, char delim);



void printLetterLine(int letter){
    switch(letter){
        case 1:
            cout<<"|......................"<<"....................."<<"W"<<"......................"<<"......................|"<<endl;
            break;
        case 2:
            cout<<"|....................."<<"A"<<"......................"<<"......................"<<"......................|"<<endl;
            break;
        case 3:
            cout<<"|......................"<<"....................."<<"S"<<"......................"<<"......................|"<<endl;
            break;
        default:
            cout<<"|......................"<<"....................."<<"......................"<<"D"<<"......................|"<<endl;
            break;
            ;
    }
}
void printEmptyLine(){
    cout<<"|........................................................................................|"<<endl;
}

int keypress() {
    system ("/bin/stty raw");
    int c;
    system("/bin/stty -echo");
    c = getc(stdin);
    system("/bin/stty echo");
    system ("/bin/stty cooked");
    return c;
}

//CLIENT
int main(int argc, char*argv[]) {
    // printWelcome();
    //int letterN;
    //int randNum;
    // bool myBool = true;

    srand((unsigned) time(0));
    string letter;
    int randNum2;
    chrono::time_point<chrono::system_clock> start;
    //chrono::time_point<chrono::system_clock> end;
    start=chrono::system_clock::now();
    //Clock is not exact because of while loop execution time.
    while(chrono::duration_cast<std::chrono::milliseconds>(chrono::system_clock::now()-start).count()/1000<10){
        //myBool=false;
        //cout<<endl<<endl<<chrono::duration_cast<std::chrono::milliseconds>(chrono::system_clock::now() - start).count()/1000<<endl<<endl;
        randNum2 = (rand() % 4 + 1);//generates a random number from 1-4
        for (int i = 0; i < 9; ++i) {
            if (i == 0) {
                system("clear");
                printLetterLine(randNum2);
                for (int j = 0; j < 8; ++j) {
                    printEmptyLine();
                }
                cout<<endl;
                this_thread::sleep_for(std::chrono::milliseconds(GAMESPEED));
                system("clear");
            }
            if (i == 1) {
                printEmptyLine();
                printLetterLine(randNum2);
                for (int j = 0; j < 7; ++j) {
                    printEmptyLine();
                }
                cout<<endl;
                this_thread::sleep_for(std::chrono::milliseconds(GAMESPEED));
                system("clear");
            }
            if (i == 2) {
                for (int j = 0; j < 2; ++j) {
                    printEmptyLine();
                }
                printLetterLine(randNum2);
                for (int j = 0; j < 6; ++j) {
                    printEmptyLine();
                }
                cout<<endl;
                this_thread::sleep_for(std::chrono::milliseconds(GAMESPEED));
                system("clear");
            }
            if (i == 3) {
                for (int j = 0; j < 3; ++j) {
                    printEmptyLine();
                }
                printLetterLine(randNum2);
                for (int j = 0; j < 5; ++j) {
                    printEmptyLine();
                }
                cout<<endl;
                this_thread::sleep_for(std::chrono::milliseconds(GAMESPEED));
                system("clear");
            }
            if (i == 4) {
                for (int j = 0; j < 4; ++j) {
                    printEmptyLine();
                }
                printLetterLine(randNum2);
                for (int j = 0; j < 4; ++j) {
                    printEmptyLine();
                }
                cout<<endl;
                this_thread::sleep_for(std::chrono::milliseconds(GAMESPEED));
                system("clear");
            }
            if (i == 5) {
                for (int j = 0; j < 5; ++j) {
                    printEmptyLine();
                }
                printLetterLine(randNum2);
                for (int j = 0; j < 3; ++j) {
                    printEmptyLine();
                }
                cout<<endl;
                this_thread::sleep_for(std::chrono::milliseconds(GAMESPEED));
                system("clear");
            }
            if (i == 6) {
                for (int j = 0; j < 6; ++j) {
                    printEmptyLine();
                }
                printLetterLine(randNum2);
                for (int j = 0; j < 2; ++j) {
                    printEmptyLine();
                }
                cout<<endl;
                this_thread::sleep_for(std::chrono::milliseconds(GAMESPEED));
                system("clear");
            }
            if (i == 7) {
                for (int j = 0; j < 7; ++j) {
                    printEmptyLine();
                }
                printLetterLine(randNum2);
                printEmptyLine();
                cout<<endl;
                this_thread::sleep_for(std::chrono::milliseconds(GAMESPEED));
                system("clear");
            }
            if (i == 8) {
                for (int j = 0; j < 8; ++j) {
                    printEmptyLine();
                }
                printLetterLine(randNum2);
                cout<<endl;
                chrono::time_point<chrono::system_clock> startKeyListenTime;
                startKeyListenTime=chrono::system_clock::now();
                bool killPressed=false;
                while(chrono::duration_cast<std::chrono::milliseconds>(chrono::system_clock::now() - startKeyListenTime).count()<250 && !killPressed) {
                    //Listen for keys, only here.
                    int key = keypress();
                    std::cout << (char)key << std::endl;
                    std::cout << key << std::endl;
                    if((char)key=='k'){//setting 'k' as the kill switch.
                        killPressed=true;
                    }
                    //randNum2  w=1,a=2,s=3,d=4
                    //Conversion from int to char: w=119, a=97, s=115, d=100
                    if(((randNum2==1)&&(key==119))||((randNum2==2)&&(key==97))||((randNum2==3)&&(key==115))||((randNum2==4)&&(key==100))){
                        if(chrono::duration_cast<std::chrono::milliseconds>(chrono::system_clock::now() - startKeyListenTime).count()<250){
                            cout<<endl<<endl<<endl<<endl<<"CORRECT KEY PRESSED IN TIME"<<endl<<endl<<endl<<endl;
                            killPressed=true;
                        }else{
                            cout<<"Did not enter key within time limit"<<endl;
                        }
                    }else{
                        cout<<endl<<endl<<endl<<endl<<"WRONG KEY PRESSED"<<endl<<endl<<endl<<endl;
                    }
                }
                //this_thread::sleep_for(std::chrono::milliseconds(GAMESPEED+100));
                system("clear");
            }
    }
    }

}
//        if (i == 0) {
//            for (int j = 0; j < 4; ++j) {
//
//            }
//        }
//        if (i == 1) {
//            for (int j = 0; j < 4; ++j) {
//
//            }
//        }
//        if (i == 2) {
//            for (int j = 0; j < 4; ++j) {
//
//            }
//        }
//        if (i == 3) {
//            for (int j = 0; j < 4; ++j) {
//
//            }
//        }




//randNum = (rand() % 4 + 1);//generates a random number from 1-4
//        switch (randNum) {
//            case 1:
//                //cout << "w" << endl;
//                letter="w";
//                letterN=0;
//                break;
//            case 2:
//                //cout << "a" << endl;
//                letter="a";
//                letterN=1;
//                break;
//            case 3:
//                //cout << "s" << endl;
//                letter="s";
//                letterN=2;
//                break;
//            default:
//                //cout << "d" << endl;
//                letter="d";
//                letterN=3;
//                break;
//                ;
//        }
//    cout<<"\t\t\t\t"<<endl;
//    cout<<"\t\t\t\t"<<endl;
//    cout<<"\t\t\t\t"<<endl;
//    cout<<"\t\t\t\t"<<endl;
//    cout<<"\t\t\t\t"<<endl;
//    cout<<"\t\t\t\t"<<endl;



/*
int main(int argc, char*argv[]){
    printWelcome();

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
                            cout<<"> login failed. Username or password input too long. 10 character max. main()"<<endl;
                        }else{
                            Network *network = new Network();
                            if(network->login(delimitVector.at(1),delimitVector.at(2))==1){
                                loggedIn=true;
                                cout<<"> login successful. main()"<<endl;
                            }else{
                                cout<<"> login failed. main()."<<endl;
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
        }
    }
    return 0;
}
*/
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
//GAME BOARD PRINT TESTING-------------------------------------------------------------
//Game game = Game();
//game.printGame();
//cout<<endl<<endl<<endl<<">>>>>>>>>>"<<endl;
//game.homeCups[2].active=false;// 0 based, homeCups[0]=POINT
//game.awayCups[0].active=false;// 0 based, awayCups[9]=POINT
//game.printGame();
//cout<<endl<<endl<<endl<<">>>>>>>>>>"<<endl;
//game.homeCups[4].active=false;// 0 based, homeCups[0]=POINT
//game.awayCups[1].active=false;// 0 based, awayCups[9]=POINT
//game.printGame();
//cout<<endl<<endl<<endl<<">>>>>>>>>>"<<endl;
//game.homeCups[6].active=false;// 0 based, homeCups[0]=POINT
//game.awayCups[2].active=false;// 0 based, awayCups[9]=POINT
//game.printGame();
//cout<<endl<<endl<<endl<<">>>>>>>>>>"<<endl;
//game.homeCups[8].active=false;// 0 based, homeCups[0]=POINT
//game.awayCups[3].active=false;// 0 based, awayCups[9]=POINT
//game.printGame();
//cout<<endl<<endl<<endl<<">>>>>>>>>>"<<endl;
//game.homeCups[9].active=false;// 0 based, homeCups[0]=POINT
//game.awayCups[4].active=false;// 0 based, awayCups[9]=POINT
//game.printGame();
//cout<<endl<<endl<<endl<<">>>>>>>>>>"<<endl;
//game.homeCups[1].active=false;// 0 based, homeCups[0]=POINT
//game.awayCups[5].active=false;// 0 based, awayCups[9]=POINT
//game.printGame();
//cout<<endl<<endl<<endl<<">>>>>>>>>>"<<endl;
//game.homeCups[3].active=false;// 0 based, homeCups[0]=POINT
//game.awayCups[6].active=false;// 0 based, awayCups[9]=POINT
//game.printGame();
//cout<<endl<<endl<<endl<<">>>>>>>>>>"<<endl;
//game.homeCups[5].active=false;// 0 based, homeCups[0]=POINT
//game.awayCups[7].active=false;// 0 based, awayCups[9]=POINT
//game.printGame();
//cout<<endl<<endl<<endl<<">>>>>>>>>>"<<endl;
//game.homeCups[7].active=false;// 0 based, homeCups[0]=POINT
//game.awayCups[8].active=false;// 0 based, awayCups[9]=POINT
//game.printGame();
//cout<<endl<<endl<<endl<<">>>>>>>>>>"<<endl;
//game.homeCups[0].active=false;// 0 based, homeCups[0]=POINT
//game.awayCups[9].active=false;// 0 based, awayCups[9]=POINT
//game.printGame();
//cout<<endl<<endl<<endl<<">>>>>>>>>>"<<endl;

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




//    cout<<"\b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b ";
//    cout<<"\b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b ";
//    cout<<"\b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b ";
//    cout<<"\b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b ";
//    cout<<"\b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b ";
//    cout<<"\b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b ";
//    cout<<"\b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b ";
//    cout<<"\b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b ";
//    cout<<"\b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b \b "<<
//        "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<
//        "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<
//        "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<
//        "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<
//        "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<
//        "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<
//        "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<
//        "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<
//        "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<
//        "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<
//        "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<
//        "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<
//        "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<
//        "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<
//        "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<
//        "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<
//        "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<
//        "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<
//        "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<
//        "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<
//        "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<
//        "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<
//        "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<
//        "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<
//        "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<endl;

//Better way to do this found... Still works tho.
//switch(key){
//case 119://w
//if(ranNum2==1){
////correct key was pressed
//}
//break;
//case 97://a
//if(ranNum2==2){
////correct key was pressed
//}
//break;
//case 115://s
//if(ranNum2==3){
////correct key was pressed
//}
//break;
//case 100://d
//if(ranNum2==4){
////correct key was pressed
//}
//break;
//default:
//;
//}



#pragma clang diagnostic pop
