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

    int pn, q;
    float p;
    int ch;
    

    fp = fopen("inventory.txt", "rb");
    
    if(fp == NULL) {
        printf("Error, couldn't open file.\n");
        return -1;
    }

    printf("Below are the items in your inventory.\n");

    printf("%s\t%-8s\t%-9s\n", "Part#", "Quantity", "Item Price");

    fseek(fp, 0, SEEK_SET);


    
        fread(&pn, sizeof(int), 1, fp);
        fread(&q, sizeof(int), 1, fp);
        fread(&p, sizeof(float), 1, fp);

        printf("%5d\t%8d\t$%9.2f\n", pn, q, p);

        fread(&pn, sizeof(int), 1, fp);
        fread(&q, sizeof(int), 1, fp);
        fread(&p, sizeof(float), 1, fp);

        printf("%5d\t%8d\t$%9.2f\n", pn, q, p);
    
    

    fclose(fp);
    
    return 0;
}