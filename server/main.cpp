// SERVER
// Created by Ashton Hess on 3/25/22.
// SERVER

#include <iostream>
#include<unistd.h>
#include <pthread.h>
#include "Singleton.h"
#include "Network.h"
#include <ctime>
#include "SGame.h"

//disabling inf loop inspection for this file in CLion. Perm fix. Comment out to make work with -Werror.
// add -Wno-unknown-pragmas to Makefile args to ignore in compilation.
#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
/*This function splits a string up by a specified delimiter and returns a vector containing
 * each piece of the string that was split.*/
vector<string> split (const string &inputString, char delim);
/*This function constantly listens for new connections. After two new players connect, it creates a new game thread
 * to run the game between those two players.*/
void *connectListener(void*arg);
/*This function runs the game between two players. Each time two sockets connect to the server, a new thread will
start running this function. */
void *gameFunc(void*arg);

pthread_mutex_t mtx;

//SERVER
int main(int argc, char*argv[]){
    //initalize FileIO.
    FileIO *f = new FileIO();
    //set file name.
    f->setFilename("users.txt");
    //Initialize Singleton with file.
    Singleton::getInstance()->setFile(*f);

    //initialize mutex
    if(pthread_mutex_init(&mtx, NULL) != 0) {
        std::cerr<< "Error initializing writer lock\n";
    }

    //initialize Users vector.
    //Singleton::getInstance()->getFile().readUsers();
    //Singleton*singler = Singleton::getInstance();
    //cout<<"Filename: " <<singler->getFile().getFilename()<<endl;
    //singler->getFile().readUsers();

    vector<pthread_t> threads;
    // Creating and starting ConnectListener thread
    pthread_t t1;
    int res;
    /*This thread will run all the time. It dynamically creates game threads to run a game between two users.
    ConnectListener and the game threads all run concurrently so new users can connect while other users are
    playing. */
    res=pthread_create(&t1, NULL, &connectListener, NULL);
    if (res!=0){
        cout<<"> Error creating thread."<<endl;
    }
    pthread_exit(NULL);

    return 0;
}

/*This function constantly listens for new connections. After two new players connect, it creates a new game thread
 * to run the game between those two players.*/
void *connectListener(void*arg){
    bool boolV=true;
    vector<pthread_t*> threadV;
    int sock1;
    int sock2;
    while (true){
        Network network = Network();
        if(boolV){//if the server is not connected yet (first time calling this), connect to server...
            if(network.connect()){
                boolV=false;
            }else{
                cout<<"> Error connecting to network."<<endl;
            }
        }
        int connections=0;
        while(connections!=2){
            //accept first connection, store in sock1
            if(connections==0){
                sock1=network.acceptConnection();
                if(sock1==-1){
                    cout<<"> Error accepting sock1."<<endl;
                }else{
                    cout<<"> sock1 accepted: "<<sock1<<endl;
                    connections++;
                }
            }
            //accept second connection, store in sock2
            if(connections==1) {
                sock2 = network.acceptConnection();
                if(sock2==-1){
                    cout<<"> Error accepting sock2"<<endl;
                }else{
                    cout<<"> sock2 accepted: "<<sock2<<endl;
                    connections++;
                }
            }
        }
        cout<<"> Creating game with socks: "<<sock1<<" and "<<sock2<<"."<<endl;
        //store both accepted socks in pair to pass to gameThread.
        pair<int,int> *sockPair = (pair<int,int>*)malloc(sizeof(pair<int,int>*));
        sockPair->first = sock1;
        sockPair->second = sock2;
        pthread_t *threadPtr = (pthread_t*)malloc(sizeof(pthread_t));
        int res;
        //create game thread with sock1 and sock2.
        res=pthread_create(threadPtr, NULL, &gameFunc, (void*)sockPair);
        if (res!=0){
            cout<<"> Error creating thread."<<endl;
        }else{
            threadV.push_back(threadPtr);
        }
        //Resetting connection counter so a new set of players can connect.
        connections=0;
    }
    pthread_exit(NULL);
}

