#include "pch.h"
#include <iostream>
#include "LinkedList.h"

using namespace std;

/**
 * Main function
 * 
 * Execution for the program starts here
 */
int main()
{

    // Create Linked list and display welcome message
    LinkedList list1("Head");
    cout << "Welcome to the Linked List tool, this will allow you to create and modify a Linked List, and view it in real-time" << endl;

    char option = ' ';


    // Let user pick an option to modify linked list
    while (option != 'Q')
    {
        list1.display();
        cout << endl;
        cout << "Enter option: " << endl;
        cout << "[A] : Add a new value to the end of the linked list" << endl;
        cout << "[X] : Remove a value from the linked list (if found) " << endl;
        cout << "[S] : Search for a value in the linked list" << endl;
        cout << "[R] : Reverses the linked list" << endl;
        cout << "[Q] : Will end the program" << endl;

        cin >> option;
        string value;

        switch (option)
        {

            // User wants to add a node to list
        case 'A':
            cout << "Enter value to add to the Linked List:";
            cin >> value;
            cout << endl;
            list1.add(value);
            break;

            //User wants to remove a node from list
        case 'X':
            cout << "Enter value to remove from list:";
            cin >> value;
            cout << endl;
            if (list1.remove(value))
                cout << value << " successfully removed." << endl;
            else
                cout << value << " not found, cannot remove." << endl;
            break;

            // Useer wants to search for a value in the linked list
        case 'S':
            cout << "Enter value to find in the linked list:";
            cin >> value;
            cout << endl;
            if (list1.search(value))
                cout << value << " successfully found." << endl;
            else
                cout << value << " not found." << endl;
            break;

            // User wants to reverse the linked list
        case 'R':
            list1.reverse();
            break;
        }
    }

    cout << "Thank you for using the program, goodbye" << endl;
}
