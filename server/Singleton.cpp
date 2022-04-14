//SERVER
// Created by Ashton Hess on 3/25/22.
//

#include "Singleton.h"

Singleton *Singleton::instance=NULL;

Singleton *Singleton::getInstance(){
    if (!instance){
        instance = new Singleton();
    }
    return instance;
}
FileIO Singleton::getFile(){
    return file;
}
void Singleton::setFile(FileIO file) {
    this->file=file;
}