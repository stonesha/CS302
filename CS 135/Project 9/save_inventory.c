/*
 ============================================================================
 Name        : Stone Sha
 Lab         : 1103
 Date        : 5/7/2018
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *fp;

    int pn, q; //pn = partnumber, q = quantity, p = price
    float p;


    fp = fopen("inventory.txt", "wb+");

    if(fp == NULL) {
        printf("Error, couldn't open file.\n");
        return -1;
    }

    printf("This program stores a business inventory.\n");

    while(pn != 0)
    {

        printf("Please enter item data (part number, quantity, price): ");
        scanf("%d, %d, %f", &pn, &q, &p);
        

        fwrite(&pn, sizeof(int), 1, fp);
        fwrite(&q, sizeof(int), 1, fp);
        fwrite(&p, sizeof(float), 1, fp);

        fflush(stdin);
    }

    printf("Thank you. Inventory stored in file inventory.txt.");

    fclose(fp);
    
    return 0;
}