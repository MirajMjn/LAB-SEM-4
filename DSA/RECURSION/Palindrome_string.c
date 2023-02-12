//to check if a string is a palindrome using recursion.

#include <stdio.h>
#include <string.h>

int checkpalindrome(char string[], int start, int end){
    if(start >= end){
        return 1;
    }else{
        if(string[start] != string[end]
            && string[start] != string[end]+32
            && string[start] != string[end]-32){
            return 0;
        }else{
            checkpalindrome(string, start+1, end-1);
        }
    }
}

int main()
{
    char input_s[30];
    int status;

    printf("\n Enter a string : ");
    scanf("%s", input_s);

    status = checkpalindrome(input_s, 0, strlen(input_s)-1); // string, start, end

    if(status == 1){
        printf("\nIt is Palindrome");
    }else{
        printf("\nIt is NOT Palindrome");
    }

    return 0;
}
