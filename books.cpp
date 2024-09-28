// Include the necessary header files
#include "all_headers.h"

// Read the books from the CSV file
vector<Book> readBooksFromCSV(const string& filename) {
    // Create a vector to store the books
    vector<Book> books; // Vector to store the books
    ifstream file(filename); // Open the file
    string line, word; // Variables to read each line and word

    // Skip the header line
    int idCounter = 1;

    // Read each line from the file
    while (getline(file, line)) {
        // Create a string stream to parse the line
        stringstream ss(line);
        Book book;
        book.id = idCounter++;
        getline(ss, book.title, ',');
        getline(ss, book.author, ',');
        getline(ss, book.publisher, ',');
        ss >> book.price;
        ss.ignore();
        ss >> book.year;
        ss.ignore();
        ss >> book.availability;
        books.push_back(book);
    }
    return books;
}

// Search for books by title
void searchByTitle(const vector<Book>& books, const string& title) {
    // Convert the search term to lowercase
    string lowerTitle = title;

    // Convert the search term to lowercase
    transform(lowerTitle.begin(), lowerTitle.end(), lowerTitle.begin(), ::tolower);

    // Iterate over the books and search for the title
    for (const auto& book : books) {
        string lowerBookTitle = book.title;
        transform(lowerBookTitle.begin(), lowerBookTitle.end(), lowerBookTitle.begin(), ::tolower);

        // If the title contains the search term, print the book details
        if (lowerBookTitle.find(lowerTitle) != string::npos) {
            cout << "Found: " << book.title << " by " << book.author << " (ID: " << book.id << ")" << endl;
        }
    }
}

// Search for books by author
void searchByAuthor(const vector<Book>& books, const string& author) {
    string lowerAuthor = author;
    // Convert the search term to lowercase
    transform(lowerAuthor.begin(), lowerAuthor.end(), lowerAuthor.begin(),
              [](unsigned char c) { return tolower(c); });
    // Initialize a flag to check if any books are found
    bool found = false;

    // Iterate over the books and search for the author
    for (const auto& book : books) {
        string lowerBookAuthor = book.author;
        // Convert the book author's name to lowercase
        transform(lowerBookAuthor.begin(), lowerBookAuthor.end(), lowerBookAuthor.begin(),
                  [](unsigned char c) { return tolower(c); });

        // If the author contains the search term, print the book details
        if (lowerBookAuthor.find(lowerAuthor) != string::npos) {
            cout << "Found: " << book.title << " by " << book.author << " (ID: " << book.id << ")" << endl;
            found = true;
        }
    }

    // If no books are found, print a message
    if (!found) {
        cout << "No books found by author: " << author << endl;
    }
}
void searchByPublisher(const vector<Book>& books, const string& publisher) {
    string lowerPublisher = publisher;
    // Convert the search term to lowercase
    transform(lowerPublisher.begin(), lowerPublisher.end(), lowerPublisher.begin(),
              [](unsigned char c) { return tolower(c); });

    // Initialize a flag to check if any books are found
    bool found = false;

    // Iterate over the books and search for the publisher
    for (const auto& book : books) {
        string lowerBookPublisher = book.publisher;
        // Convert the book publisher's name to lowercase
        transform(lowerBookPublisher.begin(), lowerBookPublisher.end(), lowerBookPublisher.begin(),
                  [](unsigned char c) { return tolower(c); });

        if (lowerBookPublisher.find(lowerPublisher) != string::npos) {
            cout << "Found: " << book.title << " by " << book.author << " (ID: " << book.id << ")" << endl;
            found = true;
        }
    }

    // If no books are found, print a message
    if (!found) {
        cout << "No books found by publisher: " << publisher << endl;
    }
}


