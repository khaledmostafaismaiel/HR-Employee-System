//THIS PROGRAM IS AN EMPLOYEE HR SYSTEM
//YOU CAN INSERT EMPLOYEE(FIRST NAME :LAST NAME :AGE :SALARY)
//        UPDATE EMPLOYEE INFO
//        SORT EMPLOYEE LIST NOT DATABASEFILE BY(FIRST NAME :AGE :SALARY)
//        SEARCH ABOUT EMPLOYEE WITH (FIRST NAME : LAST NMAE)
//        DELET EMPLOYEE FROM YOUR DATA BASE
//THIS PROGRAM CAN ALSO READ ALL .txt FILES CONTAIN DATABASE WRETIEN WITH THIS FORMAT
//ID:FIRST NAME;LAST NAME;AGE;SALARY\n
//AUTHOR : KHALED MOSTAFA

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define DB "CREATDATABASE.txt"

#include "helper.h"
#include "linkedList.h"
#include "database.h"

int main()
{
    puts("\t\t\t\t\tWELCOME DUDE IN ROBOCORONA_COMPANY.");

    if (fopen(DB, "r") != NULL)
    {
        DBconverter();
    }

    int press = 0;
    do
    {
        switch (press)
        {
            char insertfname[20];
            char insertlname[20];
            int insertage;
            float insertsalary;

        case 1: //Insert new employee
            do
            {
                puts("\nPress 1-Insert New Emplyee\nPress 2-Exit");
                scanf("%d", &press);

            } while ((press <= 0) || (press > 2));

            switch (press)
            {

            case 1:
                puts("Enter the First Name.");
                scanf("%s", &insertfname);

                puts("Enter the Last Name.");
                scanf("%s", &insertlname);

                puts("Enter the Age.");
                scanf("%d", &insertage);

                puts("Enter the Salary.");
                scanf("%f", &insertsalary);

                insert_employee(insertfname, insertlname, insertage, insertsalary);
            }

            break;

        case 2: //List linked list
            if (startNULLchecker(start) != 0)
            {
                do
                {
                    puts("\nPress 1-List Linkedlist\nPress 2-Exit");
                    scanf("%d", &press);

                } while ((press <= 0) || (press > 2));

                switch (press)
                {

                case 1:
                    listLinkedlist(start);

                    break;
                }

                break;

            case 3: // Sort employee linked list
                if (startNULLchecker(start) != 0)
                {

                    do
                    {
                        puts("Press 1-Sort By name\npress 2-Sort By age\npress 3-Sort By salary\nPress 4-Exit");
                        scanf("%d", &press);

                    } while ((press <= 0) || (press > 4));

                    switch (press)
                    {
                        puts("The Sorted List is");

                    case 1:

                        sort_Employees(1); // Sort By First Name

                        listLinkedlist(start);

                        sort_Employees(4); // Sort By ID

                        break;

                    case 2:

                        sort_Employees(2); // Sort By Age

                        listLinkedlist(start);

                        sort_Employees(4); // Sort By ID

                        break;

                    case 3:

                        sort_Employees(3); // Sort By Salary

                        listLinkedlist(start);

                        sort_Employees(4); // Sort By ID
                    }
                }
            }
            break;

        case 4: // Search for spacific employee
            if (startNULLchecker(start) != 0)
            {

                do
                {
                    puts("\nPress 1-Search By First Name\nPress 2-Search By Last Name\nPress 3-Exit");
                    scanf("%d", &press);

                } while ((press <= 0) || (press > 3));

                switch (press)
                {

                case 1:
                    searchEmployee(1, "First Name");
                    break;

                case 2:

                    searchEmployee(2, "Last Name");
                    break;
                }
            }

            break;

        case 5: //Update a spacific employee info
            if (startNULLchecker(start) != 0)
            {

                int id = askForID();
                if (ID_checker(id))
                {
                    do
                    {
                        puts("Press 1-Update First Name\nPress 2-Update Last Name\nPress 3-Update Age\nPress 4-Update Salary\nPress 5-Exit");
                        scanf("%d", &press);
                    } while ((press < 1) || (press > 5));
                    switch (press)
                    {
                    case 1:
                        update_Employee(1, "First Name", id);
                        updateFile(start);

                        break;

                    case 2:
                        update_Employee(2, "Last Name", id);
                        updateFile(start);

                        break;

                    case 3:
                        update_Employee(3, "Age", id);
                        updateFile(start);

                        break;

                    case 4:
                        update_Employee(4, "Salary", id);
                        updateFile(start);
                    }
                }
            }
            break;

        case 6: // Delete spacific employee

            if (startNULLchecker(start) != 0)
            {

                int id = askForID();
                if (ID_checker(id))
                {
                    do
                    {
                        puts("Press 1-Delete The Employee\nPress 2-Exit");
                        scanf("%d", &press);
                    } while ((press < 1) || (press > 2));
                    switch (press)
                    {
                    case 1:

                        delete_employee(id);
                        updateFile(start);
                    }
                }
            }
            break;
        }

        puts("Press 1-Insert New Employee\nPress 2-List All Employees\nPress 3-Sort All Employees\nPress 4-Search For An Employee\nPress 5-Update An Employee Information\nPress 6-Delete An Employee\nPress 7-Exit.");
        scanf("%d", &press);
    } while ((press >= 1) && (press <= 6));

    puts("\t\t\t\t\tYou Choose To Exit Thank You.");

    return 0;
}