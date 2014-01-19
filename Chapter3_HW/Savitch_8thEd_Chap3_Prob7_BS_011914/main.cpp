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
