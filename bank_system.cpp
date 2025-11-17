#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    double balance;
public:
    void accountDetails() {
        cout << "Enter Your Name: ";
        cin.ignore();
        getline(cin, accountHolderName);
        cout << "Enter your Account Number: ";
        cin >> accountNumber;
        cout << "Enter your Initial Balance: ";
        cin >> balance;
    }

    void Deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit Money: " << amount << endl;
        } else {
            cout << "Invalid amount" << endl;
        }
    }

    void Withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            cout << "Withdraw amount: " << amount << endl;
        } else if (amount > 0 && balance < amount) {
            cout << "Insufficient balance" << endl;
        } else {
            cout << "Invalid amount" << endl;
        }
    }

    void DisplayAccount() {
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    // Friend function for transferring funds
    friend void Transfer(BankAccount& from, BankAccount& to, double amount);
};

void Transfer(BankAccount& from, BankAccount& to, double amount) {
    if (amount > 0 && from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        cout << "Transferred " << amount << " from " << from.accountHolderName
             << " to " << to.accountHolderName << endl;
    } else if (amount > 0 && from.balance < amount) {
        cout << "Insufficient balance for transfer" << endl;
    } else {
        cout << "Invalid transfer amount" << endl;
    }
}

int main() {
    BankAccount account1, account2;
    double amount;

    cout << "Enter details for Account 1:" << endl;
    account1.accountDetails();
    cout << "Enter details for Account 2:" << endl;
    account2.accountDetails();

    cout << "Enter amount to deposit in Account 1: ";
    cin >> amount;
    account1.Deposit(amount);

    cout << "Enter amount to withdraw from Account 1: ";
    cin >> amount;
    account1.Withdraw(amount);

    cout << "Enter amount to transfer from Account 1 to Account 2: ";
    cin >> amount;
    Transfer(account1, account2, amount);

    cout << "\nAfter Transactions:" << endl;
    cout << "Account 1:" << endl;
    account1.DisplayAccount();
    cout << "Account 2:" << endl;
    account2.DisplayAccount();

    return 0;
}
