#include <bits/stdc++.h>
#include "due_date.cpp"
#include "difference.cpp"

using namespace std;

class Book_database
{
public:
    void Display();
};

void Book_database::Display()
{
    fstream file;
    file.open("book.txt", ios_base::app | ios_base::in);
    string word1, word2, word3, word4, word5, word6, word7;
    cout << "book_name"
         << "\t\t\t"
         << "author"
         << "\t\t\t"
         << "publication" << endl;
    while (file >> word1 && file >> word2 && file >> word3 && file >> word4 && file >> word5 && file >> word6 && file >> word7)
    {
        cout << word1 << "\t\t\t" << word2 << "\t\t\t" << word3 << endl;
    }
}

class Book
{
public:
    string book_name;
    string author;
    string publication;
    string name;
    string choice;

    void book_request(string book_name, string author, string publiction, string date, string name, string choice);
    void show_due_date(string book_name, string author, string publication, string name, string choice);
};

void Book::show_due_date(string book_name, string author, string publication, string name, string choice)
{
    fstream file;
    file.open("book.txt", ios_base::app | ios_base::in);
    string word1, word2, word3, word4, word5, word6, word7;
    while (file >> word1 && file >> word2 && file >> word3 && file >> word4 && file >> word5 && file >> word6 && file >> word7)
    {
        if (word1 == book_name && word2 == author && word3 == publication)
        {
            if (word4 == name && word5 == choice)
            {
                cout << "Due Date :" << word7 << endl;
            }
            else
            {
                cout << "error" << endl;
            }
        }
        else
        {
            cout << "book does not exist" << endl;
        }
    }
}

