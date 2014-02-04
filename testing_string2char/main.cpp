/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: testing 
 * Created on February 3, 2014, 8:12 AM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

//Global Constants

//Function Prototypes

//Execution
int main(int argc, char** argv) {
    string word;
    word="blueberries";
    char cString[word.size()], guess;
    int arylngt=word.length();        //arylngt= array length
    for (int i=0;i<arylngt;i++){
    cString[i]=word[i];
    //cout<<cString[i];
    cout<<"__ ";
    }
    cout<<endl;
    cout<<"Type your letter guess (lowercase only): ";
    cin>>guess;
    for(int i=0;i<arylngt;i++){
        if(cString[i]==guess)cout<<word[i]<<"  ";
        else if (cString[i]!=guess)cout<<"__ ";
    }
    return 0;
}
