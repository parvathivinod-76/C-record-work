#include <iostream>
#include <iomanip>  // For setw and setfill

using namespace std;

class Time {
    int hours, minutes, seconds;

public:
    Time() : hours(0), minutes(0), seconds(0) {}

    void read() {
        cout << "Enter hours (0 or more): ";
        while (!(cin >> hours) || hours < 0) {
            cout << "Oops! Please enter a valid non-negative number for hours: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter minutes (0 to 59): ";
        while (!(cin >> minutes) || minutes < 0 || minutes > 59) {
            cout << "Try again! Minutes should be between 0 and 59: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter seconds (0 to 59): ";
        while (!(cin >> seconds) || seconds < 0 || seconds > 59) {
            cout << "Try again! Seconds should be between 0 and 59: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    void display() const {
        cout << setw(2) << setfill('0') << hours << ":"
             << setw(2) << setfill('0') << minutes << ":"
             << setw(2) << setfill('0') << seconds;
    }

    friend Time addTimes(const Time& t1, const Time& t2);
};

Time addTimes(const Time& t1, const Time& t2) {
    Time result;

    int totalSeconds = t1.seconds + t2.seconds;
    result.seconds = totalSeconds % 60;

    int totalMinutes = t1.minutes + t2.minutes + totalSeconds / 60;
    result.minutes = totalMinutes % 60;

    result.hours = t1.hours + t2.hours + totalMinutes / 60;

    return result;
}

int main() {
    Time time1, time2;

    cout << "Please enter the first time:\n";
    time1.read();

    cout << "\nNow enter the second time:\n";
    time2.read();

    cout << "\nFirst time entered: ";
    time1.display();

    cout << "\nSecond time entered: ";
    time2.display();

    Time total = addTimes(time1, time2);
    cout << "\n\nSum of both times is: ";
    total.display();
    cout << endl;

    return 0;
}