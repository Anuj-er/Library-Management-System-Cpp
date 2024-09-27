#include "all_headers.h"

// Constructor
Librarian::Librarian(vector<Book> &bks) : books(bks) {}

// Function to search for books
void Librarian::searchBook(const string &term, const string &type) {
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

// Function to search books by ID
void Librarian::searchBookByID(int bookID) {
    for (const auto& book : books) {
        if (book.id == bookID) {
            cout << "Found: " << book.title << " by " << book.author << " (ID: " << book.id << ")" << endl;
            return;
        }
    }
    cout << "No book found with ID: " << bookID << endl;
}

// Function to add a new book
void Librarian::addBook(const Book &newBook) {
    books.push_back(newBook);
    recentlyReceivedBooks.push_back(newBook);
    cout << "Book added: " << newBook.title << endl;
}

// Function to view recently received books
void Librarian::viewRecentlyReceivedBooks() {
    if (recentlyReceivedBooks.empty()) {
        cout << "No recently received books." << endl;
    } else {
        cout << "Recently received books: " << endl;
        for (const auto& book : recentlyReceivedBooks) {
            cout << book.title << " by " << book.author << " (ID: " << book.id << ")" << endl;
        }
    }
}

void Librarian::removeBook(int bookID) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->id == bookID) {
            books.erase(it);
            cout << "Book removed." << endl;
            return;
        }
    }
    cout << "No book found with ID: " << bookID << endl;
}