/*
 ============================================================================
 Name        : Stone Sha
 Lab         : 1103
 Date        : 2/20/18
 ============================================================================
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    //variables
    double n, g, d; //n is the number inputted, n2 is the guess squared - the number, d is 1e^-5, g2 is the alternate guess
    

    //print statements
    printf("Enter a number: ");
    scanf("%lf", &n);

    
    g = 1;
    d = pow(10, -6);
    

    //printf("n2 is %.5f and n4 is %.5f\n", n2, n4);
            
    while( fabs(pow(g, 2) - n) > d){

        printf("\n%10.5f\n", g);

        g = (g + (n / g)) / 2;

        if( fabs(pow(g, 2) - n) < d) {
            break;
        }

    }

    printf("\nEstimated square root of %.5f: %.5f\n", n, g);

    return 0;
}