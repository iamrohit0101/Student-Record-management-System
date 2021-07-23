#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

// hello friends this is my first project using cpp language...
// aim of this project is to management of students data by using file handling...
// i ama rohit...
using namespace std;

class Student
{
private:
    char student_name[30];
    char roll_no[15];
    int age;
    char college_name[60];
    char course_name[20];
    char branch_name[30];
    char contact_no[15];
    char address[50];

public:
    Student()
    {
        age = 0;
        strcpy(student_name, "no name");
        strcpy(roll_no, "0");
        strcpy(student_name, "0");
        strcpy(college_name, "0");
        strcpy(course_name, "0");
        strcpy(branch_name, "0");
        strcpy(address, "0");
    }

    void get_record()
    {
        cout << "Enter the Name of Student       --> ";
        // cin.ignore();
        cin.getline(student_name, 29);
        cout << "\nEnter the Roll.no. of Student   --> ";
        // cin.ignore();
        cin.getline(roll_no, 15);
        cout << "\nEnter the Age of Student:       --> ";
        cin >> age;
        cout << "\nEnter the College of Student    --> ";
        cin.ignore();
        cin.getline(college_name, 59);
        cout << "\nEnter the Course of Student     --> ";
        // cin.ignore();
        cin.getline(course_name, 19);
        cout << "\nEnter the Brach of Student      --> ";
        // cin.ignore();
        cin.getline(branch_name, 29);
        cout << "\nEnter the Contact no.of Student --> ";
        // cin.ignore();
        cin.getline(contact_no, 14);
        cout << "\nEnter the Address of Student    --> ";
        cin.getline(address, 49);
    }

    void show_record()
    {
        cout << "\n\nName of Student is      --> " << student_name;
        cout << "\n\nRoll. no. of Student is --> " << roll_no;
        cout << "\n\nAge of Student is       --> " << age;
        cout << "\n\nCollege of Student is   --> " << college_name;
        cout << "\n\nCourse of Student is    --> " << course_name;
        cout << "\n\nBranch of Student is    --> " << branch_name;
        cout << "\n\nContact of Student is   --> " << contact_no;
        cout << "\n\nAddress of Student is   --> " << address;
    }

    int store_record();
    void viewall_record();
    void search_record(char *);
    void delete_record(char *);
    void update_record(char *);
};

void Student::update_record(char *n)
{
    fstream file;
    file.open("rohit.txt", ios::binary | ios::in | ios::out | ios::ate);

    if (!file)
    {
        cout << "\nFile not found...\n";
    }
    else
    {
        file.seekg(0);
        file.read((char *)this, sizeof(*this));
        while (!file.eof())
        {
            if (!strcmp(n, student_name))
            {
                file.seekp(file.tellg()-sizeof(*this));
                cout << "\n--->>>   Complete the below information\n\n";
                get_record();
                file.write((char *)this, sizeof(*this));
            }
            else
            {
                file.read((char *)this, sizeof(*this));
            }
        }
        file.close();
    }
}

void Student::delete_record(char *n)
{
    ifstream rin;
    ofstream rout;
    rin.open("rohit.txt", ios::binary | ios::in);

    if (!rin)
    {
        cout << "\nFile not found...\n";
    }
    else
    {
        rin.read((char *)this, sizeof(*this));

        rout.open("patil.txt", ios::binary | ios::out);
        getch();
        while (!rin.eof())
        {
            if (strcmp(n, student_name))
            {
                rout.write((char *)this, sizeof(*this));
            }
            rin.read((char *)this, sizeof(*this));
        }
        rin.close(); // it is mandotary to close all the file which you want to rename or delete the files
        rout.close();

        remove("rohit.txt");
        rename("patil.txt", "rohit.txt");
    }
}

void Student::search_record(char *n)
{
    ifstream rin;
    rin.open("rohit.txt", ios::in | ios::binary);
    int counter=0;

    if (!rin)
    {
        cout << "\nfile not found...\n";
    }
    else
    {
        rin.read((char *)this, sizeof(*this));

        while (!rin.eof())
        {
            if (!strcmp(n, student_name))
            {
                cout << "\n__________________________________________\n\n";
                cout << "\n---> Record of Student is >>>";
                show_record();
                counter+=1;
            }
            rin.read((char *)this, sizeof(*this));
        }    
        rin.close();
        if(counter==0)
        {
            cout << "\n-->> Record Not Found...\t Try Firse... :)\n";
        }
    }
}

void Student::viewall_record()
{
    ifstream rin;
    rin.open("rohit.txt", ios::in | ios::binary);

    if (!rin)
    {
        cout << "\nfile not found..\n";
    }
    else
    {
        int i = 1;
        rin.read((char *)this, sizeof(*this));
        cout << "\n\t|<----Record of all Students---->|\n\n";
        while (!rin.eof())
        {

            cout << "\n-->> Record of Student : "
                 << "[" << i << "]";
            show_record();
            cout << "\n__________________________________________\n\n";
            rin.read((char *)this, sizeof(*this));
            i += 1;
        }
    }
    rin.close();
}

int Student::store_record()
{
    if (age == 0 || roll_no == 0)
    {
        cout << "Record is not valid to store\nplease Try Fir Se :)\n";

        return 0;
    }
    else
    {
        ofstream rout;

        rout.open("rohit.txt", ios::app | ios::binary);

        if (!rout)
        {
            cout << "\nFile not found...\n";
        }
        else
        {
            rout.write((char *)this, sizeof(*this));
        }
        rout.close();
        cout << "\n--->>>>\tRecord inserted successfully.\n";
        //cout << "\nPress any key to Contenue...";
        return 1;
    }
}
int menu()
{
    cout << "\n\n\t|I_am|--->>> Welcome to Student Record Management System <<<---|0101|\n";
    cout << "\n\n1. Insert New Student Record.\n";
    cout << "\n2. View all Student Records.\n";
    cout << "\n3. Search Student Record.\n";
    cout << "\n4. Update Student Record.\n";
    cout << "\n5. Delete Student Record.\n";
    cout << "\n6. Exit the program.\n";
    char ch;
    cout << "\nSelect your choice : ";
    cin >> ch;
    // cin.ignore();
    return(ch);
}
int main()
{
    Student s;
    char name[30];
    while(1)
    {
        system("cls");
        switch (menu())
        {
        case '1':
            cout << "\n--->>>   Complete the below information\n\n";
            cin.ignore();
            s.get_record();
            s.store_record();
            break;
        case '2':
            s.viewall_record();
            break;
        case '3':
            cout << "\nEnter the Name of Student --> ";
            cin.ignore();
            cin.getline(name,29);
            s.search_record(name);
            break;
        case '4':
            cout << "\nEnter the Name of Student to Update --> ";
            cin.ignore();
            cin.getline(name,29);
            s.update_record(name);
            break;
        case '5':
            cout << "\nEnter the Name of Student --> ";
            cin.ignore();
            cin.getline(name,29);
            s.delete_record(name);
            break;
        case '6':
            cout << "\n\t\t*****|I_am|  Thank You for using SRMS :)   |0101|*****\n";
            cout << "\nPress any Enter to exit the program...";
            getch();
            exit(0);
            break;
        
        default:
            cout<<"\n-->> Please Enter the valid Option... Try Firse...:)\n";
            break;
        }
        cout << "\n\nPress any key to Continue...";
            getch();
    }

    return 0;
}