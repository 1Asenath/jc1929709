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
    char myArray[word.size()];
    strcpy(myArray, word.c_str());
    cout<<myArray[0]<<endl;
    return 0;
}

