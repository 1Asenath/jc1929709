/*
Jennifer Clark
January 16, 2014
Ouput the sum of 10 numbers > 0, <0, and sum of all numbers
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
    float sum=0, sumpos, sumneg, x;
    for (int i=1;i<=10; i++){
    cout<<"Input a whole integer"<<endl;
    cin>>x;
    sum+=x;
    if (x>=0)
       sumpos+=x;
    if (x<0)
       sumneg+=x;
}
    cout<<"The sum of all positive numbers given is "<<sumpos<<endl;
    cout<<"The sum of all negative numbers given is "<<sumneg<<endl;
    cout<<"The sum of all numbers given is "<<sum<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
