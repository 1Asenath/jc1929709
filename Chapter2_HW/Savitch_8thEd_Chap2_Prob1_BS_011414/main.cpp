/*
Jennifer Clark
January 14, 2014
Calculating a Metric Ton of Breakfast Cereal
*/

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//Global Constants
const float OZ_TON=3.527392e4; //Conversion from ounces to tons

//Function Prototypes

//Execution Begins Here
int main(int argc, char *argv[]){
    //Define Variables
    float wt_oz, wt_tns, box_req;
    char ans;
do{
cout<<"Enter the weight of a box breakfast cereal in ounces."<<endl;
cin>>wt_oz;
    //Calculate the weight of the cereal in tons & number of boxes to equal one ton
wt_tns=wt_oz/OZ_TON;
box_req=OZ_TON/wt_oz;
cout<<"This box weighs "<<wt_tns<<" metric tons."<<endl;
cout<<"You would need "<<box_req<<" boxes of this cereal to equal one metric ton."<<endl;
cout<<"Press c and then ENTER to make another weight calculation."<<endl;
cin>>ans;
} while (ans=='c');
cout<<"End of Program"<<endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
