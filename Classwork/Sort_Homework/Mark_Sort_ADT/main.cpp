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
const int MAXSIZE=1000;

//ADT's
struct Array{
    int data[MAXSIZE];
    int szUtil;
};

//Function Prototypes
//fill/print array
void filAray(Array &,int);
void prntAry(Array &,int);
//two options for the swap
void swap(int &,int &);   //pass by reference swap-- a little bit less "dangerous" to pass in only two elements instead of a whole array
void swap(int[],int,int); //pass in the array and the two indices (indexes) swap
void minPos(Array &,int); //find the min and throw it into the first spot
void mrkSort(Array &); //function to call the min pos loop
void xcopy(Array &,Array &); //to copy the filled array so we can change only the copy and leave the original



//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables & Initialize the Random Number Generator
    int dSize=50;
    Array array,brray;
    srand(static_cast<unsigned int>(time(0)));
    //Fill the Arrays
    filAray(array,dSize);
    xcopy(array,brray);
    //Print the Array
    prntAry(array,10);
    //Test out the min pos routine
    int strTime=time(0);                   //Start the timing test here
    mrkSort(brray);                        //sorting done on the array copy
    int endTime=time(0); 
    cout<<"Total Time Taken = "<<endTime-strTime<< " secs"<<endl;
    //Print the Array to test for accuracy
    prntAry(brray,10);                     //printing done on the array copy
    //Exit Stage Right
    return 0;
}

void xcopy(Array &a, Array &b){
    b.szUtil=a.szUtil;
    for(int i=0;i<a.szUtil;i++){
        b.data[i]=a.data[i];
    }
}

void mrkSort(Array &a){ //changed array and SIZE to a and n for the actual function, changed back to the other names when calling it
    for(int i=0;i<a.szUtil-1;i++){
        minPos(a,i);   
    }
}

void minPos(Array &a,int pos){ //pass in array, with size, then find pos w/ min val
    for(int i=pos+1;i<a.szUtil;i++){
        if(a.data[pos]>a.data[i])swap(a.data[pos],a.data[i]);
    }
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void swap(int a[],int i,int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

void prntAry(Array &a,int perLine){
    for(int i=0;i<a.szUtil;i++){
        cout<<a.data[i]<<" ";
        if(i%10==(perLine-1))cout<<endl;
}
    cout<<endl;
}    

void filAray(Array &a,int n){  //structure a, size n
    if(n<1||n>MAXSIZE)n=2;
    a.szUtil=n;
    for(int i=0;i<a.szUtil;i++){
        a.data[i]=rand()%90+10; //keeps rand number to two digits - lowest is 10 and highest is 99
    }
}