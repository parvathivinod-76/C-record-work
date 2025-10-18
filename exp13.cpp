#include <iostream>
using namespace std;

// Base class: Polygon
class C_Polygon {
public:
    // Virtual: base class definition for area
    virtual double area() {
        cout << "This is the base polygon area.\n";
        return 0;
    }
};

class C_Rectangle : public C_Polygon {
    double length, width;
public:
    C_Rectangle(double l, double w) : length(l), width(w) {}

    double area() override {
        return length * width;
    }
};

class C_Triangle : public C_Polygon {
    double base, height;
public:
    C_Triangle(double b, double h) : base(b), height(h) {}

    double area() override {
        return 0.5 * base * height;
    }
};

int main() {
    C_Polygon* poly;

    double l, w, b, h;
    cout << "Enter rectangle length and width: ";
    cin >> l >> w;
    C_Rectangle rect(l, w);

    cout << "Enter triangle base and height: ";
    cin >> b >> h;
    C_Triangle tri(b, h);

    poly = &rect;
    cout << "Area of rectangle: " << poly->area() << endl;

    poly = &tri;
    cout << "Area of triangle: " << poly->area() << endl;

    return 0;
}