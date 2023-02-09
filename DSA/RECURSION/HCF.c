#include <stdio.h>

int hcf(int n, int a, int b){
    if(n == 1){
        return n;
    }
    else{
        if (a % n == 0 && b % n == 0)
        {
            return n;
        }else{
            hcf(n-1, a, b);
        }
    }
}

int main()
{
    int a, b, ans, n;
    printf("\nEnter 2 integers : ");
    scanf("%d%d", &a, &b);

    n = (a < b)? (a): (b);

    ans = hcf(n, a, b);

    printf("\nThe hcf is : %d", ans);

    return 0;
}
