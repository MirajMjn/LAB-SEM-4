//Gauss Elimination
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int i, j, k, n;
    float a[6][6], temp, ratio;
    float x[6];

    printf("\nHow many number of unknowns ? : ");
    scanf("%d", &n);

    if(n > 4){
        printf("\nCannot solve for more than 4 variables at the moment, comming soon");
        exit(1);
    }

    // Taking in teh augumented matrix
    printf("\nEnter Coefficients of Augumented Matrix : \n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n+1; j++)
        {
            printf("\tA[%d][%d]: ", i, j);
            scanf("%f", &a[i][j]);
        }
        printf("\n");
    }

    //rearranging if needed, then performing Gauss Elimination.
    for(i = 0; i < n; i++)
    {
        //rearrange if needed.
        if(a[i][i] == 0){
            for(j = 0; j < n+1; j++)
            {
                temp = a[i][j];
                a[i][j] = a[i+1][j];
                a[i+1][j] = temp;
            }
        }

        //elimination part
        for(j = i+1; j < n+1; j++)
        {
            ratio = a[j][i] / a[i][i];
            for (k = 0; k < n+1; k++)
            {
                a[j][k] = a[j][k] - ratio*a[i][k];
            }
        }
    }

    printf("\nAfter Elimination.\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n+1; j++)
        {
            printf("\t%.3f", a[i][j]);
        }
        printf("\n");
    }


    //Backward Subs

    x[n-1] = a[n-1][n]/a[n-1][n-1];

    for(i = n-2 ; i >= 0; i--)
    {
        x[i] = a[i][n+1];
        for(j = i+1; j < n; j++)
        {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }

    for(i = 0; i < n; i++)
    {
        printf("\nx%d = %.3f", i, x[i]);
    }

    return 0;
}
