#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    // Default constructor
    Rectangle() {
        length = 0;
        width = 0;
        cout << "constructer called " << endl;
    }

    // Parameterized constructor
    Rectangle(double l, double w) {
        length = l;
        width = w;
        cout << "Parameterized constructor called." << endl;
    }

    // Member function to display the values
    void displayValues() {
        cout << "Length: " << length << ", Width: " << width << endl;
    }

    // Destructor
    ~Rectangle() {
        cout << "Destructor called for the object." << endl;
    }
};

int main() {
    // Create a Rectangle object using the default constructor
    Rectangle rect1;
    rect1.displayValues();

    // Create a Rectangle object using the parameterized constructor
    Rectangle rect2(5.0, 3.0);
    rect2.displayValues();

    return 0;
}