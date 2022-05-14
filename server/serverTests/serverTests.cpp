//
// Created by Ashton Hess on 5/10/22.
//
#include <gtest/gtest.h>

//SingletonFileIO - GetFilenameSetFilename
#include "Singleton.cpp"
#include "FileIO.cpp"
#include "User.cpp"

//SGame - ThrowResult
//SGameState - End
#include "SGame.cpp"
#include "SGameState.cpp"

//tests Singleton getInstance(), setFile()
//tests FileIO setFilename(), getFilename
TEST(SingletonFileIO, SettingUpSingletonFileIO){
    FileIO *f = new FileIO();
    //set file name.
    f->setFilename("users.txt");
    //Initialize Singleton with file.
    Singleton::getInstance()->setFile(*f);
    ASSERT_EQ(Singleton::getInstance()->getFile().getFilename(), "users.txt");
}
//tests throwResult()
TEST(SGame, ThrowResult){
    SGame sGame = SGame();
    bool testResult=sGame.throwResult(10);
    ASSERT_EQ(testResult, true);
}
//tests end()
TEST(SGameState, End){
    SGame sGame = SGame();
    int testResult=sGame.end();
    ASSERT_EQ(testResult, 0);
}
//tests getHomeState
TEST(SGameState, GetHomeState){
    SGame sGame = SGame();
    string homeStateTest = sGame.getHomeState();
    ASSERT_EQ(homeStateTest, "1 1 1 1 1 1 1 1 1 1 ");
}
//tests getAwayState()
TEST(SGameState, GetAwayState){
    SGame sGame = SGame();
    string awayStateTest = sGame.getAwayState();
    ASSERT_EQ(awayStateTest, "1 1 1 1 1 1 1 1 1 1 ");
}
//tests switchTurn()
TEST(SGameState, SwitchTurn){
    SGame sGame = SGame();
    sGame.switchTurn();
    ASSERT_EQ(sGame.p1Turn, false);
}
//tests genTranslateMap() and translate()
TEST(SGameState, Translate){
    SGame sGame = SGame();
    sGame.genTranslateMap();
    int translateResultTest = sGame.translate("115");
    ASSERT_EQ(translateResultTest, 8);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}