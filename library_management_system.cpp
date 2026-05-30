#include <iostream>
#include <fstream>

using namespace std;

class Library
{
    int bookId;
    char title[50];
    char author[50];
    char status[20];

public:

    void addBook()
    {
        ofstream writeFile("library.txt", ios::app);

        cout << endl;
        cout << "Enter Book ID : ";
        cin >> bookId;

        cout << "Enter Book Title : ";
        cin >> title;

        cout << "Enter Author Name : ";
        cin >> author;

        writeFile << bookId << " "
                  << title << " "
                  << author << " "
                  << "Available" << endl;

        writeFile.close();

        cout << endl;
        cout << "Book Added Successfully." << endl;
    }

    void displayBooks()
    {
        ifstream readFile("library.txt");

        cout << endl;
        cout << "===== BOOK RECORDS =====" << endl;

        while(readFile >> bookId >> title >> author >> status)
        {
            cout << endl;
            cout << "Book ID : " << bookId << endl;
            cout << "Title   : " << title << endl;
            cout << "Author  : " << author << endl;
            cout << "Status  : " << status << endl;

            cout << "------------------------" << endl;
        }

        readFile.close();
    }

    void searchBook()
    {
        ifstream readFile("library.txt");

        char searchTitle[50];
        bool found = false;

        cout << endl;
        cout << "Enter Book Title : ";
        cin >> searchTitle;

        while(readFile >> bookId >> title >> author >> status)
        {
            if(strcmp(title, searchTitle) == 0)
            {
                cout << endl;
                cout << "Book Found." << endl;

                cout << "Book ID : " << bookId << endl;
                cout << "Title   : " << title << endl;
                cout << "Author  : " << author << endl;
                cout << "Status  : " << status << endl;

                found = true;
            }
        }

        if(found == false)
        {
            cout << endl;
            cout << "Book Not Found." << endl;
        }

        readFile.close();
    }

    void issueBook()
    {
        ifstream readFile("library.txt");
        ofstream tempFile("temp.txt");

        char searchTitle[50];
        bool found = false;

        cout << endl;
        cout << "Enter Book Title : ";
        cin >> searchTitle;

        while(readFile >> bookId >> title >> author >> status)
        {
            if(strcmp(title, searchTitle) == 0)
            {
                strcpy(status, "Issued");
                found = true;

                cout << endl;
                cout << "Book Issued Successfully." << endl;
            }

            tempFile << bookId << " "
                     << title << " "
                     << author << " "
                     << status << endl;
        }

        readFile.close();
        tempFile.close();

        remove("library.txt");
        rename("temp.txt", "library.txt");

        if(found == false)
        {
            cout << endl;
            cout << "Book Not Found." << endl;
        }
    }

    void returnBook()
    {
        ifstream readFile("library.txt");
        ofstream tempFile("temp.txt");

        char searchTitle[50];
        bool found = false;

        cout << endl;
        cout << "Enter Book Title : ";
        cin >> searchTitle;

        while(readFile >> bookId >> title >> author >> status)
        {
            if(strcmp(title, searchTitle) == 0)
            {
                strcpy(status, "Available");
                found = true;

                cout << endl;
                cout << "Book Returned Successfully." << endl;
            }

            tempFile << bookId << " "
                     << title << " "
                     << author << " "
                     << status << endl;
        }

        readFile.close();
        tempFile.close();

        remove("library.txt");
        rename("temp.txt", "library.txt");

        if(found == false)
        {
            cout << endl;
            cout << "Book Not Found." << endl;
        }
    }
};

int main()
{
    Library l;

    int choice;

    do
    {
        cout << endl;
        cout << "==================================" << endl;
        cout << "    LIBRARY MANAGEMENT SYSTEM" << endl;
        cout << "==================================" << endl;

        cout << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display Books" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Issue Book" << endl;
        cout << "5. Return Book" << endl;
        cout << "6. Exit" << endl;

        cout << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                l.addBook();
                break;

            case 2:
                l.displayBooks();
                break;

            case 3:
                l.searchBook();
                break;

            case 4:
                l.issueBook();
                break;

            case 5:
                l.returnBook();
                break;

            case 6:
                cout << endl;
                cout << "Program Closed Successfully." << endl;
                break;

            default:
                cout << endl;
                cout << "Invalid Choice." << endl;
        }

    } while(choice != 6);

    return 0;
}