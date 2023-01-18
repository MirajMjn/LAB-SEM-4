#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

int main()
{
	int gd = DETECT, gm;
	int ax, ay, bx, by, cx, cy, i, x, y;
	int triangle[8];
	int triangle4[8];
	int triangle3[8];
	int triangle2[8];
	int triangleT[8];

	initgraph(&gd, &gm, "c:\\turboc3\\bgi");

	printf("\nEnter a: ");
	scanf("%d", &triangle[0]);
	scanf("%d", &triangle[1]);
	printf("\nEnter b: ");
	scanf("%d", &triangle[2]);
	scanf("%d", &triangle[3]);
	printf("\nEnter c: ");
	scanf("%d", &triangle[4]);
	scanf("%d", &triangle[5]);

	triangle[6] = triangle[0];
	triangle[7] = triangle[1];

	line(getmaxx()/2, 0, getmaxx()/2, getmaxy());
	line(0, getmaxy()/2, getmaxx(), getmaxy()/2);

	for(i = 0; i < getmaxx(); i += 20)
	{
		outtextxy(i, getmaxy()/2, "|");
	}

	for(i = 0; i < getmaxy(); i += 20)
	{
		outtextxy(getmaxx()/2, i, "-");
	}

	setfillstyle(SOLID_FILL, YELLOW);
	fillpoly(4, triangle);
	delay(10);

	for(i = 1; i < 8; i+=2)
	{
		triangle4[i - 1] = triangle[i - 1];
		triangle4[i] = getmaxy() - triangle[i];
	}
	setfillstyle(HATCH_FILL, RED);
	fillpoly(4, triangle4);
	delay(10);

	for(i = 1; i < 8; i+=2)
	{
		triangle3[i - 1] = getmaxx() - triangle[i - 1];
		triangle3[i] = getmaxy() - triangle[i];
	}
	setfillstyle(HATCH_FILL, CYAN);
	fillpoly(4, triangle3);
	delay(10);

	for(i = 1; i < 8; i+=2)
	{
		triangle2[i - 1] = getmaxx() - triangle[i - 1];
		triangle2[i] = triangle[i];
	}
	setfillstyle(HATCH_FILL, GREEN);
	fillpoly(4, triangle2);
	delay(10);

	printf("\nTranslate triangle in Q1 by : ");
	scanf("%d", &x);
	scanf("%d", &y);

	for(i = 1; i < 8; i+=2)
	{
		triangleT[i - 1] = triangle[i - 1] + x;
		triangleT[i] = triangle[i] + y;
	}
	setfillstyle(SOLID_FILL, WHITE);
	fillpoly(4, triangleT);
	delay(10);

	getch();

	closegraph();

	return 0;
}
