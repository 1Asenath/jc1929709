//Jennifer Clark
//January 30, 2014
//Menu for the midterm

//Library includes Here!!!
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Global Constants Here!!!
//Problem 3
const unsigned short CNV_D_CT=100; //convert dollars to cents

//Function Prototypes Here!!!
void Menu();
int getN();
void def(int);

void problem1();
//No Functions

void problem2();
void read(int&,int&,int&,int&,int&);    //request/receive input
char test(int,int,int,int,int,char);    //test for domain
void domain(char);                      //output if not in domain
char tryagain(char);                    //press y to try again
void convert(int,int,int,int,int, char);//convert integers to asterisks

void problem3();
void read(unsigned short&);                                       //request/receive input
bool verify(bool, int);                                           //verify accuracy of account number
void read(unsigned short &, unsigned short &,unsigned short &,unsigned short &,unsigned short &,unsigned short &); //read in dollars and cents
short newbal(short,unsigned short,unsigned short,unsigned short); //calculate preliminary balance
void cents(unsigned short,unsigned short,unsigned short,unsigned short &,unsigned short &,unsigned short &); //convert dollars and cents to cents
unsigned short diff(unsigned short, unsigned short); 
void convert(unsigned short, unsigned short &, unsigned short &); //converting total cents back to dollars/cents
void convpst(unsigned short, unsigned short &, unsigned short &); //converting total cents back to dollars/cents

void problem4();
//No Functions

void problem5();
//No Functions

void problem6();
bool isfunny(unsigned int, unsigned int); //Find the funny numbers

//Begin Execution Here!!!
int main(int argv,char *argc[]){
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem6();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=6);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"Menu for the Midterm"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem1(){
        cout<<"In problem # 1"<<endl<<endl;
    //Declare Variables
    int endcnt, count, space=1;
    char ans='y';
    cout<<"This program displays a sequence of integers, starting with '1', in a descending diagonal pattern."<<endl;
    cout<<endl;
    while (ans=='y'){
    cout<<"Enter an ending integer"<<endl;
    cin>>endcnt;
    cout<<endl;
    for (count=1;count<=endcnt;count++){
    cout<<setw(space)<<count<<endl;
    space++;
    }
    cout<<"Would you like to try again? Press 'y' for yes."<<endl;
    cin>>ans;
    }    
}

void problem2(){
        cout<<"In problem # 2"<<endl<<endl;
//Declare Variables
    int int1,int2,int3,int4,int5;
    char testres, ans;
    cout<<"This program reads up to 5 integers in the domain [3,27] and produces a simple histogram."<<endl;
    while (ans='y'){
    cout<<endl;
    read(int1, int2, int3, int4, int5);
    testres=test(int1, int2, int3, int4, int5, testres);
    //TEST DOMAIN RESTRICTIONS cout<<testres<<endl;
    domain(testres);
    convert(int1, int2, int3, int4, int5, testres);
    ans=tryagain(ans);
    }
}

void problem3(){
        cout<<"In problem # 3"<<endl<<endl;
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
        cout<<"Your balance at the beginning of this month is $"<<prebald<<dum<<prebalc<<endl<<endl<<endl;
    }else{
        pstbal=(-prebal);
        //TEST cout<<pstbal<<endl;
        convpst(pstbal,pstbald,pstbalc);
        cout<<setprecision(2)<<fixed;
        cout<<"You overdrew your account last month for a balance of $-"<<pstbald<<dum<<pstbalc<<"."<<endl;
        cout<<"A $27.75 fee has been assessed."<<endl;
        pstbal=(-prebal)+fee;
        convpst(pstbal,pstbald,pstbalc);
        cout<<"Your new balance is $-"<<pstbald<<dum<<pstbalc<<endl<<"Thank you for your business."<<endl<<endl<<endl;
    }
}
}

