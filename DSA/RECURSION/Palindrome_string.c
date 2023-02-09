//to check if a string is a palindrome using recursion.

#include <stdio.h>
#include <string.h>

char rev(char string[], int n){
    if(n == 0){
        return string[n];
    }
    else{
        return strcat(string[n], rev(string, n-1));
    }
}

int main()
{
    char string[30], string_rev[30];
    int n;

    printf("\n Enter a string : ");
    scanf("%s", string);

    n = strlen(string);

    strcpy(string_rev, rev(string, n));

    printf("\n");
    puts(string_rev);

    return 0;
}
