/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Enter current time and waiting time to find the time after waiting period ends
 * Created on January 27, 2014, 1:14 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const unsigned char CNV_MIN_HRS=60; //minutes per hour (could use unsigned short)
const unsigned char CNV_24HR=12; //24 hour clock conversion
const float MIN_AM=720; //minutes in the first 12 hours of the day (AM)

//Function Prototypes
void initial(unsigned short &, unsigned short &); //read in hours and minutes
void read(unsigned short &, unsigned short &); //read in hours and minutes
unsigned short minutes(unsigned short, unsigned short); //hours, minutes
unsigned short diff(unsigned short, unsigned short); 
void convert(unsigned short, unsigned short &, unsigned short &); //converting total mins back to hour/min notation

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short shr, smin, hr, min, whr, wmin, scmin, wcmin, totMin, fhr, fmin;
    //Read in the data
    initial(shr,smin); //initial time
    read(hr, min); //waiting time
    //Convert to minutes
    scmin=minutes(shr,smin);
    wcmin=minutes(hr,min);
    //test cout<<"Starting Minutes = "<<scmin<<endl;
    //test cout<<"Waiting Time in Minutes = "<<wcmin<<endl;
    //What is the total in minutes?
    totMin=diff(scmin,wcmin);
    convert(totMin, fhr, fmin);
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"After the wait time is over, it will be "<<fhr<<":"<<fmin<<endl;
    //Exit stage right
    return 0;
}

unsigned short diff(unsigned short strt, unsigned short stp){
    short min=stp+strt;
    return (min);
} 

unsigned short minutes(unsigned short hr, unsigned short min){
    return hr*CNV_MIN_HRS+min;
}

void convert(unsigned short totMin, unsigned short &hr, unsigned short &min){
    hr=totMin/CNV_MIN_HRS;
    min=totMin%CNV_MIN_HRS;
}

void read(unsigned short &whr, unsigned short &wmin){ //reading in hours, minutes, AM/PM
    char dum; //to read in the dummy character colon
    cout<<"Input a waiting time in hours and minutes"<<endl;
    cout<<"Format XX:XX"<<endl;
    cin>>setw(2)>>whr>>dum>>wmin;
}

void initial(unsigned short &hr, unsigned short &min){
    char dum; //to read in the dummy character colon
    cout<<"Input a time in 24-hr notation"<<endl;
    cout<<"Format XX:XX"<<endl;
    cin>>setw(2)>>hr>>dum>>min;
    //test cout<<"You input the following: "<<endl;
    //test cout<<" The hour = "<<hr<<endl;
    //test cout<<" The minute = "<<min<<endl;
    //test cout<<"AM/PM = "<<ampm<<"m"<<endl;
}