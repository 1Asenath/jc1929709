/*
Jennifer Clark
January 17, 2014
Reformatting a Sphere Volume Program
*/

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char *argv[]){
    //Define Variables
    float radius, vm;
    cout<<"Enter radius of a sphere."<<endl;
    cin>>radius;
    vm=(4.0/3.0)*3.1415*radius*radius*radius; //Computes the volume of a sphere given the radius
    cout<<"The volume is "<<vm<<endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
