#include <iostream>
using namespace std;

// Function to calculate area of a circle
double area(double radius) {
    return 3.1415 * radius * radius;
}

// Function to calculate area of a square
double area(int side) {
    return side * side;
}

// Function to calculate area of a rectangle
double area(double length, double width) {
    return length * width;
}

// Function to calculate area of a triangle
double area(double base, double height, int dummy) {
    return 0.5 * base * height;
}

int main() {
    double radius, length, width, base, height;
    int side;

    // Circle
    cout << "Enter radius of the circle: ";
    cin >> radius;
    cout << "Area of Circle is " << area(radius) << endl;

    // Square
    cout << "Enter side of the square: ";
    cin >> side;
    cout << "Area of Square is " << area(side) << endl;

    // Rectangle
    cout << "Enter length and width of the rectangle: ";
    cin >> length >> width;
    cout << "Area of Rectangle is " << area(length, width) << endl;

    // Triangle
    cout << "Enter base and height of the triangle: ";
    cin >> base >> height;
    cout << "Area of Triangle is " << area(base, height, 0) << endl;

    return 0;
}