/* 
 * File:   main.cpp
 * Author: Jennifer
 * Purpose: Hangman- CIS Project 1
 * Created on February 3, 2014, 2:53 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

//Global Constants

//Function Prototypes
void blank(char); //output for platform
void h(char);     //output for head
void hb(char);    //output for head & body
void hab(char); //output for head, body, arm
void haab(char); //output for head, body, arm, arm
void haabl(char); //output for head, body, arm, arm
void dead(char); //output for hanged man
//input the word from the file
string filewrd(string [], string);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    string word, line ,filaray[200];
    int hang=0, wrong=0;
    char guess;
    bool gamOver=false;
    //Set Random Counter
    srand(static_cast<unsigned int>(time(0)));
    //Intro
    cout<<"Welcome to Hangman!"<<endl;
    cout<<"To play, guess a letter. "<<endl;
    //Read in the file & generate a random word
    word=filewrd(filaray, line);
    //Output the random word
    char cString[word.size()];
    int arylngt=word.length();        //arylngt= array length
    bool marker[word.size()];
    for (int i=0;i<(arylngt-1);i++){
    cString[i]=word[i];
    marker[i]=false;
    cout<<"__ ";
    }
    cout<<endl;
    //Begin Game Loop
    while(!gamOver){
    cout<<"Type your letter guess (lowercase letters only): ";
    cin>>guess;
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
    cout<<endl<<"You have used "<<hang<<"/6 chances"<<endl;
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
    return 0;
}

string filewrd(string filaray[], string line){
    
    short loop=0; //short for loop for input
    // string line; //this will contain the data read from the file
    ifstream input;
    //Open the input file
    input.open("random_words.dat");
    if (input.is_open()){ //if the file is open
        while (! input.eof() ){ //while the end of file is NOT reached
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


void blank(char x){
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
cout<<"  x x x x x x x x x"<<endl;
}

void h(char x){
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
cout<<"  x x x x x x x x x"<<endl;
}

void hb(char x){
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
cout<<"  x x x x x x x x x"<<endl;
}

void hab(char x){
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
cout<<"  x x x x x x x x x"<<endl;
}

void haab(char x){
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
cout<<"  x x x x x x x x x"<<endl;
}

void haabl(char x){
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
cout<<"  x x x x x x x x x"<<endl;
}

void dead(char x){
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
cout<<"  x x x x x x x x x"<<endl;
}