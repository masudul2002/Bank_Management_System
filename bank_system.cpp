
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Bank {
public:
    void createAccount();
    void deposit();
    void withdraw();
    void balance();
};

void Bank::createAccount(){
    string name; int id; float bal;
    cout<<"Enter Name: "; cin>>name;
    cout<<"Enter ID: "; cin>>id;
    cout<<"Initial Deposit: "; cin>>bal;
    ofstream file("accounts.txt", ios::app);
    file<<id<<" "<<name<<" "<<bal<<"\n";
    cout<<"Account Created Successfully!\n";
}

void Bank::deposit(){
    int id; float amount;
    cout<<"Enter ID: "; cin>>id;
    cout<<"Deposit Amount: "; cin>>amount;

    ifstream in("accounts.txt");
    ofstream out("temp.txt");
    int fid; string name; float bal;

    while(in>>fid>>name>>bal){
        if(fid==id) bal+=amount;
        out<<fid<<" "<<name<<" "<<bal<<"\n";
    }
    in.close(); out.close();
    remove("accounts.txt"); rename("temp.txt","accounts.txt");
    cout<<"Deposit Successful!\n";
}

void Bank::withdraw(){
    int id; float amount;
    cout<<"Enter ID: "; cin>>id;
    cout<<"Withdraw Amount: "; cin>>amount;

    ifstream in("accounts.txt");
    ofstream out("temp.txt");
    int fid; string name; float bal;

    while(in>>fid>>name>>bal){
        if(fid==id){
            if(bal>=amount) bal-=amount;
            else cout<<"Insufficient Balance!\n";
        }
        out<<fid<<" "<<name<<" "<<bal<<"\n";
    }
    in.close(); out.close();
    remove("accounts.txt"); rename("temp.txt","accounts.txt");
    cout<<"Withdrawal Completed!\n";
}

void Bank::balance(){
    int id;
    cout<<"Enter ID: "; cin>>id;

    ifstream in("accounts.txt");
    int fid; string name; float bal;

    while(in>>fid>>name>>bal){
        if(fid==id){
            cout<<"Name: "<<name<<" | Balance: "<<bal<<"\n";
            return;
        }
    }
    cout<<"Account Not Found!\n";
}

int main(){
    Bank b;
    int choice;
    while(true){
        cout<<"\n1.Create 2.Deposit 3.Withdraw 4.Balance 5.Exit\nEnter: ";
        cin>>choice;
        if(choice==1) b.createAccount();
        else if(choice==2) b.deposit();
        else if(choice==3) b.withdraw();
        else if(choice==4) b.balance();
        else break;
    }
}
