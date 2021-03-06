/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Hangman- CIS Project 2
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
void blank();   //output for platform
void h();       //output for head
void hb();      //output for head & body
void hab();     //output for head, body, arm
void haab();    //output for head, body, arm, arm
void haabl();   //output for head, body, arm, arm
void dead();    //output for hanged man
void pict(int); //determine graphic output
string filewrd(string [], string);      //input the word from the file
bool gamOv( bool[], int);               //determine if game is really over
int hanger(bool &,int);                 //Increments the number of wrong guesses
void otptChr(bool &, char &);           //If guess is wrong, writes the letter to wrong_guess_output.dat
char *wrngChr(int);                     //Reads in the list of wrong-letter guesses
void prntChr(char *, int);              //Prints the list of wrong-letter guesses
void clearChr();                        //Cleans up the file wrong_guess_output.dat

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    string word, line, filaray[200];
    int hang;
    char guess, ans='y', wrgLtrs;
    bool gamOver, ret;
    //Set Random Counter
    srand(static_cast<unsigned int> (time(0)));
    //Output Intro
    cout<<"Welcome to Hangman!"<<endl<<endl;
    cout<<"To play, guess a letter."<<endl;
    cout<<"But beware! If you guess an incorrect letter multiple times, you are that much closer to Hangman."<<endl<<endl;
    //Begin Game Loop
    while (ans=='y'){
        //Set Game Counters   
        gamOver=false;
        ret=false;
        hang=0;
        guess=0;
        //Read in the file & generate a random word
        word=filewrd(filaray, line);
        //Output the random word
        char cString[word.size()];
        int arylngt = word.length(); //arylngt= array length
        bool marker[word.size()];
        for (int i=0; i<(arylngt-1); i++){
            cString[i]=word[i];
            marker[i]=false;
        }
        cout<<endl;
        //Determine graphic output
        pict(hang);
        //Output initial blank spaces for the word
        for (int i=0; i<(arylngt-1); i++){
                if (cString[i]!=guess)
                    cout<<"__ ";
        }
        cout<<endl;
        //Begin Guessing Loop
        char *array;
        do {
            //Request input of letter
            cout<<endl<<endl<<"Type your letter guess (lowercase letters only): ";
            cin>>guess;
            cout<<endl;
            //reset return boolean
            ret=false;
            for (int i=0; i<arylngt; i++) {
                if (cString[i]==guess)ret=true;
            }
            //Increment number of incorrect guesses if needed
            hang=hanger(ret, hang);
            cout<<endl<<"(You have used "<<hang<<"/6 chances)"<<endl;
            //Determine graphic output
            pict(hang);
            //Output word thus far
            for (int i=0; i<(arylngt-1); i++){
                    if (marker[i]==true){
                        cout<<word[i]<<"  ";
                    } else if (cString[i]==guess){
                        cout<<word[i]<<"  ";
                        marker[i]=true;
                    } else if (cString[i]!=guess)
                        cout<<"__ ";
                }
            cout<<endl;
            //Write the next wrong-letter to the file, if necessary
            otptChr(ret, guess);
            //Fill the char array and cout wrong_guess_output.dat
            array=wrngChr(hang);
            cout<<endl<<"Your wrong guesses are: "<<endl;
            prntChr(array,hang);
            cout<<endl<<endl;
            delete []array;
            //Set Game Over Boolean
            gamOver=true;
            //Determine if gamOver is really True
            for (int i=0; i<(arylngt-1); i++){
                if (marker[i]==false){
                    gamOver=false;
                }
            }
            if (hang>5){
                gamOver=true;
            }
        } while (!gamOver);
        if (gamOver==true&&hang==6){
            dead();
            cout<<setw(15)<<"Hangman!!"<<endl;
            cout<<"Your word was: "<<word<<endl;
        }
        if (gamOver == true) {
            cout<<"Would you like to play again? Press 'y' for yes."<<endl<<endl;
            cin>>ans;
            cout<<endl;
            //Clean up to end round
            clearChr();
        }
        if (ans!='y'){
            break;
        }
    }
    return 0;
}

void clearChr() {
    //this will contain the data to clear/read out to the file
    ofstream output;
    //Open the file for output
    output.open("wrong_guess_output.dat", ios::out);
         output<<" ";
         output.close();
    }

void prntChr(char *a,int hang){
	for(int i=0;i<hang;i++){
		cout<<*(a+i)<<" ";
	}
	cout<<endl;
}

char *wrngChr(int hang) {
    //Declare character variable name for the array
    char wrgLetr;
    //Declare a Pointer and allocate memory
    char *array=new char[hang];
    //this will contain the data read from the file
    ifstream input;
    //Open the input file
    input.open("wrong_guess_output.dat", ios::in);
    while (input){
        //input>>wrgLetr;
	for(int loop=0;loop<hang;loop++){
            input>>wrgLetr;
            *(array+loop)=wrgLetr;
        }
        break;
    }
        input.close(); //closing the file
    return array;
}

void otptChr(bool &ret, char &guess) {
    if(ret==false){
    //this will contain the data to read out to the file
    fstream output;
    //Open the file for output
    output.open("wrong_guess_output.dat", ios::out | ios::app);
    //TEST cout<<"I'm in the file"<<endl;
         output<<guess;
         output.close();
    }
}

