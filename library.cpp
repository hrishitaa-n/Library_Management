
#include <iostream>
using namespace std;

struct Book
{
    int bookid;
    string bookname;
    string author;
    string publisher;
    float price;
    string typeofbook;
    Book *next;
};

Book *head = NULL;

void AddBooks()
{
    Book *newbook = new Book();

    cout << "Enter Book ID: ";
    cin >> newbook->bookid;

    cout << "Enter Book Name: ";
    cin >> newbook->bookname;

    cout << "Enter Author: ";
    cin >> newbook->author;

    cout << "Enter Publisher: ";
    cin >> newbook->publisher;

    cout << "Enter Price: ";
    cin >> newbook->price;

    cout << "Enter Type Of Book: ";
    cin >> newbook->typeofbook;

    newbook->next = NULL;

    if (head == NULL)
    {
        head = newbook;
    }
    else
    {
        Book *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newbook;
    }
}

void DisplayAllBooks()
{
    if (head == NULL)
    {
        cout << "Library is Empty\n";
        return;
    }

    Book *temp = head;

    cout << "\nBookID\tBookName\tAuthor\tPublisher\tPrice\tType\n";

    while (temp != NULL)
    {
        cout << temp->bookid << "\t"
             << temp->bookname << "\t\t"
             << temp->author << "\t"
             << temp->publisher << "\t"
             << temp->price << "\t"
             << temp->typeofbook << endl;

        temp = temp->next;
    }
}

void DisplayBooksByType()
{
    string type;

    cout << "Enter Type: ";
    cin >> type;

    Book *temp = head;

    cout << "\nBookID\tBookName\tAuthor\tPublisher\tPrice\tType\n";

    while (temp != NULL)
    {
        if (temp->typeofbook == type)
        {
            cout << temp->bookid << "\t"
                 << temp->bookname << "\t\t"
                 << temp->author << "\t"
                 << temp->publisher << "\t"
                 << temp->price << "\t"
                 << temp->typeofbook << endl;
        }

        temp = temp->next;
    }
}

void BookIssue()
{
    string name;

    cout << "Enter Book Name To Issue: ";
    cin >> name;

    if (head == NULL)
    {
        cout << "Library is Empty\n";
        return;
    }

    if (head->bookname == name)
    {
        Book *temp = head;
        head = head->next;
        delete temp;

        cout << "Book Issued\n";
    }
    else
    {
        Book *temp = head;
        Book *previous = NULL;

        while (temp != NULL && temp->bookname != name)
        {
            previous = temp;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Book Not Found\n";
            return;
        }

        previous->next = temp->next;
        delete temp;

        cout << "Book Issued Successfully\n";
    }
}

void AddNewBook()
{
    int position;

    cout << "Enter Position: ";
    cin >> position;

    Book *newbook = new Book();

    cout << "Enter Book ID: ";
    cin >> newbook->bookid;

    cout << "Enter Book Name: ";
    cin >> newbook->bookname;

    cout << "Enter Author: ";
    cin >> newbook->author;

    cout << "Enter Publisher: ";
    cin >> newbook->publisher;

    cout << "Enter Price: ";
    cin >> newbook->price;

    cout << "Enter Type Of Book: ";
    cin >> newbook->typeofbook;

    newbook->next = NULL;

    if (position == 1)
    {
        newbook->next = head;
        head = newbook;
    }
    else
    {
        Book *temp = head;
        int count = 1;

        while (count < position - 1)
        {
            temp = temp->next;
            count++;
        }

        newbook->next = temp->next;
        temp->next = newbook;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n Library Management Using Linked List ";
        cout << "\n1. Add Books";
        cout << "\n2. Display All Books";
        cout << "\n3. Display Books By Type";
        cout << "\n4. Book Issue";
        cout << "\n5. Add New Book At Position";
        cout << "\n6. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            AddBooks();
            break;

        case 2:
            DisplayAllBooks();
            break;

        case 3:
            DisplayBooksByType();
            break;

        case 4:
            BookIssue();
            break;

        case 5:
            AddNewBook();
            break;

        case 6:
            cout << "Thank You\n";
            break;

        default:
            cout << "Invalid Choice";
        }

    } while (choice != 6);

    return 0;
}
