#include <iostream>
#include <cmath>  // needed for M_PI

using namespace std;

inline double circleArea(double r) {
    return M_PI * r * r;
}

inline double squareArea(double s) {
    return s * s;
}

inline double rectArea(double l, double w) {
    return l * w;
}

inline double triArea(double b, double h) {
    return 0.5 * b * h;
}

int main() {
    double r, s, l, w, b, h;

    cout << "Radius of circle ";
    cin >> r;
    cout << "Circle's area is: " << circleArea(r) << "\n";

    cout << "Square side length ";
    cin >> s;
    cout << "Square area = " << squareArea(s) << "\n";

    cout << "Rectangle length and width ";
    cin >> l >> w;
    cout << "Area of rectangle: " << rectArea(l, w) << "\n";

    cout << "Triangle base and height ";
    cin >> b >> h;
    cout << "Triangle area = " << triArea(b, h) << "\n";

    return 0;
}