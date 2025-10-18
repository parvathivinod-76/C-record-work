#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string brand;
    string model;
    int year;

public:
    // This function gets the car details from the user
    void readCarDetails() {
        cout << "Please enter the brand of the car: ";
        cin >> brand;
        cout << "Please enter the model of the car: ";
        cin >> model;
        cout << "Now enter the year of the car: ";
        cin >> year;
    }

    // This function shows the car details
    void displayCarDetails() {
        cout << "\n--- Car Info ---" << endl;
        cout << "Brand : " << brand << endl;
        cout << "Model : " << model << endl;
        cout << "Year  : " << year << endl;
    }
};

int main() {
    Car car1, car2, car3;

    cout << "Enter details for the first car below." << endl;
    car1.readCarDetails();

    cout << "\nEnter details for the second car below." << endl;
    car2.readCarDetails();

    cout << "\nEnter details for the third car below." << endl;
    car3.readCarDetails();

    cout << "\nDisplaying details of the first car:";
    car1.displayCarDetails();

    cout << "\nDisplaying details of the second car:";
    car2.displayCarDetails();

    cout << "\nDisplaying details of the third car:";
    car3.displayCarDetails();

    return 0;
}