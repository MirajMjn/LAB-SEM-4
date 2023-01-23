#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int sum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n + sum(n - 1);
    }
}

int main()
{
    int n;

    printf("\nFind sum of first n natural number, n = ? : ");
    scanf("%d", &n);

    printf("\nSum of %d natural numbers = %d", n, sum(n));

    return 0;
}
