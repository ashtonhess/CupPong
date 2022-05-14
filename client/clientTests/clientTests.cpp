//
// Created by Ashton Hess on 5/10/22.
//
#include <gtest/gtest.h>

//Game - SwitchTurn
#include "Game.cpp"
#include "Cup.cpp"

//Network - hostnameToIP
#include "Network.cpp"

//User - SetUsernameGetUsername
#include "User.cpp"

//Main - Split


TEST(Game, SwitchTurn){
Game testGame = Game();
testGame.switchTurn();
ASSERT_EQ(true, testGame.turn);
}

TEST(Network, HostnameToIP){
Network *testNetwork = new Network();
string testStrHostname = "cuppong.hessdevelopments.com";
const char*testHostname=testStrHostname.c_str();
char testIP[256];
//string testStrExpectedIP="35.129.56.107";
char expectedIP[256]="35.129.56.107";
testNetwork->hostnameToIP(const_cast<char*>(testHostname), testIP);
ASSERT_EQ(*expectedIP, *testIP);
}

TEST(User, SetUsernameGetUsername){
User testUser = User();
testUser.setUsername("AshtonHess");
ASSERT_EQ("AshtonHess", testUser.getUsername());
}

//TEST(Main, Split){
//
//}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}