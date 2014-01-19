/*
Jennifer Clark
January 18, 2014
Computing Intrest and Amount Due for a Revolving Credit Account
*/

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes
int main(int argc, char *argv[]){
    //Declare Variables
    float intrst=.01, amt_due, bal, min_pay, frsthou=1000;
    cout<<"Enter the account balance, in dollars."<<endl;
    cin>>bal;
    cout<<"Interest is 1.5% on the first $1,000 and 1% after that."<<endl;
    //Calculations
    if (bal>=frsthou){
    bal=intrst*(bal-1000)+bal+(1.5*1000);
}
    else {
    bal=intrst*bal+bal;
}
    if (bal<=10){
    amt_due=bal;
}
    else {
    amt_due=.1*bal;
}
    cout<<"The minimum payment due is $"<<amt_due<<endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
