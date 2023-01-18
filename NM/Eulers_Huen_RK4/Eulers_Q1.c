#include <stdio.h>
#include <math.h>

float f(float x, float y){ return (1 + 3 * x * x); }

float Eulers(float x, float y, float h, float xp)
{
    int n, i;
    n = (xp - x) / h;

    for(i = 1; i <= n; i++)
    {
        printf("\ny(%.4f) = %.4f", x, y);
        y = y + h*f(x, y);
        x = x + h;
    }
    return y;
}

int main()
{
    float x, y, xp, yp;
    float h;

    printf("\nEnter x0 : ");
    scanf("%f", &x);
    printf("\nEnter y0 : ");
    scanf("%f", &y);
    printf("\nEnter step size (h) : ");
    scanf("%f", &h);
    printf("\nEnter for what value of x, y(x) is to be calculated (xp) : ");
    scanf("%f", &xp);

    yp = Eulers(x, y, h, xp);

    printf("\ny(%.4f) = %.4f", xp, yp);

    return 0;
}
