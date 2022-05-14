//SERVER
// Created by Ashton Hess on 3/25/22.
//

#ifndef V1_SINGLETON_H
#define V1_SINGLETON_H

#include <iostream>
#include "FileIO.h"
using namespace std;
class Singleton {
private:
    static Singleton *instance;
    Singleton(){};
    FileIO file;
public:

    Singleton(Singleton const& ) = delete; // copy constructor;
    Singleton& operator=(Singleton const&) = delete; // copy assignment
    Singleton(Singleton &&) = delete; // move constructor
    Singleton& operator = (Singleton &&) = delete; // move assignment
    ~Singleton(); //Deconstructor

    static Singleton *getInstance();

    //FileIO ops
    FileIO getFile();
    void setFile(FileIO file);

};




#endif //V1_SINGLETON_H
