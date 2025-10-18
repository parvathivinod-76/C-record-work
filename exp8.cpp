#include <iostream>
using namespace std;

class Counter {
    int count;

public:
    Counter() : count(0) {}
    Counter(int c) : count(c) {}

    // Pre-increment
    Counter& operator++() {
        ++count;
        return *this;
    }

    // Post-increment
    Counter operator++(int) {
        Counter temp = *this;
        count++;
        return temp;
    }

    void display() const {
        cout << "Count = " << count << endl;
    }
};

int main() {
    Counter c1(5);

    cout << "Initial value:\n";
    c1.display();

    cout << "\nUsing pre-increment (++c1):\n";
    ++c1;
    c1.display();

    cout << "\nUsing post-increment (c1++):\n";
    c1++;
    c1.display();

    return 0;
}