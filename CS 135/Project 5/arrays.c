/*
 ============================================================================
 Name        : Stone Sha
 Lab         : 1103
 Date        : 2/20/18
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main(void){
    
    int r, c, i, j;
    int freq[10] = {0};

    
    printf("This program cunts occurences of digits 0 through 9 in an NxM array.\n");
    printf("Enter the size of the array (Row Column): ");
    scanf("%d %d", &r, &c);


    int a[r][c];

    for(i = 0; i < r; i++){
        
        printf("Enter row %d: ", i);
        
        for(j = 0; j < c; j++){
            
            scanf("%d", &a[i][j]);
            
        }

           
    }

    printf("Total counts for each digit:\n");

    for(i = 0; i < r; i++){

        for(j = 0; j < c; j++){

            switch(a[i][j]){

                case 0:
                freq[0]++;
                break;

                case 1:
                freq[1]++;
                break;

                case 2:
                freq[2]++;
                break;

                case 3:
                freq[3]++;
                break;
                
                case 4:
                freq[4]++;
                break;

                case 5:
                freq[5]++;
                break;
                
                case 6:
                freq[6]++;
                break;

                case 7:
                freq[7]++;
                break;

                case 8:
                freq[8]++;
                break;

                case 9:
                freq[9]++;
                break;

                default:
                break;
            }


        }
 
    }

    
    for(i = 0; i < 10; i++){

        printf("Digit %d occurs %d times\n", i, freq[i]);
    
    }

    printf("The digit counts directly from the 1D array: \n");

    for(i = 0; i < 10; i++){
        printf("%d ", freq[i]);
    }
        
    printf("\n");
    

    printf("The original 2D array entered by the user:");

    for(i = 0; i < r; i++){

        printf("\n");

        for(j = 0; j < c; j++){

            printf("%d ", a[i][j]);
        }


    }

    return 0;
}