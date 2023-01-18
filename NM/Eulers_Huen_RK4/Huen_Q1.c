#include <stdio.h>
#include <math.h>

float f(float x, float y){ return (1 + 3 * x * x); }

float Heun(float x, float y, float h, float xp)
{
    int n, i;
    float m1, m2;
    n = (xp - x) / h;

    for(i = 1; i <= n; i++)
    {
        printf("\ny(%.4f) = %.4f", x, y);

        m1 = f(x, y);
        m2 = f(x+h, y+h*m1);

        y = y + (h/2) * (m1 + m2);
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

    yp = Heun(x, y, h, xp);

    printf("\ny(%.4f) = %.4f", xp, yp);

    return 0;
}
