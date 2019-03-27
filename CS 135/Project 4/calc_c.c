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

void option()
{
    printf("\nOptions\n1 - addition\n2 - subtraction\n3 - multiplication\n");
    printf("4 - division\n5 - exp(x)\n6 - log(x)\n7 - toggle calculator type\n8 - exit program\n"); 
    printf("Please enter your option: ");
}

int main() {

    int i1, i2, type = 0, dblc, intc;// number 1 and 2, choice

    double f1, f2;// float 1 and 2

    printf("This program implements a calculator");

/*----------------------------------------------*/
for(;;){
    while(type == 0){
        option();
        scanf("%d", &dblc);                        
        switch(dblc) { 

            case 1 :
                printf("Enter first term: ");
                scanf("%lf", &f1);
                printf("Enter second term: ");
                scanf("%lf", &f2);
                printf("The sum is: %.15lf", f1 + f2);
            break;

            case 2 :
                printf("Enter first term: ");
                scanf("%lf", &f1);
                printf("Enter second term: ");
                scanf("%lf", &f2);
                printf("The difference is: %.15f", f1 - f2);
            break;

            case 3 :
                printf("Enter first term: ");
                scanf("%lf", &f1);
                printf("Enter second term: ");
                scanf("%lf", &f2);
                printf("The product is: %.15lf", f1 * f2);
            break;

            case 4 :
                printf("Enter first term: ");
                scanf("%lf", &f1);
                printf("Enter second term: ");
                scanf("%lf", &f2);
                if(f2 == 0){
                    printf("Cannot divide by zero!");
                } else {
                    printf("The quotient is: %.15lf", f1 / f2);
                }
            break;

            case 5 :
                printf("Enter term: ");
                scanf("%lf", &f1);
                printf("The result of exp(%.15lf) is: %.15lf", f1, exp(f1));
            break;

            case 6 : 
                printf("Enter term: ");
                scanf("%lf", &f1);
                if(f1 < 0){
                    printf("Cannot take the log of that number!");
                } else {
                    printf("The result of log(%.15lf) is: %.15lf", f1, log(f1));
                }
            break;

            case 7 :
                printf("Calculator now works with integers.");
                type = 1;
            break;

            case 8 :
                exit(0);
            break;

            default :
                printf("Invalid Option.");
            break;
        }
    }
    while(type == 1){
        option();
        scanf("%d", &intc);         
        switch(intc) { 

            case 1 :
                printf("Enter first term: ");
                scanf("%d", &i1);
                printf("Enter second term: ");
                scanf("%d", &i2);
                printf("The sum is: %d", i1 + i2);
            break;

            case 2 :
                printf("Enter first term: ");
                scanf("%d", &i1);
                printf("Enter second term: ");
                scanf("%d", &i2);
                printf("The difference is: %d", i1 - i2);
            break;

            case 3 :
                printf("Enter first term: ");
                scanf("%d", &i1);
                printf("Enter second term: ");
                scanf("%d", &i2);
                printf("The product is: %d", i1 * i2);
            break;

            case 4 :
                printf("Enter first term: ");
                scanf("%d", &i1);
                printf("Enter second term: ");
                scanf("%d", &i2);
            if(i2 == 0) {
                printf("Cannot divide by zero!");
            } else {
                printf("The quotient is: %d", i1 / i2);
            }
            break;

            case 5 :
                printf("Cannot calculate with integers.");
            break;

            case 6 :
                printf("Cannot calculate with integers.");
            break;

            case 7 :
                printf("Calculator now works with doubles.");
                type = 0;
            break;

            case 8 :
                exit(0);
            break;

            default :
                printf("Invalid Option.");
            break;
        }
    }  
    
}
/*----------------------------------------------*/

}