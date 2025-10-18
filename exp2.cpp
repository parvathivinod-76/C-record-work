#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    int BookID;
    string BookName;
    double BookPrice;

public:
    // Function to input book details from the user
    void inputBookDetails() {
        cout << "Please enter Book ID: ";
        cin >> BookID;
        cout << "Please enter Book Name (one word only): ";
        cin >> BookName;  // Using cin, so only single word allowed here
        cout << "Please enter Book Price: ";
        cin >> BookPrice;
    }

    // Function to display all the book details
    void displayBookDetails() {
        cout << "Book ID: " << BookID << endl;
        cout << "Book Name: " << BookName << endl;
        cout << "Book Price: $" << BookPrice << endl;
    }

    // Function to calculate total cost given number of copies
    double total_cost(int n) {
        return n * BookPrice;
    }
};

int main() {
    Book book1, book2, book3;

    cout << "Enter details for Book 1 below:" << endl;
    book1.inputBookDetails();
    cout << endl;

    cout << "Enter details for Book 2 below:" << endl;
    book2.inputBookDetails();
    cout << endl;

    cout << "Enter details for Book 3 below:" << endl;
    book3.inputBookDetails();
    cout << endl;

    cout << "Details of Book 1 are:" << endl;
    book1.displayBookDetails();
    cout << endl;

    cout << "Details of Book 2 are:" << endl;
    book2.displayBookDetails();
    cout << endl;

    cout << "Details of Book 3 are:" << endl;
    book3.displayBookDetails();
    cout << endl;

    int copies;

    cout << "How many copies of Book 1 do you want? ";
    cin >> copies;
    cout << "Total cost for Book 1 is: $" << book1.total_cost(copies) << endl << endl;

    cout << "How many copies of Book 2 do you want? ";
    cin >> copies;
    cout << "Total cost for Book 2 is: $" << book2.total_cost(copies) << endl << endl;

    cout << "How many copies of Book 3 do you want? ";
    cin >> copies;
    cout << "Total cost for Book 3 is: $" << book3.total_cost(copies) << endl;

    return 0;
}