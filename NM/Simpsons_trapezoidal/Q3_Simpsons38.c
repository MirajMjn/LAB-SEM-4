#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

float f(float x)
{
    return( 1 + pow(x, 3) );
}

float Simpson38(float a, float b, int n)
{
    float i, sum = 0, sum_3 = 0, h;
    int j;
    h = (b - a)/n;

    for(j = 1; j <= n-1; j++)
    {
        if (j%3 == 0){
            sum_3 += f(a + j*h);
        }
        else {
            sum += f(a + j*h);
        }
    }

    i = (0.375 * h) * ( f(a) + f(b) + 3*sum + 2*sum_3 );

    return i;
}

int main()
{
    float a , b, h, i;
    int n;

    printf("\nEnter lower and upper limits of integration : ");
    scanf("%f%f", &a, &b);

    printf("\nEnter number of strips : ");
    scanf("%d", &n);

    printf("\nUsing Composite Simpsons 3/8 rule, ");
    printf("\nn = %d\t| I = %f ", n, Simpson38(a, b, n));


    return 0;
}
