/* 
 * File:   main.cpp
 * Author: Jennifer
 * Purpose: Convert liters to gallons and calculate milage
 * Created on January 23, 2014, 7:54 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//Global Constants
const float CNV_LGAL=0.264179;

//Function Prototypes
float convert(float,float);

int main(int argc, char** argv) {
    //Declare variables
    float miles, gallon, liters, milage;
    char ans;
    while (ans='y'){
    cout<<"Enter the number of miles traveled using a tank of gas"<<endl;
    cin>>miles;
    gallon=convert(liters,gallon);
    cout<<"Your current mileage is "<<miles/gallon<<" miles per gallon"<<endl;
    cout<<"For another calculation, enter 'y'"<<endl;
    cin>>ans;
    }
    return 0;

}

float convert(float liters,float gallon){
    cout<<"Enter the number of liters of gas in the tank"<<endl;
    cin>>liters;
    gallon=liters*CNV_LGAL;
    return gallon;
}