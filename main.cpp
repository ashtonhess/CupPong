#include <iostream>
using namespace std;
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#include "Game.h"
#include "Cup.h"




int main(int argc, char*argv[]){


    Game game = Game();
    game.homeCups[0].active=false;// 0 based, homeCups[0]=POINT
    game.awayCups[9].active=false;// 0 based, awayCups[9]=POINT
    game.printGame();




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