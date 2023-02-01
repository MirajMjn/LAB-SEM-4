//Bresenham Line Drawing Algorithm (for +ve slopes)
// note that the following only works for 0 < m < 1 and m > 1.
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void BLA_line(int xa, int ya, int xb, int yb){
	int dx, dy, i, x, y, pk, temp, flip_axis = 0;

	dx = xb - xa;
	dy = yb - ya;

	//we interchange the axes so the code for |m| < 1 works for all cases.
	if(abs(dy) > abs(dx)){ // |m| > 1
		temp = ya;
		ya = xa;
		xa = temp;

		temp = yb;
		yb = xb;
		xb = temp;

		flip_axis = 1;
		//new values after axis interchange.
		dx = xb - xa;
		dy = yb - ya;
	}

	if(xa < xb){
		x = xa;
		y = ya;
	}
	else{
		x = xb;
		y = yb;
	}

	//initial decision parameter.
	pk = 2*dy - dx;
	(flip_axis == 1)? (putpixel(y, x, WHITE)): (putpixel(x, y, WHITE));
	delay(10);

	for(i = 0; i < abs(dx); i++){
		x++;
		if(pk < 0){
			pk = pk + 2*dy;
		}
		else{
			pk = pk + 2*dy - 2*dx;
			y++;
		}
		(flip_axis == 1)? (putpixel(y, x, WHITE)): (putpixel(x, y, WHITE));
		delay(10);
	}

}

int main()
{
	int gd = DETECT, gm, xa, ya, xb, yb;

	initgraph(&gd, &gm, "c:\\turboc3\\bgi");

	printf("xa : ");
	scanf("%d", &xa);
	printf("ya : ");
	scanf("%d", &ya);
	printf("xb : ");
	scanf("%d", &xb);
	printf("yb : ");
	scanf("%d", &yb);

	BLA_line(xa, ya, xb, yb);

	getch();
	cleardevice();
	closegraph();

	return 0;
}
