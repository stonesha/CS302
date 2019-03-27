//circle.c
//Stone Sha
//1/32/2018
//This program computes values related to an inscribed circle.

#include <stdio.h>
#include <math.h>
#define pi 3.14f

int main(void)
{
    int r, d, pr, ars; //r for radius, d for diameter, ars for area of square
    float cr, arc, diff; //cr for circumference, ar for area, diff for difference btween ars and arc
    
    printf("This program computes values related to an inscribed circle.\n");
    printf("Enter the value of the radius:");
    scanf("%d", &r);

    //the boi put in radius

    d = r * 2;
    printf("The diameter of the circle is: %d\n", d);

    //calculated diameter wooh

    cr = 2 * pi * r;
    printf("The circumference of the circle is: %.3f\n", cr);

    //calculated circumference esketit

    arc = pi * pow(r,2);
    printf("The area of the circle is: %.3f\n", arc);

    //did area of circle

    pr = d * 4;
    printf("The perimeter of the square is: %d\n", pr);

    //perimeter square

    ars = d * d;
    printf("The area of the square is: %d\n", ars);

    //square area

    diff = ars - arc;
    printf("The difference between the area of the square and the circle is: %.3f\n", diff);

    return 0;
}