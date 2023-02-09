#include <stdio.h>

int func(int x, int n){
    if(n == 1){
        return x;
    }
    else{
        return x * func(x, n-1);
    }
}

int main()
{
    int x, n, ans;

    printf("\nEnter x : ");
    scanf("%d", &x);
    printf("\nEnter n : ");
    scanf("%d", &n);

    ans = func(x, n);

    printf("\nThe ans is : %d", ans);

    return 0;
}
