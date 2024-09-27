#include "all_headers.h"

// Constructor
Student::Student(vector<Book> &bks) : books(bks) {}

// Function to search for books
void Student::searchBook(const string &term, const string &type) {
    if (type == "title") {
        searchByTitle(books, term);
    } else if (type == "author") {
        searchByAuthor(books, term);
    } else if (type == "publisher") {
        searchByPublisher(books, term);
    } else {
        cout << "Invalid search type!" << endl;
    }
}

// Function to issue a book
void Student::issueBook(int bookID) {
    for (const auto& book : books) {
        if (book.id == bookID) {
            if (book.availability == 'Y') {
                // Confirm issuing by displaying the book title
                char confirm;
                cout << "You are about to issue the book: " << book.title << ". Do you want to proceed? (y/n): ";
                cin >> confirm;
                cin.ignore(); // Clear the newline character from the input buffer
                
                if (confirm == 'y' || confirm == 'Y') {
                    issuedBooks[bookID] = book;
                    cout << "Book issued: " << book.title << endl;
                } else {
                    cout << "Issuing cancelled." << endl;
                }
                return;
            } else {
                cout << "Book not available for issuing!" << endl;
                return;
            }
        }
    }
    cout << "Book ID not found!" << endl;
}

// Function to view issued books
void Student::viewIssuedBooks() {
    if (issuedBooks.empty()) {
        cout << "No books have been issued." << endl;
    } else {
        cout << "Issued books: " << endl;
        for (const auto& pair : issuedBooks) {
            cout << pair.second.title << " by " << pair.second.author << " (ID: " << pair.second.id << ")" << endl;
        }
    }
}

// Function to return a book
void Student::returnBook(int bookID) {
    if (issuedBooks.find(bookID) != issuedBooks.end()) {
        // Get the book details for confirmation
        Book bookToReturn = issuedBooks[bookID];

        // Confirm returning by displaying the book title
        char confirm;
        cout << "You are about to return the book: " << bookToReturn.title << ". Do you want to proceed? (y/n): ";
        cin >> confirm;
        cin.ignore(); // Clear the newline character from the input buffer

        if (confirm == 'y' || confirm == 'Y') {
            returnedBooks[bookID] = bookToReturn; // Add to returned books
            issuedBooks.erase(bookID); // Remove from issued books
            cout << "Book returned: " << bookToReturn.title << endl;
        } else {
            cout << "Returning cancelled." << endl;
        }
    } else {
        cout << "No such book issued." << endl;
    }
}

// Function to view returned books
void Student::viewReturnedBooks() {
    if (returnedBooks.empty()) {
        cout << "No books have been returned." << endl;
    } else {
        cout << "Returned books: " << endl;
        for (const auto& pair : returnedBooks) {
            const Book& book = pair.second;
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "Publisher: " << book.publisher << endl;
            cout << "Price: $" << book.price << endl;
            cout << "Year: " << book.year << endl;
            cout << "Availability: " << (book.availability == 'Y' ? "Available" : "Not Available") << endl;
            cout << "====================" << endl; // Separator for better readability
        }
    }
}