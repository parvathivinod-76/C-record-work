#include <iostream>
using namespace std;

// Base class for shopping details
class online_shopping {
protected:
    string item_name;
    int quantity;
    double unit_price;
public:
    void getShopping() {
        cout << "Item name: ";
        getline(cin, item_name);
        cout << "Quantity: ";
        cin >> quantity;
        cout << "Unit price: ";
        cin >> unit_price;
        cin.ignore();
    }
};

// Base class for shipping
class Shipping_details {
protected:
    double shipping_charge;
public:
    void getShipping() {
        cout << "Shipping charge: ";
        cin >> shipping_charge;
        cin.ignore();
    }
};

// Derived class from both bases
class Bill : public online_shopping, public Shipping_details {
public:
    void display() {
        double total = quantity * unit_price;
        double grand_total = total + shipping_charge;

        cout << "\n---- Bill ----\n";
        cout << "Item: " << item_name << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Unit Price: " << unit_price << endl;
        cout << "Total: " << total << endl;
        cout << "Shipping: " << shipping_charge << endl;
        cout << "Grand Total: " << grand_total << endl;
    }
};

int main() {
    Bill b;

    b.getShopping();
    b.getShipping();
    b.display();

    return 0;
}