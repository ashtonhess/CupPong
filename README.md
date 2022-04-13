# Cup Pong
Multiplayer, Command Line Cup Pong.

C++ Project. 

Created by Ashton Hess.

# Client

# Server
## Hardware and OS
The server will run on a Dell Poweredge Ubuntu server. 
Ububtu release 20.04
## Networking
### Dynamic DNS
cuppong.hessdevelopments.com is the domain used to connect to the server.
Cup Pong runs on port 11328. DNS ip is updated every 15mins through Google DNS and a chron task on the connected router.
## Setup
### Required Software
1. apt & apt-get package managers
2. git
3. make
4. C++ compiler (g++)

To install, run the commands below in your desired directory:
```
sudo apt update
sudo apt upgrade
sudo apt install make
sudo apt-get install g++

git clone https://github.com/ashtonhess/CupPong
```

## Abstract
For my project I am going to implement the game of Cup Pong to be played on the command line. I plan on using sockets to enable two players to face each other in a game. To determine the probability of making a cup, the player will play a short ‘Dance Dance Revolution’ inspired keyboard game with the WASD keys. This game will favor those strong in the art of finger-dancing. There will be two programs: a client and server. The server will be the backbone of the multiplayer implementation. Clients will connect to the server and be able to play against each other. The server will track and store each player’s win/loss record. The server will be hosted on an AWS EC2 instance that will always be available for players to connect to. Matchmaking will be handled by the server, either automatically or with users sending requests. 


Created by Ashton Hess.
