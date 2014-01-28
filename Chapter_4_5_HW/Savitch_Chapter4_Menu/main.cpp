/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose:  Chapter 4 menu
 * Problem 1 -> Savitch Chapter 4, Problem 1
 * Problem 2 -> Savitch Chapter 4, Problem 2
 * Problem 3 -> Savitch Chapter 4, Problem 3
 * Problem 4 -> Savitch Chapter 4, Problem 7
 * Problem 5 -> Savitch Chapter 4, Problem 9
 * Problem 6 -> Savitch Chapter 4, Problem 10
 * Problem 7 -> Savitch Chapter 4, Problem 13
 * Problem 8 -> Savitch Chapter 4, Problem 16
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
        cout<<"Type 3 to solve problem 3"<<endl;
        cout<<"Type 4 to solve problem 4"<<endl;
        cout<<"Type 5 to solve problem 5"<<endl;
        cout<<"Type 6 to solve problem 6"<<endl;
        cout<<"Type 7 to solve problem 7"<<endl;
        cout<<"Type 8 to solve problem 8"<<endl;
        cout<<"Type anything else to quit with no solutions."<<endl;
        //Read the choice
        char choice;
        cin>>choice;
        //Solve a problem that has been chosen.
        switch(choice){
                case '1':{
/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Convert liters to gallons and calculate milage
 * Created on January 23, 2014, 7:54 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//Global Constants
const float CNV_LGAL=0.264179;

//Function Prototypes
float convert(float,float);

int main(int argc, char** argv) {
    //Declare variables
    float miles, gallon, liters, milage;
    char ans;
    while (ans='y'){
    cout<<"Enter the number of miles traveled using a tank of gas"<<endl;
    cin>>miles;
    gallon=convert(liters,gallon);
    cout<<"Your current mileage is "<<miles/gallon<<" miles per gallon"<<endl;
    cout<<"For another calculation, enter 'y'"<<endl;
    cin>>ans;
    }
    return 0;

}

float convert(float liters,float gallon){
    cout<<"Enter the number of liters of gas in the tank"<<endl;
    cin>>liters;
    gallon=liters*CNV_LGAL;
    return gallon;
}
            
                    break;
                }
                case '2':{
                    
                    /* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Convert liters to gallons and calculate milage
 * Created on January 23, 2014, 7:54 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//Global Constants
const float CNV_LGAL=0.264179;

//Function Prototypes
float convert1(float,float);
float convert2(float,float);

int main(int argc, char** argv) {
    //Declare variables
    float miles, gallon1, gallon2, liters, gallon, mileag1, mileag2;
    char ans;
    while (ans='y'){
    //Calculate first car's mileage
    cout<<"Enter the number of miles traveled in the first car using a tank of gas"<<endl;
    cin>>miles;
    gallon1=convert1(liters,gallon);
    mileag1=miles/gallon1;
    cout<<"The first car's mileage is "<<mileag1<<" miles per gallon"<<endl;
    //Calculate second car's mileage
    cout<<"Enter the number of miles traveled in the second car using a tank of gas"<<endl;
    cin>>miles;
    gallon2=convert2(liters,gallon);
    mileag2=miles/gallon2;
    cout<<"The second car's mileage is "<<mileag2<<" miles per gallon"<<endl<<endl;
    //Calculate which car has best fuel efficiency
    if(mileag1>mileag2){
        cout<<"The first car has the best fuel efficiency."<<endl;        
    }
    if(mileag1<mileag2){
        cout<<"The second car has the best fuel efficiency."<<endl;
    }
    else {cout<<"Fuel efficiency is equal for both vehicles."<<endl;}
    
    cout<<"For another calculation, enter 'y'"<<endl;
    cin>>ans;
    }
    return 0;

}

float convert2(float liters,float gallon){
    cout<<"Enter the number of liters of gas in the first tank"<<endl;
    cin>>liters;
    gallon=liters*CNV_LGAL;
    return gallon;
}

float convert1(float liters,float gallon){
    cout<<"Enter the number of liters of gas in the first tank"<<endl;
    cin>>liters;
    gallon=liters*CNV_LGAL;
    return gallon;
}
                    
                    break;
                }
                case '3':{
                    
/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Change a Stock Price from Fractions to Integers using a Function
 * Created on January 21, 2014, 11:51 AM
 */

//System Libraries
#include <iostream>
#include <iomanip>

using namespace std;

//Global Constants

//Function Prototypes
float stkprc(int &,int &,int &);
float convert(int,int,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int dollars, num, den;
    float result;
    //Read in the Stock Price
    stkprc(dollars,num,den);
    //Convert to Dollar Price
    result=convert(dollars,num,den);
    //Format and Output the Result
    cout<<setprecision(3)<<fixed<<showpoint;
    cout<<"The price in dollars is $"<<result<<endl;
    return 0;
}

float convert(int dollars,int num,int den){
    return dollars+(1.0*num/den);
}


float stkprc(int &dollars,int &num,int &den){
    //Declare the dummy "/" symbol
    char dum;
    //Request Input of Stock Price
    cout<<"Enter a stock price in the format XXX X/X"<<endl;
    cin>>dollars>>setw(2)>>num>>dum>>den;
}

                    
                    break;
                }
                case '4':{
                    
/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Calculate the gravitational force between two bodies
 * Created on January 24, 2014, 11:29 AM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const float G=6.673e-8; //Univ. Grav. Const in cm^3/(g*sec^2)
const float CNV_KGG=1e-3, CNV_MCM=1e-4, CNV_NLB=4.448222; //kg per g, m^2 per cm^2, Newtons per pound

//Function Prototypes
float convert(float, float, float, float);

//Execution Begins Here
int main(int argc, char** argv) {
    //Define Variables
    float d, F, masses, n1, n2, m1, m2;
    masses=convert(n1,n2,m1,m2);
    cout<<"Enter the distance between the two bodies, in meters."<<endl;
    cin>>d;
    F=G*masses/d*CNV_KGG*CNV_MCM;
    cout<<"The gravitational force between the two bodies is "<<F<<" Newtons"<<endl;
    return 0;
}

float convert(float n1, float n2, float m1, float m2){
    cout<<"Enter the weight of a body, in pounds."<<endl;
    cin>>m1;
        cout<<"Enter the weight of a second body, in pounds."<<endl;
    cin>>m2;
    //Calculate Newtons
    n1=m1*CNV_NLB;
    n2=m2*CNV_NLB;
    cout<<"(The first body is "<<n1<<" Newtons)"<<endl;
    cout<<"(The second body is "<<n2<<" Newtons)"<<endl;
    return n1*n2;
}
                    
                    break;
                }
                case '5':{
                    
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
                    
                    break;
                }
                case '6':{
                   
/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Alter previous  clothing measurement calculations to include projected calculations
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
    cout<<endl<<endl;
            
    //Set Precision
    cout<<setprecision(1)<<fixed<<showpoint;
    //Calculate Sizes
    hatsz=hat(weight, height, hatsz);
    cout<<"Apparently your hat size is "<<hatsz<<endl;
    jacksz=jacket(weight, height, jacksz, age);
    cout<<"Your supposed jacket size is "<<jacksz<<endl;
    waistsz=waist(query, adj, weight, waistsz, age);
    cout<<"And most assuredly, your waist is "<<waistsz<<" inches in circumference,"<<endl;
    cout<<"with absolutely no deviation whatsoever."<<endl<<endl;
    //Calculate jacket and waist sizing in ten years
    age=age+10;
    jacksz=jacket(weight, height, jacksz, age);
    cout<<"In 10 years, your jacket size will be "<<jacksz<<endl;
    waistsz=waist(query, adj, weight, waistsz, age);
    cout<<"and your waist will be "<<waistsz<<" inches in circumference"<<endl;
    cout<<"(assuming you don't diet or go on a 10-year fast-food binge)."<<endl;
    cout<<"Do you want to try again? Press 'y' for yes."<<endl;
    cin>>ans;
    cout<<endl<<endl;
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
                    
                    break;
                }
                case '7':{
                    
/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Output the English Lyrics to "99 Bottles of Beer"
 * Created on January 24, 2014, 3:09 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes
int frstwrd(int, int, int);
int scndwrd(int, int, int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int tens, ones, count, word;
    cout<<"Ninety-Nine Bottles of Beer on the Wall"<<endl<<endl;
    //Start Loop
    for(int count=99;count>=20;count--){
    frstwrd(tens, count, word);
    scndwrd(tens, count, word);
    cout<<"Bottles of beer on the wall,"<<endl;
    frstwrd(tens, count, word);
    scndwrd(tens, count, word);
    cout<<"Bottles of beer,"<<endl;
    cout<<"You take one down, pass it around,"<<endl;
    count=count--;
    frstwrd(tens, count, word);
    scndwrd(tens, count, word);
    cout<<"Bottles of beer on the wall."<<endl<<endl;
    return 0;
    }
}

int scndwrd(int tens, int count, int word){
    word=count%10;
    if (word=9){
        cout<<"-nine"<<endl;
    }else if (word=8){
        cout<<"-eight"<<endl;
    }else if (word=7){
        cout<<"-seven"<<endl;
    }else if (word=6){
        cout<<"-six"<<endl;
    }else if (word=5){
        cout<<"-five"<<endl;
    }else if (word=4){
        cout<<"-four"<<endl;
    }else if (word=3){
        cout<<"-three"<<endl;
    }else if (word=2){
        cout<<"-two"<<endl;
    }else if (word=1){
        cout<<"-one"<<endl;
    }else {
        cout<<"ERROR"<<endl;
    }
    return 0;
    }

int frstwrd(int tens, int count, int word){
    word=count/10;
    if ((word=9)&&(word%10!=0)){
        cout<<"Ninety"<<endl;
    }else if ((word=8)&&(word%10!=0)){
        cout<<"Eighty"<<endl;
    }else if ((word=7)&&(word%10!=0)){
        cout<<"Seventy"<<endl;
    }else if ((word=6)&&(word%10!=0)){
        cout<<"Sixty"<<endl;
    }else if ((word=5)&&(word%10!=0)){
        cout<<"Fifty"<<endl;
    }else if ((word=4)&&(word%10!=0)){
        cout<<"Fourty"<<endl;
    }else if ((word=3)&&(word%10!=0)){
        cout<<"Thirty"<<endl;
    }else if ((word=2)&&(word%10!=0)){
        cout<<"Twenty"<<endl;
    return 0;
    }
}
                    
                    break;
                }
                case '8':{
                    
/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Compute difference between start and end time in a 24-hour time machine
 * Created on January 23, 2014, 8:41 AM
 */

//System Libraries
#include <iomanip>
#include <iostream>
using namespace std;

//Global Constants
const unsigned char CNV_MIN_HRS=60; //minutes per hour (could use unsigned short)
const unsigned char CNV_24HR=12; //24 hour clock conversion

//Function Prototypes
void read(unsigned short &, unsigned short &, char &); //reading in hours, minutes, AM/PM
unsigned short minutes(unsigned short, unsigned short, char); //hours, minutes, AM/PM
unsigned short diff(unsigned short, unsigned short); 

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short shr,ehr,smin,emin,scmin,ecmin,diffMin;
    char sampm,eampm;
    //Read in the data
    read(shr,smin,sampm);
    read(ehr,emin,eampm);
    //Convert to minutes
    scmin=minutes(shr,smin,sampm);
    ecmin=minutes(ehr,emin,eampm);
    cout<<"Starting Minutes = "<<scmin<<endl;
    cout<<"Ending Minutes = "<<ecmin<<endl;
    //What is the difference in minutes?
    diffMin=diff(scmin,ecmin);
    cout<<"The difference in minutes = "<<diffMin<<endl;
    //Exit stage right
    return 0;
}

unsigned short diff(unsigned short strt, unsigned short stp){
    short min=stp-strt;
    return (min>=0)?min:(min+(2*CNV_24HR)*CNV_MIN_HRS); //IF (stp-strt>=0)?stp-strt THEN stp-strt+24*CNV_MIN_HRS
} 

unsigned short minutes(unsigned short hr, unsigned short min, char ampm){
    hr+=(ampm=='p'&&hr!=CNV_24HR)?CNV_24HR:0;
    hr-=(ampm=='a'&&hr==CNV_24HR)?CNV_24HR:0;
    return hr*CNV_MIN_HRS+min;
}

void read(unsigned short &hr, unsigned short &min, char &ampm){
    char dum; //to read in the dummy character colon and the "m" in am/pm
    cout<<"Input a time"<<endl;
    cout<<"Format XX:XX am/pm"<<endl;
    cin>>setw(2)>>hr>>dum>>min>>setw(2)>>ampm>>dum;
    //test cout<<"You input the following: "<<endl;
    //test cout<<" The hour = "<<hr<<endl;
    //test cout<<" The minute = "<<min<<endl;
    //test cout<<"AM/PM = "<<ampm<<"m"<<endl;
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

