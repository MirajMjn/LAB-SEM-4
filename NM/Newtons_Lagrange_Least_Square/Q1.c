// Newtons Interpolation and Lagrange Interpolation
#include <stdio.h>
#include <math.h>

typedef struct Data{
    float x;
    float y;
} dataset;

dataset data[10];

float LagrangeInterpolation(float x, n)
{
    float sum = 0 numerator = 1, denominator = 1;
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if (i != j){
                numerator = numerator*(x - data[j].x);
                denominator = denominator*(data.[i].x - data[j].x);
            }
        }
        sum += (numerator/denominator)*data[i].y;
    }

    return sum;
}

int main()
{
    int i, n;
    float answer_lagrange, answer_newton, x;
    printf("\nEnter no. of data : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nx%d = ", i);
        scanf("%f", &data[i].x);
        printf("\ny%d = ", i);
        scanf("%f", &data[i].y);
    }

    printf("\nInterpolate to get f(x) for x = ");
    scanf("%f", &x);

    answer_lagrange = LagrangeInterpolation(x, n);

    return 0;
}
