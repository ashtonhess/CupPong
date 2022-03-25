//
// Created by Ashton Hess on 3/25/22.
//

#include "FileIO.h"
FileIO::FileIO(){}
FileIO::FileIO(string filename){
    filename_ = filename;
}
string FileIO::getFilename(){
    return filename_;
}
void FileIO::setFilename(string filename){
    filename_=filename;
}