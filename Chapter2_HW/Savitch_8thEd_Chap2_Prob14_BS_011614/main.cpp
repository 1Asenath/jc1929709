/*
Jennifer Clark
January 16, 2014
Mad Lib Game
*/

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char *argv[]){
    //Declare Variables
    float instruc, name, food, number, adj, color, animal;
    cout<<"Enter the first or last name of your instructor"<<endl;
    cin>>instruc;
    cout<<"Enter your first name"<<endl;
    cin>>name;
    cout<<"Enter a food"<<endl;
    cin>>food;
    cout<<"Enter a number between 100 and 120"<<endl;
    cin>>number;
    cout<<"Enter an adjective"<<endl;
    cin>>adj;
    cout<<"Enter a color"<<endl;
    cin>>color;
    cout<<"Enter the name of an animal"<<endl;
    cin>>animal;
    cout<<"Here is your Mad Lib:"<<endl;
    cout<<endl;
    cout<<"Dear Instructor "<<instruc<<endl;
    cout<<endl;
    cout<<"I am sorry that I am unable to turn in my homework at this time. First, "
    <<"I ate a rotten "<<food<<", which made me turn "<<color<<" and feel extremely ill. "
    <<"I came down with a fever of "<<number<< " degrees. Next, my "<<adj<<" pet "
    <<animal<<" must have smelled the remains of the "<<food<<" on my homework, because "
    <<"he ate it. I am currently rewriting my homework and hope you will accept it late."<<endl;
    cout<<endl;
    cout<<"Sincerly,"<<endl;
    cout<<name<<endl;
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
