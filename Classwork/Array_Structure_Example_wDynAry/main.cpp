/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Introduce rest of syntax until advanced classes, Introduce structures
 * Created on February 10, 2014, 8:52 AM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

//Global Constants
const int SIZE=100;     //for the static array

//Structures - Static & Dynamic Arrays
struct AryDyn{          //*******By Convention: Use a capital letter to start a variable name for structures*******
  int *data;            //*******Indicates when you see it that you need to go to where it's defined to figure out what it is?
  int size;
};
struct AryStat{         //Static Array, needs the global const SIZE (the other is a dynamic array)
  int data[SIZE];
  int sizeUtl;
};

//Function Prototypes
//Fill Arrays
        //for static functions you won't return pointers
void fillAry(AryStat &, int); //Don't need to pass in size because it's all built in to the structure, but we'll pass an int in to tell it how far to fill
        //dynamic - the structure and everything else
AryDyn *fillAry(int);
//Print Arrays - (include the int for how many lines we're going to output for each row)
void prntAry(const AryStat&,int); //using a reference
void prntAry(const AryDyn *,int); //using a pointer
//Reclaim memory
void reclaim(AryDyn *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables and set the random number seed
    AryStat aStat;
    int sizUtl=100;
    srand(static_cast<unsigned int>(time(0)));
    //Fill the arrays
    fillAry(aStat,sizUtl);
    AryDyn *aDyn=fillAry(sizUtl);
    //Print the Arrays
    prntAry(aStat,10);
    prntAry(aDyn,10);
    //Reclaim Memory for the dynamic array
    reclaim(aDyn);
    //Exit Stage Right
    return 0;
}

//Un-allocate/Destroy Memory
void reclaim(AryDyn *a){
    //Reclaim array memory FIRST
    delete []a->data;
    //Now delete the pointer/structure itself
    delete a;
}

//Fill the Dynamic Array
AryDyn *fillAry(int us){                //us also means utilize size here, 'a' is also similar to the stat array
    //Allocate Memory for Structure     //necessary for dynamic arrays- allocate once for the structure and once for the array
    AryDyn *a=new AryDyn;
    //Validate the size of the array
    if(us<=1||us>SIZE)us=2;
    //Allocate Memory for the Array
    a->size=us;                      //A pointer to a structure
    // (*a).size=us; //(Equivalent to the line above)
    a->data=new int[a->size];
    //Fill the Array (similar to the static array fill)
    for(int i=0;i<a->size;i++){
        a->data[i]=rand()%900+100;    //Create random 3 digit numbers
        // (*a).data[i]=rand()%900+100 //(Equivalent to line above)
        // *(a->data+i)=rand()%900+100 //(Also Equivalent to line above) - pointer notation with dereferencing
        // *((*a).data+i)=rand()%900+100 //(Also Equivalent to line above) - dot notation with pointers?
    }
    return a;
}

//Fill the Static Array
void fillAry(AryStat &a, int us){  //us- utilize size
    //Validate the size of the array
    if(us<=1||us>SIZE)a.sizeUtl=2;
    else a.sizeUtl=us;
    //Fill the Array
    for(int i=0;i<a.sizeUtl;i++){
        a.data[i]=rand()%900+100;    //Create random 3 digit numbers
    }
}

//Print the Dynamic Array - same stuff as printing stat array, just different notation
void prntAry(const AryDyn *a,int perLine){
    //Print the Array
    cout<<endl;
    for(int i=0;i<a->size;i++){
        cout<<setw(4)<<a->data[i];
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//Print the Static Array
void prntAry(const AryStat&a,int perLine){
    //Print the Array
    cout<<endl;
    for(int i=0;i<a.sizeUtl;i++){
        cout<<setw(4)<<a.data[i];
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}