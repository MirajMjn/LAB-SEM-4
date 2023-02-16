// Newtons Interpolation and Lagrange Interpolation
#include <stdio.h>
#include <math.h>

float x[7];
//for difference table
float y[7][7];

void fill_difference_table(int n)
{
    int i, j, e = n;

    for(i = 1; i < n; i++){
        for(j = 0; j < e; j++){
            y[i][j] = y[i-1][j+1] - y[i-1][j];
        }
        e--;
    }
}

void display_difference_table(int n)
{
    int i, j, e = n;
    printf("\n\nThe difference table is as follows :\n\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < e; j++){
            printf("%.2f\t", y[j][i]);
        }
        printf("\n");
        e--;
    }
}

int factorial(int n)
{
    if(n == 0)
        return 1;
    else
        return n * factorial(n-1);
}

float LagrangeInterpolation(float xp, int n)
{
    float sum = 0, numerator, denominator;
    int i, j;
    for(i = 0; i < n; i++)
    {
        numerator = denominator = 1;
        for(j = 0; j < n; j++)
        {
            if (i != j){
                numerator = numerator*(xp - x[j]);
                denominator = denominator*(x[i] - x[j]);
            }
        }
        sum += (numerator/denominator)*y[0][i];
    }

    return sum;
}

float NewtonInterpolation(float xp, int n)
{
    float p, h, result, prod;
    int i, j;

    fill_difference_table(n);
    display_difference_table(n);

    h = x[1] - x[0];
    p = (xp - x[0]) / h;
    result = 0;

    for (i = 0; i < n; i++){
        prod = 1;
        for (j = 0; j < i; j++){
            prod = prod * (p - j);
        }
        result += (prod * y[i][0]) / factorial(i);
    }
    return result;
}

int main()
{
    int i, n = 7;
    float answer_lagrange, answer_newton, xp;

    for(i = 0; i < n; i++){
        printf("\nx%d = ", i);
        scanf("%f", &x[i]);
        printf("y%d = ", i);
        scanf("%f", &y[0][i]);
    }

    xp = 1;
    answer_lagrange = LagrangeInterpolation(xp, n);
    printf("\n(Lagrange Interpolation) f(%.3f) = %.3f", xp, answer_lagrange);
    answer_newton = NewtonInterpolation(xp, n);
    printf("\n(Newton Interpolation) f(%.3f) = %.3f", xp, answer_newton);

    xp = 10;
    answer_lagrange = LagrangeInterpolation(xp, n);
    printf("\n(Lagrange Interpolation) f(%.3f) = %.3f", xp, answer_lagrange);
    answer_newton = NewtonInterpolation(xp, n);
    printf("\n(Newton Interpolation) f(%.3f) = %.3f", xp, answer_newton);

    return 0;
}
