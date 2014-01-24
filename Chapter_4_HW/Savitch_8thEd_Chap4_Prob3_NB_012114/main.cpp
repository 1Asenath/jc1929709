/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Change a Stock Price from Fractions to Integers using a Function
 * Created on January 21, 2014, 11:51 AM
 */

//System Libraries
#include <iostream>
#include <iomanip>

using namespace std;

//Global Constants

//Function Prototypes
float stkprc(int &,int &,int &);
float convert(int,int,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int dollars, num, den;
    float result;
    //Read in the Stock Price
    stkprc(dollars,num,den);
    //Convert to Dollar Price
    result=convert(dollars,num,den);
    //Format and Output the Result
    cout<<setprecision(3)<<fixed<<showpoint;
    cout<<"The price in dollars is $"<<result<<endl;
    return 0;
}

float convert(int dollars,int num,int den){
    return dollars+(1.0*num/den);
}


float stkprc(int &dollars,int &num,int &den){
    //Declare the dummy "/" symbol
    char dum;
    //Request Input of Stock Price
    cout<<"Enter a stock price in the format XXX X/X"<<endl;
    cin>>dollars>>setw(2)>>num>>dum>>den;
}
