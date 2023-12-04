#include <iostream>
using namespace std;
//#include<stdio.h>
//#include<stdlib.h>
class banking
{
    int amount,ac_number;
    char cust_name[20],ac_type[10];
    public:
    void get_record();
    friend void show_record(banking);
    int re_amount(),re_account(),deposit(),withdraw(),transfer1(int a),transfer2(int a);
};

void banking::get_record()
{
    cout<<"Enter account no:"<<endl;
    cin>>ac_number;
    cout<<"Enter account name:"<<endl;
    cin>>cust_name;
    cout<<"Enter account type:"<<endl;
    cin>>ac_type;
    cout<<"Enter amount:"<<endl;
    cin>>amount;
}

int banking::re_amount()
{
    return(amount);
}
void show_record(banking obj)
{
    cout<<"account no:"<<obj.ac_number<<endl;
    cout<<"name:"<<obj.cust_name<<endl;
    cout<<"account type:"<<obj.ac_type<<endl;
    cout<<"amount:"<<obj.amount<<endl;
}
int banking::re_account()
{
    return(ac_number);
}
int banking::deposit()
{
int d;
cout<<"Enter the amount to be deposit: "<<endl;
cin>>d;
amount=amount+d;
return amount; 
}
int banking::withdraw()
{
    int w;
if (amount <500)
{
cout<<endl;
cout<<"Sorry! Insuficient Balance transection not available"<<endl;
cout<<"Enter the ammount to be withdraw"<<endl;
cin>>w;
amount = amount-w;
cout<<"amount successfully withdraw"<<endl;
}
return amount;
}

int banking::transfer1(int a)
{
if (a<amount)
{
cout<<endl;
amount = amount-a;
cout<<"amount successfully transfer"<<endl;
}
else{
    cout<<"Sorry! Insuficient Balance transection not available"<<endl;
}
return 0;
}
int banking::transfer2(int a)
{
    amount=amount+a;
return 0;
}

int main()
{
banking x[6]; 
int ch,count,account,amount,a,flag=0,right=0,search,correct=0,acc1,acc2;

do{
start:
cout<<"__________"<<endl;
cout<<"*BANKING*"<<endl;
cout<<"1.CREATE ACCOUNT"<<endl;
cout<<"2.DEPOSIT"<<endl;
cout<<"3.WITHDROW"<<endl;
cout<<"4.DISPLAY ALL ACCOUNT"<<endl;
cout<<"5.SEARCH"<<endl;
cout<<"6.transfer"<<endl;
cout<<"7.exit"<<endl;
cout<<"__________"<<endl;
cout<<endl;
cout<<"Enter Your Choice: "<<endl;
cin>>ch;
switch(ch)
{
case 1:
int cust;
cout<<"How Many Customer Record you want to Store:"<<endl;
cin>>cust;
for (count=0;count<cust;count++)
{
cout<<count+1<< ") ACCOUNT"<<endl;
x[count].get_record(); // get_record function calling
cout<<"Account Created Successfully"<<endl;
}
break;

case 2:
cout<<"Enter the Account No"<<endl;
cin>>account;
for (count=0;count<cust;count++)
{
if (account==x[count].re_account())
{
x[count].deposit(); // deposit function calling 
cout<<" Amount Successfully Deposit"<<endl;

flag=1;
break;
}
}
if (!flag)
{
cout<<"Account Not Found"<<endl;
}
break;

case 3:

cout<<"Enter the account No!"<<endl;
cin>>account;
for (count=0;count<cust;count++)
{
if (account==x[count].re_account())
{
x[count].withdraw();
right=1;
}
}
if(!right)
{
cout<<"Account Not Found"<<endl;
}
break;

case 4:

cout<<"ACCOUNT DETAILS:"<<endl;
for (count=0;count<cust;count++)
{
if (x[count].re_account()==0) 
return 0;
cout<<count+1<<" ACCOUNT"<<endl;
cout<<"___________\n";
show_record (x[count]); // display all account record
cout<<"===============================\n";
}
break;
case 5:
cout<<"Enter account No. to be search"<<endl;
cin>>search;
for (count=0; count<cust ;count++)
{
if (search==x[count].re_account())
{
cout<<endl<<count+1<< ".ACCOUNT"<<endl;
show_record(x[count]); 
correct=1;
} 
}
if (!correct) 
{
cout<<"This Acount Not Available....Try Again."<<endl;
}
break;

case 6:
int a;
cout<<"Enter your Account number:";
cin>>acc1;
cout<<"Enter Account number for deposite amount:";
cin>>acc2;
cout<<"Enter the ammount to be transfer"<<endl;
cin>>a;

for (count=0;count<cust;count++)
{
if (acc1==x[count].re_account())
{
x[count].transfer1(a); // transfer function calling 
flag=1;
break;
}
}
for (count=0;count<cust;count++)
{
if (acc2==x[count].re_account())
{
x[count].transfer2(a); // transfer function calling 
flag=1;
break;
}
}
if (!flag)
{
cout<<"Account Not Found"<<endl;
}
        
break;

case 7:
exit(0);
break;
default: cout<<"Invalid Choice";
goto start;
}
}while(ch!=0);
return 0;

}