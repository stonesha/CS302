/*
 ============================================================================
 Name        : Stone Sha
 Lab         : 1103
 Date        : 2/20/18
 ============================================================================
 */
#include <stdio.h>
#include <math.h>

int main(void) {

    int n, s = 0, i, r; //n is the user input, s is the sum, r is the ratio

    printf("Enter an integer number: ");
    scanf("%d", &n);

    for(i = 0; i <= n; i++)  {
        
        

        r = pow(i, 2) * pow(-1, i + 1);
        
        s += r;
        
    }
    

    printf("The value of the series is: %d", s);
    return 0;
}