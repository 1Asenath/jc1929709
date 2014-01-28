/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose:  Chapter 4 menu
 * Problem 1 -> Savitch Chapter 5, Problem 1
 * Problem 2 -> Savitch Chapter 5, Problem 2
 * Problem 3 -> Savitch Chapter 5, Problem 3
 * Problem 4 -> Savitch Chapter 5, Problem 6
 * Problem 5 -> Savitch Chapter 5, Problem 7
 * Problem 6 -> Savitch Chapter 5, Problem
 * Problem 7 -> Savitch Chapter 5, Problem
 * Problem 8 -> Savitch Chapter 5, Problem
 * Created on October 13, 2011, 6:44 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const unsigned char CNV_MIN_HRS=60; //minutes per hour (could use unsigned short)
const unsigned char CNV_24HR=12; //24 hour clock conversion
const unsigned char MIN_AM=12;

//Function Prototypes
void read(unsigned short &, unsigned short &); //read in waiting time in hours, minutes
unsigned short minutes(unsigned short, unsigned short, char); //hours, minutes, AM/PM
unsigned short minutes(unsigned short, unsigned short); //hours, minutes
void convert(unsigned short, unsigned short &, unsigned short &, char &); //converting total mins back to AM/PM


int main(int argc, char** argv) {
    //General Menu Format
    bool loop=true;
    do{
        //Display the selection
        cout<<"Type 1 to solve problem 1"<<endl;
        cout<<"Type 2 to solve problem 2"<<endl;
        cout<<"Type 3 to solve problem 3"<<endl;
        cout<<"Type 4 to solve problem 4"<<endl;
        cout<<"Type 5 to solve problem 5"<<endl;
        cout<<"Type 6 to solve problem 6"<<endl;
        cout<<"Type 7 to solve problem 7"<<endl;
        cout<<"Type 8 to solve problem 8"<<endl;
        cout<<"Type anything else to quit with no solutions."<<endl;
        //Read the choice
        char choice;
        cin>>choice;
        //Solve a problem that has been chosen.
        switch(choice){
                case '1':{
/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Enter current time and waiting time to find the time after waiting period ends
 * Created on January 27, 2014, 1:14 PM
 */

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short shr, smin, totMin, fhr, fmin;
    char fampm;
    //Read in the data
    read(shr,smin); //initial time
    //Convert to minutes
    totMin=minutes(shr,smin);
    //Convert to 12 hour time
    convert(totMin, fhr, fmin, fampm);
    cout<<"The conversion to 12-hour time is "<<fhr<<":"<<fmin<<setw(2)<<fampm<<"m"<<endl;
    //Exit stage right
    return 0;
}


unsigned short minutes(unsigned short hr, unsigned short min){
    return hr*CNV_MIN_HRS+min;
}

void convert(unsigned short totMin, unsigned short &hr, unsigned short &min, char &ampm){
    if(totMin<MIN_AM){
        ampm='a';
    }else{
        ampm='p';
}
    hr=totMin/CNV_MIN_HRS;
    min=totMin%CNV_MIN_HRS;
    if(hr>CNV_24HR){
        hr=hr-CNV_24HR;
    }
}

unsigned short minutes(unsigned short hr, unsigned short min, char ampm){
    hr+=(ampm=='p'&&hr!=CNV_24HR)?CNV_24HR:0;
    hr-=(ampm=='a'&&hr==CNV_24HR)?CNV_24HR:0;
    return hr*CNV_MIN_HRS+min;
}

void read(unsigned short &hr, unsigned short &min){
    char dum; //to read in the dummy character colon
    cout<<"Input a time"<<endl;
    cout<<"Format XX:XX "<<endl;
    cin>>setw(2)>>hr>>dum>>min;
    //test cout<<"You input the following: "<<endl;
    //test cout<<" The hour = "<<hr<<endl;
    //test cout<<" The minute = "<<min<<endl;
    //test cout<<"AM/PM = "<<ampm<<"m"<<endl;
}
            
                    break;
                }
               
                    
                    break;
                }
                default:{
                        cout<<"Exit?"<<endl;
                        loop=false;
                        break;
                }
        };
    }while(loop);//Upper do-while
    return 0;
}

