#include <stdio.h>

void display(int n, int a[], int b[], int c[]){
    int i;
    for(i = n-1; i >= 0; i--){
        printf("\n%d\t %d\t %d\t", a[i], b[i], c[i]);
    }
}

void TOH(int n, int source[], int* source_index, int aux[], int* aux_index, int destination[], int* dest_index)
{
    if (n == 1){
        destination[*dest_index] = source[*source_index];
        source[*source_index] = 0;
        *dest_index++;
        *source_index--;
    } else {
        TOH(n-1, source, source_index, destination, dest_index, aux, aux_index);

        destination[*dest_index] = source[*source_index];
        source[*source_index] = 0;
        *dest_index++;
        *source_index--;

        TOH(n-1, aux, aux_index, source, source_index, destination, dest_index);
    }
}

int main()
{
    int a[12];
    int index_a = 0;

    int b[12];
    int index_b = 0;

    int c[12];
    int index_c = 0;

    int n, i;

    printf("\nEnter number of disks : ");
    scanf("%d", &n);
    i = 1;
    for(index_a = n-1; index_a >= 0; index_a--){
        a[index_a] = i; // fill the source pole up with n disks.
        b[index_a] = 0;
        c[index_a] = 0;
        i++;
    }
    index_a = n-1;

    display(n, a, b, c);

    TOH(n, a, &index_a, b, &index_b, c, &index_c);

    printf("\n\n");

    display(n, a, b, c);

    return 0;
}
