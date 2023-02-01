//Gauss Elimination
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float modulo(float x)
{
    return ((x<0)?(x*-1):(x);)
}

int main()
{
    int o, n = 3;
    float e, a[5][5], x[5], xnew, xold, mold, mnew, temp, xnew[5];

    printf("\nOrder ? : ");
    scanf("%d", &o);
    printf("\nAcceptable Error ? : ");
    scanf("%f", &e);

    printf("\nEnter Matrix A : \n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            printf("\tA[%d][%d]: ", i, j);
            scanf("%f", &a[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter initial guess vactor X : \n");
    for(i = 1; i <= n; i++)
    {
        printf("\tx[%d]: ", i);
        scanf("%f", &x[i]);
    }

    mold = 1;

    for(i = 1; i <= n; i++)
    {
        temp = 0.0;
        for(j = 1; j <= n; j++)
        {
            temp = temp + a[i][j] * x[j];
        }
        xnew[i] = temp;
    }

    for(i = 1; i <= n; i++)
    {
        x[i] = xnew[i]
    }

    mnew = modulo(x[1]);
    for(i = 2; i <=n; i++)
    {
        if(modulo(x[i]) > mnew)
        {
            mnew = modulo(x[i]);
        }
    }

    return 0;
}