void Book::book_request(string book_name, string author, string publiction, string date, string name, string choice)
{
    int c;
    bool flag1 = true;
    fstream utfile;
    string filename = "user.txt";
    utfile.open(filename.c_str());
    fstream f1;
    f1.open("temp1.txt", ios_base::app | ios_base::in);
    string word11, word21, word31, word41;
    while (utfile >> word11 && utfile >> word21 && utfile >> word31 && utfile >> word41)
    {
        if (word11 == name)
        {
            c = stoi(word41);
            if (c >= 5)
            {
                flag1 = false;
                f1 << word11 << "\t\t\t\t\t" << word21 << "\t\t\t\t\t" << word31 << "\t\t\t\t\t"
                   << word41 << endl;
            }
            else
            {

                c++;
                string a = to_string(c);
                f1 << word11 << "\t\t\t\t\t" << word21 << "\t\t\t\t\t" << word31 << "\t\t\t\t\t"
                   << a << endl;
            }
        }
        else
        {
            f1 << word11 << "\t\t\t\t\t" << word21 << "\t\t\t\t\t" << word31 << "\t\t\t\t\t"
               << word41 << endl;
        }
    }
    utfile.close();
    ofstream tfile;
    tfile.open("user.txt", ios::out);
    fstream f3;
    f3.open("temp1.txt", ios_base::app | ios_base::in);
    while (f3 >> word11 && f3 >> word21 && f3 >> word31 && f3 >> word41)
    {
        tfile << word11 << "\t\t\t\t\t" << word21 << "\t\t\t\t\t" << word31 << "\t\t\t\t\t"
              << word41 << endl;
    }
    tfile.close();
    f3.close();
    remove("temp1.txt");

    if (flag1 == false && choice == "Student")
    {
        cout << "You can not request more than 5 book" << endl;
    }
    else
    {
        fstream outfile;
        outfile.open("book.txt", ios_base::app | ios_base::in);
        fstream file;
        file.open("temp.txt", ios_base::app | ios_base::in);
        string word1, word2, word3, word4, word5, word6, word7;
        bool flag = true;
        string dd = date.substr(0, 2);
        int d = stoi(dd);
        dd = date.substr(3, 5);
        int m = stoi(dd);
        dd = date.substr(6, 10);
        int y = stoi(dd);
        string date2;
        if (choice == "Student")
        {
            date2 = addDays(d, m, y, 30);
        }
        else if (choice == "Professor")
        {
            date2 = addDays(d, m, y, 60);
        }
        while (outfile >> word1 && outfile >> word2 && outfile >> word3 && outfile >> word4 && outfile >> word5 && outfile >> word6 && outfile >> word7)
        {
            if (word1 == book_name && word2 == author && word3 == publication)
            {
                flag = false;
                if (word4 == "empty")
                {
                    file << word1 << "\t\t\t\t\t" << word2 << "\t\t\t\t\t" << word3 << "\t\t\t\t\t"
                         << name
                         << "\t\t\t\t\t"
                         << choice
                         << "\t\t\t\t\t"
                         << date
                         << "\t\t\t\t\t"
                         << date2 << endl;
                    cout << "Book request accepted";
                }
                else
                {
                    file << word1 << "\t\t\t\t\t" << word2 << "\t\t\t\t\t" << word3 << "\t\t\t\t\t"
                         << word4
                         << "\t\t\t\t\t"
                         << word5
                         << "\t\t\t\t\t"
                         << word6
                         << "\t\t\t\t\t"
                         << word7 << endl;
                    cout << "Already Booked";
                }
            }
            else
            {
                file << word1 << "\t\t\t\t\t" << word2 << "\t\t\t\t\t" << word3 << "\t\t\t\t\t"
                     << word4
                     << "\t\t\t\t\t"
                     << word5
                     << "\t\t\t\t\t"
                     << word6
                     << "\t\t\t\t\t"
                     << word7 << endl;
            }
        }
        if (flag)
        {
            cout << "book does not exist" << endl;
        }
        outfile.close();
        ofstream otfile;
        otfile.open("book.txt", ios::out);
        fstream f;
        f.open("temp.txt", ios_base::app | ios_base::in);
        while (f >> word1 && f >> word2 && f >> word3 && f >> word4 && f >> word5 && f >> word6 && f >> word7)
        {
            otfile << word1 << "\t\t\t\t\t" << word2 << "\t\t\t\t\t" << word3 << "\t\t\t\t\t"
                   << word4
                   << "\t\t\t\t\t"
                   << word5
                   << "\t\t\t\t\t"
                   << word6
                   << "\t\t\t\t\t"
                   << word7 << endl;
        }
        otfile.close();
        f.close();
        remove("temp.txt");
    }
}

class User
{
public:
    string choice;
    string name;
    string password;
};

class Student : public User
{
public:
    int count;

    void display_user(string name);
    int calculate_fine(string name, string choice, string date);
    void clear_fine_amount(string name, string choice, string date);
};

int Student::calculate_fine(string name, string choice, string date)
{
    fstream file;
    file.open("book.txt", ios_base::app | ios_base::in);
    string word1, word2, word3, word4, word5, word6, word7;
    int n;
    int s = 0;
    while (file >> word1 && file >> word2 && file >> word3 && file >> word4 && file >> word5 && file >> word6 && file >> word7)
    {
        if (word4 == name && word5 == choice)
        {
            string dd = date.substr(0, 2);
            int d = stoi(dd);
            dd = date.substr(3, 5);
            int m = stoi(dd);
            dd = date.substr(6, 10);
            int y = stoi(dd);

            dd = word7.substr(0, 2);
            int d2 = stoi(dd);
            dd = word7.substr(3, 5);
            int m2 = stoi(dd);
            dd = word7.substr(6, 10);
            int y2 = stoi(dd);

            n = getDifference(d2, m2, y2, d, m, y);
            if (n > 0)
            {
                s = s + n * 2;
            }
        }
    }

    return s;
}

