/* 
 * File:   main.cpp
 * Author: Jennifer
 * Purpose: Hangman- CIS Project 1
 * Created on February 3, 2014, 2:53 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

//Global Constants

//Function Prototypes
void blank(); //output for platform
void h();     //output for head
void hb();    //output for head & body
void hab(); //output for head, body, arm
void haab(); //output for head, body, arm, arm
void haabl(); //output for head, body, arm, arm
void dead(); //output for hanged man
//input the word from the file
string filewrd(string [], string);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    string word, line ,filaray[200];
    int hang;
    char guess, ans='y';
    bool gamOver=false;
    //Set Random Counter
    srand(static_cast<unsigned int>(time(0)));
    //Intro
    cout<<"Welcome to Hangman!"<<endl<<endl;
    cout<<"To play, guess a letter."<<endl;
    cout<<"But beware! If you guess an incorrect letter multiple times, you are that much closer to Hangman."<<endl<<endl;
    //Being Game Loop
    while(ans=='y'){
    //Set Game Counters   
    gamOver=false;
    hang=0;
    guess=0;
    //Read in the file & generate a random word
    word=filewrd(filaray, line);
    //Output the random word
    char cString[word.size()];
    int arylngt=word.length();          //arylngt= array length
    bool marker[word.size()];
    for (int i=0;i<(arylngt-1);i++){
    cString[i]=word[i];
    marker[i]=false;
    //TEST FOR OUTPUT cout<<"__ ";
    }
    cout<<endl;
    //Begin Guessing Loop
    while(!gamOver){
        //Determine Graphic Output
        do{
        if(hang==0){
            blank();
            break;
        }
        if(hang==1){
            h();
            break;
        }
        if(hang==2){
            hb();
            break;
        }
        if(hang==3){
            hab();
            break;
        }
        if(hang==4){
            haab();
            break;
        }
        if(hang==5){
            haabl();
            break;
        }
        }
        //Output the hidden word BELOW the gallows graphic
        while(!gamOver);
        for(int i=0;i<(arylngt-1);i++){
            if(marker[i]==true){
                cout<<word[i]<<"  ";
            }
            else if(cString[i]==guess){
                cout<<word[i]<<"  ";
                marker[i]=true;
            }
            else if (cString[i]!=guess)
                cout<<"__ ";        
        }
        
    cout<<endl<<endl<<"Type your letter guess (lowercase letters only): ";
    cin>>guess;
    cout<<endl<<endl;
    bool ret=false;
    for(int i=0;i<arylngt;i++){
        if(cString[i]==guess)ret=true;
    }
    if(ret==true){
        for(int i=0;i<(arylngt-1);i++){
            if(marker[i]==true){
                cout<<word[i]<<"  ";
            }
            else if(cString[i]==guess){
                cout<<word[i]<<"  ";
                marker[i]=true;
            }
            else if (cString[i]!=guess)
                cout<<"__ ";        
        }
    }else{
        cout<<"That letter is not found in the word!"<<endl;
        hang++;
    }
    cout<<endl<<"(You have used "<<hang<<"/6 chances)"<<endl<<endl;
    gamOver=true;
    for(int i=0;i<(arylngt-1);i++){
            if(marker[i]==false){
                gamOver=false;
            }
    }
    if(hang>5){
        gamOver=true;
    }
    }
    if(gamOver==true&&hang==6){
        dead();
        cout<<setw(30)<<"Hangman!!"<<endl;
        cout<<"Your word was: "<<word<<endl;
    }
    if(gamOver==true){
        cout<<"Would you like to play again? Press 'y' for yes."<<endl<<endl;
        cin>>ans;
        cout<<endl;
    }
            if(ans!='y'){
            break;
        }
    }
    return 0;
}

string filewrd(string filaray[], string line){
    short loop=0; //short for loop for input
    //this will contain the data read from the file
    ifstream input;
    //Open the input file
    input.open("random_word_list.dat");
    if (input.is_open()){ //if the file is open
        while (!input.eof() ){ //while the end of file is NOT reached
            getline(input,line); //get one line from the file
            filaray[loop]=line;
            //TEST cout<<filaray[loop]<<endl; //output the array
            loop++;
        }
        input.close(); //closing the file
    }
    int randnum=rand()%loop;
    return (filaray[randnum]);
}

void blank(){
cout<<"    x x x x x x"<<endl;
cout<<"    x         x"<<endl;
cout<<"    x         x"<<endl;
cout<<"              x"<<endl;
cout<<"              x"<<endl;
cout<<"              x"<<endl;
cout<<"              x"<<endl;
cout<<"              x"<<endl;
cout<<"              x"<<endl;
cout<<"              x"<<endl;
cout<<"              x"<<endl;
cout<<"              x"<<endl;
cout<<"              x"<<endl;
cout<<"  x x x x x x x x x"<<endl<<endl;
}

void h(){
cout<<"    x x x x x x"<<endl;
cout<<"    x         x"<<endl;
cout<<"    x         x"<<endl;
cout<<"  x   x       x"<<endl;
cout<<"    x         x"<<endl;
cout<<"              x"<<endl;
cout<<"              x"<<endl;
cout<<"              x"<<endl;
cout<<"              x"<<endl;
cout<<"              x"<<endl;
cout<<"              x"<<endl;
cout<<"              x"<<endl;
cout<<"              x"<<endl;
cout<<"  x x x x x x x x x"<<endl<<endl;
}

void hb(){
cout<<"    x x x x x x"<<endl;
cout<<"    x         x"<<endl;
cout<<"    x         x"<<endl;
cout<<"  x   x       x"<<endl;
cout<<"    x         x"<<endl;
cout<<"    x         x"<<endl;
cout<<"    x         x"<<endl;
cout<<"    x         x"<<endl;
cout<<"    x         x"<<endl;
cout<<"              x"<<endl;
cout<<"              x"<<endl;
cout<<"              x"<<endl;
cout<<"              x"<<endl;
cout<<"  x x x x x x x x x"<<endl<<endl;
}

void hab(){
cout<<"    x x x x x x"<<endl;
cout<<"    x         x"<<endl;
cout<<"    x         x"<<endl;
cout<<"  x   x       x"<<endl;
cout<<"    x         x"<<endl;
cout<<"    xx        x"<<endl;
cout<<"    x x       x"<<endl;
cout<<"    x x       x"<<endl;
cout<<"    x         x"<<endl;
cout<<"              x"<<endl;
cout<<"              x"<<endl;
cout<<"              x"<<endl;
cout<<"              x"<<endl;
cout<<"  x x x x x x x x x"<<endl<<endl;
}

void haab(){
cout<<"    x x x x x x"<<endl;
cout<<"    x         x"<<endl;
cout<<"    x         x"<<endl;
cout<<"  x   x       x"<<endl;
cout<<"    x         x"<<endl;
cout<<"   xxx        x"<<endl;
cout<<"  x x x       x"<<endl;
cout<<"  x x x       x"<<endl;
cout<<"    x         x"<<endl;
cout<<"              x"<<endl;
cout<<"              x"<<endl;
cout<<"              x"<<endl;
cout<<"              x"<<endl;
cout<<"  x x x x x x x x x"<<endl<<endl;
}

void haabl(){
cout<<"    x x x x x x"<<endl;
cout<<"    x         x"<<endl;
cout<<"    x         x"<<endl;
cout<<"  x   x       x"<<endl;
cout<<"    x         x"<<endl;
cout<<"   xxx        x"<<endl;
cout<<"  x x x       x"<<endl;
cout<<"  x x x       x"<<endl;
cout<<"    x         x"<<endl;
cout<<"   x          x"<<endl;
cout<<"  x           x"<<endl;
cout<<"  x           x"<<endl;
cout<<"              x"<<endl;
cout<<"  x x x x x x x x x"<<endl<<endl;
}

void dead(){
cout<<"    x x x x x x"<<endl;
cout<<"    x         x"<<endl;
cout<<"    x         x"<<endl;
cout<<"  xX Xx       x"<<endl;
cout<<"    x         x"<<endl;
cout<<"   xxx        x"<<endl;
cout<<"  x x x       x"<<endl;
cout<<"  x x x       x"<<endl;
cout<<"    x         x"<<endl;
cout<<"   x x        x"<<endl;
cout<<"  x   x       x"<<endl;
cout<<"  x   x       x"<<endl;
cout<<"              x"<<endl;
cout<<"  x x x x x x x x x"<<endl<<endl;
}