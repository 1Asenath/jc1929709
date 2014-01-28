/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose:Read in a length in feet and inches and output the length in meters and cm
 * Created on January 27, 2014
 */

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//Global Constants
const float CNV_FT_M=.3048; //convert feet to meters
const float CNV_IN_M=.0254; //convert inches to meters
const float CNV_M_CM=.01; //convert meters to cm

//Function Prototypes
void read( float &,  float &); //read in feet and inches
void convert( float &,  float &,  float &, float &); //convert feet/inches to meters
void readout( float &,  float &); //read out results

//Execution Begins Here
int main(int argc, char** argv) {
    //Define Variables
    float feet, inches, meters, cm;
    read(feet, inches);
    convert(feet, inches, meters, cm);
    readout(meters, cm);
    return 0;
}

void readout(float &meters,  float &cm){
     cout<<"That's "<<meters<<" meters or "<<cm<<" centimeters"<<endl;
}

void convert( float &feet,  float &inches,  float &meters,  float &cm){
    meters=(feet*CNV_FT_M)+(inches*CNV_IN_M);
    cm=meters/CNV_M_CM;
}

void read( float &feet,  float &inches){
    cout<<"Enter a length in whole feet and inches."<<endl;
    cin>>feet>>inches;
    cout<<"You entered "<<feet<< " feet and "<<inches<<" inches"<<endl;   
}