/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 27, 2014, 9:18 PM
 * Purpose:  Food for Monkeys
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//Global Constants
const int COLS=7;

//Function Prototypes
int read(const char [],int [][COLS]); //char is the file name
void write(const int [][COLS],int); //not changing the write, or the size (int ROWS) but the size is pass by copy so it doesn't matter to change to const
void write(const int [][COLS],const float [],int); //including float avg and the size of the rows - to display the average in the table
int min(const int [][COLS], int); //same thing w/ second int... it's the size
int max(const int [][COLS],int);
void avg(const int [][COLS],float [],int); //the float is the avg, since we're calculating we are actually changing something y returning values, so don't make it const

int main(int argc, char** argv) {
    //Declare variables
    const int ROWS=20;
    int mnkFood[ROWS][COLS];
    float avgMnk[ROWS];
    char fName[]="./monkey.dat";
    //Read the data from the file
    int actSize=read(fName,mnkFood);
    //Write the data
    write(mnkFood,actSize);
    //Output the minimum amount of food eaten by
    //a monkey
    cout<<"Smallest amount eaten by a monkey = "
        <<min(mnkFood,actSize)<<" ounces"<<endl;
    //Output the minimum amount of food eaten by
    //a monkey
    cout<<"Largest amount eaten by a monkey = "
        <<max(mnkFood,actSize)<<" ounces"<<endl;
    //Output the average amount of food eaten by each monkey
    avg(mnkFood,avgMnk,actSize);
    //Output the augmented table w avg
    write(mnkFood,avgMnk,actSize);
    //Exit stage right
    return 0;
}

void write(const int monkey[][COLS],const float mnkAvg[],int ROWS){
    cout<<endl;
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"Monkey    M   T   W   T   F   S   S   Avg"<<endl;
    for(int row=0;row<ROWS;row++){
        cout<<"  "<<row+1<<"    ";
        for(int col=0;col<COLS;col++){
            cout<<setw(4)<<monkey[row][col];
        }
        cout<<"   "<<mnkAvg[row];
        cout<<endl;
    }
    cout<<endl;
}

void avg(const int monkey[][COLS],float avgMnk[],int ROWS){
    //initialize the avg array
    for(int row=0;row<ROWS;row++){
        avgMnk[row]=0;
        }
    //sum up the result, by monkey
    for(int row=0;row<ROWS;row++){
        for(int col=0;col<COLS;col++){
            avgMnk[row]+=monkey[row][col];
        }
    }
    //divide by number of days
    cout<<setprecision(2)<<fixed<<showpoint;
    for(int row=0;row<ROWS;row++){
        avgMnk[row]/=COLS;
        cout<<"Monkey "<<(row+1)<<" averaged "<<avgMnk[row]<<" ounces per day"<<endl;
        }
}

int max(const int monkey[][COLS],int ROWS){
    //Declare some small variable;
    int big=monkey[0][0];
    for(int row=0;row<ROWS;row++){
        for(int col=0;col<COLS;col++){
            if(big<monkey[row][col]){
                big=monkey[row][col];
            }
        }
    }
    return big;
}

int min(const int monkey[][COLS],int ROWS){
    //Declare some small variable;
    int small=monkey[0][0];
    for(int row=0;row<ROWS;row++){
        for(int col=0;col<COLS;col++){
            if(small>monkey[row][col]){
                small=monkey[row][col];
            }
        }
    }
    return small;
}

void write(const int monkey[][COLS],int ROWS){
    cout<<endl;
    cout<<"Monkey    M   T   W   T   F   S   S"<<endl;
    for(int row=0;row<ROWS;row++){
        cout<<"  "<<row+1<<"    ";
        for(int col=0;col<COLS;col++){
            cout<<setw(4)<<monkey[row][col];
        }
        cout<<endl;
    }
    cout<<endl;
}

int read(const char fName[],int monkey[][COLS]){
    //Open the file
    ifstream input;
    input.open(fName);
    //Read the data
    int row=0;
    while(input){
        for(int col=0;col<COLS;col++){
                input>>monkey[row][col];
        }
        row++;
    }
    //Close the file
    input.close();
    //return the number of rows
    return --row;
}


