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
//char filwrd(char,char,char,char,char,char);

int main(int argc, char** argv) {
    char w1, w2, w3, w4, w5, w6;
    char x;
    float word[3]=[blueberries, applesauce, spinach, cinnamon];
    const int SIZE=50;
    int array[SIZE];
    cout<<"Welcome to Hangman!"<<endl;
    cout<<"To play, guess a letter. "<<endl;
    //set up random drawing
    srand(static_cast<unsigned int>(time(0)));
    //Reading in from a file
    //w2=word(w1, w2, w3, w4, w5, w6);
    //cout<<w2<<endl;
    return 0;
}


//char filewrd(char w1,char w2,char w3,char w4,char w5,char w6){
//    ifstream input;
    //Open the input file
//    input.open("random_words.dat");
    //Read in the table data
//    input>>w1>>w2>>w3>>w4>>w5;
//    return(w2);
//}

void word(float word[blueberries, applesauce, spinach, cinnamon], in n){
    for(int i=0;i<1;i++){
        word[i]=rand();
        cout<<word[i];
        
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