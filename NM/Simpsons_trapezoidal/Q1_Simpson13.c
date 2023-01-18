//Simple Simpsons 1/3
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

float f(float x)
{
    return( 1 + pow(x, 3) );
}

int main()
{
    float a , b, h, i;

    printf("\nEnter lower and upper limits of integration : ");
    scanf("%f%f", &a, &b);

    h = b - a;

    i = (h/3) * (f(a) + 4 * ( f( (a+b)/2 ) ) + f(b));

    printf("\nUsing simple Simpsons 1/3 Rule, Integration = %.4f", i);

    return 0;
}
