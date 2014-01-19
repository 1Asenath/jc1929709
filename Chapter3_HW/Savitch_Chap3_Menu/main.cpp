/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose:  Savitch Chapter 3 Homework
 * Problem 1 -> Paper-Scissors-Rock
 * Problem 2 -> Computing Interest and Amount Due for a Revolving Credit Account
 * Problem 5 -> Cost of a Long Distance Call
 * Problem 7 -> Converting Arabic Year Numerals to Roman Numerals 
 * Problem 15 -> Determining Bouyancy of a Sphere in Water
 * Created on October 13, 2011, 6:44 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    //General Menu Format
    bool loop=true;
    do{
        //Display the selection
        cout<<"Type 1 to solve problem 1"<<endl;
        cout<<"Type 2 to solve problem 2"<<endl;
        cout<<"Type 5 to solve problem 5"<<endl;
        cout<<"Type 7 to solve problem 7"<<endl;
        cout<<"Type anything else to quit with no solutions."<<endl;
        //Read the choice
        char choice;
        cin>>choice;
        //Solve a problem that has been chosen.
        switch(choice){
                case '1':{
/*
Jennifer Clark
January 17, 2014
Paper-Scissors-Rock
*/

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes
int main(int argc, char *argv[]){
    //Define Variables
    char p_one, p_two, ans, R, r, S, s, P, p, Y;
    cout<<"This is a two-player Paper-Scisssors-Rock game."<<endl;
    
    while (ans=Y){
    cout<<"Player one, enter P (paper), S (scissors), or R (rock)."<<endl;
    cin>>p_one;
    cout<<"Player two, enter P (paper), S (scissors), or R (rock)."<<endl;
    cin>>p_two;
    if ((p_one=R || p_one=r) && (p_two=R || p_two=r)){
       cout<<"Nobody wins"<<endl;
    else if (((p_one=R||p_one=r)&&(p_two=S||p_two=s))||((p_one=S||p_one=s)&&(p_two=R||p_two=r))){
         cout<<"Scissors cut Paper"<<endl;
         }
    else if (((p_one=R||p_one=r)&&(p_two=P||p_two=p))||((p_one=P||p_one=p)&&(p_two=R||p_two=r))){
         cout<<"Paper covers Rock"<<endl;
         }
    else if (((p_one=S||p_one=s)&&(p_two=R||p_two=r))||((p_one=R||p_one=r)&&(p_two=S||p_two=s))){
        cout<<"Rock breaks Scissors"<<endl;
         }
}
    cout<<"Do you want to play again? Press 'Y' for yes."<<endl;
    cin>>ans;
}    
    system("PAUSE");
    return EXIT_SUCCESS;
}
                    break;
                }
                case '2':{
/*
Jennifer Clark
January 18, 2014
Computing Interest and Amount Due for a Revolving Credit Account
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
                    break;
                }
                case '5':{
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

                    break;
                }
                case '7':{
/*
Jennifer Clark
January 19, 2014
Converting Arabic Year Numerals to Roman Numerals
*/

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//Global Constants
const int I=1, V=5, X=10, L=50, C=100, D=500, M=1000;

//Function Prototypes
int main(int argc, char *argv[]){
    //Declare Variables
    int arabic, roman;
    cout<<"Enter a four-digit Arabic year to output the year in Roman numerals."<<endl;
    cin>>arabic
     //Calculate Number    
   if (arabic<=1999){
   cout<<M<<
}
   if ((arabic>=2000)&&(arabic<=2999)){
   cout<<MM<<
}else{       
   cout<<MMM<<
}   
                                    
    system("PAUSE");
    return EXIT_SUCCESS;
}
                    break;
                }
                 break;
                }
                case '15':{
/*
Jennifer Clark
January 19, 2014
Determining Bouyancy of a Sphere in Water
*/

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const float Y=62.4, pi=3.14; // Y=sp. wt. of water in lb/ft^3

//Function Prototypes
int main(int argc, char *argv[]){
    //Declare Variables
    float f, v, r, wt, yes, no; //f=bouyant force, v=volume of object, r=radius of spherical object, wt=weight of object
    //Input Weight and Radius
    cout<<"Enter the weight of the sphere in pounds."<<endl;
    cin>>wt;
    cout<<"Enter the radius of the sphere in feet."<<endl;
    cin>>r;
    //Calculations
    v=(4/3)*pi*r*r*r;
    f=v*Y;
    //Output findings
    cout<<"The bouyant force of the spherical object is "<<f<<endl;
    if (f>=wt){
    cout<<"The object will float in water."<<endl;
}   else{
    cout<<"The object will sink in water."<<endl;
}
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

                    break;
                }
                default:{
                        cout<<"Exit?"<<endl;
                        loop=false;
                        break;
                }
        };
    }while(loop);//Upper do-while
    return 0;
}

