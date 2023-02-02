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

    // Taking in the augumented matrix
    printf("\nEnter Coefficients of Augumented Matrix : \n");
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n+1; j++){
            printf("\tA[%d][%d]: ", i, j);
            scanf("%f", &a[i][j]);
        }
        printf("\n");
    }

    if(a[0][0] == 0){
        printf("\nFirst element of Matrix cannot be zero, please re-enter.");
        exit(1);
    }

    for(i = 1; i < n; i++){
        for(j = i+1; j <= n; j++){
            ratio = a[j][i]/a[i][i];
            for(k = 1; k <= n+1; k++){
                a[j][k] =a[j][k] - ratio * a[i][k];
            }
        }
    }

    x[n] = a[n][n+1]/a[n][n];

    for(i = n-1 ; i >= 1; i--)
    {
        x[i] = a[i][n+1];
        for(j = i+1; j <= n; j++)
        {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }

    for(i = 1; i <= n; i++)
    {
        printf("\nx%d = %.3f", i, x[i]);
    }

    return 0;
}
