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
float convert1(float,float);
float convert2(float,float);

int main(int argc, char** argv) {
    //Declare variables
    float miles, gallon1, gallon2, liters, gallon, mileag1, mileag2;
    char ans;
    while (ans='y'){
    //Calculate first car's mileage
    cout<<"Enter the number of miles traveled in the first car using a tank of gas"<<endl;
    cin>>miles;
    gallon1=convert1(liters,gallon);
    mileag1=miles/gallon1;
    cout<<"The first car's mileage is "<<mileag1<<" miles per gallon"<<endl;
    //Calculate second car's mileage
    cout<<"Enter the number of miles traveled in the second car using a tank of gas"<<endl;
    cin>>miles;
    gallon2=convert2(liters,gallon);
    mileag2=miles/gallon2;
    cout<<"The second car's mileage is "<<mileag2<<" miles per gallon"<<endl<<endl;
    //Calculate which car has best fuel efficiency
    if(mileag1>mileag2){
        cout<<"The first car has the best fuel efficiency."<<endl;        
    }
    if(mileag1<mileag2){
        cout<<"The second car has the best fuel efficiency."<<endl;
    }
    else {cout<<"Fuel efficiency is equal for both vehicles."<<endl;}
    
    cout<<"For another calculation, enter 'y'"<<endl;
    cin>>ans;
    }
    return 0;

}


float convert2(float liters,float gallon){
    cout<<"Enter the number of liters of gas in the first tank"<<endl;
    cin>>liters;
    gallon=liters*CNV_LGAL;
    return gallon;
}

float convert1(float liters,float gallon){
    cout<<"Enter the number of liters of gas in the first tank"<<endl;
    cin>>liters;
    gallon=liters*CNV_LGAL;
    return gallon;
}