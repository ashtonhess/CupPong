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
void FileIO::addUserToFile(User user){
    string userString;
    userString="("+user.getUsername()+","+" "+user.getPassword()+","+" "+to_string(user.getWins())+")";
    ofstream outFile;
    outFile.open(filename_, std::ios_base::app);
    outFile<<userString<<endl;
}
void FileIO::writeAllUsersToFile(vector<User>allUsersVec){
    ofstream outFile;
    outFile.open(filename_, ios_base::trunc);
    for(auto user: allUsersVec){
        string userString;
        userString="("+user.getUsername()+","+" "+user.getPassword()+","+" "+to_string(user.getWins())+")";
        outFile<<userString<<endl;
    }
}
vector<User> FileIO::readUsers(){
    vector<User> errorVector;
    std::ifstream ifs;
    ifs.open(filename_, ios::in | ios::binary);
    if (!ifs) {
        cerr << "Cannot open file: " << filename_ << "." << endl;
        return errorVector;
    }
    string data;
    if (ifs.is_open()) {
        vector<User> returnVector;
        while (getline(ifs, data)) {
            //cout<<"Data before erase: "<<data<<endl;
            data.erase(remove(data.begin(), data.end(), '('), data.end());
            //data.erase(remove(data.begin(),data.end(),')'), data.end());
            data.erase(remove(data.begin(), data.end(), ' '), data.end());
            //cout<<"Data after erase: "<<data<<endl;
            stringstream ss(data);
            string username;
            getline(ss, username, ',');
            string password;
            getline(ss, password, ',');
            string winsString;
            getline(ss, winsString, ')');
            int winsInt;
            winsInt=stoi(winsString);
            cout<<"userID: "<<username<<endl;
            cout<<"password: "<<password<<endl;
            cout<<"wins: "<<winsInt<<endl;
            User *newUser = new User(username, password, winsInt);
            returnVector.push_back(*newUser);
        }
        return returnVector;
    }else{
        return errorVector;
    }
}
