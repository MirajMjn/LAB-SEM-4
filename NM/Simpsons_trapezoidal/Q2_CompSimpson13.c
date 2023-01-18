//Composite Simpsons
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

float f(float x)
{
    return( 1 + pow(x, 3) );
}

float Simpson13(float a, float b, int n)
{
    float i, sum_even = 0, sum_odd = 0, h;
    int j;
    h = (b - a)/n;

    for(j = 1; j <= n-1; j++)
    {
        if (j%2 == 0){
            sum_even += f(a + j*h);
        }
        else {
            sum_odd += f(a + j*h);
        }
    }

    i = (h/3) * ( f(a) + f(b) + 4*sum_odd + 2*sum_even );

    return i;
}

int main()
{
    float a , b, h, i, n;

    printf("\nEnter lower and upper limits of integration : ");
    scanf("%f%f", &a, &b);

    printf("\nUsing Composite Simpsons 1/3 rule, ");
    printf("\nn = 4\t| I = %f ", Simpson13(a, b, 4));
    printf("\nn = 8\t| I = %f ", Simpson13(a, b, 8));
    printf("\nn = 15\t| I = %f ", Simpson13(a, b, 15));
    printf("\nn = 20\t| I = %f ", Simpson13(a, b, 20));


    return 0;
}
