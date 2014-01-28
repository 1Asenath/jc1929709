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
void read(unsigned short &, unsigned short &, char &); //reading in hours, minutes, AM/PM
void read(unsigned short &, unsigned short &); //read in waiting time in hours, minutes
unsigned short minutes(unsigned short, unsigned short, char); //hours, minutes, AM/PM
unsigned short minutes(unsigned short, unsigned short); //hours, minutes
unsigned short diff(unsigned short, unsigned short); 
void convert(unsigned short, unsigned short &, unsigned short &, char &); //converting total mins back to AM/PM

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short shr, smin, hr, min, whr, wmin, scmin, wcmin, totMin, fhr, fmin;
    char sampm, fampm;
    //Read in the data
    read(shr,smin,sampm); //initial time
    read(hr, min); //waiting time
    //Convert to minutes
    scmin=minutes(shr,smin,sampm);
    wcmin=minutes(hr,min);
    //test cout<<"Starting Minutes = "<<scmin<<endl;
    //test cout<<"Waiting Time in Minutes = "<<wcmin<<endl;
    //What is the difference in minutes?
    totMin=diff(scmin,wcmin);
    //test cout<<"The difference in minutes = "<<totMin<<endl;
    convert(totMin, fhr, fmin, fampm);
    cout<<"After the wait time is over, it will be "<<fhr<<":"<<fmin<<setw(2)<<fampm<<"m"<<endl;
    //Exit stage right
    return 0;
}

unsigned short diff(unsigned short strt, unsigned short stp){
    short min=stp+strt;
    return (min); //IF (stp-strt>=0)?stp-strt THEN stp-strt+24*CNV_MIN_HRS
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

void read(unsigned short &whr, unsigned short &wmin){ //reading in hours, minutes, AM/PM
    char dum; //to read in the dummy character colon
    cout<<"Input a waiting time in hours and minutes"<<endl;
    cout<<"Format XX:XX"<<endl;
    cin>>setw(2)>>whr>>dum>>wmin;
}

void read(unsigned short &hr, unsigned short &min, char &ampm){
    char dum; //to read in the dummy character colon and the "m" in am/pm
    cout<<"Input a time"<<endl;
    cout<<"Format XX:XX am/pm"<<endl;
    cin>>setw(2)>>hr>>dum>>min>>setw(2)>>ampm>>dum;
    //test cout<<"You input the following: "<<endl;
    //test cout<<" The hour = "<<hr<<endl;
    //test cout<<" The minute = "<<min<<endl;
    //test cout<<"AM/PM = "<<ampm<<"m"<<endl;
}