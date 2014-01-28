/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose:  Chapter 4 menu
 * Problem 1 -> Savitch Chapter 5, Problem 1
 * Problem 2 -> Savitch Chapter 5, Problem 2
 * Problem 3 -> Savitch Chapter 5, Problem 3
 * Problem 4 -> Savitch Chapter 5, Problem 6
 * Problem 5 -> Savitch Chapter 5, Problem 7
 * Problem 6 -> Savitch Chapter 5, Problem
 * Problem 7 -> Savitch Chapter 5, Problem
 * Problem 8 -> Savitch Chapter 5, Problem
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
 * Purpose: Enter current time and waiting time to find the time after waiting period ends
 * Created on January 27, 2014, 1:14 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const unsigned char CNV_MIN_HRS=60; //minutes per hour (could use unsigned short)
const unsigned char CNV_24HR=12; //24 hour clock conversion
const unsigned char MIN_AM=12;

//Function Prototypes
void read(unsigned short &, unsigned short &); //read in waiting time in hours, minutes
unsigned short minutes(unsigned short, unsigned short, char); //hours, minutes, AM/PM
unsigned short minutes(unsigned short, unsigned short); //hours, minutes
void convert(unsigned short, unsigned short &, unsigned short &, char &); //converting total mins back to AM/PM

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short shr, smin, totMin, fhr, fmin;
    char fampm;
    //Read in the data
    read(shr,smin); //initial time
    //Convert to minutes
    totMin=minutes(shr,smin);
    //Convert to 12 hour time
    convert(totMin, fhr, fmin, fampm);
    cout<<"The conversion to 12-hour time is "<<fhr<<":"<<fmin<<setw(2)<<fampm<<"m"<<endl;
    //Exit stage right
    return 0;
}


unsigned short minutes(unsigned short hr, unsigned short min){
    return hr*CNV_MIN_HRS+min;
}

void convert(unsigned short totMin, unsigned short &hr, unsigned short &min, char &ampm){
    if(totMin<MIN_AM){
        ampm='a';
    }else{
        ampm='p';
}
    hr=totMin/CNV_MIN_HRS;
    min=totMin%CNV_MIN_HRS;
    if(hr>CNV_24HR){
        hr=hr-CNV_24HR;
    }
}

unsigned short minutes(unsigned short hr, unsigned short min, char ampm){
    hr+=(ampm=='p'&&hr!=CNV_24HR)?CNV_24HR:0;
    hr-=(ampm=='a'&&hr==CNV_24HR)?CNV_24HR:0;
    return hr*CNV_MIN_HRS+min;
}

void read(unsigned short &hr, unsigned short &min){
    char dum; //to read in the dummy character colon
    cout<<"Input a time"<<endl;
    cout<<"Format XX:XX "<<endl;
    cin>>setw(2)>>hr>>dum>>min;
    //test cout<<"You input the following: "<<endl;
    //test cout<<" The hour = "<<hr<<endl;
    //test cout<<" The minute = "<<min<<endl;
    //test cout<<"AM/PM = "<<ampm<<"m"<<endl;
}
            
                    break;
                }
                case '2':{
/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Enter current time and waiting time to find the time after waiting period ends
 * Created on January 27, 2014, 1:14 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const unsigned char CNV_MIN_HRS=60; //minutes per hour (could use unsigned short)
const unsigned char CNV_24HR=12; //24 hour clock conversion
const float MIN_AM=720; //minutes in the first 12 hours of the day (AM)

//Function Prototypes
void initial(unsigned short &, unsigned short &); //read in hours and minutes
void read(unsigned short &, unsigned short &); //read in hours and minutes
unsigned short minutes(unsigned short, unsigned short); //hours, minutes
unsigned short diff(unsigned short, unsigned short); 
void convert(unsigned short, unsigned short &, unsigned short &); //converting total mins back to hour/min notation

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short shr, smin, hr, min, whr, wmin, scmin, wcmin, totMin, fhr, fmin;
    //Read in the data
    initial(shr,smin); //initial time
    read(hr, min); //waiting time
    //Convert to minutes
    scmin=minutes(shr,smin);
    wcmin=minutes(hr,min);
    //test cout<<"Starting Minutes = "<<scmin<<endl;
    //test cout<<"Waiting Time in Minutes = "<<wcmin<<endl;
    //What is the total in minutes?
    totMin=diff(scmin,wcmin);
    convert(totMin, fhr, fmin);
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"After the wait time is over, it will be "<<fhr<<":"<<fmin<<endl;
    //Exit stage right
    return 0;
}

