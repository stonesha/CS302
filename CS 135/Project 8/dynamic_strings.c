/*
 ============================================================================
 Name        : Stone Sha
 Lab         : 1103
 Date        : 4/26/18
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

//String Functions
int my_strlen (const char *str);
int my_strcmp (const char *str1, const char *str2);
char *my_strcat (char *dest, const char *src);
char *my_strcpy (char *dest, const char *src);

//Other Functions
void print();//to print options because i'm lazy to retype
void putStr(char **str, int strnum);


int main(int argc, char *argv[])
{

    int i = 0, strNum, length, temp1, temp2, result, option;

    strNum = atoi(argv[1]);

    char *strings[strNum], temp;

    for(i = 0; i < strNum; i++)
    {
        printf("Enter the length of string %d: ", i + 1);
        scanf("%d", length);

        strings[i] = malloc(length * sizeof(char) + 1); 

        printf("Please enter string %d: ", i + 1);
        scanf("%s", strings[i]);

    }

//-----------------------------------------------------------------------------------------------

    for(;;)
    {

        putStr(strings, strNum);
        print();
        scanf("%d", &option);
        switch(option)
        {
            //1 – Find string length
            case 1:
            printf("Enter a string number: ");
            
            scanf("%d", &temp1);

            printf("The length of string %d is: %d\n", temp1, my_strlen(strings[temp1 - 1]));

            break;
//-----------------------------------------------------------------------------------------------
            //2 – Compare strings
            case 2:
            printf("Enter the number of the first string: ");
            scanf("%d", &temp1);

            printf("Enter the number of the second string: ");
            scanf("%d", &temp2);

            result = my_strcmp(strings[temp1 - 1], strings[temp2 - 1]);

            if (result < 0) {

                printf("String %d comes before string %d alphabetically.\n", temp1, temp2);

            } else if (result > 0) { 

                printf("String %d comes before string %d alphabetically.\n", temp2, temp1);

            } else {

                printf("The two strings are the same.\n");

            }

            break;
//-----------------------------------------------------------------------------------------------
            //3 – Copy strings
            case 3:
            printf("Enter the number of the source string: ");
            scanf("%d", &temp1);

            printf("Enter the number of the destination string: ");
            scanf("%d", &temp2);

            my_strcpy(strings[temp2 - 1]/*dest*/, strings[temp1 - 1]/*source*/);
            break;
//-----------------------------------------------------------------------------------------------
            //4 – Concatenate strings
            case 4:
            printf("Enter the number of the source string: ");
            scanf("%d", &temp1);

            printf("Enter the number of the destination string: ");
            scanf("%d", &temp2);

            my_strcat(strings[temp2 - 1]/*dest*/, strings[temp1 - 1]/*source*/);

            break;
//-----------------------------------------------------------------------------------------------
            //5 – Quit
            case 5:
            free(strings);
            return 0;
            break;
//-----------------------------------------------------------------------------------------------
            //Invalid Option
            default:
            printf("Invalid Option.\n");
            break;

        }

    }

}

//--------------------------------------------------------------------

void print()
{

    printf("Options:\n");
    printf("1 - Find string length\n");
    printf("2 - Compare strings\n");
    printf("3 - Copy strings\n");
    printf("4 - Concatenate strings\n");
    printf("5 - Quit\n");
    printf("Please enter your option: ");

}

void putStr(char **str, int strnum)
{
    int i = 0;

    printf("Your strings are:\n");

    for(i = 0; i < strnum; i++)
    {
       
    printf("String number %d - \"%s\"\n", i + 1, str[i]);

    }

    free(str);
}

int my_strlen (const char *str)
{
    int i = 0, length = 0;

    for(i = 0; str[i] != '\0'; i++)
    {
        length++;
    }

    return length;

}

int my_strcmp (const char *str1, const char *str2)
{
    unsigned char *c1 = (unsigned char *) str1;
    unsigned char *c2 = (unsigned char *) str2;

    while (*c1 != '\0')
    {
        if (*c2 == '\0') return 1;

        if (*c2 > *c1) return -1;

        if (*c2 < *c1) return 1;
    
        c1++;
        c2++;
    }

    if (*c2 != '\0') return -1;

    return 0;

}

char *my_strcat (char *dest, const char *src)
{
    int i, j, len1 = my_strlen(src), len2 = my_strlen(dest);

    char *new_dest;

    new_dest = (char *)realloc(dest, (len1 + len2 + 1) * sizeof(char));
    

    for(i = 0; new_dest[i] != '\0'; i++)
        ;
    for(j = 0; src[j] != '\0'; j++)
        new_dest[i+j] = src[j];
    
    
    new_dest[i+j] = '\0';

    return new_dest;


}

char *my_strcpy (char *dest, const char *src)
{
    int i;

    char *new_dest;

    new_dest = (char *)realloc(dest, my_strlen(src) + 1);

    for(i = 0; src[i] != '\0'; ++i)
    {
        new_dest[i] = src[i];
    }

    new_dest[i] = '\0';

    return new_dest;

}