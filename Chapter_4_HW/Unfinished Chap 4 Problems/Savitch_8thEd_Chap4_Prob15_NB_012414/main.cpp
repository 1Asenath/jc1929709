/* 
 * File:   main.cpp
 * Author: Jennifer
 * Purpose: Calculate Amount of change to enter in a vending machine
 * Created on January 24, 2014, 6:59 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes
int calccn(float,float,int,int,int,int,int,int);

//Execution Begins Here
int main(int argc, char** argv) {
    int dollar=100, quarter=25, dime=10, nickel=5, nxtcoin;
    float input, baldue, change, cost=3.50, totinput;
    cout<<"One twinkie is $3.50. Insert dollar bills or coins. (EX: For a dollar type"
            "'dollar'. For a quarter type 'quarter')"<<endl;
    //Run the coin-calculation function
    while (baldue>0){
    nxtcoin=calccn(input, cost, baldue, nxtcoin, dollar, quarter, dime, nickel);
    }   
   return 0;
}

int calccn(float input, float cost, int baldue, int nxtcoin,int dollar,int quarter,int dime,int nickel){
    cout<<"Insert a "<<nxtcoin<<endl;
    cin>>input;
    //Calculate Balance Due
    baldue=cost-input;
    if (baldue>=100){
        nxtcoin=dollar;
    }
    if ((baldue<100)&&(baldue>=25)){
        nxtcoin=quarter;
    }
    if ((baldue<25)&&(baldue>=10)){
        nxtcoin=dime;
    }    
    if (baldue<10){
        nxtcoin=nickel;
    }    
    return (nxtcoin);
}