void Student::clear_fine_amount(string name, string choice, string date)
{
    fstream outfile;
    outfile.open("book.txt", ios_base::app | ios_base::in);
    fstream file;
    file.open("temp.txt", ios_base::app | ios_base::in);
    string word1, word2, word3, word4, word5, word6, word7;
    while (outfile >> word1 && outfile >> word2 && outfile >> word3 && outfile >> word4 && outfile >> word5 && outfile >> word6 && outfile >> word7)
    {
        if (word4 == name && word5 == choice)
        {
            file << word1 << "\t\t\t\t\t" << word2 << "\t\t\t\t\t" << word3 << "\t\t\t\t\t"
                 << word4
                 << "\t\t\t\t\t"
                 << word5
                 << "\t\t\t\t\t"
                 << word6
                 << "\t\t\t\t\t"
                 << date << endl;
        }
        else
        {
            file << word1 << "\t\t\t\t\t" << word2 << "\t\t\t\t\t" << word3 << "\t\t\t\t\t"
                 << word4
                 << "\t\t\t\t\t"
                 << word5
                 << "\t\t\t\t\t"
                 << word6
                 << "\t\t\t\t\t"
                 << word7 << endl;
        }
    }
    outfile.close();
    ofstream otfile;
    otfile.open("book.txt", ios::out);
    fstream f;
    f.open("temp.txt", ios_base::app | ios_base::in);
    while (f >> word1 && f >> word2 && f >> word3 && f >> word4 && f >> word5 && f >> word6 && f >> word7)
    {
        otfile << word1 << "\t\t\t\t\t" << word2 << "\t\t\t\t\t" << word3 << "\t\t\t\t\t"
               << word4
               << "\t\t\t\t\t"
               << word5
               << "\t\t\t\t\t"
               << word6
               << "\t\t\t\t\t"
               << word7 << endl;
    }
    otfile.close();
    f.close();
    remove("temp.txt");
}

void Student::display_user(string name)
{
    fstream file;
    file.open("book.txt", ios_base::app | ios_base::in);
    string word1, word2, word3, word4, word5, word6, word7;
    cout << "book_name"
         << "\t\t\t"
         << "author"
         << "\t\t\t"
         << "publication"
         << "issue_date"
         << "\t\t\t"
         << "due_date" << endl;
    while (file >> word1 && file >> word2 && file >> word3 && file >> word4 && file >> word5 && file >> word6 && file >> word7)
    {
        if (word4 == name)
        {
            cout << word1 << "\t\t\t" << word2 << "\t\t\t" << word3 << "\t\t\t" << word6 << "\t\t\t" << word7 << endl;
        }
    }
}

class Professor : public User
{
public:
    int fine;

    void display_prof(string name);
    int calculate_fine(string name, string choice, string date);
    void clear_fine_amount(string name, string choice, string date);
};

void Professor::display_prof(string name)
{
    fstream file;
    file.open("book.txt", ios_base::app | ios_base::in);
    string word1, word2, word3, word4, word5, word6, word7;
    cout << "book_name"
         << "\t\t\t"
         << "author"
         << "\t\t\t"
         << "publication"
         << "issue_date"
         << "\t\t\t"
         << "due_date" << endl;
    while (file >> word1 && file >> word2 && file >> word3 && file >> word4 && file >> word5 && file >> word6 && file >> word7)
    {
        if (word4 == name)
        {
            cout << word1 << "\t\t\t" << word2 << "\t\t\t" << word3 << "\t\t\t" << word4 << "\t\t\t" << word5 << "\t\t\t" << word6 << "\t\t\t" << word7 << endl;
        }
    }
}

