//to check if an int is a palindrome using recursion.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

int count = 1;

int rev(int n)
{
    if (n / 10 == 0)
    {
        return n;
    }
    else {
        return(rev(n/10) + (n%10)*pow(10, count++));
    }
}

int main()
{
    int n, a;

    printf("\nEnter a number : ");
    scanf("%d", &n);

    a = rev(n);
    printf("\n%d is ", n);
    (a == n)? (printf("Palindrome.")): (printf("NOT Palindrome."));

    return 0;
}
