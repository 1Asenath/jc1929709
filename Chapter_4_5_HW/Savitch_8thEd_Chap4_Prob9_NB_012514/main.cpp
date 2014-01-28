/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Calculate various clothing measurements as supposedly related to weight, height, and age
 * Created on January 25, 2014, 6:59 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes
float hat(float,float,float);
float jacket(float,float,float,int);
float waist(float,int,float,float,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    float weight, height, hatsz, jacksz, waistsz, query;
    int age, adj;
    char ans;
    //Define Weight, height, age
    cout<<"This program will calculate clothing measurements"<<endl;
    cout<<"as they supposedly relate to various physical aspects."<<endl<<endl;
    while (ans='y'){
    cout<<"What is the user's height, in inches?"<<endl;
    cin>>height;
    cout<<"What is the user's weight, in pounds?"<<endl;
    cin>>weight;
    cout<<"What is the user's age, in years?"<<endl;
    cin>>age;
    //Set Precision
    cout<<setprecision(1)<<fixed<<showpoint;
    //Calculate Sizes
    hatsz=hat(weight, height, hatsz);
    cout<<"Apparently your hat size is "<<hatsz<<endl;
    jacksz=jacket(weight, height, jacksz, age);
    cout<<"Your supposed jacket size is "<<jacksz<<endl;
    waistsz=waist(query, adj, weight, waistsz, age);
    cout<<"And most assuredly, your waist is "<<waistsz<<" inches in circumference,"<<endl;
    cout<<"with no deviation whatsoever."<<endl<<endl;
    cout<<"Do you want to try again? Press 'y' for yes."<<endl;
    cin>>ans;
    cout<<endl;
}
    return 0;
}

float waist(float query, int adj, float weight, float waistsz, int age){
    query=age-30;
    if(query>=0){
        adj=(age-28)/2;
        waistsz=(weight/5.7)+(adj*.1);
    }else{
        waistsz=weight/5.7;
    }
    return(waistsz);
}

float jacket(float weight,float height,float jacksz,int age){
    if((age>39)&&(age<=49)){
        jacksz=(weight*height/288)+.125;
    }
    if((age>49)&&(age<=59)){
        jacksz=(weight*height/288)+.25;
    }
    if((age>59)&&(age<=69)){
        jacksz=(weight*height/288)+.375;
    }
    if((age>69)){
        jacksz=(weight*height/288)+.5;
    }else{
        jacksz=weight*height/288;
    }
    return(jacksz);
}

float hat(float weight,float height,float hatsz){
    hatsz=(weight/height)*2.9;
    return (hatsz);
}