/*This function runs the game between two players. Each time two sockets connect to the server, a new thread will
start running this function. */
void *gameFunc(void*arg){
    cout<<"Game func"<<endl;
    cout<<"first sock: "<<((pair<int,int>*)arg)->first<<endl;
    cout<<"second sock: "<<((pair<int,int>*)arg)->second<<endl;
    int sock1=((pair<int,int>*)arg)->first;
    int sock2=((pair<int,int>*)arg)->second;
    Network network=Network();
    SGame game=SGame();
    //It is PLAYER1's turn first.
    network.sendMsg(sock1, "You have successfully joined a game.\nWelcome to Cup Pong!\n");
    network.sendMsg(sock1, "INIT PLAYER1");
    cout<<"> SENT: INIT PLAYER1"<<endl;
    //PLAYER2 is waiting to receive game state after player 1's toss.
    network.sendMsg(sock2, "You have successfully joined a game.\nWelcome to Cup Pong!\n");
    network.sendMsg(sock2, "INIT PLAYER2");
    cout<<"> SENT: INIT PLAYER2"<<endl;
    bool playing=true;
    while(playing){
        string rmsg;
        if(game.p1Turn){
            rmsg=network.recvMsg(sock1);
            cout<<"> RECEIVED msg from sock "<<sock1<<": "<<rmsg<<endl;
        }else{
            rmsg=network.recvMsg(sock2);
            cout<<"> RECEIVED msg from sock "<<sock2<<": "<<rmsg<<endl;
        }
        if(rmsg!=""){
            vector<string> delimitVector;
            delimitVector = split(rmsg,' ');
            switch(delimitVector.size()){
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    //Accepts in format 'THROW (cupInput) (keyboardHeroResult)'
                    if(delimitVector.at(0)=="THROW"){
                        //cupInput keys
                        /* cupInput keys: '1'=49, '2'=50, '3'=51, '4'=52
                            ' '=lowercase=uppercase
                            'q'=113=81, 'w'=119=87, 'e'=101=69, 'a'=97=65, 's'=115=83, 'z'=122=90
                        */
                        //determine make/miss using probability from client
                        bool throwResult;
                        throwResult=game.throwResult(stoi(delimitVector.at(2)));
                        if(throwResult){
                            int makeCupIndex;
                            //cout<<"translating: "<<delimitVector.at(1)<<endl;
                            makeCupIndex = game.translate(delimitVector.at(1));
                            //cout<<"MAKE CUP: "<<makeCupIndex<<endl;
                            //cout<<"MAKE-throwResult TRUE."<<endl;
                            //Remove cup from table-set cup to false
                            if(game.p1Turn){
                                game.homeCupsState[makeCupIndex]=false;
                            }else{
                                game.awayCupsState[makeCupIndex]=false;
                            }
                            //cout<<"New home state: "<<endl<<game.getHomeState()<<endl;
                            //cout<<"New away state: "<<endl<<game.getAwayState()<<endl;
                            //uncomment true for quick testing.
                            if(/*true){*/game.end()==1||game.end()==2){ //If the game is over and we have a winner
                                cout<<"GAME between sock "<<sock1<<" and sock"<<sock2<<" IS OVER"<<endl;
                                //end game here
                                //uncomment true for quick testing.
                                if (/*true){*/game.end()==1){
                                    network.sendMsg(sock1, "ENDWIN");
                                    cout<<"> SENT to "<<sock1<<": "<<"ENDWIN"<<endl;
                                    network.sendMsg(sock2, "ENDLOSS");
                                    cout<<"> SENT to "<<sock2<<": "<<"ENDLOSS"<<endl;
                                    bool loggedIn=false;
                                    while(!loggedIn){
                                        string saveMsg=network.recvMsg(sock1);
                                        vector<string> delimitVector;
                                        delimitVector = split(saveMsg,' ');
                                        if(delimitVector.at(0)=="LOGIN"){
                                            //critical section. Though we are just reading to login, this ensures
                                            //the file is not currently being written to while trying to read for login.
                                            pthread_mutex_lock(&mtx);
                                            //return 0 for user does not exist; return 1 for login success; return 2 for wrong password.
                                            int loginResult=network.login(delimitVector.at(1), delimitVector.at(2));
                                            pthread_mutex_unlock(&mtx);
                                            if(loginResult==1){
                                                //critical section. Reading and writing back to file.
                                                pthread_mutex_lock(&mtx);
                                                //increment user's wins value in file.
                                                vector<User> currentAllUserVec=Singleton::getInstance()->getFile().readUsers();
                                                //loop through all current users that are in the file.
                                                //Using auto& because we need this by reference, not value.
                                                //This is to actually update the value within the user object that is
                                                //in the vector.
                                                for(auto& user: currentAllUserVec){
                                                    if(user.getUsername()==delimitVector.at(1)){
                                                        //increment user w matching username's wins value by 1.
                                                        user.setWins(user.getWins()+1);
                                                    }
                                                }
                                                //write this new, updated vector back to the file.
                                                Singleton::getInstance()->getFile().writeAllUsersToFile(currentAllUserVec);
                                                pthread_mutex_unlock(&mtx);
                                                network.sendMsg(sock1, "SUCCESS");
                                                loggedIn=true;
                                            }else{
                                                network.sendMsg(sock1, "FAILED");
                                            }
                                        }
                                        if(delimitVector.at(0)=="NEW"){
                                            //critical section. writing a new user to the file.
                                            pthread_mutex_lock(&mtx);
                                            int newUserResult = network.newUser(delimitVector.at(1), delimitVector.at(2));
                                            pthread_mutex_unlock(&mtx);
                                            if(newUserResult==1){
                                                network.sendMsg(sock1, "SUCCESS");
                                                loggedIn=true;
                                            }else{
                                                network.sendMsg(sock1, "FAILED");
                                            }
                                        }
                                    }

                                    playing=false;
                                }else if(game.end()==2){
                                    network.sendMsg(sock1, "ENDLOSS");
                                    cout<<"> SENT to "<<sock1<<": "<<"ENDLOSS"<<endl;
                                    network.sendMsg(sock2, "ENDWIN");
                                    cout<<"> SENT to "<<sock2<<": "<<"ENDWIN"<<endl;
                                    bool loggedIn = false;
                                    while(!loggedIn){
                                        string saveMsg=network.recvMsg(sock2);
                                        vector<string> delimitVector;
                                        delimitVector = split(saveMsg,' ');
                                        if(delimitVector.at(0)=="LOGIN"){
                                            //critical section. Though we are just reading to login, this ensures
                                            //the file is not currently being written to while trying to read for login.
                                            pthread_mutex_lock(&mtx);
                                            //return 0 for user does not exist; return 1 for login success; return 2 for wrong password.
                                            int loginResult=network.login(delimitVector.at(1), delimitVector.at(2));
                                            pthread_mutex_unlock(&mtx);
                                            if(loginResult==1){
                                                //critical section. Reading and writing back to file.
                                                pthread_mutex_lock(&mtx);
                                                //increment user's wins value in file.
                                                vector<User> currentAllUserVec=Singleton::getInstance()->getFile().readUsers();
                                                //loop through all current users that are in the file.
                                                //Using auto& because we need this by reference, not value.
                                                //This is to actually update the value within the user object that is
                                                //in the vector.
                                                for(auto& user: currentAllUserVec){
                                                    if(user.getUsername()==delimitVector.at(1)){
                                                        //increment user w matching username's wins value by 1.
                                                        user.setWins(user.getWins()+1);
                                                    }
                                                }
                                                //write this new, updated vector back to the file.
                                                Singleton::getInstance()->getFile().writeAllUsersToFile(currentAllUserVec);
                                                pthread_mutex_unlock(&mtx);
                                                network.sendMsg(sock2, "SUCCESS");
                                                loggedIn=true;
                                            }else{
                                                network.sendMsg(sock2, "FAILED");
                                            }
                                        }
                                        if(delimitVector.at(0)=="NEW"){
                                            //critical section. writing a new user to the file.
                                            pthread_mutex_lock(&mtx);
                                            int newUserResult = network.newUser(delimitVector.at(1), delimitVector.at(2));
                                            pthread_mutex_unlock(&mtx);
                                            if(newUserResult==1){
                                                network.sendMsg(sock2, "SUCCESS");
                                                loggedIn=true;
                                            }else{
                                                network.sendMsg(sock2, "FAILED");
                                            }
                                        }
                                    }
                                    playing=false;
                                }
                            }else{
                                //Send updated gamestate to both clients, this tells clients what cups are still live or not
                                string sock1GameState="GAMESTATE "+game.getAwayState()+game.getHomeState();
                                //cout<<"Msg:sock1: "<<sock1GameState<<endl;
                                string sock2GameState="GAMESTATE "+game.getHomeState()+game.getAwayState();
                                //cout<<"Msg:sock2: "<<sock2GameState<<endl;                  //.
                                network.sendMsg(sock1, sock1GameState);
                                cout<<"> SENT to "<<sock1<<": "<<sock1GameState<<endl;
                                network.sendMsg(sock2, sock2GameState);
                                cout<<"> SENT to "<<sock2<<": "<<sock2GameState<<endl;
                                //TEST GAMESTATE STRINGS
                                //"GAMESTATE 0 1 0 1 0 1 1 0 1 1. 1 0 1 1 0 1 1 0 1 1 "
                                //"GAMESTATE 1 0 1 1 0 1 1 0 1 1. 0 1 0 1 0 1 1 0 1 1 "
                                game.switchTurn();
                            }
                        }else{
                            //Don't remove cup from table.
                            string sock1GameState="GAMESTATE "+game.getAwayState()+game.getHomeState();
                            string sock2GameState="GAMESTATE "+game.getHomeState()+game.getAwayState();
                            network.sendMsg(sock1, sock1GameState);
                            cout<<"> SENT to "<<sock1<<": "<<sock1GameState<<endl;
                            network.sendMsg(sock2, sock2GameState);
                            cout<<"> SENT to "<<sock2<<": "<<sock2GameState<<endl;
                            //network.sendMsg();
                            //network.sendMsg();
                            game.switchTurn();
                        }
                        cout<<"> PROCESSED msg: "<<rmsg<<endl;
                    }
                    break;
                default:
                    ;
            }
        }else{
            playing=false;
        }
    }
    return NULL;
}

