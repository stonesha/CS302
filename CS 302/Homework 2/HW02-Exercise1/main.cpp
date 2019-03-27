/**
 * @brief  CS-302 Homework 2
 * @Author Stone Sha (stones@nevada.unr.edu)
 * @date   February 2019
 *
 * This file is the implementation of a postfix calculator
 */
#include "StackLinked.h"
#include <string>
#include <cctype>
#include <cmath>

//function prototypes
float convert_postfix(StackLinked<float> &stack, string postfix) noexcept;
float calculate_postfix(float oper1, float oper2, char postfix_operator) throw(logic_error);

int main()
{

    StackLinked<float> stack;

    //exercise 1 assignment 1
    cout << "Exercise 1. Assignment 1" << endl;
    cout << " (3+4)*(5/2) or 34+52/* = " << convert_postfix(stack, "34+52/*") << endl;

    //exercise 1 assignment 2
    cout << "Exercise 1. Assignment 2" << endl;
    cout << "1. (7-5)*(3/6) or 75-36/* = " << convert_postfix(stack, "75-36/*") << endl;
    cout << "2. (1+2)*(4/5) or 12+45/* = " << convert_postfix(stack, "12+45/*") << endl;
    cout << "3. (3/8)*(3/9) or 38/39/* = " << convert_postfix(stack, "38/39/*") << endl;
    cout << "4. (5^2)+(3^3) or 52^33^+ = " << convert_postfix(stack, "52^33^+") << endl;
    cout << "5. (1+3)*(5-4) or 13+54-* = " << convert_postfix(stack, "13+54-*") << endl;

    return 0;
}

//interpreting and calculating expression
float convert_postfix(StackLinked<float> &stack, string postfix) noexcept
{
    //defined variables
    float oper1, oper2, result;
    char postfix_operator;
    //safety
    stack.clear();

    //for loop to iterate over string
    for(size_t i = 0;i < postfix.length(); i++)
    {
        //checks if digit/number
        if(isdigit(postfix[i]))
        {
            //pushes if number, converts to float/int thing
            stack.push(postfix[i] - '0');
        }
        else
        {
            //pops operands
            oper1 = stack.pop();
            oper2 = stack.pop();
            //postfix operator sensed
            postfix_operator = postfix[i];

            //calculates answer
            result = calculate_postfix(oper1, oper2, postfix_operator);

            //pushes answer
            stack.push(result);
        }
    }

    //returns answer
    return stack.pop();
}

//for calculating the expressions once interpreted
float calculate_postfix(float oper1, float oper2, char postfix_operator) throw(logic_error)
{
    //testing for all cases
    //break statements added for safety
    switch(postfix_operator)
    {
    case '+':
        return oper1 + oper2;
        break;

    case '-':
        return oper2 - oper1;
        break;

    case '*':
        return oper1 * oper2;
        break;

    case '/':
        return oper2 / oper1;
        break;

    case '^':
        return pow(oper2, oper1);
        break;

    default:
        //throws error if operator isn't one of the above
        throw logic_error("Operator isn't valid");
    }
}