void problem4(){
        cout<<"In problem # 4"<<endl<<endl;
        //Declare Variables
    float hrswork, payrate, stime=0, dtime=0, ttime=0, gross;
    int doub=2, triple=3;
    char ans='y';
    //Set up format
    cout<<setprecision(2)<<fixed<<showpoint;
    //Request Input
    cout<<"This program determines gross pay for overpaid employees."<<endl<<endl;
    while (ans=='y'){
    cout<<"Enter the number of hours the employee worked."<<endl;
    cin>>hrswork;
    cout<<"Enter the employee's straight-time pay rate, in dollars (per hour)."<<endl;
    cin>>payrate;
    //Calculate gross pay
    if (hrswork>40){
        ttime=(hrswork-40)*payrate*triple;
        dtime=20*payrate*doub;
        stime=20*payrate;
    }else if ((hrswork<=40)&&(hrswork>20)){
        ttime=0;
        dtime=(hrswork-20)*payrate*doub;
        stime=20*payrate;
    }else if ((hrswork<=20)&&(hrswork>0)){
        stime=hrswork*payrate;
    }else{
        cout<<"Go home- your pay is 0."<<endl;
    }
    gross=stime+dtime+ttime;
    if (hrswork>0){
        cout<<"The employee's gross pay is $"<<gross<<endl<<endl;
    }
    cout<<"Would you like to calculate another employee? Press 'y' for Yes."<<endl;
    cin>>ans;
    }
}

void problem5(){
        cout<<"In problem # 5"<<endl<<endl;
    //Declare Variables
    float rateA = 29.95, rtAstp1 = 2.75, rtAstp2 = 5, rateB = 34.95, rtBstp1 = 1.5, rtBstp2 = 2.5, rateC = 39.75; //rates
    float hrs, charge, rtAprc = 0, rtBprc = 0, rtCprc = 0, atimea = 0, atimeb = 0, atimec = 0, btimea = 0, btimeb = 0, btimec = 0;
    char ans, endans;
    //Set Format
    cout << setprecision(2) << fixed << showpoint;
    //Explain Billing System & Request Input
    cout << "This ISP has three billing options for your enjoyment (or confusion)." << endl;
    //while (endans = 'y') {
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
        //cout << "For another round, press 'y'" << endl;
        //cin >> endans;
        cout << endl << endl;
    //}
}

void problem6(){
        cout<<"In problem # 6"<<endl<<endl;
    unsigned int n=1, val, count=0;
    cout<<"This program can find the 1501st funny number (with prime factors only of 2, 3, or 5)"<<endl;
    while(count<=1501){
        if(isfunny(n,val)==true){
            count++;
        }
        n++;
    }
    cout<<"The 1501st number is "<<n<<endl<<endl;
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

//Problem 6 Function
bool isfunny(unsigned int n, unsigned int val){
    val=n;
            while(val%2==0){
                val=val/2;
            }
            while(val%3==0){
                val=val/3;
            }
            while(val%5==0){
                val=val/5;
            }
            if(val==1){
                return true;
            }
            else{
                return false;
    }
}

//Problem 3 Functions:
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


//Problem 2 Functions
char tryagain (char ans){
         cout<<"Press 'y' to try again"<<endl;
         cin>>ans;
         return(ans);
}

void convert(int int1,int int2,int int3,int int4,int int5, char testres){
    if (testres!='f'){
    for(int1;(int1>=3)&&(int1<=27);int1--){
        for(int1;int1>0;int1--){
        cout<<"*";
        }
        cout<<endl;
    }
    for(int2;(int2>=3)&&(int2<=27);int2--){
        for(int2;int2>0;int2--){
            cout<<"*";
        } 
        cout<<endl;
    }
    for(int3;(int3>=3)&&(int3<=27);int3--){
        for(int3;int3>0;int3--){
            cout<<"*";
        }
        cout<<endl;

    }
    for(int4;(int4>=3)&&(int4<=27);int4--){
        for(int4;int4>0;int4--){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int5;(int5>=3)&&(int5<=27);int5--){
        for(int5;int5>0;int5--){
            cout<<"*";
        } 
        cout<<endl;
    }
    }
}

void domain(char testres){
    if (testres=='f'){
        cout<<"You did not follow instructions."<<endl;
    }
}

char test(int int1,int int2,int int3,int int4,int int5, char testres) {
    if((int1<3)||(int1>27)){
        testres='f';
    }
    if((int2<3)||(int2>27)){
        testres='f';
    }
    if((int3<3)||(int3>27)){
        testres='f';
    }
    if((int4<3)||(int4>27)){
        testres='f';
    }
    if((int5<3)||(int5>27)){
        testres='f';
    }
    return(testres);
}

void read(int &int1,int &int2,int &int3,int &int4,int &int5){
    cout<<"Enter 5 integers within this domain."<<endl;
    cin>>int1>>setw(2)>>int2>>setw(2)>>int3>>setw(2)>>int4>>setw(2)>>int5>>setw(2);
    
}