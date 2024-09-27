#include "all_headers.h"

int main() {
    vector<Book> books = readBooksFromCSV("BooksDatasetCleanAnuj.csv");

    string searchTerm;
    cout << "Enter search term: ";
    getline(cin, searchTerm);

    string searchType;
    cout << "Is this a search by (title/author/publisher)? ";
    getline(cin, searchType);

    // Transform searchType to lowercase for easier comparison
    transform(searchType.begin(), searchType.end(), searchType.begin(), ::tolower);

    if (searchType == "title") {
        searchByTitle(books, searchTerm);
    } else if (searchType == "author") {
        searchByAuthor(books, searchTerm);
    } else if (searchType == "publisher") {
        searchByPublisher(books, searchTerm);
    } else {
        cout << "Invalid search type!" << endl;
    }

    return 0;
}