/*This function splits a string up by a specified delimiter and returns a vector containing
  each piece of the string that was split.*/
vector<string> split (const string &inputString, char delim) {
    stringstream stringStream (inputString);
    string piece;
    vector<string> result;
    while (getline (stringStream, piece, delim)) {
        result.push_back (piece);
    }
    return result;
}
#pragma clang diagnostic pop

//DETERMINE CUP MAKE OR MISS
//initalizing rand to calculate make or miss.
//                        srand((unsigned) time(0));
//                        int randNum;
//                        randNum = (rand() % 10 + 1);//generates a random number from 1-10
//                        if(randNum<=stoi(delimitVector.at(3))){//if the random number is less than or = to result, it is a make.
//                            cout<<"THROW MAKE"<<endl;
//                        }else{
//                            cout<<"THROW MISS"<<endl;
//                        }


//}else{
    //    cout<<"> Error connecting to network."<<endl;
    //}

//    Network networkObj = Network();
//    if (networkObj.connect()) {
//
//    }


    /*
    bool isActive=false;
    if(networkObj.connect()){
        isActive=true;
        int sock;
        int numOfConnections=0;
        bool acceptingPair=true;
        while(isActive){
            //store socket connection values for pair
            int s1;
            int s2;
            while (acceptingPair){
                sock=networkObj.acceptConnection();
                if (sock==-1){
                    cout<<"> Error: Network::acceptConnection().";
                    //return -1;//returning
                }else if (sock==-2){
                    isActive=false;//THIS ELSE IF IS TO MAKE INF LOOP HIGHLIGHT GO AWAY IN CLION. NOT ACTUALLY USED.
                                    //ended up disabling inf loop inspection for this file in CLion. Perm fix. This is not needed anymore.
                }else{
                    //add this socket to list for matchmaking...
                    numOfConnections++;
                    if(numOfConnections==2){//if we have a pair of sockets, stop accepting new connections.
                        s2=sock;//store value of second socket connected.
                        cout<<"s2: "<<s2<<endl;
                        cout<<"Pair of sockets accepted:"<<endl<<"\ts1: "<<s1<<endl<<"\ts2: "<<s2<<endl;
                        acceptingPair=false;
                    }else{
                        s1=sock;//store value of first socket connected.
                        cout<<"s1: "<<s1<<endl;
                    }
                    networkObj.sendMsg("Welcome to Cup Pong!\n");
                    //once match is found, add both users into a thread of a game instance...

                }
            }
            while(true){


                break;
            }

            //isActive=false;
        }

    }else{
        cout<<"Network is not connected"<<endl;
    }
     */


//    bool isConnected = false;
//    while(!isConnected){
//        isConnected=networkObj.connect();
//    }
//    while(isConnected){
//
//
//
//        isConnected=false;
//    }