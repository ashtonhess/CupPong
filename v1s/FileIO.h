//
// Created by Ashton Hess on 3/25/22.
//

#ifndef V1_FILEIO_H
#define V1_FILEIO_H

#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <vector>
#include <sstream>



#include "User.h"

class FileIO {
private:
    string filename_;
public:
    FileIO();
    FileIO(string filename);
    string getFilename();
    void setFilename(string filename);

    vector<User> readUsers();


};


#endif //V1_FILEIO_H
