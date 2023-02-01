//Digital Differential Analyzer algorithm to draw a line.
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void DDA_line(int x0, int y0, int xn, int yn){
	int dx, dy, i;
	float incx, incy, steps, x, y;

	dx = xn - x0;
	dy = yn - y0;

	x = x0;
	y = y0;

	putpixel(x, y, WHITE);

	if(abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);

	incx = dx / steps;
	incy = dy / steps;

	for(i = 0; i < steps; i++){
		x += incx;
		y += incy;
		putpixel(x, y, WHITE);
	}
}

int main()
{
	int gd = DETECT, gm, x1, y1, x2, y2;

	initgraph(&gd, &gm, "c:\\turboc3\\bgi");

	printf("x1 : ");
	scanf("%d", &x1);
	printf("y1 : ");
	scanf("%d", &y1);
	printf("x2 : ");
	scanf("%d", &x2);
	printf("y2 : ");
	scanf("%d", &y2);

	DDA_line(x1, y1, x2, y2);

	getch();
    cleardevice();
	closegraph();

	return 0;
}
