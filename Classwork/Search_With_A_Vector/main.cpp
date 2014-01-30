/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr - mod by Jennifer Clark
 * Created on January 29, 2014, 7:58 PM
 * 
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

//Global Constants

//Function Prototypes
void filAray(int [],int);
void prntAry(const int [],int,int);
void prntVec(const vector<int>&,int);
int  find(const int [],int,int,int);
void find(const int [],int,int,int,vector<int> &);
void find(const int [],int,int,int,int []);

int main(int argc, char** argv) {
    //Declare and setup the problem
    const int SIZE=100;
    int array[SIZE], val, val2;
    srand(static_cast<unsigned int>(time(0)));
    //Initialize the array
    filAray(array,SIZE);
    //Display the array
    prntAry(array,SIZE,10);
    //Find a value
    cout<<"Insert a value to find between 10 and 99."<<endl;
    cin>>val;
    cout<<"Insert another value to find"<<endl;
    cin>>val2;
    int pos=-1;
    do{
        pos=find(array,SIZE,val,pos+1);
        cout<<"Value 1 found at "<<pos<<endl;
    }while(pos>0);
    do{
    pos=find(array,SIZE,val2,pos+1);
    cout<<"Value 2 found at "<<pos<<endl;
    }while(pos>0);
    //Declare an array and fill
    int brray[SIZE];
    find(array,SIZE,val,val2,brray);
    //Print array 
    prntAry(brray,SIZE,10);
    //Declare a vector and fill
    vector<int> posVec;
    find(array,SIZE,val,val2,posVec);
    //Print the vector
    prntVec(posVec,10);
    //Exit Stage RIGHT!!!
    return 0;
}

void prntVec(const vector<int>&vec,int perLine){
    cout<<endl;
    cout<<"Found "<<vec.size()<<" values!"<<endl;
    cout<<"Position Vector where found = { ";
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
        if(i%10==(perLine-1))cout<<endl;
    }
    cout<<"}"<<endl;
}

void find(const int a[],int n,int val,int val2,int b[]){
    int cnt=0;
    for(int i=0;i<n;i++){
        b[i]=-1;
        if((a[i]==val)||(a[i]==val2))b[cnt++]=i;
    }
}

void find(const int a[],int n,int val,int val2,vector<int> &vec){
    for(int i=0;i<n;i++){
        if((a[i]==val)||(a[i]==val2))vec.push_back(i);
    }
}

int  find(const int a[],int n,int val,int pStrt){
    for(int i=pStrt;i<n;i++){
        if(a[i]==val)return i;
    }
    return -1;
}

//Fill the array with 2 digit numbers
void filAray(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
}

//Print the array with perLine elements on a line
void prntAry(const int a[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%10==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

