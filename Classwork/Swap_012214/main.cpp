/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Demonstrate Pass by Reference, Random Numbers, Overloading Fxns, Swap
 * Created on January 22, 2014, 10:19 AM
 */

//System Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes
void swap(int &,int &);  //the swap - don't need it to return anything
void swap(short &,short &);  //swap utilizing a short; same fxn, diff parameters
short sDrvGen(); //created a short drive generator
int iDrvGen();  //created a int drive generator

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables
    short sa,sb;
    int   ia,ib;
    //Initialize variables
    sa=sDrvGen(); sb=sDrvGen();  // <- ***
    ia=iDrvGen(); ib=iDrvGen();  // <- ***
    //Output before the swap
    cout<<"Short Before Swap {"<<sa<<", "<<sb<<"}"<<endl;
    cout<<"Int   Before Swap {"<<ia<<", "<<ib<<"}"<<endl;
    //Perform the Swap
    swap(sa,sb); swap (ia,ib); //pass by reference - referencing the variables up there ^ ***
    //Output the result of the swap
    cout<<"Short After Swap {"<<sa<<", "<<sb<<"}"<<endl;
    cout<<"Int   After Swap {"<<ia<<", "<<ib<<"}"<<endl;
    //Exit Stage Right
    return 0;
}


int iDrvGen(){
    return static_cast<int>(rand());
}

short sDrvGen(){
    return static_cast<short>(rand()); //return random (statically cast as a short)
}


void swap(int &a,int &b) { //a & b are two inputs that are also outputs?
    a=a^b;
    b=a^b;
    a=a^b;  //prog gets down to the last line, then returns
}

void swap(short &a,short &b) {
    short temp=a;
    a=b;
    b=temp;
}