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

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int endcnt, count, space=1;
    char ans='y';
    cout<<"This program displays a sequence of integers, starting with '1', in a descending diagonal pattern."<<endl;
    cout<<endl;
    while (ans=='y'){
    cout<<"Enter an ending integer"<<endl;
    cin>>endcnt;
    cout<<endl;
    for (count=1;count<=endcnt;count++){
    cout<<setw(space)<<count<<endl;
    space++;
    }
    cout<<"Would you like to try again? Press 'y' for yes."<<endl;
    cin>>ans;
    }    
    return 0;
}
