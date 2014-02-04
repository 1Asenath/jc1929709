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
//two options for the swap
void swap(int &,int &);   //pass by reference swap-- a little bit less "dangerous" to pass in only two elements instead of a whole array
void swap(int[],int,int); //pass in the array and the two indices (indexes) swap
void minPos(int [],int,int); //find the min and throw it into the first spot
void mrkSort(int [],int); //function to call the min pos loop
void xcopy(int [],int [],int); //to copy the filled array so we can change only the copy and leave the original



//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables & Initialize the Random Number Generator
    const int SIZE=142000;
    int array[SIZE], brray[SIZE];
    srand(static_cast<unsigned int>(time(0)));
    //Fill the Arrays
    filAray(array,SIZE);
    xcopy(array,brray,SIZE);
    //Print the Array
    //prntAry(array,SIZE,10);
    //Test out the min pos routine
    int strTime=time(0);                        //Start the timeing test here
    mrkSort(brray,SIZE);                        //sorting done on the array copy
    int endTime=time(0); 
    cout<<"Total Time Taken = "<<endTime-strTime<< " secs"<<endl;
    //Print the Array to test for accuracy
    //prntAry(brray,SIZE,10);                     //printing done on the array copy
    //Exit Stage Right
    return 0;
}

void xcopy(int a[],int b[],int n){
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
}

void mrkSort(int a[],int n){ //changed array and SIZE to a and n for the actual function, changed back to the other names when calling it
    for(int i=0;i<n-1;i++){
        minPos(a,n,i);   
}
}

void minPos(int a[],int n,int pos){ //pass in array, with size, then find pos w/ min val
    for(int i=pos+1;i<n;i++){
        if(a[pos]>a[i])swap(a[pos],a[i]);
        // if(a[pos]>a[i])swap(a,pos,i); //the second, alternate option, using the array (see comments in the function definitions)
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