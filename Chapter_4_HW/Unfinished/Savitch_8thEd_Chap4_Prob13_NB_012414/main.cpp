/* 
 * File:   main.cpp
 * Author: Jennifer
 * Output the English Lyrics to "99 Bottles of Beer"
 * Created on January 24, 2014, 3:09 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes
int frstwrd(int, int, int);
int scndwrd(int, int, int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int tens, ones, count, word;
    cout<<"Ninety-Nine Bottles of Beer on the Wall"<<endl<<endl;
    //Start Loop
    // Loop-> for(int count=99;count>=20){
    frstwrd(tens, count, word);
    scndwrd(tens, count, word);
    cout<<"Bottles of beer on the wall,"<<endl;
    frstwrd(tens, count, word);
    scndwrd(tens, count, word);
    cout<<"Bottles of beer,"<<endl;
    cout<<"You take one down, pass it around,"<<endl;
    count=count--;
    frstwrd(tens, count, word);
    scndwrd(tens, count, word);
    cout<<"Bottles of beer on the wall."<<endl<<endl;
    return 0;
    // End Loop -> }
}

int scndwrd(int tens, int count, int word){
    word=count%10;
    if (word=9){
        cout<<"-nine"<<endl;
    }else if (word=8){
        cout<<"-eight"<<endl;
    }else if (word=7){
        cout<<"-seven"<<endl;
    }else if (word=6){
        cout<<"-six"<<endl;
    }else if (word=5){
        cout<<"-five"<<endl;
    }else if (word=4){
        cout<<"-four"<<endl;
    }else if (word=3){
        cout<<"-three"<<endl;
    }else if (word=2){
        cout<<"-two"<<endl;
    }else if (word=1){
        cout<<"-one"<<endl;
    }else {
        cout<<"ERROR"<<endl;
    }
    return 0;
    }

int frstwrd(int tens, int count, int word){
    word=count/10;
    if ((word=9)&&(word%10!=0)){
        cout<<"Ninety"<<endl;
    }else if ((word=8)&&(word%10!=0)){
        cout<<"Eighty"<<endl;
    }else if ((word=7)&&(word%10!=0)){
        cout<<"Seventy"<<endl;
    }else if ((word=6)&&(word%10!=0)){
        cout<<"Sixty"<<endl;
    }else if ((word=5)&&(word%10!=0)){
        cout<<"Fifty"<<endl;
    }else if ((word=4)&&(word%10!=0)){
        cout<<"Fourty"<<endl;
    }else if ((word=3)&&(word%10!=0)){
        cout<<"Thirty"<<endl;
    }else if ((word=2)&&(word%10!=0)){
        cout<<"Twenty"<<endl;
    return 0;
    }
}