unsigned short diff(unsigned short strt, unsigned short stp){
    short min=stp+strt;
    return (min);
} 

unsigned short minutes(unsigned short hr, unsigned short min){
    return hr*CNV_MIN_HRS+min;
}

void convert(unsigned short totMin, unsigned short &hr, unsigned short &min){
    hr=totMin/CNV_MIN_HRS;
    min=totMin%CNV_MIN_HRS;
}

void read(unsigned short &whr, unsigned short &wmin){ //reading in hours, minutes, AM/PM
    char dum; //to read in the dummy character colon
    cout<<"Input a waiting time in hours and minutes"<<endl;
    cout<<"Format XX:XX"<<endl;
    cin>>setw(2)>>whr>>dum>>wmin;
}

void initial(unsigned short &hr, unsigned short &min){
    char dum; //to read in the dummy character colon
    cout<<"Input a time in 24-hr notation"<<endl;
    cout<<"Format XX:XX"<<endl;
    cin>>setw(2)>>hr>>dum>>min;
    //test cout<<"You input the following: "<<endl;
    //test cout<<" The hour = "<<hr<<endl;
    //test cout<<" The minute = "<<min<<endl;
    //test cout<<"AM/PM = "<<ampm<<"m"<<endl;
}                    
                    
                    break;
                }
                case '3':{
                    
/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Enter current time and waiting time to find the time after waiting period ends
 * Created on January 27, 2014, 1:14 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const unsigned char CNV_MIN_HRS=60; //minutes per hour (could use unsigned short)
const unsigned char CNV_24HR=12; //24 hour clock conversion
const float MIN_AM=720; //minutes in the first 12 hours of the day (AM)

//Function Prototypes
void read(unsigned short &, unsigned short &, char &); //reading in hours, minutes, AM/PM
void read(unsigned short &, unsigned short &); //read in waiting time in hours, minutes
unsigned short minutes(unsigned short, unsigned short, char); //hours, minutes, AM/PM
unsigned short minutes(unsigned short, unsigned short); //hours, minutes
unsigned short diff(unsigned short, unsigned short); 
void convert(unsigned short, unsigned short &, unsigned short &, char &); //converting total mins back to AM/PM

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short shr, smin, hr, min, whr, wmin, scmin, wcmin, totMin, fhr, fmin;
    char sampm, fampm;
    //Read in the data
    read(shr,smin,sampm); //initial time
    read(hr, min); //waiting time
    //Convert to minutes
    scmin=minutes(shr,smin,sampm);
    wcmin=minutes(hr,min);
    //test cout<<"Starting Minutes = "<<scmin<<endl;
    //test cout<<"Waiting Time in Minutes = "<<wcmin<<endl;
    //What is the difference in minutes?
    totMin=diff(scmin,wcmin);
    //test cout<<"The difference in minutes = "<<totMin<<endl;
    convert(totMin, fhr, fmin, fampm);
    cout<<"After the wait time is over, it will be "<<fhr<<":"<<fmin<<setw(2)<<fampm<<"m"<<endl;
    //Exit stage right
    return 0;
}

unsigned short diff(unsigned short strt, unsigned short stp){
    short min=stp+strt;
    return (min); //IF (stp-strt>=0)?stp-strt THEN stp-strt+24*CNV_MIN_HRS
} 

unsigned short minutes(unsigned short hr, unsigned short min){
    return hr*CNV_MIN_HRS+min;
}

