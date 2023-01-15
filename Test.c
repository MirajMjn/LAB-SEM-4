int main()
{
	float result, a, b, e, root, slope, fa, fb;
	int i;

	printf("\nEnter initial range : ");
	scanf("%f%f", &a, &b);

    printf("\nEnter acceptable error : ");
	scanf("%f", &e);

	while(f(a)*f(b) > 0)
    {
        fa = f(a);
        fb = f(b);
        slope = (fb - fa / (b - a);

        if(slope > 0)
        {
            (fa > 0 && fb > 0)? a-- : b++ ;
            // if (fa > 0 && fb > 0)
            // {
            //     a--;
            // }
            //
            // else
            // {
            //     b++;
            // }
        }
        else if(slope < 0)
        {
            (fa > 0 && fb > 0)? b++ : a-- ;
            // if (fa > 0 && fb > 0)
            // {
            //     b++;
            // }
            //
            // else
            // {
            //     a--;
            // }
        }
        else{ // deals with infinite slope or zero slope cases.
            b++;
        }
    }

    if(f(a) == 0){
        root = a;
    }

    else if(f(b) == 0){
        root = b;
    }

    else {
        root = Secant();
    }

	printf("\n\nThe Root by Secant method = %f", root);

	return 0;
}
