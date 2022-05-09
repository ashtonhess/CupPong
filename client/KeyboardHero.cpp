//CLIENT
// Created by ahess on 4/13/22.
//

#include "KeyboardHero.h"

int KeyboardHero::playKeyboardHero(){
    int score=0;
    string scoreMsg;
    srand((unsigned) time(0));
    string letter;
    int randNum2;
    chrono::time_point<chrono::system_clock> start;
    start=chrono::system_clock::now();
    //Clock is not exact because of while loop execution time.
    //Runs game for 8 seconds... Through testing i found this to be a good time for a max score of 8(ish) if perfectly played.
    //Having max score of 8 is really good->if you play perfectly you have a 80% chance to make cup. Should never be 100% for realism...
    while(chrono::duration_cast<std::chrono::milliseconds>(chrono::system_clock::now()-start).count()/1000<8){
        randNum2 = (rand() % 4 + 1);//generates a random number from 1-4 to determine which key will fall next.
        for (int i = 0; i < 9; ++i) { //this loop prints the falling keys.
            if (i == 0) {
                system("clear");
                printLetterLine(randNum2);
                for (int j = 0; j < 8; ++j) {
                    printEmptyLine();
                }
                cout<<endl;
                printScoreLine(scoreMsg, score);
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
                printScoreLine(scoreMsg, score);
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
                printScoreLine(scoreMsg, score);
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
                printScoreLine(scoreMsg, score);
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
                printScoreLine(scoreMsg, score);
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
                printScoreLine(scoreMsg, score);
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
                printScoreLine(scoreMsg, score);
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
                printScoreLine(scoreMsg, score);
                this_thread::sleep_for(std::chrono::milliseconds(GAMESPEED));
                system("clear");
            }
            if (i == 8) {
                for (int j = 0; j < 8; ++j) {
                    printEmptyLine();
                }
                printLetterLine(randNum2);
                cout<<endl;
                printScoreLine(scoreMsg, score);
                chrono::time_point<chrono::system_clock> startKeyListenTime;
                startKeyListenTime=chrono::system_clock::now();
                bool killPressed=false;
                /*Adding a kill switch 'k' to kill listening for keys. This is needed because
                                          when using stty raw ctrl+c will not terminate the program since the input
                                          is not processed but just put straight through.
                                          If you need to terminate while game is listening for key input, input 'k'
                                          first, then use ctrl+c to terminate.*/
                while(chrono::duration_cast<std::chrono::milliseconds>(chrono::system_clock::now() - startKeyListenTime).count()<250 && !killPressed) {

                    /*Using '#include <termios.h>' for clearing the input buffer. Fixes bug where user could just spam
                     * the keys and the game would just keep scanning inputs from past keypresses. Big W.*/
                    int stdin_copy = dup(STDIN_FILENO);
                    /* remove garbage and old content from stdin */
                    tcdrain(stdin_copy);
                    tcflush(stdin_copy, TCIFLUSH);
                    close(stdin_copy);
                    int key = keypress();
                    if((char)key=='k'){//setting 'k' as the kill switch.
                        killPressed=true;
                    }
                    //randNum2  w=1,a=2,s=3,d=4
                    //Conversion from int to char: w=119, a=97, s=115, d=100
                    if(((randNum2==1)&&(key==119))||((randNum2==2)&&(key==97))||((randNum2==3)&&(key==115))||((randNum2==4)&&(key==100))){
                        if(chrono::duration_cast<std::chrono::milliseconds>(chrono::system_clock::now() - startKeyListenTime).count()<250){
                            scoreMsg="Correct key pressed in time!\t+1 Score!";
                            score++;
                            killPressed=true;
                        }else{
                            scoreMsg="Did not enter '"+to_string((char)key)+"' in time! Speed it up!";
                        }
                    }else{
                        scoreMsg="Wrong key!";
                    }
                }
                system("clear");
            }
        }
    }
    return score;
}
//This function prints the line that contains the letter based on an input.
void KeyboardHero::printLetterLine(int letter){
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
//This function prints empty lines when there is no key to place on the line.
void KeyboardHero::printEmptyLine(){
    cout<<"|........................................................................................|"<<endl;
}
//This function prints the current score
void KeyboardHero::printScoreLine(string scoreMsg, int currentScore){
    cout<<"\t\t\t\t\t\t\t\t"<<scoreMsg<<endl<<endl<<"\t\t\t\t\t\t\t\t"<<"Current score: "<<currentScore<<endl;
}
int KeyboardHero::keypress() {
    system ("/bin/stty raw");
    int c;
    system("/bin/stty -echo");
    c = getc(stdin);
    system("/bin/stty echo");
    system ("/bin/stty cooked");
    return c;
}






//std::cout << (char)key << std::endl;
//std::cout << key << std::endl;

//cout<<endl<<endl<<endl<<endl<<"CORRECT KEY PRESSED IN TIME"<<endl<<endl<<endl<<endl;


//cout<<"Did not enter key within time limit"<<endl;

//cout<<endl<<endl<<endl<<endl<<"WRONG KEY PRESSED"<<endl<<endl<<endl<<endl;


//while ((getc(stdin)) != '\n');

//while ((getchar()) != '\n');

//this_thread::sleep_for(std::chrono::milliseconds(GAMESPEED+100));


// int c;
// while ((c = getchar()) != '\n' && c != EOF) { }
//Listen for keys, only here.
//fflush(stdin);


//myBool=false;
//cout<<endl<<endl<<chrono::duration_cast<std::chrono::milliseconds>(chrono::system_clock::now() - start).count()/1000<<endl<<endl;

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

//Original code from main:
//Returns ASCII int value of key pressed.
//int keypress();
//void printLetterLine(int letter){
//    switch(letter){
//        case 1:
//            cout<<"|......................"<<"....................."<<"W"<<"......................"<<"......................|"<<endl;
//            break;
//        case 2:
//            cout<<"|....................."<<"A"<<"......................"<<"......................"<<"......................|"<<endl;
//            break;
//        case 3:
//            cout<<"|......................"<<"....................."<<"S"<<"......................"<<"......................|"<<endl;
//            break;
//        default:
//            cout<<"|......................"<<"....................."<<"......................"<<"D"<<"......................|"<<endl;
//            break;
//            ;
//    }
//}
//void printEmptyLine(){
//    cout<<"|........................................................................................|"<<endl;
//}
//
//int keypress() {
//    system ("/bin/stty raw");
//    int c;
//    system("/bin/stty -echo");
//    c = getc(stdin);
//    system("/bin/stty echo");
//    system ("/bin/stty cooked");
//    return c;
//}
//    srand((unsigned) time(0));
//    string letter;
//    int randNum2;
//    chrono::time_point<chrono::system_clock> start;
//    //chrono::time_point<chrono::system_clock> end;
//    start=chrono::system_clock::now();
//    //Clock is not exact because of while loop execution time.
//    while(chrono::duration_cast<std::chrono::milliseconds>(chrono::system_clock::now()-start).count()/1000<10){
//        //myBool=false;
//        //cout<<endl<<endl<<chrono::duration_cast<std::chrono::milliseconds>(chrono::system_clock::now() - start).count()/1000<<endl<<endl;
//        randNum2 = (rand() % 4 + 1);//generates a random number from 1-4
//        for (int i = 0; i < 9; ++i) {
//            if (i == 0) {
//                system("clear");
//                printLetterLine(randNum2);
//                for (int j = 0; j < 8; ++j) {
//                    printEmptyLine();
//                }
//                cout<<endl;
//                this_thread::sleep_for(std::chrono::milliseconds(GAMESPEED));
//                system("clear");
//            }
//            if (i == 1) {
//                printEmptyLine();
//                printLetterLine(randNum2);
//                for (int j = 0; j < 7; ++j) {
//                    printEmptyLine();
//                }
//                cout<<endl;
//                this_thread::sleep_for(std::chrono::milliseconds(GAMESPEED));
//                system("clear");
//            }
//            if (i == 2) {
//                for (int j = 0; j < 2; ++j) {
//                    printEmptyLine();
//                }
//                printLetterLine(randNum2);
//                for (int j = 0; j < 6; ++j) {
//                    printEmptyLine();
//                }
//                cout<<endl;
//                this_thread::sleep_for(std::chrono::milliseconds(GAMESPEED));
//                system("clear");
//            }
//            if (i == 3) {
//                for (int j = 0; j < 3; ++j) {
//                    printEmptyLine();
//                }
//                printLetterLine(randNum2);
//                for (int j = 0; j < 5; ++j) {
//                    printEmptyLine();
//                }
//                cout<<endl;
//                this_thread::sleep_for(std::chrono::milliseconds(GAMESPEED));
//                system("clear");
//            }
//            if (i == 4) {
//                for (int j = 0; j < 4; ++j) {
//                    printEmptyLine();
//                }
//                printLetterLine(randNum2);
//                for (int j = 0; j < 4; ++j) {
//                    printEmptyLine();
//                }
//                cout<<endl;
//                this_thread::sleep_for(std::chrono::milliseconds(GAMESPEED));
//                system("clear");
//            }
//            if (i == 5) {
//                for (int j = 0; j < 5; ++j) {
//                    printEmptyLine();
//                }
//                printLetterLine(randNum2);
//                for (int j = 0; j < 3; ++j) {
//                    printEmptyLine();
//                }
//                cout<<endl;
//                this_thread::sleep_for(std::chrono::milliseconds(GAMESPEED));
//                system("clear");
//            }
//            if (i == 6) {
//                for (int j = 0; j < 6; ++j) {
//                    printEmptyLine();
//                }
//                printLetterLine(randNum2);
//                for (int j = 0; j < 2; ++j) {
//                    printEmptyLine();
//                }
//                cout<<endl;
//                this_thread::sleep_for(std::chrono::milliseconds(GAMESPEED));
//                system("clear");
//            }
//            if (i == 7) {
//                for (int j = 0; j < 7; ++j) {
//                    printEmptyLine();
//                }
//                printLetterLine(randNum2);
//                printEmptyLine();
//                cout<<endl;
//                this_thread::sleep_for(std::chrono::milliseconds(GAMESPEED));
//                system("clear");
//            }
//            if (i == 8) {
//                for (int j = 0; j < 8; ++j) {
//                    printEmptyLine();
//                }
//                printLetterLine(randNum2);
//                cout<<endl;
//                chrono::time_point<chrono::system_clock> startKeyListenTime;
//                startKeyListenTime=chrono::system_clock::now();
//                bool killPressed=false;
//                while(chrono::duration_cast<std::chrono::milliseconds>(chrono::system_clock::now() - startKeyListenTime).count()<250 && !killPressed) {
//                    //Listen for keys, only here.
//                    int key = keypress();
//                    std::cout << (char)key << std::endl;
//                    std::cout << key << std::endl;
//                    if((char)key=='k'){//setting 'k' as the kill switch.
//                        killPressed=true;
//                    }
//                    //randNum2  w=1,a=2,s=3,d=4
//                    //Conversion from int to char: w=119, a=97, s=115, d=100
//                    if(((randNum2==1)&&(key==119))||((randNum2==2)&&(key==97))||((randNum2==3)&&(key==115))||((randNum2==4)&&(key==100))){
//                        if(chrono::duration_cast<std::chrono::milliseconds>(chrono::system_clock::now() - startKeyListenTime).count()<250){
//                            //cout<<endl<<endl<<endl<<endl<<"CORRECT KEY PRESSED IN TIME"<<endl<<endl<<endl<<endl;
//
//                            killPressed=true;
//                        }else{
//                            //cout<<"Did not enter key within time limit"<<endl;
//                        }
//                    }else{
//                        //cout<<endl<<endl<<endl<<endl<<"WRONG KEY PRESSED"<<endl<<endl<<endl<<endl;
//                    }
//                }
//                //this_thread::sleep_for(std::chrono::milliseconds(GAMESPEED+100));
//                system("clear");
//            }
//    }
//    }

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



//Returns ASCII int value of key pressed.
//int keypress();

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