int hanger(bool &ret,int hang){
    if (ret==true) {
         cout<<endl;
    }else{
         cout<<"That letter is not found in the word!"<<endl;
         hang++;
    }
 return hang;   
}

void pict(int hang){
                switch(hang){
                case(0):
                    blank();
                    break;
                case(1):
                    h();
                    break;
                case(2):
                    hb();
                    break;
                case(3):
                    hab();
                    break;
                case(4):
                    haab();
                    break;
                case(5):
                    haabl();
                    break;
            }
}

string filewrd(string filaray[], string line) {
    short loop=0; //short for loop for input
    //this will contain the data read from the file
    ifstream input;
    //Open the input file
    input.open("random_word_list.dat");
    if (input.is_open()){ //if the file is open
        while (!input.eof()){ //while the end of file is NOT reached
            getline(input, line); //get one line from the file
            filaray[loop]=line;
            //TEST cout<<filaray[loop]<<endl; //output the array
            loop++;
        }
        input.close(); //closing the file
    }
    int randnum=rand()%loop;
    return (filaray[randnum]);
}

void blank() {
    cout << "    x x x x x x" << endl;
    cout << "    x         x" << endl;
    cout << "    x         x" << endl;
    cout << "              x" << endl;
    cout << "              x" << endl;
    cout << "              x" << endl;
    cout << "              x" << endl;
    cout << "              x" << endl;
    cout << "              x" << endl;
    cout << "              x" << endl;
    cout << "              x" << endl;
    cout << "              x" << endl;
    cout << "              x" << endl;
    cout << "  x x x x x x x x x" << endl << endl;
}

void h() {
    cout << "    x x x x x x" << endl;
    cout << "    x         x" << endl;
    cout << "    x         x" << endl;
    cout << "  x   x       x" << endl;
    cout << "    x         x" << endl;
    cout << "              x" << endl;
    cout << "              x" << endl;
    cout << "              x" << endl;
    cout << "              x" << endl;
    cout << "              x" << endl;
    cout << "              x" << endl;
    cout << "              x" << endl;
    cout << "              x" << endl;
    cout << "  x x x x x x x x x" << endl << endl;
}

void hb() {
    cout << "    x x x x x x" << endl;
    cout << "    x         x" << endl;
    cout << "    x         x" << endl;
    cout << "  x   x       x" << endl;
    cout << "    x         x" << endl;
    cout << "    x         x" << endl;
    cout << "    x         x" << endl;
    cout << "    x         x" << endl;
    cout << "    x         x" << endl;
    cout << "              x" << endl;
    cout << "              x" << endl;
    cout << "              x" << endl;
    cout << "              x" << endl;
    cout << "  x x x x x x x x x" << endl << endl;
}

void hab() {
    cout << "    x x x x x x" << endl;
    cout << "    x         x" << endl;
    cout << "    x         x" << endl;
    cout << "  x   x       x" << endl;
    cout << "    x         x" << endl;
    cout << "    xx        x" << endl;
    cout << "    x x       x" << endl;
    cout << "    x x       x" << endl;
    cout << "    x         x" << endl;
    cout << "              x" << endl;
    cout << "              x" << endl;
    cout << "              x" << endl;
    cout << "              x" << endl;
    cout << "  x x x x x x x x x" << endl << endl;
}

void haab() {
    cout << "    x x x x x x" << endl;
    cout << "    x         x" << endl;
    cout << "    x         x" << endl;
    cout << "  x   x       x" << endl;
    cout << "    x         x" << endl;
    cout << "   xxx        x" << endl;
    cout << "  x x x       x" << endl;
    cout << "  x x x       x" << endl;
    cout << "    x         x" << endl;
    cout << "              x" << endl;
    cout << "              x" << endl;
    cout << "              x" << endl;
    cout << "              x" << endl;
    cout << "  x x x x x x x x x" << endl << endl;
}

void haabl() {
    cout << "    x x x x x x" << endl;
    cout << "    x         x" << endl;
    cout << "    x         x" << endl;
    cout << "  x   x       x" << endl;
    cout << "    x         x" << endl;
    cout << "   xxx        x" << endl;
    cout << "  x x x       x" << endl;
    cout << "  x x x       x" << endl;
    cout << "    x         x" << endl;
    cout << "   x          x" << endl;
    cout << "  x           x" << endl;
    cout << "  x           x" << endl;
    cout << "              x" << endl;
    cout << "  x x x x x x x x x" << endl << endl;
}

void dead() {
    cout << "    x x x x x x" << endl;
    cout << "    x         x" << endl;
    cout << "    x         x" << endl;
    cout << "  xX Xx       x" << endl;
    cout << "    x         x" << endl;
    cout << "   xxx        x" << endl;
    cout << "  x x x       x" << endl;
    cout << "  x x x       x" << endl;
    cout << "    x         x" << endl;
    cout << "   x x        x" << endl;
    cout << "  x   x       x" << endl;
    cout << "  x   x       x" << endl;
    cout << "              x" << endl;
    cout << "  x x x x x x x x x" << endl << endl;
}