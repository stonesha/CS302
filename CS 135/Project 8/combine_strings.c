/*
 ============================================================================
 Name        : Stone Sha
 Lab         : 1103
 Date        : 4/20/18
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 30

//String Functions
int my_strcmp (const char *str1, const char *str2); //string compare for command line arguments
int my_strlength(const char *str); // string length for memory allocation

//String Combining Functions
char intersperse(const char *s1, const char *s2, char *s3); // interspersing strings
char widen_stars(const char *s1, const char *s2, char *s3); // putting stars and concencating strings

int main(int argc, char* argv[])
{
    
    int i = 0;
    char string1[MAX], string2[MAX];
    char *string3;

    for(i = 0; i < argc; i++){
        
        //combine strings
        if(my_strcmp( argv[i], "-i") == 0) {
            
            string3 = malloc(my_strlength(string1) + my_strlength(string2) + 1);

            printf("Please enter a string of maximum 30 characters: ");
            scanf("%s", &string1);

            printf("Please enter a string of maximum 30 characters: ");
            scanf("%s", &string2);

            intersperse(string1, string2, string3);

            printf("The combined string is: %s\n", string3);
        
        //combine strings with stars
        } else if(my_strcmp( argv[i], "-w") == 0) {

            string3 = malloc(my_strlength(string1) + my_strlength(string2) + 31);
            
            printf("Please enter a string of maximum 30 characters: ");
            scanf("%s", &string1);

            printf("Please enter a string of maximum 30 characters: ");
            scanf("%s", &string2);

            widen_stars(string1, string2, string3);

            printf("The combined string is %s\n", string3);

        }
    }

    free(string3);

    return 0;

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

int my_strlength(const char *str)
{
    int i = 0, length = 0;

    for(i = 0; str[i] != '\0'; i++)
    {
        length++;
    }

    return length;

}

char intersperse(const char *s1, const char *s2, char *s3)
{

    while(*s1 != '\0' && *s2 != '\0')
    {
        *s3++ = *s1++;
        *s3++ = *s2++;
    }
    while(*s1 != '\0')
    {
        *s3++ = *s1++;
    }
    while(*s2 != '\0')
    {
        *s3++ = *s2++;
    }
    *s3 = '\0';

    return *s3;

}

char widen_stars(const char *s1, const char *s2, char *s3)
{
    int i = 0;

    for(i = 0; *s1 != '\0'; i++){


        while(*s1 != '\0')
        {
        
        *s3++ = *s1++;
        *s3++ = '*';
        }
    }
    
    for(i = 0; *s2 != '\0'; i++){

        if(i == 0)
        {

            *s3++ = *s2++;

        } else 
        {
        
            while(*s2 != '\0')
            {
                *s3++ = '*';

                *s3++ = *s2++;

            }

        }

        
        
    }
    
    *s3 = '\0';

    return *s3;

}