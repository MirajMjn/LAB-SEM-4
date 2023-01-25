#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

int main()
{
	int gd = DETECT, gm;
	int x1, y1, x2, y2, d, f;

	initgraph(&gd, &gm, "c:\\turboc3\\bgi");

	printf("\nEnter x1, y1 : ");
	scanf("%d", &x1);
	scanf("%d", &y1);
	printf("\nEnter x2, y2 : ");
	scanf("%d", &x2);
	scanf("%d", &y2);
	printf("\nEnter depth : ");
	scanf("%d", &d);
	printf("\nCreate Top ? < 1 / 0 > : ");
	scanf("%d", &f);

	setfillstyle(HATCH_FILL, RED);

	bar3d(x1, y1, x2, y2, d, f);

	getch();

	closegraph();

	return 0;
}
