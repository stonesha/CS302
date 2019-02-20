/**
 * @brief  CS-302 Homework 1
 * @Author Stone Sha (stones@nevada.unr.edu)
 * @date   February 2019
 *
 * This file is the file for delimiter checking
 */
//--------------------------------------------------------------------
//
//   delimiters.cpp
//
//--------------------------------------------------------------------

#include "StackLinked.h"

//--------------------------------------------------------------------

bool delimitersOk ( const string &expression ) throw(logic_error);

//--------------------------------------------------------------------

int main()
{
    string inputLine;            // Input line
    char   ch;                   // Holding pen for input chars

    cout << "This program checks for properly matched delimiters."
         << endl;

    /* commented out to allow for test cases to run
    while( cin )
    {
        cout << "Enter delimited expression (<EOF> to quit) : "
             << endl;

        // Read in one line
        inputLine = "";
        cin.get(ch);
        while( cin && ch != '\n' )
        {
            inputLine = inputLine + ch;
            cin.get(ch);
        }

        if( ! cin )              // Reached EOF: stop processing
            break;

        if ( delimitersOk (inputLine) )
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }
    */

    cout << "Test Cases" << endl;
    cout << "(test) is:" << boolalpha << delimitersOk("(test)") << endl;
    cout << "()((test)) is:" << boolalpha << delimitersOk("()((test))") << endl;
    cout << "((()))test is:" << boolalpha << delimitersOk("((()))test") << endl;
    cout << ")()()( is: " << boolalpha << delimitersOk(")()()(") << endl;
    cout << ")( is:" << boolalpha << delimitersOk(")(") << endl;

    return 0;
}

//--------------------------------------------------------------------
// delimitersOk: the function that students must implement for
//    Programming Exercise 3.
// Note: we used the term "braces" to describe '[' and ']'. It would
//    have been better to use the term "brackets". The program can be
//    easily modified to process any set of matching delimiters.
//--------------------------------------------------------------------

// Insert your delimitersOk function below

//throws a logic error just in case popping an empty element (which happened frequently during tests)
bool delimitersOk ( const string &expression ) throw(logic_error)
{
    //clears just in case
    StackLinked<char> stack;
    stack.clear();

    //try catch block for catching the popping error
    try
    {
        //for loop iterating over the string
        for(size_t i = 0; i < expression.length();i++)
        {
            //switch statement for catching different delimiters
            switch(expression[i])
            {
            case '(':
                //pushes delimiters that are open
                stack.push(expression[i]);
                break;

            case ')':
                //pops delimiters to close
                stack.pop();
                break;

            }
        }
        //if all elements have been pushes and popped properly
        //this should return true, returns false if there's still
        // a delimiter
        return stack.isEmpty();

    } catch (logic_error)
    {
        //otherwise if theres a close delimiter
        //it will try to pop and throws a logical error
        return false;
    }

}



