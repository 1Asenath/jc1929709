/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Read <= 5 integers in the domain [3,27] and produce an asterisk-histogram
 * Created on January 28, 2014, 9:45 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes
void read(int&,int&,int&,int&,int&);    //request/receive input
char test(int,int,int,int,int,char);    //test for domain
void domain(char);                      //output if not in domain
char tryagain(char);                    //press y to try again
void convert(int,int,int,int,int, char);//convert integers to asterisks

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int int1,int2,int3,int4,int5;
    char testres, ans;
    cout<<"This program reads up to 5 integers in the domain [3,27] and produces a simple histogram."<<endl;
    while (ans='y'){
    cout<<endl;
    read(int1, int2, int3, int4, int5);
    testres=test(int1, int2, int3, int4, int5, testres);
    //TEST DOMAIN RESTRICTIONS cout<<testres<<endl;
    domain(testres);
    convert(int1, int2, int3, int4, int5, testres);
    ans=tryagain(ans);
    }
    return 0;
}

char tryagain (char ans){
         cout<<"Press 'y' to try again"<<endl;
         cin>>ans;
         return(ans);
}

void convert(int int1,int int2,int int3,int int4,int int5, char testres){
    if (testres!='f'){
    for(int1;(int1>=3)&&(int1<=27);int1--){
        for(int1;int1>0;int1--){
        cout<<"*";
        }
        cout<<endl;
    }
    for(int2;(int2>=3)&&(int2<=27);int2--){
        for(int2;int2>0;int2--){
            cout<<"*";
        } 
        cout<<endl;
    }
    for(int3;(int3>=3)&&(int3<=27);int3--){
        for(int3;int3>0;int3--){
            cout<<"*";
        }
        cout<<endl;

    }
    for(int4;(int4>=3)&&(int4<=27);int4--){
        for(int4;int4>0;int4--){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int5;(int5>=3)&&(int5<=27);int5--){
        for(int5;int5>0;int5--){
            cout<<"*";
        } 
        cout<<endl;
    }
    }
}



void domain(char testres){
    if (testres=='f'){
        cout<<"You did not follow instructions."<<endl;
    }
}

char test(int int1,int int2,int int3,int int4,int int5, char testres) {
    if((int1<3)||(int1>27)){
        testres='f';
    }
    if((int2<3)||(int2>27)){
        testres='f';
    }
    if((int3<3)||(int3>27)){
        testres='f';
    }
    if((int4<3)||(int4>27)){
        testres='f';
    }
    if((int5<3)||(int5>27)){
        testres='f';
    }
    return(testres);
}

void read(int &int1,int &int2,int &int3,int &int4,int &int5){
    cout<<"Enter 5 integers within this domain."<<endl;
    cin>>int1>>setw(2)>>int2>>setw(2)>>int3>>setw(2)>>int4>>setw(2)>>int5>>setw(2);
    
}