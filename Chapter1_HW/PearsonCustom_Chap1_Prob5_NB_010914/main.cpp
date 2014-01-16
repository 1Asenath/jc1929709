/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Created on January 9, 2014
 * Two Integers - Sums and Products
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Functional Prototypes

//Execution Begins Here
int main( ) {
    int int1, int2, sum, product;
    cout << "(Press return after entering a number.)\n";
    cout << "Enter an integer:\n";
    cin >> int1;
    cout << "Enter a second integer:\n";
    cin >> int2;
    sum = int1 + int2;
    product = int1 * int2;
    cout <<endl;
    cout << "The sum of ";
    cout << int1;
    cout << " and ";
    cout << int2;
    cout << " is ";
    cout << sum;
    cout << "."<<endl;
    cout << "The product of ";
    cout << int1;
    cout << " and ";
    cout << int2;
    cout << " is ";
    cout << product;
    cout <<"."<<endl;
    cout <<endl;
    cout <<"These are the only calculations available in this program.";
    cout <<endl;
    
    return 0;
}
