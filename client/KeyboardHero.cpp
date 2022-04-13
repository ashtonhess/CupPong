//
// Created by ahess on 4/13/22.
//

#include "KeyboardHero.h"

int KeyboardHero::play(){
    int score=0;
    string scoreMsg;
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
                            //cout<<endl<<endl<<endl<<endl<<"CORRECT KEY PRESSED IN TIME"<<endl<<endl<<endl<<endl;
                            score++;
                            killPressed=true;
                        }else{
                            //scoreMsg="Did not enter '"<<to_string((char)key)<<"' in time!";
                            //cout<<"Did not enter key within time limit"<<endl;
                        }
                    }else{
                        scoreMsg="Wrong key!";
                        //cout<<endl<<endl<<endl<<endl<<"WRONG KEY PRESSED"<<endl<<endl<<endl<<endl;
                    }
                }
                //this_thread::sleep_for(std::chrono::milliseconds(GAMESPEED+100));
                system("clear");
            }
        }
    }
    return score;
}
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
void KeyboardHero::printEmptyLine(){
    cout<<"|........................................................................................|"<<endl;
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