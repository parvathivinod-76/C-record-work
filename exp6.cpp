#include <iostream>
#include <string>
using namespace std;

class TelephoneBill {
private:
    string name;
    string address;
    string phone;
    int calls;

public:
    TelephoneBill() {
        calls = 0;
    }

    void getDetails() {
        cout << "\nWhat's the customer's name? ";
        cin.ignore(); // clear leftover input
        getline(cin, name);

        cout << "Where does " << name << " live? ";
        getline(cin, address);

        cout << "What's the phone number? ";
        cin >> phone;

        cout << "How many calls did they make? ";
        while (!(cin >> calls) || calls < 0) {
            cout << "Oops, enter a valid number of calls please: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    friend void calculateBill(const TelephoneBill&);
};

const double chargePerCall = 2.0;

void calculateBill(const TelephoneBill& bill) {
    double total = bill.calls * chargePerCall;

    cout << "\nHere’s the bill info:\n";
    cout << "Name          : " << bill.name << endl;
    cout << "Address       : " << bill.address << endl;
    cout << "Phone         : " << bill.phone << endl;
    cout << "Calls made    : " << bill.calls << endl;
    cout << "Charge/call   : Rs. " << chargePerCall << endl;
    cout << "-----------------------------\n";
    cout << "Total amount  : Rs. " << total << endl;
    cout << "-----------------------------\n";
}

int main() {
    TelephoneBill customer;

    customer.getDetails();
    calculateBill(customer);

    return 0;
}