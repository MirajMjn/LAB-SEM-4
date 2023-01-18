//Simple Trapezoidal Rule.
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

    i = (h/2) * (f(a) + f(b));

    printf("\nUsing Simple Trapezoidal Rule, Integration = %.4f", i);

    return 0;
}
