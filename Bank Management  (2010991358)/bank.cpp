#include <iostream>
#include <fstream>
using namespace std;

class customer{

char depositer_name[50];
 long long int account_number;
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

void allCustomers(){
	ofstream file;
   
    file.open("allcustomers.txt",ios::app);
    file<<depositer_name<<"          "<<account_number<<"        "<<type_of_acc<<"     "<<balance_amount<<endl;    
file.close();


}

void getList(){
cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"Name.             A/c no              Type     Balance\n";
	cout<<"====================================================\n";
   fstream file;
   string myfile;
   file.open("allcustomers.txt");
   while (getline (file, myfile)) {
 
  cout<<myfile<<endl;
   }
    cout<<"\n------------------------------------------------------";
  
  
  
  
    
  cout<<endl;
  }

};





int main()
{

  cout<<"Enter the number of accounts added to the system ";
int x;
  cin>>x;
customer c[x];
customer cl;
int cas;
  do{
   
   
   cout<<"Press 1 to add new customers"<<endl;
   cout<<"Press 2 to display all the details of account holders"<<endl;
   cin>>cas;
  
   switch (cas)
   {
   case 1:
   for(int i=0;i<x;i++){
        c[i].addCustomers();
        c[i].allCustomers();
    }
    break;
   case 2:
  cout<<"Account Holder List"<<endl;
   cl.getList();
   break;
   case 3:
   return 0;
   default:
   cout<<"none"<<endl;
   }
  }
while (true);






    
  
    return 0;
}
