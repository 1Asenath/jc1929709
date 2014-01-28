/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Compute difference between start and end time in a 24-hour time machine
 * Created on January 23, 2014, 8:41 AM
 */

//System Libraries
#include <iomanip>
#include <iostream>
using namespace std;

//Global Constants
const unsigned char CNV_MIN_HRS=60; //minutes per hour (could use unsigned short)
const unsigned char CNV_24HR=12; //24 hour clock conversion

//Function Prototypes
void read(unsigned short &, unsigned short &, char &); //reading in hours, minutes, AM/PM
unsigned short minutes(unsigned short, unsigned short, char); //hours, minutes, AM/PM
unsigned short diff(unsigned short, unsigned short); 

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short shr,ehr,smin,emin,scmin,ecmin,diffMin;
    char sampm,eampm;
    //Read in the data
    read(shr,smin,sampm);
    read(ehr,emin,eampm);
    //Convert to minutes
    scmin=minutes(shr,smin,sampm);
    ecmin=minutes(ehr,emin,eampm);
    cout<<"Starting Minutes = "<<scmin<<endl;
    cout<<"Ending Minutes = "<<ecmin<<endl;
    //What is the difference in minutes?
    diffMin=diff(scmin,ecmin);
    cout<<"The difference in minutes = "<<diffMin<<endl;
    //Exit stage right
    return 0;
}

unsigned short diff(unsigned short strt, unsigned short stp){
    short min=stp-strt;
    return (min>=0)?min:(min+(2*CNV_24HR)*CNV_MIN_HRS); //IF (stp-strt>=0)?stp-strt THEN stp-strt+24*CNV_MIN_HRS
} 

unsigned short minutes(unsigned short hr, unsigned short min, char ampm){
    hr+=(ampm=='p'&&hr!=CNV_24HR)?CNV_24HR:0;
    hr-=(ampm=='a'&&hr==CNV_24HR)?CNV_24HR:0;
    return hr*CNV_MIN_HRS+min;
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

