/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Display a requested number of integers in a descending diagonal pattern
 * Created on January 28, 2014, 10:06 AM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes
int input(int);
int output(int,int,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int endcnt, count, space;
    endcnt=input(endcnt);
    cout<<endl;
    
    
    return 0;
}

int output(int count,int space){
    
    
    
    cout<<setw(space)<<count
}

int input(int endcnt){
    cout<<"This program displays a number of integers, starting with '1', in a descending diagonal pattern."<<endl;
    cout<<"Enter an ending integer"<<endl;
    cin>>endcnt;
    return (endcnt);
}

//need a function to request and receive input
 //variables int -> endcnt

//need a looping function to output count++ with setwidth(space) (count=1;count<=endcnt;count++;space++)
 //variables int -> count, space=2