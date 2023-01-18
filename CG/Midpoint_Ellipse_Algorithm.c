#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void midptellipse(long rx, long ry, long xc, long yc)
{
	long dx, dy, d1, d2, x, y;
	x = 0;
	y = ry;
	// Initial decision parameter of region 1
	d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
	dx = 2 * ry * ry * x;
	dy = 2 * rx * rx * y;

	// For region 1
	while (dx < dy) {
		// Print points based on 4-way symmetry
		putpixel(xc + x, yc + y, 15);
		putpixel(xc - x, yc + y, 15);
		putpixel(xc + x, yc - y, 15);
		putpixel(xc - x, yc - y, 15);

		// Checking and updating value of
		// decision parameter based on algorithm
		if (d1 < 0) {
			d1 = d1 + dx + (ry * ry);
		}
		else {
			y--;
			dy = dy - (2 * rx * rx);
			d1 = d1 + dx - dy + (ry * ry);
		}
		x++;
		dx += (2 * ry * ry);
		delay(10);
	}

	// Decision parameter of region 2
	d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);

	// Plotting points of region 2
	while (y > 0) {
		// printing points based on 4-way symmetry
		putpixel(xc + x, yc + y, 15);
		putpixel(xc - x, yc + y, 15);
		putpixel(xc + x, yc - y, 15);
		putpixel(xc - x, yc - y, 15);

		// Checking and updating parameter
		// value based on algorithm
		if (d2 >= 0) {
			d2 = d2 + (rx * rx) - dy;
		}
		else {
			x++;
			dx = dx + (2 * ry * ry);
			d2 = d2 + dx - dy + (rx * rx);
		}
		y--;
		dy -= (2 * rx * rx);
	}
}

int main()
{
	int gd = DETECT, gm;
	long xc, yc, rx, ry;

	initgraph(&gd, &gm, "c:\\turboc3\\bgi");

	printf("\nEnter xc: ");
	scanf("%ld", &xc);
	printf("\nEnter yc: ");
	scanf("%ld", &yc);
	printf("\nEnter rx: ");
	scanf("%ld", &rx);
	printf("\nEnter ry: ");
	scanf("%ld", &ry);

	midptellipse(rx, ry, xc, yc);

	getch();

	closegraph();

	return 0;
}
