/* 
 * File:   main.cpp
 * Author: Jennifer Clark
 * Purpose: 
 * Created on January 28, 2014, 11:15 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const unsigned short CNV_D_CT=100; //convert dollars to cents

//Function Prototypes
void read(unsigned short&);                                       //request/receive input
bool verify(bool, int);                                           //verify accuracy of account number
void read(unsigned short &, unsigned short &,unsigned short &,unsigned short &,unsigned short &,unsigned short &);  //read in dollars and cents
short newbal(short,unsigned short,unsigned short,unsigned short); //calculate preliminary balance
void cents(unsigned short,unsigned short,unsigned short,unsigned short &,unsigned short &,unsigned short &); //convert dollars and cents to cents
unsigned short diff(unsigned short, unsigned short); 
void convert(unsigned short, unsigned short &, unsigned short &); //converting total cents back to dollars/cents
void convpst(unsigned short, unsigned short &, unsigned short &); //converting total cents back to dollars/cents

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    bool valid;
    unsigned short acctnum,begbald,begbalc,deposd,deposc,checkd,checkc,prebald,prebalc,pstbald,pstbalc;
    unsigned short pstbal,begbal=0,deposit=0,checks=0;
    short prebal;
    float fee=2775;
    char dum='.';
    //Request Bank Account Number
    cout<<"This is the Gracious Bank of Jennifer, where both fees and security are low."<<endl<<endl;
    read(acctnum);
    valid=verify(valid, acctnum);
    if(valid==true){
        //insert subsequent input request
        read(begbald,begbalc,deposd,deposc,checkd,checkc);
        cents(begbald,deposd,checkd,begbal,deposit,checks);
        //add in cents to balances
        begbal=begbal+begbalc;
        deposit=deposit+deposc;
        checks=checks+checkc;
        //TEST cout<<begbal<<endl;
        //TEST cout<<deposit<<endl;
        //TEST cout<<checks<<endl;
        prebal=newbal(prebal, begbal, deposit, checks);
        if(prebal>=0){
        convert(prebal,prebald,prebalc);
        cout<<"Your balance at the beginning of this month is $"<<prebald<<dum<<prebalc<<endl;
    }else{
        pstbal=(-prebal);
        //TEST cout<<pstbal<<endl;
        convpst(pstbal,pstbald,pstbalc);
        cout<<setprecision(2)<<fixed;
        cout<<"You overdrew your account last month for a balance of $-"<<pstbald<<dum<<pstbalc<<"."<<endl;
        cout<<"A $27.75 fee has been assessed."<<endl;
        pstbal=(-prebal)+fee;
        convpst(pstbal,pstbald,pstbalc);
        cout<<"Your new balance is $-"<<pstbald<<dum<<pstbalc<<endl<<"Thank you for your business."<<endl;
    }
    }

    return 0;
}

short newbal(short prebal, unsigned short begbal, unsigned short deposit, unsigned short checks){
    //Calculate preliminary balance
    prebal=begbal+deposit-checks;
    //TEST cout<<"$"<<prebal<<endl;
    return prebal;
}

void convpst(unsigned short pstbal, unsigned short &pstbald, unsigned short &pstbalc){
    pstbald=pstbal/CNV_D_CT;
    pstbalc=pstbal%CNV_D_CT;
}

void convert(unsigned short prebal, unsigned short &prebald, unsigned short &prebalc){
    prebald=prebal/CNV_D_CT;
    prebalc=prebal%CNV_D_CT;
}

void cents(unsigned short begbald,unsigned short deposd,unsigned short checkd,unsigned short &begbal,unsigned short &deposit,unsigned short &checks){
    begbal=begbald*CNV_D_CT;
    deposit=deposd*CNV_D_CT;
    checks=checkd*CNV_D_CT;
}

void read(unsigned short &begbald,unsigned short &begbalc,unsigned short &deposd,unsigned short &deposc,unsigned short &checkd,unsigned short &checkc){
    char dum;
    cout<<"Enter your account balance from the beginning of the month (format XXX.XX)."<<endl<<"$";
    cin>>setw(2)>>begbald>>dum>>begbalc;
    cout<<endl<<"Enter the total of all deposits you made this month."<<endl<<"$";
    cin>>setw(2)>>deposd>>dum>>deposc;
    cout<<endl<<"Enter the total of all checks you made this month."<<endl;
    cout<<"     (We laid off our accountant, so we haven't been keeping track)"<<endl<<"$";
    cin>>setw(2)>>checkd>>dum>>checkc;
    cout<<endl;
}

bool verify(bool valid, int acctnum){
    if((acctnum>=10000)&&(acctnum<=99999)){
        cout<<"Account number confirmed!"<<endl<<endl;
        valid=true;
    }else{
        cout<<"Access denied. Please try again."<<endl;
        valid=false;
    }
    return valid;
}

void read(unsigned short &acctnum){
    cout<<"Enter your 5-digit account number. Leading zeros will be omitted."<<endl;
    cin>>acctnum;
}