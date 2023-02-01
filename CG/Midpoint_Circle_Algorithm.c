//Midpoint Circle ALgorithm.
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void plot(int xc, int yc, int x, int y){
	putpixel(xc + x, yc + y, 15);
	putpixel(xc - x, yc + y, 15);
	putpixel(xc + x, yc - y, 15);
	putpixel(xc - x, yc - y, 15);
	putpixel(xc + y, yc + x, 15);
	putpixel(xc - y, yc + x, 15);
	putpixel(xc + y, yc - x, 15);
	putpixel(xc - y, yc - x, 15);
}

void midptcircle(int xc, int yc, int r)
{
	int x = 0;
	int y = r;
	int p = 1 - r;

	plot(xc, yc, x, y);
	while(x < y)
	{
		x++;
		if(p < 0){
			p = p + 2*x + 1;
		}
		else{
			p = p + 2*x + 1 - 2*y;
			y--;
		}

		plot(xc, yc, x, y);
	}

}

int main()
{
	int gd = DETECT, gm;
	int xc, yc, r;

	initgraph(&gd, &gm, "c:\\turboc3\\bgi");

	printf("\nEnter xc: ");
	scanf("%d", &xc);
	printf("\nEnter yc: ");
	scanf("%d", &yc);
	printf("\nEnter r: ");
	scanf("%d", &r);

	midptcircle(xc, yc, r);

	getch();

	closegraph();

	return 0;
}