void convert(unsigned short totMin, unsigned short &hr, unsigned short &min, char &ampm){
    if(totMin<MIN_AM){
        ampm='a';
    }else{
        ampm='p';
}
    hr=totMin/CNV_MIN_HRS;
    min=totMin%CNV_MIN_HRS;
    if(hr>CNV_24HR){
        hr=hr-CNV_24HR;
    }
}

unsigned short minutes(unsigned short hr, unsigned short min, char ampm){
    hr+=(ampm=='p'&&hr!=CNV_24HR)?CNV_24HR:0;
    hr-=(ampm=='a'&&hr==CNV_24HR)?CNV_24HR:0;
    return hr*CNV_MIN_HRS+min;
}

void read(unsigned short &whr, unsigned short &wmin){ //reading in hours, minutes, AM/PM
    char dum; //to read in the dummy character colon
    cout<<"Input a waiting time in hours and minutes"<<endl;
    cout<<"Format XX:XX"<<endl;
    cin>>setw(2)>>whr>>dum>>wmin;
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
                case '4':{
                    
/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose:Read in a length in feet and inches and output the length in meters and cm
 * Created on January 27, 2014
 */

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//Global Constants
const float CNV_FT_M=.3048; //convert feet to meters
const float CNV_IN_M=.0254; //convert inches to meters
const float CNV_M_CM=.01; //convert meters to cm

//Function Prototypes
void read( float &,  float &); //read in feet and inches
void convert( float &,  float &,  float &, float &); //convert feet/inches to meters
void readout( float &,  float &); //read out results

//Execution Begins Here
int main(int argc, char** argv) {
    //Define Variables
    float feet, inches, meters, cm;
    read(feet, inches);
    convert(feet, inches, meters, cm);
    readout(meters, cm);
    return 0;
}

void readout(float &meters,  float &cm){
     cout<<"That's "<<meters<<" meters or "<<cm<<" centimeters"<<endl;
}

void convert( float &feet,  float &inches,  float &meters,  float &cm){
    meters=(feet*CNV_FT_M)+(inches*CNV_IN_M);
    cm=meters/CNV_M_CM;
}

void read( float &feet,  float &inches){
    cout<<"Enter a length in whole feet and inches."<<endl;
    cin>>feet>>inches;
    cout<<"You entered "<<feet<< " feet and "<<inches<<" inches"<<endl;   
}
                    
                    break;
                }
                case '5':{
                    
/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose:Read in a length in feet and inches and output the length in meters and cm
 * Created on January 27, 2014
 */

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//Global Constants
const float CNV_FT_M=.3048; //convert feet to meters
const float CNV_IN_M=.0254; //convert inches to meters
const float CNV_M_CM=.01; //convert meters to cm

//Function Prototypes
void read( float &,  float &); //read in meters and cm
void convert( float &,  float &,  float &, float &); //convert feet/inches to meters
void readout( float &,  float &); //read out results

//Execution Begins Here
int main(int argc, char** argv) {
    //Define Variables
    float feet, inches, meters, cm;
    read(meters, cm);
    convert(feet, inches, meters, cm);
    readout(feet, inches);
    return 0;
}

void readout(float &feet,  float &inches){
     cout<<"That's "<<feet<<" feet or "<<inches<<" inches"<<endl;
}

void convert( float &feet,  float &inches,  float &meters,  float &cm){
    feet=(meters/CNV_FT_M)+(cm*CNV_M_CM/CNV_FT_M);
    inches=feet/12;
}

void read( float &meters,  float &cm){
    cout<<"Enter a length in whole meters and centimeters."<<endl;
    cin>>meters>>cm;
    cout<<"You entered "<<meters<< " meters and "<<cm<<" centimeters"<<endl;   
}
                    
                    break;
                }
                case '6':{
                   
                    
                    break;
                }
                case '7':{
                    

}
                    
                    break;
                }
                case '8':{
                    

                    
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

