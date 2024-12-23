#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Structure to represent a book
struct Book {
    string title;
    string author;
    string isbn;
    bool isAvailable;

    Book(string t, string a, string i) : title(t), author(a), isbn(i), isAvailable(true) {}
};

// Structure to represent a borrower
struct Borrower {
    string name;
    string borrowedISBN;
    int daysOverdue;
};

// Global variables for books and borrowers
vector<Book> books;
vector<Borrower> borrowers;

// Function to display all books
void displayBooks() {
    cout << "\nLibrary Books:\n";
    cout << left << setw(20) << "Title" << setw(20) << "Author" << setw(15) << "ISBN" << "Availability\n";
    for (const auto& book : books) {
        cout << left << setw(20) << book.title << setw(20) << book.author 
             << setw(15) << book.isbn << (book.isAvailable ? "Available" : "Checked Out") << "\n";
    }
}

// Function to search for a book
void searchBook() {
    string query;
    cout << "Enter title, author, or ISBN to search: ";
    cin.ignore();
    getline(cin, query);

    cout << "\nSearch Results:\n";
    for (const auto& book : books) {
        if (book.title == query || book.author == query || book.isbn == query) {
            cout << left << setw(20) << book.title << setw(20) << book.author 
                 << setw(15) << book.isbn << (book.isAvailable ? "Available" : "Checked Out") << "\n";
        }
    }
}

// Function to check out a book
void checkoutBook() {
    string isbn, name;
    cout << "Enter ISBN of the book to checkout: ";
    cin >> isbn;
    cout << "Enter borrower's name: ";
    cin.ignore();
    getline(cin, name);

    for (auto& book : books) {
        if (book.isbn == isbn && book.isAvailable) {
            book.isAvailable = false;
            borrowers.push_back({name, isbn, 0});
            cout << "Book checked out successfully.\n";
            return;
        }
    }
    cout << "Book is not available or ISBN not found.\n";
}

// Function to return a book
void returnBook() {
    string isbn;
    cout << "Enter ISBN of the book to return: ";
    cin >> isbn;

    for (auto& book : books) {
        if (book.isbn == isbn && !book.isAvailable) {
            book.isAvailable = true;
            cout << "Book returned successfully.\n";

            // Remove borrower record
            for (size_t i = 0; i < borrowers.size(); ++i) {
                if (borrowers[i].borrowedISBN == isbn) {
                    borrowers.erase(borrowers.begin() + i);
                    break;
                }
            }
            return;
        }
    }
    cout << "Invalid ISBN or book was not checked out.\n";
}

// Function to calculate fine for overdue books
void calculateFine() {
    for (const auto& borrower : borrowers) {
        if (borrower.daysOverdue > 0) {
            cout << "Borrower: " << borrower.name << ", ISBN: " << borrower.borrowedISBN 
                 << ", Fine: ₹" << borrower.daysOverdue * 5 << "\n";
        }
    }
}

// Main menu
int main() {
    // Sample data
    books.push_back({"The Great Gatsby", "F. Scott Fitzgerald", "1234567890"});
    books.push_back({"1984", "George Orwell", "0987654321"});
    books.push_back({"To Kill a Mockingbird", "Harper Lee", "1122334455"});

    int choice;

    do {
        cout << "\n--- Library Management System ---\n";
        cout << "1. View Books\n";
        cout << "2. Search Book\n";
        cout << "3. Checkout Book\n";
        cout << "4. Return Book\n";
        cout << "5. Calculate Fine\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayBooks();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                checkoutBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                calculateFine();
                break;
            case 6:
                cout << "Exiting Library Management System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please select a valid option.\n";
        }
    } while (choice != 6);

    return 0;
}
