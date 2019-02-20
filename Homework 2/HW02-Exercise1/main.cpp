#include "StackLinked.h"
#include <string>
#include <stdlib.h>

float calculate_postfix(StackLinked<float> stack, string postfix);

int main()
{

    StackLinked<float> stack;
    string postfix;

    cout << "Enter an expression to calculate: ";
    getline(cin, postfix);

    cout << postfix;


}

float calculate_postfix(StackLinked<float> stack, string postfix)
{

}
