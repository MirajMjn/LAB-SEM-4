#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

int main()
{
	int gd = DETECT, gm;
	int x1 = 100, y1,  y = 300, x2, y2, d = 10, f = 1, i;
	int h[] = {50, 25, 70, 100, 10, 200, 70};
	int width = 20, gap = 50;

	initgraph(&gd, &gm, "c:\\turboc3\\bgi");

	line(x1, 100, x1, 300); // yaxixs
	line(x1, y, 500, y); // xaxis

	for(i = 0; i < 7; i++)
	{
		x1 = x1 + gap;
		x2 = x1 + width;

		y1 = y - h[i];
		y2 = y;

		setfillstyle(HATCH_FILL, RED);
		bar3d(x1, y1, x2, y2, d, f);
		delay(50);
	}

	getch();

	closegraph();

	return 0;
}
