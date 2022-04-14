//
// Created by Ashton Hess on 3/24/22.
//

#include "Cup.h"
// ‾
//cout << UNDERLINE << "hello world." << CLOSEUNDERLINE<< endl;

//void Cup::printCupAway() {
//    if (this->active){
//        cout<<" /‾\\";
//    }else{
//        cout<<"     ";
//    }
//}
void Cup::printCupHome() {
    if (this->active){
        cout<<" \\_/";
        //cout<<" \\"<<UNDERLINE<<"a"<<CLOSEUNDERLINE<<"/";
    }else{
        cout<<"     ";
    }
}
void Cup::printCupAway(int cupNum) {
    if (this->active){
        //cout<<" \\_/";
        switch (cupNum) {
            case 0:
                cout<<" \\"<<UNDERLINE<<"4"<<CLOSEUNDERLINE<<"/";
                break;
            case 1:
                cout<<" \\"<<UNDERLINE<<"5"<<CLOSEUNDERLINE<<"/";
                break;
            case 2:
                cout<<" \\"<<UNDERLINE<<"6"<<CLOSEUNDERLINE<<"/";
                break;
            case 3:
                cout<<" \\"<<UNDERLINE<<"7"<<CLOSEUNDERLINE<<"/";
                break;
            case 4:
                cout<<" \\"<<UNDERLINE<<"R"<<CLOSEUNDERLINE<<"/";
                break;
            case 5:
                cout<<" \\"<<UNDERLINE<<"T"<<CLOSEUNDERLINE<<"/";
                break;
            case 6:
                cout<<" \\"<<UNDERLINE<<"Y"<<CLOSEUNDERLINE<<"/";
                break;
            case 7:
                cout<<" \\"<<UNDERLINE<<"F"<<CLOSEUNDERLINE<<"/";
                break;
            case 8:
                cout<<" \\"<<UNDERLINE<<"G"<<CLOSEUNDERLINE<<"/";
                break;
            default:
                cout<<" \\"<<UNDERLINE<<"V"<<CLOSEUNDERLINE<<"/";
                ;
        }
    }else{
        cout<<"     ";
    }
}



//if(cupNum==0){
//cout<<" \\"<<UNDERLINE<<"v"<<CLOSEUNDERLINE<<"/";
//}
//if(){
//cout<<" \\"<<UNDERLINE<<"g"<<CLOSEUNDERLINE<<"/";
//}
//if(){
//cout<<" \\"<<UNDERLINE<<"f"<<CLOSEUNDERLINE<<"/";
//}
//if(){
//cout<<" \\"<<UNDERLINE<<"y"<<CLOSEUNDERLINE<<"/";
//}
//if(){
//cout<<" \\"<<UNDERLINE<<"t"<<CLOSEUNDERLINE<<"/";
//}
//if(){
//cout<<" \\"<<UNDERLINE<<"r"<<CLOSEUNDERLINE<<"/";
//}
//if(){
//cout<<" \\"<<UNDERLINE<<"7"<<CLOSEUNDERLINE<<"/";
//}
//if(){
//cout<<" \\"<<UNDERLINE<<"6"<<CLOSEUNDERLINE<<"/";
//}
//if(){
//cout<<" \\"<<UNDERLINE<<"5"<<CLOSEUNDERLINE<<"/";
//}
//if(){
//cout<<" \\"<<UNDERLINE<<"4"<<CLOSEUNDERLINE<<"/";
//}