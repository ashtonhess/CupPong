#include <iostream>
using namespace std;
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "Game.h"
#include "Cup.h"



int main(int argc, char*argv[]){

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

    //sleep(3);
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    cout<<"> Please login or signup."<<endl;
    cout<<"> Type 'help' for user manual."<<endl;







    //GAME LOOP
    bool isPlaying=true;
    while(isPlaying){
        int x,y;
        x=0;
        y=0;
        if (x-y==1){





        }else{
            isPlaying=false;
        }
    }

    Game game = Game();
    game.homeCups[0].active=false;// 0 based, homeCups[0]=POINT
    game.awayCups[9].active=false;// 0 based, awayCups[9]=POINT
    //game.printGame();




    return 0;
}


//KEY LISTENER FUNCTION
/*
int keypress() {
    system ("/bin/stty raw");
    int c;
    system("/bin/stty -echo");
    c = getc(stdin);
    system("/bin/stty echo");
    system ("/bin/stty cooked");
    return c;
}
*/
//KEY LISTENER MAIN
/*
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