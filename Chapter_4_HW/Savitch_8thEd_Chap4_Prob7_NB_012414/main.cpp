/* 
 * File:   main.cpp
 * Author: Jennifer
 * Purpose: Calculate the gravitational force between two bodies
 * Created on January 24, 2014, 11:29 AM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const float G=6.673e-8; //Univ. Grav. Const in cm^3/(g*sec^2)
const float CNV_KGG=1e-3, CNV_MCM=1e-4, CNV_NLB=4.448222; //kg per g, m^2 per cm^2, Newtons per pound

//Function Prototypes
float convert(float, float, float, float);

//Execution Begins Here
int main(int argc, char** argv) {
    //Define Variables
    float d, F, masses, n1, n2, m1, m2;
    masses=convert(n1,n2,m1,m2);
    cout<<"Enter the distance between the two bodies, in meters."<<endl;
    cin>>d;
    F=G*masses/d*CNV_KGG*CNV_MCM;
    cout<<"The gravitational force between the two bodies is "<<F<<" Newtons"<<endl;
    return 0;
}

float convert(float n1, float n2, float m1, float m2){
    cout<<"Enter the weight of a body, in pounds."<<endl;
    cin>>m1;
        cout<<"Enter the weight of a second body, in pounds."<<endl;
    cin>>m2;
    //Calculate Newtons
    n1=m1*CNV_NLB;
    n2=m2*CNV_NLB;
    cout<<"(The first body is "<<n1<<" Newtons)"<<endl;
    cout<<"(The second body is "<<n2<<" Newtons)"<<endl;
    return n1*n2;
}