/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Calculate pay for employees with an outrageous pay structure
 * Created on January 29, 2014, 5:35 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    float hrswork, payrate, stime=0, dtime=0, ttime=0, gross;
    int doub=2, triple=3;
    char ans;
    //Set up format
    cout<<setprecision(2)<<fixed<<showpoint;
    //Request Input
    cout<<"This program determines gross pay for overpaid employees."<<endl<<endl;
    while (ans='y'){
    cout<<"Enter the number of hours the employee worked."<<endl;
    cin>>hrswork;
    cout<<"Enter the employee's straight-time pay rate, in dollars (per hour)."<<endl;
    cin>>payrate;
    //Calculate gross pay
    if (hrswork>40){
        ttime=(hrswork-40)*payrate*triple;
        dtime=20*payrate*doub;
        stime=20*payrate;
    }else if ((hrswork<=40)&&(hrswork>20)){
        ttime=0;
        dtime=(hrswork-20)*payrate*doub;
        stime=20*payrate;
    }else if ((hrswork<=20)&&(hrswork>0)){
        stime=hrswork*payrate;
    }else{
        cout<<"Go home- your pay is 0."<<endl;
    }
    gross=stime+dtime+ttime;
    if (hrswork>0){
        cout<<"The employee's gross pay is $"<<gross<<endl<<endl;
    }
    cout<<"Would you like to calculate another employee? Press 'y' for Yes."<<endl;
    cin>>ans;
    }
    return 0;
}

