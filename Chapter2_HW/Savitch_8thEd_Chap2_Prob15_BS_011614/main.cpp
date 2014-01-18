/*
Jennifer Clark
January 16, 2014
Velocity of Sound as Related to Temperature
*/

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes

int main(int argc, char *argv[]){
    //Define Variables
    float t_start, t_end, velo;
    int T;

    cout<<"This program calculates the velocity of sound as related to temmperature, in 1 degree intervals."<<endl;
    cout<<"Enter a starting temperature in degrees Celsius."<<endl;
    cin>>t_start;
    cout<<"Enter an ending temperature in degrees Celsius."<<endl;
    cin>>t_end;
    //Convert and setup heading
    T=t_start;
    velo=3.313e2+6.1e-1*T;
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"Temperature    Velocity"<<endl;
    for (int T=t_start;T<=t_end;T++;){
    cout<<setw(6)<<T<<setw(11)<<velo<<endl;
}
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
