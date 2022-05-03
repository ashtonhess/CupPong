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
#include "KeyboardHero.h"
#include<vector>
#include <sstream>
#include <ctime>
#include <chrono>
#include <thread>

#define GAMESPEED 150

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

//Prints welcome message at beginning of prog. Time until clear can be changed in the
//sleep function within.
void printWelcome();
//This function splits a string by a delimiter and places each piece in a string vector.
vector<string> split (const string &inputString, char delim);

//CLIENT
int main(int argc, char*argv[]) {
//    KeyboardHero* kh = new KeyboardHero;
//    int score=kh->play();
//    cout<<"Score: "<<score<<endl;
    printWelcome();
    Network network = Network();
    bool connected=false;
    bool receivedMsg=false;
    bool playing=false;
    while(true){
        receivedMsg=false;
        while(!connected){
            connected=network.connect();
            if(!connected){
                cout<<"> Error connecting to network. Trying again..."<<endl;
                sleep(3);
            }
        }
        while(!receivedMsg){
            cout<<"> Waiting for another player to join..."<<endl;
            string rmsg=network.recvMsg();
            if(rmsg!=""){
                cout<<rmsg<<endl;
                receivedMsg=true;
                playing=true;
            }else{
                connected=false;
                receivedMsg=false;
            }
        }
        Game game = Game();
        while(playing){
            string gmsg=network.recvMsg();
            if(gmsg!=""){
                vector<string> delimitVector;
                delimitVector = split(gmsg,' ');
                switch(delimitVector.size()){
                    case 1:
                        if(gmsg=="ENDWIN"){
                            cout<<"The game is over!"<<endl<<endl<<"You are the winner! :)"<<endl<<endl<<"Reconnecting to a new game in 10 seconds!"<<endl;
                            sleep(10);
                            playing=false;
                            connected=false;
                        }else if(gmsg=="ENDLOSS"){
                            cout<<"The game is over!"<<endl<<endl<<"You lost! :("<<endl<<endl<<"Reconnecting to a new game in 10 seconds!"<<endl;
                            sleep(10);
                            playing=false;
                            connected=false;
                        }
                        break;
                    case 2:
                        if(gmsg=="INIT PLAYER1"){
                            game.player=1;
                            game.turn=true;
                            cout<<"> You are player 1. It is your turn."<<endl;
                            game.printGame();
                            cout<<"Use the keyboard to choose your shot and press enter!"<<endl;
                            int cupInput;
                            cupInput=getchar();
                            cout<<endl<<endl<<"Throwing at cup "<<(char)cupInput<<"!"<<endl<<endl;
                            cout<<"Starting in 3... "<<endl;
                            sleep(1);
                            cout<<"2... "<<endl;
                            sleep(1);
                            cout<<"1..."<<endl<<endl<<endl<<endl;
                            sleep(1);
                            int keyboardHeroResult;
                            keyboardHeroResult=game.playKeyboardHero();
                            //cupInput keys
                            /* cupInput keys:
                            '1'=49
                            '2'=50
                            '3'=51
                            '4'=52
                                ' '=lowercase=uppercase
                            'q'=113=81
                            'w'=119=87
                            'e'=101=69
                            'a'=97=65
                            's'=115=83
                            'z'=122=90
                             */
                            string smsg = "THROW "+to_string(cupInput)+" "+to_string(keyboardHeroResult);
                            network.sendMsg(smsg);
                            //game.switchTurn();
                        }
                        if(gmsg=="INIT PLAYER2"){
                            game.player=2;
                            game.turn=false;
                            game.printGame();
                            cout<<"> You are player 2. Wait for the other player to toss!"<<endl;
                        }//break and wait for new msg...
                        break;
                    case 21:
                        if(delimitVector.at(0)=="GAMESTATE"){
                            //cout<<gmsg<<endl;

//                            for (int i = 0; i < 22; ++i) {
//                                cout<<"delimV: "<<i<<" "<<delimitVector.at(i)<<endl;
//                            }
                            for (int i = 0; i < 10; ++i) {

                                bool home=true;
                                if(delimitVector.at(i+1)=="0"){
                                    home=false;
                                }
                                bool away=true;
                                if(delimitVector.at(i+1+10)=="0"){//setting offset so this passes the values for home.
                                    away=false;
                                }
                                game.homeCups[(i-9)*-1].active=home;
                                game.awayCups[(i-9)*-1].active=away;
                                //(i-9)*-1
                                //cout<<"homeCup: "<<game.homeCups[i].active;
                                //cout<<"awayCup: "<<game.awayCups[i].active;
                            }
                            //cout<<"GAMESTATE UPDATED"<<endl;
                            game.switchTurn();
                            //game.printGame();

                            if(game.turn){
                                cout<<">It is your turn."<<endl;
                                game.printGame();
                                cout<<"Use the keyboard to choose your shot and press enter!"<<endl;
                                int cupInput;
                                cupInput=getchar();
                                cout<<endl<<endl<<"Throwing at cup "<<(char)cupInput<<"!"<<endl<<endl;
                                cout<<"Starting in 3... "<<endl;
                                sleep(1);
                                cout<<"2... "<<endl;
                                sleep(1);
                                cout<<"1..."<<endl<<endl<<endl<<endl;
                                sleep(1);
                                int keyboardHeroResult;
                                keyboardHeroResult=game.playKeyboardHero();
                                //cupInput keys
                                /* cupInput keys:
                                '1'=49
                                '2'=50
                                '3'=51
                                '4'=52
                                    ' '=lowercase=uppercase
                                'q'=113=81
                                'w'=119=87
                                'e'=101=69
                                'a'=97=65
                                's'=115=83
                                'z'=122=90
                                 */
                                string smsg = "THROW "+to_string(cupInput)+" "+to_string(keyboardHeroResult);
                                network.sendMsg(smsg);
                            }else{
                                game.printGame();
                                cout<<"Wait for the other player to toss!"<<endl;
                            }
                        }
                        break;
                    default:
                        ;
                }
            }else{
                cout<<"> Network error. Reconnecting..."<<endl;
                playing=false;
                connected=false;
            }
        }
    }
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
    sleep(3);
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

}



//    cout<<"\t\t\t\t"<<endl;
//    cout<<"\t\t\t\t"<<endl;
//    cout<<"\t\t\t\t"<<endl;
//    cout<<"\t\t\t\t"<<endl;
//    cout<<"\t\t\t\t"<<endl;
//    cout<<"\t\t\t\t"<<endl;



/*OLD MAIN
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
END OLD MAIN
 */


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

//Getting to_string conversion of chars.
//cout<<to_string('1')<<endl;
//cout<<to_string('2')<<endl;
//cout<<to_string('3')<<endl;
//cout<<to_string('4')<<endl;
//cout<<"q "<<to_string('q')<<endl;
//cout<<"w "<<to_string('w')<<endl;
//cout<<"e "<<to_string('e')<<endl;
//cout<<"a "<<to_string('a')<<endl;
//cout<<"s "<<to_string('s')<<endl;
//cout<<"z "<<to_string('z')<<endl;
//cout<<"Q "<<to_string('Q')<<endl;
//cout<<"W "<<to_string('W')<<endl;
//cout<<"E "<<to_string('E')<<endl;
//cout<<"A "<<to_string('A')<<endl;
//cout<<"S "<<to_string('S')<<endl;
//cout<<"Z "<<to_string('Z')<<endl;





#pragma clang diagnostic pop