int Professor::calculate_fine(string name, string choice, string date)
{
    fstream file;
    file.open("book.txt", ios_base::app | ios_base::in);
    string word1, word2, word3, word4, word5, word6, word7;
    int n;
    int s = 0;
    while (file >> word1 && file >> word2 && file >> word3 && file >> word4 && file >> word5 && file >> word6 && file >> word7)
    {
        if (word4 == name && word5 == choice)
        {
            string dd = date.substr(0, 2);
            int d = stoi(dd);
            dd = date.substr(3, 5);
            int m = stoi(dd);
            dd = date.substr(6, 10);
            int y = stoi(dd);

            dd = word7.substr(0, 2);
            int d2 = stoi(dd);
            dd = word7.substr(3, 5);
            int m2 = stoi(dd);
            dd = word7.substr(6, 10);
            int y2 = stoi(dd);

            n = getDifference(d2, m2, y2, d, m, y);
            if (n > 0)
            {
                s = s + n * 5;
            }
        }
    }

    return s;
}

void Professor::clear_fine_amount(string name, string choice, string date)
{
    fstream outfile;
    outfile.open("book.txt", ios_base::app | ios_base::in);
    fstream file;
    file.open("temp.txt", ios_base::app | ios_base::in);
    string word1, word2, word3, word4, word5, word6, word7;
    while (outfile >> word1 && outfile >> word2 && outfile >> word3 && outfile >> word4 && outfile >> word5 && outfile >> word6 && outfile >> word7)
    {
        if (word4 == name && word5 == choice)
        {
            file << word1 << "\t\t\t\t\t" << word2 << "\t\t\t\t\t" << word3 << "\t\t\t\t\t"
                 << word4
                 << "\t\t\t\t\t"
                 << word5
                 << "\t\t\t\t\t"
                 << word6
                 << "\t\t\t\t\t"
                 << date << endl;
        }
        else
        {
            file << word1 << "\t\t\t\t\t" << word2 << "\t\t\t\t\t" << word3 << "\t\t\t\t\t"
                 << word4
                 << "\t\t\t\t\t"
                 << word5
                 << "\t\t\t\t\t"
                 << word6
                 << "\t\t\t\t\t"
                 << word7 << endl;
        }
    }
    outfile.close();
    ofstream otfile;
    otfile.open("book.txt", ios::out);
    fstream f;
    f.open("temp.txt", ios_base::app | ios_base::in);
    while (f >> word1 && f >> word2 && f >> word3 && f >> word4 && f >> word5 && f >> word6 && f >> word7)
    {
        otfile << word1 << "\t\t\t\t\t" << word2 << "\t\t\t\t\t" << word3 << "\t\t\t\t\t"
               << word4
               << "\t\t\t\t\t"
               << word5
               << "\t\t\t\t\t"
               << word6
               << "\t\t\t\t\t"
               << word7 << endl;
    }
    otfile.close();
    f.close();
    remove("temp.txt");
}

class Librarian : public User
{
public:
    void Add(string book_name, string author, string publication);
    void Delete(string book_name, string author, string publication);
    void Add_user(string name, string password, string choice);
    void Delete_user(string name);
};

void Librarian::Add(string book_name, string author, string publication)
{
    ofstream outfile;
    outfile.open("book.txt", ios_base::app | ios_base::in);

    outfile << book_name << "\t\t\t\t\t" << author << "\t\t\t\t\t" << publication << "\t\t\t\t\t"
            << "empty"
            << "\t\t\t\t\t"
            << "empty"
            << "\t\t\t\t\t"
            << "issue_date"
            << "\t\t\t\t\t"
            << "due_date"
            << endl;
}

void Librarian::Add_user(string name, string password, string choice)
{
    ofstream outfile;
    outfile.open("user.txt", ios_base::app | ios_base::in);

    outfile << name << "\t\t\t\t\t" << password << "\t\t\t\t\t" << choice << endl;
}

