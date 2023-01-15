#include <stdio.h.>
#include <math.h>
#include <stdlib.h>

float f (float x)
{
	return ( sin(x) + 3*x - 2 );
}

float g (float x)
{
    return ( (2 - sin(x)) / 3 ) ;
}

float absolute(float n)
{
	return(n < 0 ? -1.0 * n : n);
}

float FixedPI(float x0, float e, int n)
{
	float x1, error;
	int iteration = 0, loop = 1;
	while (loop == 1)
	{
		iteration ++;

        x1 = g(x0);
		error = absolute(f(x1)) ;

		printf("\n\nx1 = %f with E = %f, in Iteration %d", x1, error, iteration);

        x0 = x1;

		if(error < e)
        {
			loop = 0;
		}

		else if(iteration > n)
        {
            printf("\nDid Not Converge.");
            exit(1);
		}
	}

	return x1;
}

int main()
{
	float root, a, e;
	int i, n;

	printf("\nEnter x0 : ");
	scanf("%f", &a);

    printf("\nEnter acceptable error : ");
	scanf("%f", &e);

    printf("\nEnter how many iterations to check till : ");
	scanf("%d", &n);

	root = FixedPI(a, e, n);

	printf("\n\nThe Root by Fixed Point Iteration method = %f", root);

	return 0;
}
