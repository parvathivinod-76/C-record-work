#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    void getData() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cin.ignore();
    }

    void showData() const {
        cout << "Name : " << name << endl;
        cout << "Age  : " << age << endl;
    }
};

class Student : public Person {
    int roll;

public:
    void getStudent() {
        getData();  // take name & age first
        cout << "Enter roll number: ";
        cin >> roll;
        cin.ignore();
    }

    void displayAll() const {
        showData();
        cout << "Roll No : " << roll << endl;
    }
};

int main() {
    Student s;

    cout << "Enter student details:\n";
    s.getStudent();

    cout << "\nDetails of student:\n";
    s.displayAll();

    return 0;
}