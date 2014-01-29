/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Seat People in a Plane - General Seating Chart
 * Created on January 29, 2014, 9:20 AM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const unsigned short COLS=500; //two-d arrays always require at least one global constant (only need to make 6 col for this prob but whatevz)

//Function Prototypes
  //not reading in any arrays at this point, but do want to display the array
void display(const bool [][COLS],const unsigned short[],int); //boolean two-dimensional, row-array (unsigned short), size of row array
  //need to initialize the arrays
void initial(bool [][COLS],unsigned short[],int,int);
bool whtSeat(bool [][COLS],const unsigned short[],int);  //to test if the input is within the bounds & available- bool no longer a const

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare the variables
    const int ROWS=500;
    bool seat[ROWS][COLS];
    int rowUtil=7, colUtil=6;
    unsigned short pCol[ROWS];
    //Initialize arrays
    initial(seat,pCol,rowUtil,colUtil);
    //Prompt user for seat desired
    do{
        //Display seating array
        display(seat,pCol,rowUtil);
    }while(whtSeat(seat,pCol,rowUtil));
    //Exit Stage Right
    return 0;
}

bool whtSeat(bool seat[][COLS],const unsigned short pCol[],int ROWS){
    //Prompt user for seat desired
    cout<<"Choose seat to take, i.e. 3C"<<endl;
    int rowSeat;char colSeat;
    cin>>rowSeat>>colSeat;
    rowSeat--;colSeat-='A';
    //Check if valid seats
    if(rowSeat<ROWS&&(colSeat)<=pCol[rowSeat]){
        if(!seat[rowSeat][colSeat]){
            seat[rowSeat][colSeat]=true; 
        }else{
            cout<<"Seat already taken!"<<endl;
        }
    }else{
        cout<<"Not a seat"<<endl;
        return false;
    }
    return true;
}

void initial(bool seat[][COLS],unsigned short pCol[],int ROWS,int colMax){  //seat array, pCol array, rows, col maximum
    //initialize the arrays
    for(int row=0;row<ROWS;row++){
        for(int col=0;col<COLS;col++){
            seat[row][col]=false; //initializing everything to false (seats not taken)
        }
        pCol[row]=colMax;
    }
}

void display(const bool seat[][COLS],const unsigned short pCol[],int ROWS){ //set to const because not changing, just displaying
    //Display Seating Arrangement- first display row as a number, then display abcdef across
    char view='A';
    cout<<endl;
    for(int row=0;row<ROWS;row++){
        cout<<setw(2)<<row+1;
        for(int col=0;col<pCol[row];col++){
            if(seat[row][col])cout<<setw(2)<<"X";
            else cout<<setw(2)<<static_cast<char>(view+col);//initializing everything to false (seats not taken)
        }
        cout<<endl;
    }
    
}