#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
vector<long double> balance_amount;
int indx=0;
long long int ac_last_entry;
class customer{

public:
char depositer_name[50];
 long long int account_number;
char type_of_acc[10];
long double balance;



public:
void addCustomers(int &i){
  cout<<endl;
  cout<<"Enter the details of account holder "<<i+1<<endl;
    cout<<"Enter the account holder name ";
    cin.ignore();
cin.getline(depositer_name,50);

    cout<<"Enter the account number ";

    cin>>account_number;
   
  
    cout<<"Enter the type of account ";
cin.ignore();
cin.getline(type_of_acc,10);
    cout<<"Enter the amount ";

      cin>>balance;
        balance_amount.push_back(balance);
    cout<<endl;
    
    write_detail(i);
}

void write_detail(int &i){
ac_last_entry=account_number;
	ofstream file;
    string str=to_string(account_number);
    file.open(("individual_records/"+(str)+".txt").c_str());
    file<<"\nAccount Holder Name: "<<" "<<depositer_name;
     file<<"\nAccount Number: "<<" "<<account_number;
       file<<"\nAccount Type: "<<" "<<type_of_acc;
         file<<"\nBalance: "<<" "<<balance_amount[i];     
file.close();

}

void allCustomers(int &i){
	ofstream file;
   
    file.open("allcustomers.txt",ios::app);
    file<<depositer_name<<"                           "<<account_number<<"            "<<type_of_acc<<"               "<<balance_amount[i]<<endl;    
file.close();


}

void getList(){
cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"======================================================================================-\n";
	cout<<"Name.                                 A/c no              Type               Balance\n";
	cout<<"======================================================================================\n";
   fstream file;
   string myfile;
   file.open("allcustomers.txt");
   while (getline (file, myfile)) {
  cout<<myfile<<endl;
   }
    cout<<"\n------------------------------------------------------------------------------------";

  cout<<endl;
  }


void deleteFile(long long int x){
  string s=to_string(x);
   if(remove(("individual_records/"+(s)+".txt").c_str())==0){
    cout<<"File deleted successfully!!!"<<endl;

   }
   else {
    cout<<"Error";
   }


}


void accountNumberExists(long long a){
string s=to_string(a);
ifstream file;
file.open(("individual_records/"+(s)+".txt").c_str());
  if(file){
            cout<<"Account number exists"<<endl;
  }
  else {
    cout<<"Account number not exists"<<endl;
  }
  cout<<endl;
}




};

class transaction:public customer{
  public:
long double updated_balance;

public:
void deposit(int &i){
  cout<<"Enter the account number ";
long long int a;
cin>>a;
  cout<<"Enter the amount to deposit ";
  long double amt;
  cin>>amt;
  updated_balance=balance_amount[i]+amt;
  cout<<endl;
  cout<<"Balance "<<balance_amount[i]<<endl;
   cout<<"Updated Balance "<<updated_balance<<endl;

  cout<<endl;
   	ofstream file;
    string str=to_string(a);
    file.open(("individual_records/"+(str)+".txt").c_str(),ios::app);
         file<<"\nAfter Deposting Updated Balance: "<<" "<<updated_balance<<endl;  
file.close();

}

void withdraw(int &i){
  cout<<"Enter the account number ";
  long long int a;
  cin>>a;
  cout<<"Enter the amount to withdraw ";
  long int with_draw;
  cin>>with_draw;
  updated_balance=balance_amount[i]-with_draw;
    cout<<endl;
  cout<<"Balance "<<balance_amount[i]<<endl;
   cout<<"Updated Balance "<<updated_balance<<endl;
  cout<<endl;
     	ofstream file;
    string str=to_string(a);
    file.open(("individual_records/"+(str)+".txt").c_str(),ios::app);
         file<<"\nAfter Withdrawing Updated Balance: "<<" "<<updated_balance<<endl;  
file.close();

}


  




};





int main()
{

  cout<<"Enter the number of accounts added to the system ";
int x;
  cin>>x;
customer c[x];
customer cl;
transaction t;
int cas;
  do{
   
   
   cout<<"Press 1 to add new customers"<<endl;
   cout<<"Press 2 to display all the details of account holders"<<endl;
   cout<<"Press 3 to delete the information related to account holder"<<endl;
    cout<<"Press 4 to either deposit or withdraw"<<endl;
    cout<<"Press 5 display the account number of last entry"<<endl;
    cout<<"Press 6 to check whether an account exists or not"<<endl;
   cin>>cas;
  
   switch (cas)
   {
   case 1:
   for(int i=0;i<x;i++){
        c[i].addCustomers(i);
        c[i].allCustomers(i);
    }
    break;
   case 2:
  cout<<"Account Holder List"<<endl;
   cl.getList();
   break;


case 3:

long long int a;
for(int i=0;i<x;i++){
  cout<<"Enter the account number of customer "<<i+1<<endl;
cin>>a;
cl.deleteFile(a);
}
break;

case 4:
cout<<"Do you want to deposit or withdraw "<<endl;
cout<<"Press d for deposit "<<endl;
cout<<"Press w for deposit "<<endl;

for(int i=0;i<x;i++){
cout<<endl;
cout<<"Enter the  choice for customer "<<i+1<<endl;
char c;
cin>>c;
switch (c)
{
  cout<<endl;
  
  case 'd':
  
 t.deposit(i);

 break;
  case 'w':
    
 t.withdraw(i);
  break;
default:
cout<<"Invalid choice"<<endl;
  break;
}
}

case 5:
cout<<endl;
cout<<"Account number of last entry is "<<ac_last_entry<<endl;
break;

case 6:
cout<<endl;
cout<<"Enter the account number ";
long long int ac_no;
cin>>ac_no;
cl.accountNumberExists(ac_no);
break;

   case 7:
   return 0;
   default:
   cout<<"none"<<endl;
   }
  }
while (cas!=5);






    
  
    return 0;
}
