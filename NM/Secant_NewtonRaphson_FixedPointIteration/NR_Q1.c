#include <stdio.h.>
#include <math.h>
#include <stdlib.h>

float f (float x)
{
	return (x * tan(x) - 1);
}

float f1 (float x)
{
    return (x * pow((1/cos(x)), 2) + tan(x)) ;
}

float absolute(float n)
{
	return(n < 0 ? -1.0 * n : n);
}

float NewtonRaphson(float x0, float e)
{
	float x1, error;
	int iteration = 0, loop = 1;
	while (loop == 1)
	{
		iteration ++;

        x1 = x0 - f(x0)/f1(x0);
		error = absolute((x1 - x0) / x1) ;

		printf("\n\nx1 = %f with E = %f, in Iteration %d", x1, error, iteration);

        x0 = x1;

		if(error < e)
        {
			loop = 0;
		}

		else if(iteration > 200)
        {
			exit(1);
		}
	}

	return x1;
}

int main()
{
	float root, a, e;
	int i;

	printf("\nEnter x0 : ");
	scanf("%f", &a);

    printf("\nEnter acceptable error : ");
	scanf("%f", &e);

	root = NewtonRaphson(a, e);

	printf("\n\nThe Root by Newton Raphson method = %f", root);

	return 0;
}
