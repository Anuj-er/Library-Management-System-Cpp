// Include the necessary header files
#ifndef ALL_HEADERS_H
#define ALL_HEADERS_H


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

// Define the Book structure
struct Book {
    int id;
    string title;
    string author;
    string publisher;
    double price;
    int year;
    char availability;
};

// Function prototypes
vector<Book> readBooksFromCSV(const string& filename);
void searchByTitle(const vector<Book>& books, const string& title);
void searchByAuthor(const vector<Book>& books, const string& author);
void searchByPublisher(const vector<Book>& books, const string& publisher);

#endif // ALL_HEADERS_H