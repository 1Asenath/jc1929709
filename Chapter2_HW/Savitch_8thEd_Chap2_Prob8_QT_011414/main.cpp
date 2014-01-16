/*
  Jennifer Clark
  January 14, 2014
  Inflation, Effects of
  */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const float CNV_PERC=100

//Function Prototypes

//Execution Begins Here
;int main(){
    //Declare Variables
    float price, infltn;
    //Input Price
    cout << "Input the starting price of an item in dollars." << endl;
    cin>>price;
    cout<<"Input the % inflation rate over time."<<endl;
    cin>>infltn;
    //Adjust (Divide by 100)
        infltn/=CNV_PERC;
    //Calculate the first year increase
        price*=(1+infltn);
    //Output (added library iomanip for setprecision/fixed/showpoint, to fix to dollars and cents to two decimal places)
        cout<<setprecision (2);
        cout<<fixed;
        cout<<showpoint;
        cout<<"Price increase first year = $"<<price<<endl;
    //Calculate the second year increase
        price*=(1+infltn);
    //Output
        cout<<"Price increase second year = $"<<price<<endl;
    //Calculate the third year increase
        price*=(1+infltn);
    //Output
        cout<<"Price third second year = $"<<price<<endl;
    //Exit Stage Right
    system("PAUSE");
    return 0;
}

