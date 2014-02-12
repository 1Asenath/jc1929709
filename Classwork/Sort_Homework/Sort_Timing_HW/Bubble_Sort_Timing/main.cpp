/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Comparing Sorting Techniques: Bubble Sort
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
void bubSort(int [],int);
void xcopy(int [],int [],int); //to copy the filled array so we can change only the copy and leave the original


//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables & Initialize the Random Number Generator
    const int SIZE=85000;
    int array[SIZE], brray[SIZE];
    srand(static_cast<unsigned int>(time(0)));
    //Fill the Arrays
    filAray(array,SIZE);
    //Copy the Array so we don't use the original data
    xcopy(array,brray,SIZE);
    //Print the Array
    //prntAry(brray,SIZE,10);
    //Test out the Bubble Sort
    int strTime=time(0);                        //start time
    bubSort(brray,SIZE);
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

void bubSort(int a[],int n){
    bool swap;
    int temp;
    do{
        swap=false;
        for (int i=0;i<(n-1);i++){
            if (a[i]>a[i+1]){
            temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
            swap=true;
        }
        }
    } while (swap);
}