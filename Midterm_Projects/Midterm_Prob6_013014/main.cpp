/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Find the 1501st Funny Number
 * Created on January 30, 2014, 5:51 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

//Global Constants

//Function Prototypes
bool isfunny(unsigned int, unsigned int);

//Execution Begins Here
int main(int argc, char** argv) {
    unsigned int n=1, val, count=0;
    cout<<"This program can find the 1501st funny number (with prime factors only of 2, 3, or 5)"<<endl;
    while(count<=1501){
        if(isfunny(n,val)==true){
            count++;
        }
        n++;
    }
    cout<<"The 1501st number is "<<n<<endl;
    return 0;
}

bool isfunny(unsigned int n, unsigned int val){
    val=n;
            while(val%2==0){
                val=val/2;
            }
            while(val%3==0){
                val=val/3;
            }
            while(val%5==0){
                val=val/5;
            }
            if(val==1){
                return true;
            }
            else{
                return false;
    }
}