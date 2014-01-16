/*
Jennifer Clark
January 14, 2014
Determining Violation of Meeting Room Capacity
*/

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char *argv[]){
    //Define Variables
    float mtg_cap, attend, xtra_ppl, exclude;
cout<<"Enter the maximum capacity of the meeting room."<<endl;
cin>>mtg_cap;
cout<<"Enter the total number of people attending the meeting."<<endl;
cin>>attend;
    //Calculate whether people exceed maximum capacity
if (attend>=mtg_cap){
if (attend=mtg_cap)
cout<<"You may hold the meeting, but you are at maximum capacity."<<endl; 
}
else{
   //Calculate how many people must be excluded
   exclude=attend-mtg_cap;
   cout<<"The meeting cannot be held due to fire regulations."<<endl;
   cout<<exclude<<" people must be excluded in order to meet regulations."<<endl;
}
if (attend<mtg_cap){
    //Calculate how many additional people may attend
    xtra_ppl=mtg_cap-attend;
    cout<<xtra_ppl<<" additional people may legally attend in accordance with fire regulations."<<endl;
}    
    system("PAUSE");
    return EXIT_SUCCESS;
}
    
