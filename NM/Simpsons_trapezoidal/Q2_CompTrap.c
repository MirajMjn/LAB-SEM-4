//Composite Trapezoidal Rule.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

float f(float x)
{
    return( 1 + pow(x, 3) );
}

float Trapezoidal(float a, float b, int n)
{
    float i, sum = 0, h;
    int j;
    h = (b - a)/n;

    for(j = 1; j <= n-1; j++)
    {
        sum += f(a + j*h);
    }

    i = (h/2) * ( f(a) + f(b) + 2*(sum) );

    return i;
}

int main()
{
    float a , b, h, i, n;

    printf("\nEnter lower and upper limits of integration : ");
    scanf("%f%f", &a, &b);

    printf("\nUsing Composite Trapezoidal rule, ");
    printf("\nn = 4\t| I = %f ", Trapezoidal(a, b, 4));
    printf("\nn = 8\t| I = %f ", Trapezoidal(a, b, 8));
    printf("\nn = 15\t| I = %f ", Trapezoidal(a, b, 15));
    printf("\nn = 20\t| I = %f ", Trapezoidal(a, b, 20));


    return 0;
}
