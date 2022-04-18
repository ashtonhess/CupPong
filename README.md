# Cup Pong
Multiplayer, Command Line Cup Pong.

C++ Project. 

Created by Ashton Hess.

# Client
All you need to play the game is a runnable client program and an internet connection. The client program will automatically connect to the central server hosted at CupPong.HessDevelopments.com. Matchmaking will be handled automatically and the server will insert you in a game against another connected player.
## Quickstart
### Required Software
1. apt & apt-get package managers
2. git
3. make
4. C++ compiler (g++)

### Quick Setup:
Run the following commands through terminal in your desired directory:
```
sudo apt update
sudo apt upgrade
sudo apt install git 
sudo apt install make
sudo apt-get install g++

git clone https://github.com/ashtonhess/CupPong

cd CupPong
cd client
make
./client
```

# Server
## Hardware and OS
Dell Poweredge 

Ubuntu release 20.04
## Networking
### Dynamic DNS - CupPong.HessDevelopments.com
cuppong.hessdevelopments.com is the domain used to connect to the central Cup Pong server.
By default, Cup Pong runs on port 11328. DNS IP is updated every 15 minutes through a cron task on the connected gateway that sends Google DNS the live, updated IP of the server. To host the server on your own, you will have to modify some of the network programming.
## Setup
### Required Software
1. apt & apt-get package managers
2. git
3. make
4. C++ compiler (g++)

Run the following commands through terminal in your desired directory:
```
sudo apt update
sudo apt upgrade
sudo apt install git
sudo apt install make
sudo apt-get install g++

git clone https://github.com/ashtonhess/CupPong

cd CupPong
cd server
make
./server
```

## Abstract
For my project I am going to implement the game of Cup Pong to be played on the command line. I plan on using sockets to enable two players to face each other in a game. To determine the probability of making a cup, the player will play a short ‘Dance Dance Revolution’ inspired keyboard game with the WASD keys. This game will favor those strong in the art of finger-dancing. There will be two programs: a client and server. The server will be the backbone of the multiplayer implementation. Clients will connect to the server and be able to play against each other. The server will track and store each player’s win/loss record. The server will be hosted on an AWS EC2 instance that will always be available for players to connect to. Matchmaking will be handled by the server, either automatically or with users sending requests. 


Created by Ashton Hess.
