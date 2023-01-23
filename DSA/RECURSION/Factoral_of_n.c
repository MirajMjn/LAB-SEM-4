#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int facto(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    else
    {
        return n * facto(n - 1);
    }
}

int main()
{
    int n;

    printf("\nTo find factorial of : ");
    scanf("%d", &n);

    printf("\n%d ! = %d", n, facto(n));

    return 0;
}
