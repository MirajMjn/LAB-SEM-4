#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int fibo(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if(n == 2)
    {
        return 1;
    }
    else
    {
        return fibo(n-1) + fibo(n-2);
    }
}

void printfibo(int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        printf("%d, ", fibo(i));
    }
}

int main()
{
    int n;

    printf("\nTo display n terms of Fibonnaci Series, n = ? : ");
    scanf("%d", &n);

    printfibo(n);

    return 0;
}
