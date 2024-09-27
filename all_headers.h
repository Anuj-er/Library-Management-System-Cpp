// Include the necessary header files
#ifndef ALL_HEADERS_H
#define ALL_HEADERS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Define the Book structure
struct Book {
    int id;
    string title;
    string author;
    string publisher;
    double price;
    int year;
    char availability;  // 'Y' for available, 'N' for not available
};

// Function prototypes for handling books
vector<Book> readBooksFromCSV(const string& filename);
void searchByTitle(const vector<Book>& books, const string& title);
void searchByAuthor(const vector<Book>& books, const string& author);
void searchByPublisher(const vector<Book>& books, const string& publisher);

// Class declarations
class Student {
private:
    vector<Book> &books;  // Reference to the book collection
    unordered_map<int, Book> issuedBooks;  // Issued books by the student
    unordered_map<int, Book> returnedBooks;  // Returned books by the student
public:
    Student(vector<Book> &bks);  // Constructor

    // Function to search books
    void searchBook(const string &term, const string &type);

    // Function to issue a book
    void issueBook(int bookID);

    // Function to view issued books
    void viewIssuedBooks();

    // Function to return a book
    void returnBook(int bookID);

    // Function to view returned books
    void viewReturnedBooks();
};

class Librarian {
private:
    vector<Book> &books;  // Reference to the book collection
    vector<Book> recentlyReceivedBooks;  // Books recently added
public:
    Librarian(vector<Book> &bks);  // Constructor

    // Function to search books
    void searchBook(const string &term, const string &type);

    // Function to search books by unique ID
    void searchBookByID(int bookID);

    // Function to add a new book
    void addBook(const Book &newBook);

    // Function to view recently received books
    void viewRecentlyReceivedBooks();

    // Function to remove a book
    void removeBook(int bookID);
};

#endif // ALL_HEADERS_H