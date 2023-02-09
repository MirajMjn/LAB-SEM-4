#include <stdio.h>

void TOH(int n, char source, char aux, char destination)
{
    if (n == 1){
        printf("\n\t%d : %c to %c", n, source, destination);
    } else {
        TOH(n-1, source, destination, aux);

        printf("\n\t%d : %c to %c", n, source, destination);

        TOH(n-1, aux, source, destination);
    }
}

int main()
{
    int n, i;

    char source = 'a';
    char destination = 'c';
    char aux = 'b';

    printf("\nEnter number of disks : ");
    scanf("%d", &n);

    TOH(n, source, aux, destination);

    return 0;
}
