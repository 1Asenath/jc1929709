/* 
 * File:   main.cpp
 * Author: Jennifer
 * Purpose: Calculate the amount of interest paid on a load with payments of 1/20th per month
 * Created on January 26, 2014, 3:42 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes
float getinput(float&, float&, float&);
float loanamt(float&, float&, float&, float&, float&);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    float loanamt, irate, mopymt, intpaid=0, amtpaid=0, amtrmng, tointpd=0, percint;
    int month=0;
    //Set up precision
    cout<<setprecision(2)<<fixed<<showpoint;
    mopymt=getinput(loanamt, irate, mopymt);
    //Preliminary Calculations
    intpaid=irate*mopymt;
    amtrmng=loanamt;
    //Header
    cout<<"Month   "<<"Interest Paid   "<<"Amt Paid   "<<"Amt Remaining   "<<"Total Int Paid"<<endl;
    //Calculate Numbers
    for (int month=0;amtrmng>=mopymt;month++){
    tointpd=tointpd+intpaid;
    amtpaid=amtpaid+mopymt-intpaid;
    amtrmng=loanamt-amtpaid;
    cout<<setw(4)<<month<<setw(14)<<intpaid<<setw(15)<<amtpaid
                <<setw(11)<<amtrmng<<setw(16)<<tointpd<<endl;
    }
    percint=(tointpd/loanamt)*100;
    cout<<endl<<"You paid a total of "<<percint<<"% of the original loan in interest"<<endl;
    return 0;
}

float getinput(float& loanamt, float& irate, float& mopymt){    
    cout<<"Enter your beginning loan amount, in dollars."<<endl;
    cin>>loanamt;
    cout<<"Enter your annual interest rate."<<endl;
    cin>>irate;
    irate=irate/100;
    //Calculate monthly payment; arbitrarily 1/20th of the original amount
    mopymt=loanamt/20;
    cout<<"Your monthly payment is $"<<mopymt<<endl;
    return (mopymt);
}