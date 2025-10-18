#include <iostream>
using namespace std;

// Base class
class BankAccount {
protected:
    string acc_no;
    double balance;

public:
    BankAccount(string ano = "", double bal = 0) : acc_no(ano), balance(bal) {}

    void setAccountDetails() {
        cout << "Enter Account Number: ";
        getline(cin, acc_no);
        cout << "Enter Initial Balance: ";
        cin >> balance;
        cin.ignore();
    }

    void deposit(double amt) {
        if (amt > 0) {
            balance += amt;
            cout << "Deposited: " << amt << "\n";
        } else {
            cout << "Deposit amount invalid!\n";
        }
    }

    void withdraw(double amt) {
        if (amt > 0 && amt <= balance) {
            balance -= amt;
            cout << "Withdrawn: " << amt << "\n";
        } else {
            cout << "Cannot withdraw. Amount invalid or insufficient funds!\n";
        }
    }

    virtual void show() {
        cout << "Account No: " << acc_no << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
    double roi;

public:
    SavingsAccount() : roi(0) {}

    void inputDetails() {
        setAccountDetails();
        cout << "Enter Rate of Interest (%): ";
        cin >> roi;
        cin.ignore();
    }

    void calcInterest() {
        double interest = balance * roi / 100;
        cout << "Interest @ " << roi << "% = " << interest << endl;
    }

    void show() override {
        cout << "\n**Savings Account Info**\n";
        BankAccount::show();
        cout << "Rate of Interest: " << roi << "%" << endl;
        calcInterest();
    }
};

class CurrentAccount : public BankAccount {
    double min_bal, service_chg;

public:
    CurrentAccount() : min_bal(0), service_chg(0) {}

    void inputDetails() {
        setAccountDetails();
        cout << "Enter Minimum Balance: ";
        cin >> min_bal;
        cout << "Enter Service Charge: ";
        cin >> service_chg;
        cin.ignore();
    }

    void calcServiceCharge() {
        if (balance < min_bal) {
            cout << "Balance below minimum. Deducting charge: " << service_chg << endl;
            balance -= service_chg;
        } else {
            cout << "Minimum balance maintained. No service charge.\n";
        }
    }

    void show() override {
        cout << "\n**Current Account Info**\n";
        BankAccount::show();
        cout << "Minimum Balance: " << min_bal << endl;
        cout << "Service Charge: " << service_chg << endl;
        calcServiceCharge();
        cout << "Balance after charges: " << balance << endl;
    }
};

int main() {
    SavingsAccount s;
    CurrentAccount c;

    cout << "Enter Savings Account Details:\n";
    s.inputDetails();
    double depAmt, withAmt;
    cout << "Deposit amount for savings account: ";
    cin >> depAmt;
    s.deposit(depAmt);
    cout << "Withdraw amount for savings account: ";
    cin >> withAmt;
    s.withdraw(withAmt);
    cin.ignore();
    s.show();

    cout << "\nEnter Current Account Details:\n";
    c.inputDetails();
    cout << "Deposit amount for current account: ";
    cin >> depAmt;
    c.deposit(depAmt);
    cout << "Withdraw amount for current account: ";
    cin >> withAmt;
    c.withdraw(withAmt);
    cin.ignore();
    c.show();

    return 0;
}