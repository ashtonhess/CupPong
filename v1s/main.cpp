//
// Created by Ashton Hess on 3/25/22.
//

#include <iostream>
#include "Singleton.h"
#include "Network.h"


int main(int argc, char*argv[]){
    FileIO *f = new FileIO();
    f->setFilename("users.txt");
    Singleton::getInstance()->setFile(*f);
    Singleton*singler = Singleton::getInstance();
    cout<<"Filename: " <<singler->getFile().getFilename()<<endl;

    Network networkObj = Network();
    cout<<"Network connect result: "<<networkObj.connect()<<endl;


}
