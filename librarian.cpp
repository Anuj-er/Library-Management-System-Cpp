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
        
        // Sort the recently received books by ID (assuming ID correlates with recency)
        // You can modify this to sort by other criteria like date received if available.
        sort(recentlyReceivedBooks.begin(), recentlyReceivedBooks.end(), 
            [](const Book& a, const Book& b) { return a.id > b.id; });
        
        for (const auto& book : recentlyReceivedBooks) {
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "Publisher: " << book.publisher << endl;
            cout << "Year: " << book.year << endl;
            cout << "Price: $" << book.price << endl;
            cout << "Availability: " << (book.availability == 'Y' ? "Available" : "Not Available") << endl;
            cout << "ID: " << book.id << endl;
            cout << "--------------------------" << endl;
        }
    }
}


// Function to remove a book
void Librarian::removeBook(int bookID) {
    auto bookIt = find_if(books.begin(), books.end(), [bookID](const Book& book) {
        return book.id == bookID;
    });

    if (bookIt != books.end()) {
        // Confirming book details before removal
        cout << "Removing book: " << endl;
        cout << "Title: " << bookIt->title << endl;
        cout << "Author: " << bookIt->author << endl;
        cout << "Publisher: " << bookIt->publisher << endl;
        cout << "Year: " << bookIt->year << endl;
        cout << "Price: $" << bookIt->price << endl;
        cout << "Availability: " << (bookIt->availability == 'Y' ? "Available" : "Not Available") << endl;

        // Remove book from books collection
        books.erase(bookIt);
        cout << "Book removed successfully." << endl;

        // Remove the book from recently received books, if applicable
        auto recentIt = find_if(recentlyReceivedBooks.begin(), recentlyReceivedBooks.end(), [bookID](const Book& book) {
            return book.id == bookID;
        });

        if (recentIt != recentlyReceivedBooks.end()) {
            recentlyReceivedBooks.erase(recentIt);
            cout << "Book also removed from recently received books." << endl;
        }

    } else {
        cout << "No book found with ID: " << bookID << endl;
    }
}