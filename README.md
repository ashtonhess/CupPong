# Cup Pong
Multiplayer, Command Line Cup Pong.

C++ Project. 

Created by Ashton Hess.
# Quickstart
1. Download the latest CupPong.zip from releases
2. Unzip to desired directory
3. Run the executable

Note: 
1. On MacOS, you may need to open System Preferences -> Security & Privacy to allow the executable to run.
2. This program makes use of pthreads and sockets. Ensure your system OS is UNIX based. Not tested on Windows.
# Client
All you need to play the game is a runnable client program and an internet connection. The client program will automatically connect to the central server hosted at CupPong.HessDevelopments.com. Matchmaking will be handled automatically and the server will insert you in a game against another connected player.
## Setup from Source Code:
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
cd client
make
./client
```
## Client Tests:
Run the following commands in the client directory:
1. cd clientTests
2. mkdir build
3. cd build
4. cmake ..
5. make
6. ./clientTests

# Server
## Hardware and OS
Dell Poweredge 

Ubuntu release 20.04
## Networking
### Dynamic DNS - CupPong.HessDevelopments.com
cuppong.hessdevelopments.com is the domain used to connect to the central Cup Pong server.
By default, Cup Pong runs on port 11328. DNS IP is updated every 15 minutes through a cron task on the connected router that sends Google DNS the live, updated, public IP of the this router. This prevents any breakage that would occur if the router's IP is reassigned. The server is set up with a static IP address, so the router's forwarding on port 11328 will always reach the server. To host the server on your own, you will have to modify some of the network programming.
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
## Server Tests:
Run the following commands in the server directory:
1. cd serverTests
2. mkdir build
3. cd build
4. cmake ..
5. make
6. ./serverTests

## Abstract
For my project I am going to implement the game of Cup Pong to be played on the command line. I plan on using sockets to enable two players to face each other in a game. To determine the probability of making a cup, the player will play a short ‘Dance Dance Revolution’ inspired keyboard game with the WASD keys. This game will favor those strong in the art of finger-dancing. There will be two programs: a client and server. The server will be the backbone of the multiplayer implementation. Clients will connect to the server and be able to play against each other. The server will track and store each player’s number of wins. The server will be hosted on Dell Poweredge that will always be available for players to connect to. Matchmaking will be handled by the server automatically.

## Features
- Multithreaded using pthreads enabling server to handle multiple games at once.
- Singleton design pattern for saving usernames, passwords, and win counts to the server.
- Pthread mutex for FileIO reading and writing critical sections.
- Web sockets to communicate over the internet.
- Server hosted at CupPong.HessDevelopments.com.
- Dynamic DNS for reliable connection to server.

Created by Ashton Hess.
