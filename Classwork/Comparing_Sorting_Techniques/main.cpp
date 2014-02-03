/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Comparing Sorting Techniques:Creating algorithms for sorting
 * Created on February 3, 2014, 8:12 AM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//Global Constants

//Function Prototypes
//fill/print array
void filAray(int[],int);
void prntAry(int[],int,int);


//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables & Initialize the Random Number Generator
    const int SIZE=200;
    int array[SIZE];
    srand(static_cast<unsigned int>(time(0)));
    //Fill the Array
    filAray(array,SIZE);
    //Print the Array
    prntAry(array,SIZE,10);
    //Exit Stage Right
    return 0;
}

void prntAry(int a[],int n,int perLine){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%10==(perLine-1))cout<<endl;
}
    cout<<endl;
}    

void filAray(int a[],int n){  //array a, size n
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10; //keeps rand number to two digits - lowest is 10 and highest is 99
    }
}