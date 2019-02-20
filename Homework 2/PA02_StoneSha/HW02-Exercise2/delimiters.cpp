//
//  delimiters.cpp
//  proj2
//
//  Created by Joshua Insorio on 2/19/19.
//  Copyright © 2019 Joshua Insorio. All rights reserved.
//
//--------------------------------------------------------------------
//
//   delimiters.cpp
//
//--------------------------------------------------------------------

#include "StackLinked.h"
#include <string>

//--------------------------------------------------------------------

bool delimetersOk( const string& expression )
{
    StackLinked<char> stack;
    for(unsigned int i = 0; i < expression.length(); i++)
    {
        if((expression[i] == '(')||(expression[i] == '{')||(expression[i] == '<')||(expression[i] == '['))
        {
            stack.push(expression[i]);
        }
        else if((expression[i] == ')')||(expression[i] == '}')||(expression[i] == '>')||(expression[i] == ']'))
        {
            if((stack.pop() != '('))
            {
                return false;
            }
            else if((stack.pop() != '{'))
            {
                return false;
            }
            else if((stack.pop() != '<'))
            {
                return false;
            }
            else if((stack.pop() != '['))
            {
                return false;
            }
        }
    }
    if(stack.isEmpty())
    {
        return true;
    }
    return false;
}

//--------------------------------------------------------------------

int main()
{

    string inputLine;            // Input line
    char   ch;                   // Holding pen for input chars

    cout << "This program checks for properly matched delimiters."
    << endl;

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

        if ( delimetersOk(inputLine))
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }


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

