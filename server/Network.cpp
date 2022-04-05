//SERVER
// Created by Ashton Hess on 3/25/22.
//

#include "Network.h"

bool Network::connect() {
    //creating FD (file descriptor) for socket.
    if ((serverFD = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("> Error: setting server file descriptor.\n");
        return false;
    }
    if (setsockopt(serverFD, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        cout << "> Error: setsockopt()" << endl;
        return false;
    }
    addy.sin_family = AF_INET;
    addy.sin_addr.s_addr = INADDR_ANY;
    addy.sin_port = htons(SERVER_PORT);//host byte order->network byte order

/* Testing- to resolve host name to ip... (DNS)

    //if ((status = getaddrinfo(argv[1], NULL, &hints, &res)) != 0) {
    char *hostname = "cuppong.hessdevelopments.com";
    char ip[100];
    struct addrinfo hints, *servinfo;
    int status;
    if ((status = getaddrinfo(hostname, "11328", &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return false;
    }
    strcpy(ip, inet_ntoa(addy.sin_addr));
    printf("%s resolved to %s" , hostname , ip);
*/

    //Binding socket
    //Must use scope resolution operator '::' here to call bind() from the socket import,
    // since I'm using the std namespace. This is because std::bind() also exists.
    if (::bind(serverFD, (struct sockaddr *) &addy, sizeof(addy)) < 0) {
        cout << "> Error: binding socket." << endl;
        return false;
    }
    //listening on the socket for a new connection. Next, accept a socket connection and store it
    if (listen(serverFD, MAX_PENDING) < 0) {
        cout << "> Error: listening on socket." << endl;
        return false;
    }
    cout<<" > Network is connected."<<endl;
    return true;
}

int Network::acceptConnection() {
        //accepting and storing a socket connection
    int size = sizeof(addy);
    if ((currentSocket = accept(serverFD, (struct sockaddr *) &addy, (socklen_t *) &size)) < 0) {
        cout<<"> Error: accepting the socket."<<endl;
        return -1;
    }else{
        cout<<"> Socket connection has been accepted: "<<currentSocket<<endl;
        return currentSocket;
    }
}
int Network::login(string username, string password){
    vector<User> allUsersVec;
    allUsersVec=FileIO().readUsers();
    for (auto it = begin (allUsersVec); it != end (allUsersVec); ++it) {
        if(it->getUsername()==username&&it->getPassword()==password){
            //cout<<it->getUserID()<<" login."<<endl;//---------------------------------------------------------------NEEDED--------------------------------------------------------------------------
            return 1;
        }else if(it->getUsername()==username&&it->getPassword()!=password){
            return 2;
        }
    }
    return 0;
}
int Network::newUser(string username, string password){
    if (login(username, password)==1 || login(username,password)==2){
        return 0;
    }else{
        User*newUser = new User(username, password);
        Singleton::getInstance()->getFile().addUserToFile(*newUser);

        return 1;
    }
}
bool Network::sendMsg(string msg){
    if(send(currentSocket, msg.c_str(), msg.length(), 0) < 0){
        cout<<"> Error: Message sending failed."<<endl;
        return false;
    }
    return true;
}

//    //accepting and storing a socket connection
//    int size = sizeof(addy);
//    if ((currentSocket = accept(serverFD, (struct sockaddr *) &addy, (socklen_t *) &size)) < 0) {
//        cout<<"> Error: accepting the socket."<<endl;
//        return false;
//    }else{
//        cout<<"> Socket connection has been accepted."<<endl;
//        return true;
//    }