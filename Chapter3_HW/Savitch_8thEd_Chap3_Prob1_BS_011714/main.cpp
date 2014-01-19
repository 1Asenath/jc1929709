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
