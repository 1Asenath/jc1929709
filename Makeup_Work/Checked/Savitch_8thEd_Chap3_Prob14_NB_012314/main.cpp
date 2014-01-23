/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Finding all Prime Numbers between 3 and 100
 * Created on January 23, 2014, 11:14 AM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes
bool isPrime(unsigned int); //requirement for Gaddis problem
int outPrime(unsigned int); //for Savitch problem
int random(unsigned int,unsigned int); //for the random seed prob, for gaddis

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed - for gaddis
    srand(static_cast<unsigned int>(time(0)));
    //Choose Random number range - for gaddis
    int strt=100,stp=200;
    int rnd=random(100,200);
    //Output the results
    cout<<"The random numbers up to "<<rnd<<" are"<<endl;
    //call outPrime
    cout<<"The number of primes = "<<outPrime(rnd)<<endl;
    //Exit Stage Right
    return 0;
}

int random(unsigned int strt,unsigned int stp){
    return rand()%(stp-strt+1)+strt; //gives a range of rand numbs from starting to ending pt
}

int outPrime(unsigned int n){ //output until you reach the number n
    //count the number of primes
    int cnt=0;
    cout<<endl;
    for(int i=2;i<=n;i++){ //counter starts with zero
        if(isPrime(i)){
            cout<<setw(5)<<i;
            if(cnt++%10==9)cout<<endl;
    }
}
    cout<<endl;
    return cnt;
}

//Requirement for Gaddis Problem
bool isPrime(unsigned int n){
    int loop=sqrt(n); //no point to loop beyond the square root of the number
    for(int i=2;i<=loop;i++){
        if(n%i==0)return false; //looking for the mod of the number
    }
    return true; //return true if we don't return false
}
