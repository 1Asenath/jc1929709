/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: Calculate a customer's monthly bill for a certain price package
 * Created on January 30, 2014
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    //Declare Variables
    float rateA = 29.95, rtAstp1 = 2.75, rtAstp2 = 5, rateB = 34.95, rtBstp1 = 1.5, rtBstp2 = 2.5, rateC = 39.75; //rates
    float hrs, charge, rtAprc = 0, rtBprc = 0, rtCprc = 0, atimea = 0, atimeb = 0, atimec = 0, btimea = 0, btimeb = 0, btimec = 0;
    char ans, endans;
    //Set Format
    cout << setprecision(2) << fixed << showpoint;
    //Explain Billing System & Request Input
    cout << "This ISP has three billing options for your enjoyment (or confusion)." << endl;
    while (endans = 'y') {
        cout << "Please choose a billing option below (i.e. enter 'a' for option a):" << endl << endl;
        cout << "a) $29.95 per month for up to 11 hours of Internet." << endl;
        cout << "    Additional hours are $2.75 for the next 11 hours," << endl;
        cout << "    and $5/hour for any additional hours after that." << endl;
        cout << "b) $34.95 per month for up to 22 hours of Internet." << endl;
        cout << "    Additional hours are $1.50 for the next 11 hours," << endl;
        cout << "    and $2.50/hour for any additional hours after that." << endl;
        cout << "c) $39.75 per month for unlimited Internet access." << endl << endl;
        cin >> ans;

        if ((ans != 'a')&&(ans != 'b')&&(ans != 'c')) {
            cout << "You did not choose a valid answer. Please try again." << endl;
            cin >> ans;
        }

        cout << endl << "..." << endl << endl;
        cout << "Congratulations on completing your first month of service with billing option " << ans << "." << endl;
        cout << "Please enter the number of hours of Internet used this past month." << endl;
        cin >> hrs;
        //Create calculations for billing
        if (ans == 'a') {
            if (hrs > 22) {
                atimea = (hrs - 22) * rtAstp2;
                atimeb = 11 * rtAstp1;
                atimec = rateA;
            } else if ((hrs <= 22)&&(hrs > 11)) {
                atimeb = (hrs - 11) * rtAstp1;
                atimec = rateA;
            } else if ((hrs <= 11)&&(hrs > 0)) {
                atimec = rateA;
            } else {
                cout << "Why didn't you use your Internet service this month?" << endl;
            }
            rtAprc = atimea + atimeb + atimec;
        } else if (ans == 'b') {
            if (hrs > 33) {
                btimea = (hrs - 33) * rtBstp2;
                btimeb = 22 * rtBstp1;
                btimec = rateB;
            } else if ((hrs <= 33)&&(hrs > 22)) {
                btimeb = (hrs - 22) * rtBstp1;
                btimec = rateB;
            } else if ((hrs <= 22)&&(hrs > 0)) {
                btimec = rateB;
            } else {
                cout << "Why didn't you use your Internet service this month?" << endl;
            }
            rtBprc = btimea + btimeb + btimec;
        } else {
            rtCprc = rateC;
        }
        //Output Charge
        charge = rtAprc + rtBprc + rtCprc;
        cout << "Your total charge for last month is $" << charge << endl << endl;
        //Loop
        cout << "For another round, press 'y'" << endl;
        cin >> endans;
        cout << endl << endl;
    }
    return 0;
}

