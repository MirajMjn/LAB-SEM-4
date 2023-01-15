#include <stdio.h.>
#include <math.h>
#include <stdlib.h>

float f (float x)
{
	return (x*x - 4*x - 10);
}

float absolute(float n)
{
	return(n < 0 ? -1.0 * n : n);
}

float Secant(float x0, float x1, float e)
{
	float x2, error;
	int iteration = 0, loop = 1;
	while (loop == 1)
	{
		iteration ++;

        x2 = x1 - ( f(x1) * ( (x1 - x0)/( f(x1) - f(x0) ) ) );
		error = absolute((x2 - x1) / x2) ;

		printf("\n\nx2 = %f with E = %f, in Iteration %d", x2, error, iteration);

		x0 = x1;
        x1 = x2;

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
	float result, a, b, e, root, slope, fa, fb;
	int i;

	printf("\nEnter initial range : ");
	scanf("%f%f", &a, &b);

    printf("\nEnter acceptable error : ");
	scanf("%f", &e);

	/*
	Here in the while block below we make use of slope made by the initial
	guesses to determine whether to increase b or decrease a.
	*/
	while(f(a)*f(b) > 0)
    {
        fa = f(a);
        fb = f(b);
        slope = (fb - fa) / (b - a);

        if(slope > 0)
        {
            (fa > 0 && fb > 0)? a-- : b++ ;
        }
        else if(slope < 0)
        {
            (fa > 0 && fb > 0)? b++ : a-- ;
        }
        else{ // deals with infinite slope or zero slope cases.
            b++;
        }
    }

	printf("\nOperting with initial assumptions : x0 = %f, x1 = %f .", a, b);

    if(f(a) == 0){
        root = a;
    }

    else if(f(b) == 0){
        root = b;
    }

    else {
        root = Secant(a, b, e);
    }

	printf("\n\nThe Root by Secant method = %f", root);

	return 0;
}
