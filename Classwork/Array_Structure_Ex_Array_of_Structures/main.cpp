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
const int SSIZE=10;       //Structure SIZE

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
void fillAry(AryStat [],int,int,int); //pass in an array of structures - need another int for structure arrays
        //dynamic - the structure and everything else
AryDyn *fillAry(int,int,int);   //These are returning structures so you don't need another asterisk!! - need another int for struct. array
//Print Arrays - (include the int for how many lines we're going to output for each row)
void prntAry(const AryStat[],int); //using a reference - don't need "int" anymore because we already embedded the number of lines and rows
void prntAry(const AryDyn *,int); //using a pointer
//Reclaim memory
void reclaim(AryDyn *,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables and set the random number seed
    const int SUTIL=2;
    AryStat aStat[SUTIL];
    int rowsUtl=10;
    int colsUtl=10;   
    srand(static_cast<unsigned int>(time(0)));
    //Fill the arrays
    fillAry(aStat,rowsUtl,colsUtl,SUTIL);
    AryDyn *aDyn=fillAry(rowsUtl,colsUtl,SUTIL);
    //Print the Arrays
    prntAry(aStat,SUTIL);
    prntAry(aDyn,SUTIL);
    //Reclaim Memory for the dynamic array
    reclaim(aDyn,SUTIL);
    //Exit Stage Right
    return 0;
}

//Un-allocate/Destroy Memory
void reclaim(AryDyn a[],int n){
    if(n<=1||n>SSIZE)n=2;
    for(int i=0;i<n;i++){
        //Reclaim array memory FIRST
        for(int row=0;row<a[i].rowsUtl;row++){
           delete []a[i].data[row];  //for every row you have to tell it how many columns you're allocating
        }
        delete []a[i].data;
    }    
    //Now delete the structure itself
    delete []a;
}    

//Fill the Dynamic Array
AryDyn *fillAry(int rows,int cols, int n){                //us also means utilize size here, 'a' is also similar to the stat array
   //Allocate Memory for Structure     //necessary for dynamic arrays- allocate once for the structure and once for the array
    if(n<=1||n>SSIZE)n=2;              //limit the dynamic array to "those elements"... ?
    AryDyn *a=new AryDyn[n];
    for(int i=0;i<n;i++){
        //Validate the size of the array
        if(rows<=1||rows>ROWS)a[i].rowsUtl=2;
        else a[i].rowsUtl=rows;
        if(cols<=1||cols>COLS)a[i].colsUtl=2;
        else a[i].colsUtl=cols;
        //Allocate Memory for the 2D Array
        a[i].data=new int*[a[i].rowsUtl];
        //Fill the Array (similar to the static array fill)
        for(int row=0;row<a[i].rowsUtl;row++){
             a[i].data[row]=new int[a[i].colsUtl];  //for every row you have to tell it how many columns you're allocating
             for(int col=0;col<a[i].colsUtl;col++){
                 a[i].data[row][col]=rand()%900+100;
             }
        }
    }
        return a;
}

//Fill the Static Array - need to loop for every static array
void fillAry(AryStat a[], int rows, int cols, int n){
    for(int i=0;i<n;i++){                               //makes a loop for every static array
        //Validate the size of the array
        if(rows<=1||rows>ROWS)a[i].rowsUtl=2;
        else a[i].rowsUtl=rows;
        if(cols<=1||cols>COLS)a[i].colsUtl=2;
        else a[i].colsUtl=cols;
        //Fill the Array
        for(int row=0;row<a[i].rowsUtl;row++){
                for(int col=0;col<a[i].colsUtl;col++){
                a[i].data[row][col]=rand()%900+100;
                }
        }
        }
}

//Print the Dynamic Array - same stuff as printing stat array, just different notation
void prntAry(const AryDyn *a,int n){
    //Print the Array
    for(int i=0;i<n;i++){
        cout<<endl;
        for(int row=0;row<a[i].rowsUtl;row++){
                for(int col=0;col<a[i].colsUtl;col++){
                 cout<<setw(4)<<a[i].data[row][col];
                }
                cout<<endl;
        }
        cout<<endl;
    }
}

//Print the Static Array
void prntAry(const AryStat a[],int n){
    //Print the Array
    for(int i=0;i<n;i++){
        cout<<endl;
        for(int row=0;row<a[i].rowsUtl;row++){
        for(int col=0;col<a[i].colsUtl;col++){
             cout<<setw(4)<<a[i].data[row][col];
             }
        cout<<endl;
    }
    cout<<endl;
    }
}