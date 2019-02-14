/**
 * @brief  CS-302 Homework 1
 * @Author Stone Sha (stones@nevada.unr.edu)
 * @date   February 2019
 *
 * This file is the main program/switch statement for HW01
 */
#include "LinkedList.h"

void printMenu();
template <class T>T pushInput(T item);

int main()
{

    //needed for the switch statement
    int option, item;
    bool exit = false;

    //the linked list that will be manipulated
    LinkedList<int> list;

    //keeping switch statement going until exit is true
    while (!exit)
    {
        //redundant repeatedly printing menu so function for it
        printMenu();
        //accepts option
        std::cin >> option;

        //switch statement using option entered
        switch(option)
        {
            //pushing data into queue
            case 1:
                std::cout << "Enter integer to be pushed: ";
                std::cin >> item;
                list.push(item);
            break;

            //popping data
            case 2:
                std::cout << "Deleting an item.";
                list.pop();
            break;

            //outputs number of items
            case 3:
                std::cout << "Number of Items: " << list.size() << std::endl;
            break;

            //shows all items
            case 4:
                std::cout << "Showing all Items: " << list << std::endl;
            break;

            //exits program
            case 5:
                exit = true;
            break;
        }
    }

    return 0;
}

//function to print options
void printMenu()
{
    std::cout << "\nLinked List Menu\n"
        << "1. Add a new item to Linked List\n"
        << "2. Delete an item from the Linked List\n"
        << "3. Show number of items in Linked List\n"
        << "4. Show all items in Linked List\n"
        << "5. Exit\n"
        << "Enter Option: " << std::endl;
}

