#include "all_headers.h"


// Greet when Open
void greet() {

    cout << "*****************************************************" << endl;
    cout << "***** Welcome to the Library Management System! *****" << endl;
    cout << "*****************************************************" << endl;

    cout << "========================================" << endl;
    cout << "  _        __  __      _____ \n";
    cout << " | |      |  \\/  |    / ____|\n";
    cout << " | |      | |\\/| |   | (___  \n";
    cout << " | |      | |  | |    \\___ \\ \n";
    cout << " | |___   | |  | |    ____) |\n";
    cout << " |_____|  |_|  |_|   |_____/ \n";
    cout << "========================================" << endl;
    cout << endl;
    cout << "== Developed by: Anuj Kumar ==\n";
    cout << endl;
}
// Function to display the menu for Student actions
void displayStudentMenu() {
    cout << "\n=== Student Menu ===" << endl;
    cout << "1. Search for a book" << endl;
    cout << "2. Issue a book" << endl;
    cout << "3. View issued books" << endl;
    cout << "4. Return a book" << endl;
    cout << "5. View returned books" << endl;
    cout << "6. Exit" << endl;
    cout << "Choose an option: ";
}

// Function to display the menu for Librarian actions
void displayLibrarianMenu() {
    cout << "\n=== Librarian Menu ===" << endl;
    cout << "1. Search for a book" << endl;
    cout << "2. Search for a book by ID" << endl;
    cout << "3. Add a new book" << endl;
    cout << "4. Remove a book" << endl; // New option for removing a book
    cout << "5. View recently received books" << endl;
    cout << "6. Exit" << endl;
    cout << "Choose an option: ";
}

// Function for student authentication
bool authenticateStudent() {
    string rollNo;
    cout << "Enter your roll number: ";
    getline(cin, rollNo);
    cout << "Authentication successful. Welcome, Student Roll No: " << rollNo << endl;
    return true; // Always authenticate successfully for demo
}

// Function for librarian authentication
bool authenticateLibrarian() {
    string username, password;
    cout << "Enter Username: ";
    getline(cin, username);
    cout << "Enter Password: ";
    getline(cin, password);

    if (username == "admin" && password == "admin") {
        cout << "Authentication successful. Welcome, Librarian!" << endl;
        return true;
    } else {
        cout << "Invalid credentials. Access denied." << endl;
        return false;
    }
}

// Function to ask the user whether to continue or exit
bool continuePrompt() {
    char choice;
    cout << "Do you want to continue? (y/n): ";
    cin >> choice;
    cin.ignore(); // Clear the newline character from the input buffer
    return (choice == 'y' || choice == 'Y');
}

int main() {
    // Load the books from CSV file
    vector<Book> books = readBooksFromCSV("BooksDatasetCleanAnuj.csv");
    greet();
    string userType;
    cout << "Are you a student or librarian? (Enter 'student' or 'librarian'): ";
    getline(cin, userType);
    
    // Transform userType to lowercase for easier comparison
    transform(userType.begin(), userType.end(), userType.begin(), ::tolower);

    if (userType == "student") {
        // Authenticate the student
        if (authenticateStudent()) {
            Student student(books);  // Create a Student object

            int choice;
            do {
                displayStudentMenu();
                cin >> choice;
                cin.ignore();  // Ignore newline character left in the buffer

                switch (choice) {
                    case 1: {
                        string searchTerm, searchType;
                        cout << "Enter search term: ";
                        getline(cin, searchTerm);
                        cout << "Search by (title/author/publisher)? ";
                        getline(cin, searchType);
                        student.searchBook(searchTerm, searchType);
                        break;
                    }
                    case 2: {
                        int bookID;
                        cout << "Enter the Book ID to issue: ";
                        cin >> bookID;
                        student.issueBook(bookID);
                        break;
                    }
                    case 3: {
                        student.viewIssuedBooks();
                        break;
                    }
                    case 4: {
                        int bookID;
                        cout << "Enter the Book ID to return: ";
                        cin >> bookID;
                        student.returnBook(bookID);
                        break;
                    }
                    case 5: {
                        student.viewReturnedBooks();
                        break;
                    }
                    case 6: {
                        cout << "Exiting... Goodbye!" << endl;
                        return 0;  // Exit the program
                    }
                    default:
                        cout << "Invalid option. Please try again." << endl;
                }
            } while (continuePrompt());
        }
    } else if (userType == "librarian") {
        // Authenticate the librarian
        if (authenticateLibrarian()) {
            Librarian librarian(books);  // Create a Librarian object

            int choice;
            do {
                displayLibrarianMenu();
                cin >> choice;
                cin.ignore();  // Ignore newline character left in the buffer

                switch (choice) {
                    case 1: {
                        string searchTerm, searchType;
                        cout << "Enter search term: ";
                        getline(cin, searchTerm);
                        cout << "Search by (title/author/publisher)? ";
                        getline(cin, searchType);
                        librarian.searchBook(searchTerm, searchType);
                        break;
                    }
                    case 2: {
                        int bookID;
                        cout << "Enter the Book ID to search: ";
                        cin >> bookID;
                        librarian.searchBookByID(bookID);
                        break;
                    }
                    case 3: {
                        Book newBook;
                        cout << "Enter Book Title: ";
                        getline(cin, newBook.title);
                        cout << "Enter Book Author: ";
                        getline(cin, newBook.author);
                        cout << "Enter Book Publisher: ";
                        getline(cin, newBook.publisher);
                        cout << "Enter Book Price: ";
                        cin >> newBook.price;
                        cout << "Enter Book Year: ";
                        cin >> newBook.year;
                        cout << "Is the book available (Y/N)? ";
                        cin >> newBook.availability;
                        newBook.id = books.size() + 1;  // Assign a new ID
                        librarian.addBook(newBook);
                        break;
                    }
                    case 4: {
                        int bookID;
                        cout << "Enter the Book ID to remove: ";
                        cin >> bookID;
                        librarian.removeBook(bookID);
                        break;
                    }
                    case 5: {
                        librarian.viewRecentlyReceivedBooks();
                        break;
                    }
                    case 6: {
                        cout << "Exiting... Goodbye!" << endl;
                        return 0;  // Exit the program
                    }
                    default:
                        cout << "Invalid option. Please try again." << endl;
                }
            } while (continuePrompt());
        }
    } else {
        cout << "Invalid user type! Please restart and choose either 'student' or 'librarian'." << endl;
    }

    return 0;
}