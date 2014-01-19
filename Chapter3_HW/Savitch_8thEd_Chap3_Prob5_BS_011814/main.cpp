/*
Jennifer Clark
January 18, 2014
Cost of a Long Distance Call
*/

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes
int main(int argc, char *argv[]){
    //Declare Variables
    float m_f_day, m_f_nt, sat_sun, start, end, cost, time, rate;
    char Mo, Tu, We, Th, Fr, Sa, Su,day;
    cout<<"Enter the start time of the call, in 24-hour notation."<<endl;
    cin>>start;
    cout<<"Enter the end time of the call, in 24-hour notation."<<endl;
    cin>>end;
    cout<<"Enter the first two letters of the day of the call (ex: Monday as 'Mo'."<<endl;
    cin>>day;
    //Problem Setup
    if ((day==Sa)||(day==Su)){
    rate=0.15;
}
    if ((day!=Sa)&&(day!=Su)&&(start>=8)&&(start<=18)){
    rate=.40;
}
    else if ((day!=Sa)&&(day!=Su)&&(start>18)&&(start<8)){
    rate=.25;
}
    else {
    cout<<"Error, Please try again"<<endl;
}
}
    //Calculations
    time=start-end;
    cost=rate*time;
    cout<<"The cost of this phone call is $"<<cost<<endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
