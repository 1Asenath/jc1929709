/*
Jennifer Clark
January 19, 2014
Determining Bouyancy of a Sphere in Water
*/

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const float Y=62.4, pi=3.14; // Y=sp. wt. of water in lb/ft^3

//Function Prototypes
int main(int argc, char *argv[]){
    //Declare Variables
    float f, v, r, wt, yes, no; //f=bouyant force, v=volume of object, r=radius of spherical object, wt=weight of object
    //Input Weight and Radius
    cout<<"Enter the weight of the sphere in pounds."<<endl;
    cin>>wt;
    cout<<"Enter the radius of the sphere in feet."<<endl;
    cin>>r;
    //Calculations
    v=(4/3)*pi*r*r*r;
    f=v*Y;
    //Output findings
    cout<<"The bouyant force of the spherical object is "<<f<<endl;
    if (f>=wt){
    cout<<"The object will float in water."<<endl;
}   else{
    cout<<"The object will sink in water."<<endl;
}
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
