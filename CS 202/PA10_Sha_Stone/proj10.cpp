/**
 * @brief  CS-202 Project 10 Test Driver
 * @Author Stone Sha (stones@nevada.unr.edu)
 * @date   November - December, 2018
 *
 * This file is the test driver for Project 10
 */
#include <iostream>
#include "ArrayStack.h"
#include "NodeStack.h"

//for the sake of lazyness
using namespace std;

int main()
{
    //Default Constructors
    cout << "===== Default Constructors =====" << endl;
    DataType dt_default;
    ArrayStack<DataType> as_default;
    NodeStack<DataType> ns_default;

    //Parameterized Constructors
    cout << "===== Param Constructors =====" << endl;
    DataType dt_param(69, 3.60);
    ArrayStack<DataType> as_param(5, dt_param);
    NodeStack<DataType> ns_param(5, dt_param);

    cout << "as_param: " << as_param << endl;
    cout << "ns_param: " << ns_param << endl;

    //NodeStack Copy Constructor
    cout << "===== NodeStack Copy Constructor =====" << endl;
    NodeStack<DataType> ns_copy(ns_param);

    cout << "ns_copy: " << ns_copy << endl;

    //Assignment Operator
    cout << "===== Assignment Operators ====" << endl;
    ArrayStack<DataType> as_new;
    as_new = as_param;
    NodeStack<DataType> ns_new;
    ns_new = ns_param;

    cout << "as_new: " << as_new << endl;
    cout << "ns_new: " << ns_new << endl;

    //Top
    cout << "===== top() =====" << endl;
    cout << "Top of as_new: " << as_new.top() << endl;
    cout << "Top of ns_new: " << ns_new.top() << endl;

    //Push
    cout << "==== push() =====" << endl;
    DataType dt_push(21, 4.20);
    cout << "dt_push: " << dt_push << endl;

    as_new.push(dt_push);
    ns_new.push(dt_push);
    cout << "After pushing, as_new: " << as_new << endl;
    cout << "After pushing, ns_new: " << ns_new << endl;

    //Pop
    cout << "===== pop() =====" << endl;

    as_new.pop();
    ns_new.pop();
    cout << "After popping, as_new: " << as_new << endl;
    cout << "After popping, ns_new: " << ns_new << endl;

    // empty or full, size
    cout << "===== empty, full, and size =====" << endl;
    cout << "as_new is empty: " << boolalpha << as_new.empty() << endl;
    cout << "as_new is full: " << boolalpha << as_new.full() << endl;

    cout << "ns_new is empty: " << boolalpha << ns_new.empty() << endl;
    cout << "ns_new is full: " << boolalpha << ns_new.full() << endl;

    cout << "as_new has " << as_new.size() << " values." << endl;
    cout << "ns_new has " << ns_new.size() << " values." << endl;


    //clear
    cout << "===== clear() =====" << endl;
    as_new.clear();
    ns_new.clear();
    cout << "After clearing, as_new is empty: " << boolalpha << as_new.empty() << endl;
    cout << "After clearing, ns_new is empty: " << boolalpha << ns_new.empty() << endl;

    return 0;
}