void Librarian::Delete_user(string name)
{
    fstream outfile;
    outfile.open("user.txt", ios_base::app | ios_base::in);
    fstream file;
    file.open("temp.txt", ios_base::app | ios_base::in);
    string word1, word2, word3, word4;
    while (outfile >> word1 && outfile >> word2 && outfile >> word3 && outfile >> word4)
    {
        if (word1 == name)
        {
        }
        else
        {
            file << word1 << "\t\t\t\t\t" << word2 << "\t\t\t\t\t" << word3 << "\t\t\t\t\t" << word4 << endl;
        }
    }
    outfile.close();
    file.close();
    ofstream otfile;
    otfile.open("user.txt", ios::out);
    fstream f;
    f.open("temp.txt", ios_base::app | ios_base::in);
    while (f >> word1 && f >> word2 && f >> word3 && f >> word4)
    {
        otfile << word1 << "\t\t\t\t\t" << word2 << "\t\t\t\t\t" << word3 << "\t\t\t\t\t" << word4 << endl;
    }
    otfile.close();
    f.close();
    remove("temp.txt");
}

void Librarian::Delete(string book_name, string author, string publication)
{
    fstream outfile;
    outfile.open("book.txt", ios_base::app | ios_base::in);
    fstream file;
    file.open("temp.txt", ios_base::app | ios_base::in);
    string word1, word2, word3, word4, word5, word6, word7;
    while (outfile >> word1 && outfile >> word2 && outfile >> word3 && outfile >> word4 && outfile >> word5 && outfile >> word6 && outfile >> word7)
    {
        if (word1 == book_name && word2 == author && word3 == publication)
        {
        }
        else
        {
            file << word1 << "\t\t\t\t\t" << word2 << "\t\t\t\t\t" << word3 << "\t\t\t\t\t"
                 << word4
                 << "\t\t\t\t\t"
                 << word5
                 << "\t\t\t\t\t"
                 << word6
                 << "\t\t\t\t\t"
                 << word7 << endl;
        }
    }
    outfile.close();
    ofstream otfile;
    otfile.open("book.txt", ios::out);
    fstream f;
    f.open("temp.txt", ios_base::app | ios_base::in);
    while (f >> word1 && f >> word2 && f >> word3 && f >> word4 && f >> word5 && f >> word6 && f >> word7)
    {
        otfile << word1 << "\t\t\t\t\t" << word2 << "\t\t\t\t\t" << word3 << "\t\t\t\t\t"
               << word4
               << "\t\t\t\t\t"
               << word5
               << "\t\t\t\t\t"
               << word6
               << "\t\t\t\t\t"
               << word7 << endl;
    }
    otfile.close();
    f.close();
    remove("temp.txt");
}

string login(string name, string password)
{
    fstream outfile;
    string l = " ";
    string filename = "user.txt";
    outfile.open(filename.c_str());
    string word1, word2, word3, word4;
    while (outfile >> word1 && outfile >> word2 && outfile >> word3 && outfile >> word4)
    {
        if (word1 == name && word2 == password)
        {
            return word3;
        }
    }
    return l;
}

int welcome()
{
    cout << "#############################LIBRARY MANAGEMENT SYSTEM#############################" << endl;
    cout << "                             1. LOGIN                                             " << endl;
    cout << "                             2. REGISTRATION                                      " << endl;

    cout << endl
         << "Type 1 for LOGIN and Type 2 for Regestration" << endl;
    int n;
    cin >> n;
    return n;
}

int choice()
{
    cout << "#############################LIBRARY MANAGEMENT SYSTEM#############################" << endl;
    cout << "############################# Registered As a#############################" << endl;
    cout << "                             1. Student                                         " << endl;
    cout << "                             2. Professor                                     " << endl;

    cout << endl
         << "Type 1 for Student and Type 2 for Professor and Type3 for Librarian" << endl;
    int n;
    cin >> n;
    return n;
}

