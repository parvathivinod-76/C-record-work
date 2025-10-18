#include <iostream>
using namespace std;

// Virtual base class Student
class Student {
protected:
    string name;
    int rollNo;
    string course;

public:
    void setStudentDetails() {
        cout << "Enter student name: ";
        getline(cin, name);
        cout << "Enter roll number: ";
        cin >> rollNo;
        cin.ignore();  // clear newline character
        cout << "Enter course name: ";
        getline(cin, course);
    }

    void displayStudentDetails() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;
        cout << "Course: " << course << endl;
    }
};

// Derived class Test from Student (virtual inheritance)
class Test : virtual public Student {
protected:
    int marks[3];

public:
    void setMarks() {
        cout << "Enter marks for 3 subjects:\n";
        for (int i = 0; i < 3; i++) {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
        cin.ignore();
    }

    void displayMarks() {
        cout << "Marks: ";
        for (int i = 0; i < 3; i++)
            cout << marks[i] << " ";
        cout << endl;
    }
};

// Derived class GraceMarks from Student (virtual inheritance)
class GraceMarks : virtual public Student {
protected:
    int bonusMark;

public:
    void setBonusMark() {
        cout << "Enter bonus marks: ";
        cin >> bonusMark;
        cin.ignore();
    }

    int getBonusMark() {
        return bonusMark;
    }
};

// Derived class Result from Test and GraceMarks
class Result : public Test, public GraceMarks {
public:
    void displayResult() {
        displayStudentDetails();
        displayMarks();
        cout << "Bonus Marks: " << getBonusMark() << endl;

        int total = 0;
        for (int i = 0; i < 3; i++)
            total += marks[i];

        total += getBonusMark();

        cout << "Total Marks (including bonus): " << total << endl;
    }
};

int main() {
    Result studentResult;

    // Take input
    studentResult.setStudentDetails();
    studentResult.setMarks();
    studentResult.setBonusMark();

    // Display all details
    cout << "\n--- Student Result ---\n";
    studentResult.displayResult();

    return 0;
}