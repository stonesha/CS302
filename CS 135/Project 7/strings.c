/*
 ============================================================================
 Name        : Stone Sha
 Lab         : 1103
 Date        : 4/14/18
 ============================================================================
 */
#include <stdio.h>

#define MAX 50

int my_strlength(const char *str);
int my_strcmp (const char *str1, const char *str2);
char *my_strcat (char *dest, const char *src);
char *my_strcpy(char *dest, const char *src);

int main()
{

    char s1[MAX], s2[MAX], s3[MAX];
    int len1, len2, ret;



    printf("Please enter your first string: ");
    scanf("%s", &s1);

    printf("Please enter your second string: ");
    scanf("%s", &s2);

    len1 = my_strlength(s1);
    len2 = my_strlength(s2);


    printf("The length of string 1 is: %d\n", len1);
    printf("The length of string 2 is: %d\n", len2);

    ret = my_strcmp(s1, s2);
    if(ret > 0)
    {
        printf("String 1 comes before string 2 alphabetically.\n");
    }else if(ret < 0)
    {
        printf("String 2 comes before string 1 alphabetically.\n");
    }else
    {
        printf("The two strings are the same.\n");
    }

  
    

    printf("String 1 after concatenation: %s\n", s1);
    printf("String 2 after concatenation: %s\n", my_strcat(s2, s1));

    printf("String 1 after copying: %s\n", my_strcpy(s1, s1));
    printf("String 2 after copying: %s\n", my_strcpy(s2, s1));
    
        






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
    int i, j;

    for(i = 0; dest[i] != '\0'; i++)
        ;
    for(j = 0; src[j] != '\0'; j++)
        dest[i+j] = src[j];
    
    
    dest[i+j] = '\0';

    return dest;


}

char *my_strcpy(char *dest, const char *src)
{
    int i;

    for(i = 0; src[i] != '\0'; ++i)
    {
        dest[i] = src[i];
    }

    dest[i] = '\0';

    return dest;

}

