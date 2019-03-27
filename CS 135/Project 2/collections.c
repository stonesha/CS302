/*
 ============================================================================
 Name        : Stone Sha
 Lab         : 1103
 Date        : 2/12/18
 ============================================================================
 */
#include <stdio.h>

int main ()
{
    //Define Variables
    int b, v1, p1, v2, p2, v3, p3, c1, c2, c3, ct;


 /*---------------------------------------user input-------------------------------------------------------------*/   


    printf("Enter volumes and price per volume for collection 1: ");
    scanf("%d %d", &v1, &p1);
    c1 = v1 * p1;
    //printf("v1 is %d p1 %d c1 is %d", v1, p1, c1);

    printf("Enter volumes and price per volume for collection 2: ");
    scanf("%d %d", &v2, &p2);
    c2 = v2 * p2;
    //printf("v2 is %d p2 %d c2 is %d", v2, p2, c2);

    printf("Enter volumes and price per volume for collection 3: ");
    scanf("%d %d", &v3, &p3);
    c3 = v3 * p3;
    //printf("v3 is %d p3 %d c3 is %d", v3, p3, c3);

    printf("Enter Bob's budget: ");
    scanf("%d", &b);
    

 /*---------------------------------------if else-------------------------------------------------------------*/

    // if 1
    if (b > 0) {

        printf("(1) Bob has some money to buy collections.\n");

    } else {

        printf("(1) Bob does not have enough money to buy all three collections.\n");

    }

    //if 2
    ct = c1 + c2 + c3;
    if (b > ct) {

        printf("(2) Bob has enough money to buy all three collections.\n");

    } else {

        printf("(2) Bob does not enough money to buy all three collections.\n");

    }

    //if 3

    if (b > c1 && b > c2 ||b > c2 && b > c3 || b > c1 && b > c3 ) {

        printf("(3) At least two collections are cheaper than or equal to Bob's budget.\n");

    } else {

        printf("(3) At least two collections are more expensive than Bob's budget.\n");

    }

    //if 4
    if (c1 == c2 || c2 == c3 || c3 == c1) {

        printf("(4) At least two collections cost the same amount of money.\n");

    } else {

        printf("(4) No two collections have the same price.\n");

    }

    //if 5
    if (b >= c1 && b < c2 && b < c3 || b < c1 && b >= c2 && b < c3 || b < c1 && b < c2 && b >= c3) {

        printf("(5) Only one collection is cheaper than or equal to Bob's budget.\n");

    } else {

        printf("(5) More than one collection is cheaper than or equal to Bob's budget or they are all more expensive.\n");

    }



    //just to test if inputs are stored
    //printf("Bob money:%d Volume 1 and Price: %d %d Volume 2 and Price:  %d %d Volume 3 and Price:  %d %d", b, v1, p1, v2, p2, v3, p3 );

    return 0;
}