int main()
{
    ofstream outfile;
    outfile.open("user.txt", ios_base::app | ios_base::in);
    ofstream file;
    file.open("book.txt", ios_base::app | ios_base::in);

    int n = welcome();
    switch (n)
    {
    case 1:
    {
        User u;
        cout << "#############################LIBRARY MANAGEMENT SYSTEM#############################" << endl;
        cout << "     #############################Login#############################" << endl;
        cout << endl
             << "Enter Email" << endl;
        cin >> u.name;
        cout << endl
             << "Enter Password" << endl;
        cin >> u.password;
        string a = login(u.name, u.password);
        if (a != " ")
        {
            if (a == "Student")
            {
                cout << "#############################LIBRARY MANAGEMENT SYSTEM#############################" << endl;
                cout << "     ############################# Student #############################" << endl;
                cout << "                                     1. Display                                       " << endl;
                cout << "                                     2. Display issue books                                    " << endl;
                cout << "                                     3. Total Fine                                  " << endl;
                cout << "                                     4. Clear Fine                                  " << endl;
                cout << "                                     5. Request Book                                  " << endl;
                cout << "                                     6. Show due date                                  " << endl;
                int m;
                cin >> m;
                switch (m)
                {
                case 1:
                {
                    Book_database bok;
                    bok.Display();
                    break;
                }
                case 2:
                {
                    Student s;
                    s.display_user(u.name);
                    break;
                }
                case 3:
                {
                    Student s;
                    string date;
                    cout << "Date of today in dd/mm/yyyy" << endl;
                    cin >> date;
                    int a = s.calculate_fine(u.name, "Student", date);
                    cout << "Fine :" << a << endl;
                    break;
                }
                case 4:
                {
                    Student s;
                    string date;
                    cout << "Date of today in dd/mm/yyyy" << endl;
                    cin >> date;
                    int a = s.calculate_fine(u.name, "Student", date);

                    if (a != 0)
                    {
                        s.clear_fine_amount(u.name, "Student", date);
                        cout << "all fine amount got cleared" << endl;
                    }
                    else
                    {
                        cout << "No fine";
                    }

                    break;
                }
                case 5:
                {
                    Book b;
                    cout << "Book Name" << endl;
                    cin >> b.book_name;
                    cout << "Author" << endl;
                    cin >> b.author;
                    cout << "Publication" << endl;
                    cin >> b.publication;
                    string date;
                    cout << "Today Date in dd/mm/yyyy" << endl;
                    cin >> date;

                    b.book_request(b.book_name, b.author, b.publication, date, u.name, "Student");
                    break;
                }
                case 6:
                {
                    Book b;
                    cout << "Book Name" << endl;
                    cin >> b.book_name;
                    cout << "Author" << endl;
                    cin >> b.author;
                    cout << "Publication" << endl;
                    cin >> b.publication;
                    b.show_due_date(b.book_name, b.author, b.publication, u.name, "Student");
                    break;
                }
                default:
                    break;
                }
            }
            else if (a == "Professor")
            {
                cout << "#############################LIBRARY MANAGEMENT SYSTEM#############################" << endl;
                cout << "     #############################  Professor #############################" << endl;
                cout << "                                   1. Display                                       " << endl;
                cout << "                                   2. Display issue books                                    " << endl;
                cout << "                                   3. Total Fine                                  " << endl;
                cout << "                                   4. Clear Fine                                  " << endl;
                cout << "                                   5. Request Book                                  " << endl;
                cout << "                                   6. Show due date                                  " << endl;
                int m;
                cin >> m;
                switch (m)
                {
                case 1:
                {
                    Book_database bok;
                    bok.Display();
                    break;
                }
                case 2:
                {
                    Professor s;
                    s.display_prof(u.name);
                    break;
                }
                case 3:
                {
                    Professor s;
                    string date;
                    cout << "Date of today in dd/mm/yyyy" << endl;
                    cin >> date;
                    int a = s.calculate_fine(u.name, "Professor", date);
                    cout << "Fine :" << a << endl;
                    break;
                }
                case 4:
                {
                    Professor s;
                    string date;
                    cout << "Date of today in dd/mm/yyyy" << endl;
                    cin >> date;
                    int a = s.calculate_fine(u.name, "Professor", date);

                    if (a != 0)
                    {
                        s.clear_fine_amount(u.name, "Professor", date);
                        cout << "all fine amount got cleared" << endl;
                    }
                    else
                    {
                        cout << "No fine";
                    }

                    break;
                }
                case 5:
                {
                    Book b;
                    cout << "Book Name" << endl;
                    cin >> b.book_name;
                    cout << "Author" << endl;
                    cin >> b.author;
                    cout << "Publication" << endl;
                    cin >> b.publication;
                    string date;
                    cout << "Today Date in dd/mm/yyyy" << endl;
                    cin >> date;

                    b.book_request(b.book_name, b.author, b.publication, date, u.name, "Professor");
                    break;
                }
                case 6:
                {
                    Book b;
                    cout << "Book Name" << endl;
                    cin >> b.book_name;
                    cout << "Author" << endl;
                    cin >> b.author;
                    cout << "Publication" << endl;
                    cin >> b.publication;
                    b.show_due_date(b.book_name, b.author, b.publication, u.name, "Professor");
                    break;
                }
                default:
                    break;
                }
            }
            else if (a == "Librarian")
            {
                Librarian lib;
                lib.name = u.name;
                cout << "#############################LIBRARY MANAGEMENT SYSTEM#############################" << endl;
                cout << "     #############################Librarian#############################" << endl;
                cout << "                                     1. Add book                                       " << endl;
                cout << "                                     2. Delete Book                                     " << endl;
                cout << "                                     3. Add User                                   " << endl;
                cout << "                                     4. Delete User                                   " << endl;
                int m;
                cin >> m;
                switch (m)
                {
                case 1:
                {
                    Book b;
                    cout << "Book Name" << endl;
                    cin >> b.book_name;
                    cout << "Author" << endl;
                    cin >> b.author;
                    cout << "Publication" << endl;
                    cin >> b.publication;

                    lib.Add(b.book_name, b.author, b.publication);

                    break;
                }
                case 2:
                {
                    Book b;
                    cout << "Book Name" << endl;
                    cin >> b.book_name;
                    cout << "Author" << endl;
                    cin >> b.author;
                    cout << "Publication" << endl;
                    cin >> b.publication;

                    lib.Delete(b.book_name, b.author, b.publication);

                    break;
                }
                case 3:
                {
                    User c;
                    cout << "User Email" << endl;
                    cin >> c.name;
                    cout << "User password" << endl;
                    cin >> c.password;
                    cout << "Registered as" << endl;
                    cin >> c.choice;

                    lib.Add_user(c.name, c.password, c.choice);
                    break;
                }
                case 4:
                {
                    User c;
                    cout << "User Email" << endl;
                    cin >> c.name;

                    lib.Delete_user(c.name);
                    break;
                }
                default:
                    cout << "error";
                    break;
                }
            }
            else
            {
                cout << "error";
            }
        }
        else
        {
            system("clear");
            cout << "Credentials are Wrong";
        }
        break;
    }
    case 2:
    {
        int l = choice();
        User u;
        if (l == 1)
        {
            u.choice = "Student";
        }
        else if (l == 2)
        {
            u.choice = "Professor";
        }
        else
        {
            cout << "error";
        }
        cout << "#############################LIBRARY MANAGEMENT SYSTEM#############################" << endl;
        cout << "     #############################Registration#############################" << endl;
        cout << endl
             << "Enter Email" << endl;

        cin >> u.name;
        cout << endl
             << "Enter Password" << endl;
        cin >> u.password;
        fstream outfile;
        string filename = "user.txt";
        outfile.open(filename.c_str());
        string word1, word2, word3, word4;
        while (outfile >> word1 && outfile >> word2 && outfile >> word3 && outfile >> word4)
        {
            if (word1 == u.name)
            {
                cout << "Email already exist";
            }
        }

        outfile << u.name << "\t\t\t\t\t\t" << u.password << "\t\t\t\t\t" << u.choice << "\t\t\t\t\t"
                << "0" << endl;
        break;
    }
    default:
        cout << "wrong number";
    }

    return 0;
}
