#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

struct Data{
    float x;
    float y;
};

void clearScreen(){
    system("cls");
}

int main()
{
    float sum_y = 0, sum_x = 0, sum_xy = 0, sum_x2 = 0, x, y;
    int j, n;
    float a, b;
    struct Data dataset[10];

    printf("\nHow many sets of data are there ? : ");
    scanf("%d", &n);

    if (n <= 1){
        clearScreen();
        printf("\nCannot compute without data.");
        exit(1);
    }

    for(j = 0; j < n; j++)
    {
        printf("\nx%d = ", j);
        scanf("%f", &x);
        printf("\ny%d = ", j);
        scanf("%f", &y);

        dataset[j].x = x;
        dataset[j].y = y;


        sum_x += x;
        sum_y += y;
        sum_xy += x * y;
        sum_x2 += x * x;
    }

    b = (n*sum_xy - sum_x*sum_y) / (n*sum_x2 - sum_x*sum_x);
    a = (sum_y - b * sum_x) / n;

    printf("\na = %f", a);
    printf("\nb = %f", b);

    return 0;
}
