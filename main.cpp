#include "all_headers.h"

// Greet when Open
void greet()
{

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
void displayStudentMenu()
{
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
void displayLibrarianMenu()
{
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
bool authenticateStudent()
{
    vector<pair<string, string>> students = readStudentsFromCSV("DATA/G19-Student-List.csv");
    string rollNo;
    cout << "Enter your roll number: ";
    getline(cin, rollNo);

    for (const auto &student : students)
    {
        if (student.first == rollNo)
        {
            cout << "Authentication successful. Welcome, " << student.second << " (Roll No: " << rollNo << ")" << endl;
            return true;
        }
    }
    cout << "Invalid roll number. Access denied." << endl;
    return false;
}
// Function to trim whitespace from input
string trim(const string &str)
{
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return (first == string::npos || last == string::npos) ? "" : str.substr(first, last - first + 1);
}

// Mock function to simulate credential validation (replace with database or file)
bool validateCredentials(const string &username, const string &password)
{
    // Sample username-password pairs (in practice, passwords should be hashed)
    unordered_map<string, string> credentials = {
        {"admin", "admin"},
        {"librarian1", "libpass1"},
        {"librarian2", "libpass2"}};

    auto it = credentials.find(username);
    if (it != credentials.end() && it->second == password)
    {
        return true;
    }
    return false;
}

// Function for librarian authentication
bool authenticateLibrarian()
{
    string username, password;
    int attempts = 3; // Limit the number of attempts

    while (attempts > 0)
    {
        cout << "Enter Username: ";
        getline(cin, username);
        username = trim(username); // Trim any accidental spaces

        cout << "Enter Password: ";
        getline(cin, password);

        if (validateCredentials(username, password))
        {
            cout << "Authentication successful. Welcome, " << username << "!" << endl;
            return true;
        }
        else
        {
            --attempts;
            cout << "Invalid credentials. Attempts remaining: " << attempts << endl;
        }
    }

    cout << "Access denied after multiple failed attempts." << endl;
    return false;
}

// Function to ask the user whether to continue or exit
bool continuePrompt()
{
    char choice;
    cout << "Do you want to continue? (y/n): ";
    cin >> choice;
    cin.ignore(); // Clear the newline character from the input buffer
    return (choice == 'y' || choice == 'Y');
}
int main()
{
    // Load the books from CSV file
    vector<Book> books = readBooksFromCSV("DATA/BooksDatasetCleanAnuj.csv");

    greet();

    string userType;
    bool programRunning = true;

    while (programRunning)
    {
        cout << "Are you a student or librarian? (Enter 'student', 'librarian', or 'exit' to quit): ";
        getline(cin, userType);

        // Transform userType to lowercase for easier comparison
        transform(userType.begin(), userType.end(), userType.begin(), ::tolower);

        if (userType == "student")
        {
            // Authenticate the student
            if (authenticateStudent())
            {
                Student student(books); // Create a Student object

                int choice;
                do
                {
                    displayStudentMenu();
                    cin >> choice;
                    cin.ignore(); // Ignore newline character left in the buffer

                    switch (choice)
                    {
                    case 1:
                    {
                        string searchTerm, searchType;
                        cout << "Enter search term: ";
                        getline(cin, searchTerm);
                        cout << "Search by (title/author/publisher)? ";
                        getline(cin, searchType);
                        student.searchBook(searchTerm, searchType);
                        break;
                    }
                    case 2:
                    {
                        int bookID;
                        cout << "Enter the Book ID to issue: ";
                        cin >> bookID;
                        student.issueBook(bookID);
                        break;
                    }
                    case 3:
                    {
                        student.viewIssuedBooks();
                        break;
                    }
                    case 4:
                    {
                        int bookID;
                        cout << "Enter the Book ID to return: ";
                        cin >> bookID;
                        student.returnBook(bookID);
                        break;
                    }
                    case 5:
                    {
                        student.viewReturnedBooks();
                        break;
                    }
                    case 6:
                    {
                        cout << "Exiting Student Menu... Returning to main prompt." << endl;
                        break; // Exit the student menu loop, go back to user type selection
                    }
                    default:
                        cout << "Invalid option. Please try again." << endl;
                    }
                } while (choice != 6 && continuePrompt());
            }
        }
        else if (userType == "librarian")
        {
            // Authenticate the librarian
            if (authenticateLibrarian())
            {
                Librarian librarian(books); // Create a Librarian object

                int choice;
                do
                {
                    displayLibrarianMenu();
                    cin >> choice;
                    cin.ignore(); // Ignore newline character left in the buffer

                    switch (choice)
                    {
                    case 1:
                    {
                        string searchTerm, searchType;
                        cout << "Enter search term: ";
                        getline(cin, searchTerm);
                        cout << "Search by (title/author/publisher)? ";
                        getline(cin, searchType);
                        librarian.searchBook(searchTerm, searchType);
                        break;
                    }
                    case 2:
                    {
                        int bookID;
                        cout << "Enter the Book ID to search: ";
                        cin >> bookID;
                        librarian.searchBookByID(bookID);
                        break;
                    }
                    case 3:
                    {
                        Book newBook;
                        cin.ignore(); // Clear any remaining input

                        // Title validation
                        do
                        {
                            cout << "Enter Book Title: ";
                            getline(cin, newBook.title);
                            if (newBook.title.empty())
                            {
                                cout << "Title cannot be empty. Please try again.\n";
                            }
                        } while (newBook.title.empty());

                        // Author validation
                        do
                        {
                            cout << "Enter Book Author: ";
                            getline(cin, newBook.author);
                            if (newBook.author.empty())
                            {
                                cout << "Author cannot be empty. Please try again.\n";
                            }
                        } while (newBook.author.empty());

                        // Publisher validation
                        do
                        {
                            cout << "Enter Book Publisher: ";
                            getline(cin, newBook.publisher);
                            if (newBook.publisher.empty())
                            {
                                cout << "Publisher cannot be empty. Please try again.\n";
                            }
                        } while (newBook.publisher.empty());

                        // Price validation
                        do
                        {
                            cout << "Enter Book Price: ";
                            cin >> newBook.price;
                            if (cin.fail() || newBook.price <= 0)
                            {
                                cout << "Invalid price. Please enter a positive number.\n";
                                cin.clear();                                         // Clear the error flag
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore bad input
                            }
                        } while (newBook.price <= 0);

                        // Year validation
                        do
                        {
                            cout << "Enter Book Year: ";
                            cin >> newBook.year;
                            int currentYear = 2024; // Update this based on current year
                            if (cin.fail() || newBook.year < 1500 || newBook.year > currentYear)
                            {
                                cout << "Invalid year. Please enter a year between 1500 and " << currentYear << ".\n";
                                cin.clear();                                         // Clear the error flag
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore bad input
                            }
                        } while (newBook.year < 1500 || newBook.year > 2024);

                        // Availability validation
                        do
                        {
                            cout << "Is the book available (Y/N)? ";
                            cin >> newBook.availability;
                            newBook.availability = toupper(newBook.availability);
                            if (newBook.availability != 'Y' && newBook.availability != 'N')
                            {
                                cout << "Invalid input. Please enter 'Y' or 'N'.\n";
                            }
                        } while (newBook.availability != 'Y' && newBook.availability != 'N');

                        newBook.id = books.size() + 1; // Assign a new ID
                        librarian.addBook(newBook);
                        break;
                    }
                    case 4:
                    {
                        int bookID;
                        cout << "Enter the Book ID to remove: ";
                        cin >> bookID;
                        librarian.removeBook(bookID);
                        break;
                    }
                    case 5:
                    {
                        librarian.viewRecentlyReceivedBooks();
                        break;
                    }
                    case 6:
                    {
                        cout << "Exiting Librarian Menu... Returning to main prompt." << endl;
                        break; // Exit the librarian menu loop, go back to user type selection
                    }
                    default:
                        cout << "Invalid option. Please try again." << endl;
                    }
                } while (choice != 6 && continuePrompt());
            }
        }
        else if (userType == "exit")
        {
            cout << "Exiting the program... Goodbye!" << endl;
            cout << "Thank you for using the Library Management System." << endl;
            cout << "This program was developed by Anuj Kumar, Group 19A, Roll No: 2310991699." << endl;
            programRunning = false; // Exit the main loop and terminate the program
        }
        else
        {
            cout << "Invalid user type! Please choose either 'student', 'librarian', or 'exit'." << endl;
        }
    }

    return 0;
}