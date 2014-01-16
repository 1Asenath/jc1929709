/*
Jennifer Clark
January 14, 2014
Calculating pay total- modification to calculate retroactive salary for X months
*/

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char *argv[]){
    //Define Variables
    float rt_inc=.076, retro, new_an, new_mnt, prev_an, no_mnts, partret;
    char ans;
    do{
cout<<"Enter the employee's previous annual salary"<<endl;
cin>>prev_an;
    //Calculate retroactive pay
retro=(.076/2)*prev_an;
        cout<<setprecision (2);
        cout<<fixed;
        cout<<showpoint;
cout<<"The employee's retroactive pay due is $"<<retro<<endl;
    //Calculate the new annual/monthly salary
new_an=prev_an + (prev_an*rt_inc);
new_mnt=new_an/12;
cout<<"The employee's new annual salary is $"<<new_an<<endl;
cout<<"The employee's new monthly salary is $"<<new_mnt<<endl;
cout<<"Enter a number of months between 1 and 6"
    <<" to calculate the retroactive pay due for just those months."<<endl;
cin>>no_mnts;
    //Calculate partial retroactive pay
partret=(no_mnts*new_mnt)-(no_mnts*(prev_an/12));
cout<<"The retroactive pay due for "<<no_mnts<<" months is $"<<partret<<endl;
cout<<"For another employee's calculation, enter c"<<endl;
cin>>ans;
} while (ans=='c');
cout<<"Goodbye"<<endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}
