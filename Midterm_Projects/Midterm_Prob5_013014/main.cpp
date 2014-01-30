/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Calculate a customer's monthly bill for a certain price package
 * Created on January 30, 2014
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    float rateA=29.95,rtAstp1=2.75,rtAsp2=5,rateB=34.95,rtBstp1=1.5,rtBstp2=2.5,rateC=39.75;
    float hrs,charge,rtAprc=0,rtBprc=0,rtCprc=0;
    char ans;
    //Set Format
    cout<<setprecision(2)<<fixed<<showpoint;
    //Explain Billing System & Request Input
    cout<<"This ISP has three billing options for your enjoyment or confusion."<<endl;
    cout<<"Please choose a billing option below (i.e. enter 'a' for option a):"<<endl<<endl;
    cout<<"a) $29.95 per month for up to 11 hours of Internet."<<endl;
    cout<<"    Additional hours are $2.75 for the next 11 hours,"<<endl;
    cout<<"    and $5/hour for any additional hours after that."<<endl;
    cout<<"b) $34.95 per month for up to 22 hours of Internet."<<endl;
    cout<<"    Additional hours are $1.50 for the next 11 hours,"<<endl;
    cout<<"    and $2.50/hour for any additional hours after that."<<endl;    
    cout<<"c) $39.75 per month for unlimited Internet access."<<endl<<endl;
    cin>>ans;
    
    if((ans!='a')&&(ans!='b')&&(ans!='c')){
        cout<<"You did not choose a valid answer. Please try again."<<endl;
        cin>>ans;
    }
    
        cout<<endl<<"..."<<endl<<endl;
    cout<<"Congratulations on completing your first month of service with billing option "<<ans<<"."<<endl;
    cout<<"Please enter the number of hours of Internet used this past month."<<endl;
    cin>>hrs;
    //Create calculations for billing
    
    //Output Charge
    charge=rtAprc+rtBprc+rtCprc;
    cout<<"Your total charge for last month is $"<<charge<<endl;
    return 0;
}

