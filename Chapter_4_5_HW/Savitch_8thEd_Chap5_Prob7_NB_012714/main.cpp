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
void read( float &,  float &); //read in meters and cm
void convert( float &,  float &,  float &, float &); //convert feet/inches to meters
void readout( float &,  float &); //read out results

//Execution Begins Here
int main(int argc, char** argv) {
    //Define Variables
    float feet, inches, meters, cm;
    read(meters, cm);
    convert(feet, inches, meters, cm);
    readout(feet, inches);
    return 0;
}

void readout(float &feet,  float &inches){
     cout<<"That's "<<feet<<" feet or "<<inches<<" inches"<<endl;
}

void convert( float &feet,  float &inches,  float &meters,  float &cm){
    feet=(meters/CNV_FT_M)+(cm*CNV_M_CM/CNV_FT_M);
    inches=feet/12;
}

void read( float &meters,  float &cm){
    cout<<"Enter a length in whole meters and centimeters."<<endl;
    cin>>meters>>cm;
    cout<<"You entered "<<meters<< " meters and "<<cm<<" centimeters"<<endl;   
}