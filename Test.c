#include <stdio.h>
#include <graphics.h>
#include <conio.h>

#define RADIUS 10
static const int startx = 20;
static const int starty = 20;
static const int endx = 420;
static const int endy = 420;
static const int unit_cell = 100;

void maze(){
	int x = 0, y = 0, i = 0;
	//node coodinates of the maze in order (x, y)
	int node[] = {20, 20, 120, 20, 120, 120, 20, 120, 120, 120, 120, 220, 20, 220, 20, 320, 20, 220, 120, 220, 120, 320, 220, 320, 120, 320, 120, 420, 120, 220, 220, 220, 220, 120, 220, 220, 420, 220, 420, 320, 320, 320, 420, 320, 420, 420};
	//making the maze border
	setcolor(RED);
	setlinestyle(3, 0, 3);
	rectangle(20 - 10, 20 - 10, 420 + 10, 420 + 10); // encloses a square of dimension 400 x 400

	//making maze path
	setcolor(LIGHTGRAY); // code : 7
	moveto(20, 20);
	while(x!=420 || y!=420)
	{
		x = node[i];
		i++;
		y = node[i];
		i++;
		setlinestyle(0, 0, 1);
		lineto(x, y);
	}
}

int bot_color(int x, int y){

	int status;
	circle(x, y, RADIUS);

	if(x == startx && y == starty){
		setfillstyle(SOLID_FILL, YELLOW);
		status = 1; // start
	}
	else if(x == endx && y == endy){
		setfillstyle(SOLID_FILL, LIGHTGREEN);
		status = 2; // end
	}
	else if(x > endx || y > endy || x < startx || y < starty){
		setfillstyle(SOLID_FILL, RED);
		status = 13; // out of bounds
	}
	else{
		setfillstyle(SOLID_FILL, DARKGRAY);
		status = 0; // on maze
	}
	floodfill(x+1, y+1, LIGHTGRAY);
	return status;
}

int refresh(int x, int y){
	int status;

	cleardevice();

	status = bot_color(x, y);

	maze();

	delay(30);

	return status;
}

void left_wall_algorithm(){
	int find = 1;
	int wait_for_key = 1;
	char key;
	int status;
	int x = startx;
	int y = starty;
	int maze_color = getpixel(x, y);

	refresh(x, y);

	while (wait_for_key == 1) {
		key = getch();
		switch(key)
		{
			case 13:
				wait_for_key = 0;
			break;
			default:
				wait_for_key = 1;
		}
	}

	while(find == 1)
	{
		//Traversal of Maze
		if (getpixel(x+1, y) == maze_color)
			x=x+1;
		else if(getpixel(x, y+1) == maze_color)
			y=y+1;
		else if(getpixel(x - 1, y) == maze_color)
			x=x-1;
		else if(getpixel(x, y-1) == maze_color)
			y=y-1;
		else{
			find = 0;
			break;
		}

		status = refresh(x, y);
		if(status == 2 || status == 13)
		{
			break;
		}
	}
}

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");

	// Darwing a maze.
	maze();

	// Trace the solution
	left_wall_algorithm();

	// Display the solution
	getch();
	closegraph();
	return 0;
}
