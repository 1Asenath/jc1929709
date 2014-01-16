/*
Jennifer Clark
January 15, 2014
Calculating the number of months required to pay off a loan accruing interest
*/

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char *argv[]){
    //Define Variables
    float initial, intrate, intrest=0, mo_pymt, bal, mntsreq, mnt=0;
cout<<"Enter the initial amount due"<<endl;
cin>>initial;
cout<<"Enter the monthly % interest rate"<<endl;
cin>>intrate;
    //Convert percent to decimal
intrate=intrate/100
cout<<"Enter the monthly payment on the loan"<<endl;
cin>>mo_pymt;
    //Calculate first month's balance after first payment
while (bal>0){
bal=initial-mo_pymt+(initial*intrate);
mnt=mnt+1;
intrest=intrest+(initial*intrate);
}
cout<<"It will take "<<mnt<<"months to pay off the loan."<<endl;
cout<<"The total amount of interest paid will be $"<<intrest<<endl;

    
    system("PAUSE");
    return EXIT_SUCCESS;
}
