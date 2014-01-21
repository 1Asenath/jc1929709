/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Created on January 21, 2014
 * Purpose: To use a function for retirement savings
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes
float retire(float,float,int,float);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    float prin,interest,deposit;
    int periods;
    //Read In the Variables
    cout<<"Principal = $'s"<<endl;
    cin>>prin;
    cout<<"Interest in %/year"<<endl;
    cin>>interest;
    cout<<"Number of compounding periods (years)"<<endl;
    cin>>periods;
    cout<<"Deposit made yearly (in dollars)"<<endl;
    cin>>deposit;
    //Run the function
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"Future value = $"<<retire(prin,interest,periods,deposit)<<endl;
    //Exit Stage Right  
    return 0;
}    
//Future Value Function
//Inputs
//  retSave-> Amount saved for retirement
//  salary-> Annual salary
//  yrDep-> Percent of salary put into retirement
//  iRate->Interest rate % on investment
//  n->no compounding periods
//  dep->yearly deposit in dollars
//Output
//  Future value, in dollars
float retire(float pv,float iRate,int n,float dep){
    float save=pv;
    for(int years=1;years<=n;years++){
        save*=(1+iRate/100);
        save+=dep;
}
    return 0;
}

