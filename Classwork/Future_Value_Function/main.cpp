/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Finding my future value, in function form
 * Created on January 21, 2014, 8:49 AM
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Global Constants

//Function Prototypes
float fv1(float,float,int); //float,float,int = future value, interest rate, no. of compounding periods
float fv2(float,float,int); //second function, rewritten
float fv3(float,float,int); //third function, rewritten
float fv4(float,float,int); //fourth function, rewritten
float fv5(float,float,int); //fourth function, rewritten in reverse

//Execution Begins Here
int main(int argc, char** argv) {
   //Declare variables
    float prin, interest;
    int periods; //no. compounding periods
    //Read in the variables
    cout<<"Principal = $'s"<<endl;
    cin>>prin;
    cout<<"Interest in %/year"<<endl;
    cin>>interest;
    cout<<"Number of compounding periods (years)"<<endl;
    cin>>periods;
    //Run the function
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"Future value = $"<<fv1(prin,interest,periods)<<endl;
    cout<<"Future value = $"<<fv2(prin,interest,periods)<<endl;
    cout<<"Future value = $"<<fv3(prin,interest,periods)<<endl;
    cout<<"Future value = $"<<fv4(prin,interest,periods)<<endl;
    cout<<"Future value = $"<<fv5(prin,interest,periods)<<endl;
    //Exit Stage Right
    return 0;
}

//Future Value Function
//Inputs
//  pv-> Present value in dollars
//  iRate->Interest rate %
//  n-> Number of compounding periods (years)
//Output
//  Future value in dollars
float fv5(float pv,float iRate,int n){
    float save=pv;
    for(int years=n;years>=1;years--){  //decrementing years
        save*=(1+iRate/100); //divide by decimal equivalent
    }
    return save;
}

//Future Value Function
//Inputs
//  pv-> Present value in dollars
//  iRate->Interest rate %
//  n-> Number of compounding periods (years)
//Output
//  Future value in dollars
float fv4(float pv,float iRate,int n){
    if(n==0)return pv;
    else return fv4(pv,iRate,n-1)*(1+iRate/100);
}


//Future Value Function
//Inputs
//  pv-> Present value in dollars
//  iRate->Interest rate %
//  n-> Number of compounding periods (years)
//Output
//  Future value in dollars
float fv3(float pv,float iRate,int n){
    return static_cast<float>(pv*exp(n*log(1+iRate/100)));
    }



//Future Value Function
//Inputs
//  pv-> Present value in dollars
//  iRate->Interest rate %
//  n-> Number of compounding periods (years)
//Output
//  Future value in dollars
float fv2(float pv,float iRate,int n){
    return static_cast<float>(pv*pow((1+iRate)/100,n)); //to the nth power
    }

//Future Value Function
//Inputs
//  pv-> Present value in dollars
//  iRate->Interest rate %
//  n-> Number of compounding periods (years)
//Output
//  Future value in dollars
float fv1(float pv,float iRate,int n){
    float save=pv;
    for(int years=1;years<=n;years++){  //years=1;years<=n means first year through nth year
        save*=(1+iRate/100); //divide by decimal equivalent
    }
    return save;
}
