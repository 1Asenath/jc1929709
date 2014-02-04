/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Comparing Sorting Techniques: Selection Sort
 * Created on February 4, 2014
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//Global Constants

//Function Prototypes
void filAray(int[],int);
void prntAry(int[],int,int);
void selSort(int [],int);
void xcopy(int [],int [],int); //to copy the filled array so we can change only the copy and leave the original


//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables & Initialize the Random Number Generator
    const int SIZE=170000;
    int array[SIZE], brray[SIZE],strtScn;
    srand(static_cast<unsigned int>(time(0)));
    //Fill the Arrays
    filAray(array,SIZE);
    //Copy the Array so we don't use the original data
    xcopy(array,brray,SIZE);
    //Print the Array
    //prntAry(brray,SIZE,10);
    //Test out the Bubble Sort
    int strTime=time(0);                        //start time
    selSort(brray,SIZE);
    int endTime=time(0);                        //end time
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

void selSort(int a[],int n){
    int strtScn, minInd, minVal;
    for(strtScn=0;strtScn<(n-1);strtScn++){
        minInd=strtScn;
        minVal=a[strtScn];
        for(int i=strtScn+1;i<n;i++){
            if(a[i]<minVal){
                minVal=a[i];
                minInd=i;
            }
        }
        a[minInd]=a[strtScn];
        a[strtScn]=minVal;
    }
}