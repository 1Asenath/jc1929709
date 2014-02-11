/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Introduce rest of syntax until advanced classes, Introduce structures
 * Created on February 11, 2014
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

//Global Constants
const int ROWS=500;     //for the static array - putting a global limit on the array rows and cols
const int COLS=500;

//Structures - Static & Dynamic Arrays
struct AryDyn{          //*******By Convention: Use a capital letter to start a variable name for structures*******
  int **data;           //*******Indicates when you see it that you need to go to where it's defined to figure out what it is?
  int rowsUtl;
  int colsUtl;
};
struct AryStat{         //Static Array, needs the global const SIZE (the other is a dynamic array)
  int data[ROWS][COLS];
  int rowsUtl;
  int colsUtl;
};

//Function Prototypes
//Fill Arrays
        //for static functions you won't return pointers
void fillAry(AryStat &,int,int); //Don't need to pass in size because it's all built in to the structure, but we'll pass an int in to tell it how far to fill
        //dynamic - the structure and everything else
AryDyn *fillAry(int,int);   //These are returning structures so you don't need another asterisk!!
//Print Arrays - (include the int for how many lines we're going to output for each row)
void prntAry(const AryStat&); //using a reference - don't need "int" anymore because we already embedded the number of lines and rows
void prntAry(const AryDyn *); //using a pointer
//Reclaim memory
void reclaim(AryDyn *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables and set the random number seed
    AryStat aStat;
    int rowsUtl=10;
    int colsUtl=10;   
    srand(static_cast<unsigned int>(time(0)));
    //Fill the arrays
    fillAry(aStat,rowsUtl,colsUtl);
    AryDyn *aDyn=fillAry(rowsUtl,colsUtl);
    //Print the Arrays
    prntAry(aStat);
    prntAry(aDyn);
    //Reclaim Memory for the dynamic array
    reclaim(aDyn);
    //Exit Stage Right
    return 0;
}

//Un-allocate/Destroy Memory
void reclaim(AryDyn *a){
    //Reclaim array memory FIRST
    for(int row=0;row<a->rowsUtl;row++){
       delete []a->data[row];  //for every row you have to tell it how many columns you're allocating
    }
    delete []a->data;
    //Now delete the structure itself
    delete a;
}

//Fill the Dynamic Array
AryDyn *fillAry(int rows,int cols){                //us also means utilize size here, 'a' is also similar to the stat array
    //Allocate Memory for Structure     //necessary for dynamic arrays- allocate once for the structure and once for the array
    AryDyn *a=new AryDyn;
    //Validate the size of the array
    if(rows<=1||rows>ROWS)a->rowsUtl=2;
    else a->rowsUtl=rows;
    if(cols<=1||cols>COLS)a->colsUtl=2;
    else a->colsUtl=cols;
    //Allocate Memory for the 2D Array
    a->data=new int*[a->rowsUtl];
    //Fill the Array (similar to the static array fill)
    for(int row=0;row<a->rowsUtl;row++){
       a->data[row]=new int[a->colsUtl];  //for every row you have to tell it how many columns you're allocating
        for(int col=0;col<a->colsUtl;col++){
            a->data[row][col]=rand()%900+100;
        }
    }
    return a;
}

//Fill the Static Array
void fillAry(AryStat &a, int rows, int cols){
    //Validate the size of the array
    if(rows<=1||rows>ROWS)a.rowsUtl=2;
    else a.rowsUtl=rows;
    if(cols<=1||cols>COLS)a.colsUtl=2;
    else a.colsUtl=cols;
    //Fill the Array
    for(int row=0;row<a.rowsUtl;row++){
        for(int col=0;col<a.colsUtl;col++){
             a.data[row][col]=rand()%900+100;
        }
    }
}

//Print the Dynamic Array - same stuff as printing stat array, just different notation
void prntAry(const AryDyn *a){
    //Print the Array
    cout<<endl;
    for(int row=0;row<a->rowsUtl;row++){
        for(int col=0;col<a->colsUtl;col++){
             cout<<setw(4)<<a->data[row][col];
        }
        cout<<endl;
    }
    cout<<endl;
}

//Print the Static Array
void prntAry(const AryStat&a){
    //Print the Array
    cout<<endl;
    for(int row=0;row<a.rowsUtl;row++){
        for(int col=0;col<a.colsUtl;col++){
             cout<<setw(4)<<a.data[row][col];
        }
        cout<<endl;
    }
    cout<<endl;
}