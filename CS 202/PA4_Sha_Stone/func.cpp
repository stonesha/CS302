#include "func.h"

using namespace std;


//Function to print the options otherwise it would be repetitive
void printOptions()
{
    cout << "Options:" << endl << "   1: Read Data from File" << endl
         << "   2: Print out Data for all Cars & Agencies" << endl
         << "   3: Print out Total Number of Sensors" << endl
         << "   4: Find Most Expensive Car" << endl
         << "   5: Exit Program" << endl
         << "Enter your option: ";
}

//String Length Function ================================================
size_t my_StringLength (const char *str)
{

    int length = 0;

    for(; *str != '\0'; str++)
    {
        length++;
    }

    return length;

}

//String Compare Function ================================================
int my_StringCompare (const char *str1, const char *str2)
{

    char *c1 = (char *) str1;
    char *c2 = (char *) str2;

    while (*c1 != '\0')
    {
        if (*c2 == '\0')
            return 1;

        if (*c2 > *c1)
            return -1;

        if (*c2 < *c1)
            return 1;

        c1++;
        c2++;
    }

    if (*c2 != '\0')
        return -1;

    return 0;

}

//String Concatenate Function ================================================
char *my_StringCat (char *dest, const char *src)
{
    char *final = dest;

    while(*dest != '\0')
    {
        dest++;
    }

    while(*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';

    return final;
}

//String Copy Function ================================================
char *my_StringCopy (char *dest, const char *src)
{
    char *final = dest;

    while(*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';

    return final;

}

