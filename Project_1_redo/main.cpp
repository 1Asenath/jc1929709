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
string filewrd(string ,string ,string ,string ,string ,string);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    string word, w1,w2,w3,w4,w5,w6;
    //Intro
    cout<<"Welcome to Hangman!"<<endl;
    cout<<"To play, guess a letter. "<<endl;
    //set up random drawing
    word=filewrd(w1,w2,w3,w4,w5,w6);
    cout<<word<<endl;
    return 0;
}

string filewrd(string w1,string w2,string w3,string w4,string w5,string w6){
    ifstream input;
    //Open the input file
    input.open("random_words.dat");
    //Read in the table data
    input>>w1>>w2>>w3>>w4>>w5;
    return(w2);
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