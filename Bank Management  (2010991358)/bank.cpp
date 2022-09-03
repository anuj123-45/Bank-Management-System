#include <iostream>
#include <fstream>
using namespace std;

class customer{

char depositer_name[50];
 long int account_number;
char type_of_acc[10];
long double balance_amount;


public:
void addCustomers(){
  
    cout<<"Enter the account holder name ";
    cin.ignore();
cin.getline(depositer_name,50);

    cout<<"Enter the account number ";

    cin>>account_number;
  
    cout<<"Enter the type of account ";
cin.ignore();
cin.getline(type_of_acc,10);
    cout<<"Enter the amount ";
    cin>>balance_amount;
    cout<<endl;
    
    write_detail();

    

}

void write_detail(){

	ofstream file;
    string str=to_string(account_number);
    file.open(((str)+".txt").c_str());
    file<<"\nAccount Holder Name: "<<" "<<depositer_name;
     file<<"\nAccount Number: "<<" "<<account_number;
       file<<"\nAccount Type: "<<" "<<type_of_acc;
         file<<"\nBalance: "<<" "<<balance_amount;     
file.close();




}


};





int main()
{
int x;
  cin>>x;
customer c[x];

    cout<<"Enter the number of accounts added to the system"<<endl;
   
    for(int i=0;i<x;i++){
        c[i].addCustomers();
    }





    
  
    return 0;
}
