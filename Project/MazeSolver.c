#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>

//Graph Data Structure ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static int radius = 5;
static int startx = 20;
static int starty = 20;
static int endx = 420;
static int endy = 420;
static int unit_cell;
static int count = -1;

int tos = -1;
int front = 0;
int rear = -1;

int queue[100];
int stack[100];
int traversal_order[100];

int stackEmpty(){
    int status;
    if (tos == -1){
        status = 1; //true
    }
    else{
        status = 0; //false
    }
    return status;
}

int stackFull(){
    int status;
    if (tos == MAXSIZE - 1){
        status = 1; //true
    }
    else{
        status = 0; //false
    }
    return status;
}

void push(int n){
    if (isFull()){
        exit(1);
    }
    else{
        tos ++;
        stack[tos] = n;
    }
}

int pop(){
    int value = 0;
    if (isEmpty()){
        exit(1);
    }
    else{
        value = stack[tos];
        tos--;
    }
    return value; ////
}

void search_stack_for(int n){
    int i;
    for (i = 0; i <= tos; i++){
        if(stack[i] == n){
			return 1;
		}
    }
	return 0;
}

int queueFull(){
    return (rear == MAXSIZE - 1 ? 1 : 0);
}

int queueEmpty(){
    return (rear < front ? 1 : 0);
}

void enqueue(int n){
    if(isFull()){
        exit(1);
    }
    rear++;
    queue[rear] = n;
    return;
}

int dequeue(){
    if(isEmpty()){
        exit(1);
    }
    int data = queue[front];
    front++;
    return data;
}

int search_queue_for(int n)
{
    int i;
    if(isEmpty()){
        return 0;
    }

    for(i = front; i <= rear; i++){
        if(queue[i] == n){
			return 1;
		}
    }

    return 0;
}

typedef struct coordinate{
    int x, y; // coordinate values

    int flag; /*
    0 = Standard Path node
    1 = Start node
    2 = Finish node */

    int status; // visited or unvisited, used during traversal.

	int proxy; // we will rename each node during traversal.

    //pointers to adjacent nodes
	struct coordinate *north;
	struct coordinate *east;
	struct coordinate *south;
	struct coordinate *west;

} node;

node *head = NULL;
node *ptr = NULL;
node *temp = NULL;
node *new_node = NULL;
node *start = NULL;

//Graph Operations ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int insertNode(int x_coord, int y_coord, char direction, int identifier){
    int status;
    new_node = (node*) malloc(sizeof(node));

    //data
    new_node->x = x_coord;
    new_node->y = y_coord;
    if(identifier == 1 || identifier == 2){
        new_node->flag = identifier;
    }else{
        new_node->flag = 0; // defaults to standard path.
    }

    if (head == NULL){
        head = new_node; // first node of graph.
		start = head; // saving the start node of graph
        status = 2;
    }else{
        //if a node already exists, traverse to that node,
        //else create node
        switch(direction){
            case 'w':
            case 'W':
                if(head->north != NULL && head->north->south == head){
                    head = head->north;
					status = -1 ;// indicates traversal was done
                }else if(head->north != NULL && head->north->south != head){
                    temp = head;
                    head = head->north;
                    head->south = temp;
                    temp->north = head;
                    status = 1;
                }else{
                    head->north = new_node;
                    new_node->south = head;
                    head = new_node;
                    status = 0;
                }
            break;

            case 'a':
            case 'A':
                if(head->west != NULL && head->west->east == head){
                    head = head->west;
                    status = -1;
                }else if(head->west != NULL && head->west->east != head){
                    temp = head;
                    head = head->west;
                    head->east = temp;
                    temp->west = head;
                    status = 1;
                }else{
                    head->west = new_node;
                    new_node->east = head;
                    head = new_node;
                    status = 0;
                }
            break;

            case 's':
            case 'S':
                if(head->south != NULL && head->south->north == head){
                    head = head->south;
                    status = -1;
                }else if(head->south != NULL && head->south->north != head){
                    temp = head;
                    head = head->south;
                    head->north = temp;
                    temp->south = head;
                    status = 1;
                }else{
                    head->south = new_node;
                    new_node->north = head;
                    head = new_node;
                    status = 0;
                }
            break;

            case 'd':
            case 'D':
                if(head->east != NULL && head->east->west == head){
                    head = head->east;
                    status = -1;
                }else if(head->east != NULL && head->east->west != head){
                    temp = head;
                    head = head->east;
                    head->west = temp;
                    temp->east = head;
                    status = 1;
                }else{
                    head->east = new_node;
                    new_node->west = head;
                    head = new_node;
                    status = 0;
                }
            break;

            default: //in case of unexpected entry.
                head = head;
                status = 13; //unexpected entry error.
        }
    }
    return status; //indicates new node created.
}

int deleteGraph(){




    return 0; //indicating function executed with no forseen issues.
}

//traversal
node* getNode(){
	return head;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int determine_orientation(int old_x, int old_y, int x, int y){
	int orientation;
		/*
		(1)facing right, <default>
		(2)facing up,
		(-1)facing left,
		(-2)facing down.
		*/
	if(old_x == x && old_y == y){
		//denotes start position.
		orientation = 1; // setting default value or starting orientation.
	}else{
		if(old_y == y){
			orientation = (x > old_x)? (1): (-1);
		}else{ //old_x == x
			orientation = (y > old_y)? (-2): (2);
		}
	}
	return orientation;
}

int check(int x, int y){
	if(x < startx || y < starty || x > endx || y > endy)
		return 0;
	else
		return 1;
}

int determine_id(int x, int y){
	int status;
	if(x == startx && y == starty){
		status = 1;
	}else if(x == endx && y == endy){
		status = 2;
	}else{
		status = 0;
	}
	return status;
}

void draw_maze(){
	char key;
	int status, check_edge, id;
	int n, u, loop = 1;
	int x, y, i;

	node* vertex;

	cleardevice();
	delay(10);
	printf("\nMaze Size: <1> 2x2 <2> 4x4 <3> 5x5 <4> 8x8 <5> 10x10 ");
	while(loop == 1){
		key = getch();
		switch(key){
			case '1':
				n = 2;
				loop = 0;
			break;

			case '2':
				n = 4;
				loop = 0;
			break;

			case '3':
				n = 5;
				loop = 0;
			break;

			case '4':
				n = 8;
				loop = 0;
			break;

			case '5':
				n = 10;
				loop = 0;
			break;

			default:
				loop =1;
		}
	}
	cleardevice();
	unit_cell = (endx - startx)/n;

	loop = 1;

	circle(startx, starty, radius);
	circle(endx, endy, radius);

	x = startx;
	y = starty;
	id = determine_id(x, y);
	insertNode(x, y, 'x', id);

	moveto(startx, starty);

	while(loop == 1){
		status = 0;
		check_edge = 0;
		id = 0;

		key = getch();

		switch(key){
			case 'a':
				if(check(x-unit_cell, y) == 1){
					count++;
					x = x-unit_cell;
					y = y;
					status = 1;
				}
			break;

			case 'w':
				if(check(x, y-unit_cell) == 1){
					count++;
					x = x;
					y = y-unit_cell; 1;
				}
			break;

			case 'd':
				if(check(x+unit_cell, y) == 1){
					count++;
					x = x+unit_cell;
					y = y;
					status = 1;
				}
			break;

			case 's':
				if(check(x, y+unit_cell) == 1){
					count++;
					x = x;
					y = y+unit_cell;
					status = 1;
				}
			break;
			case 27: // esc key resets the whole thing.
				cleardevice();
				circle(startx, starty, radius);
				circle(endx, endy, radius);
				count = 0;
				deleteGraph();
				moveto(startx, starty);
				x = startx;
				y = starty;
				status = 1;
			break;

			default:;
		}

		if(status == 1){
			id = determine_id(x, y);
			check_edge = insertNode(x, y, key, id);
			vertex = getNode();

			if(check_edge == 1 || check_edge == 0){
				lineto(vertex->x, vertex->y);
			}else{
				moveto(vertex->x, vertex->y);
			}
		}

		if(x == endx && y == endy){
			head->flag = 2;
			head = start;
			loop =0;
		}
	}
}

void bfs_span_tree(){
	int node_number = 0;
	int loop = 1;
	int i = -1;
	int j;
	int next, hold;
	node* vertex;

	front = 0;
	rear = -1;

	while(loop == 1){
		vertex = head;
		j=0;

		if(vertex->status!=2){
			node_number++;
			vertex->proxy = node_number;
			vertex->status = 2;
			i++
			traversal_order[i] = vertex->proxy;

			if(vertex->north != NULL){
				ptr = vertex->north;
				if(ptr->status!=1 && ptr->status!=2){
					node_number++;
					ptr->proxy = node_number;
					ptr->status = 1; //visited
					enqueue(node_number);
				}
			}
			if(vertex->east != NULL){
				ptr = vertex->east;
				if(ptr->status!=1 && ptr->status!=2){
					node_number++;
					ptr->proxy = node_number;
					ptr->status = 1; //visited
					enqueue(node_number);
				}
			}
			if(vertex->west != NULL){
				ptr = vertex->west;
				if(ptr->status!=1 && ptr->status!=2){
					node_number++;
					ptr->proxy = node_number;
					ptr->status = 1; //visited
					enqueue(node_number);
				}
			}
			if(vertex->south != NULL){
				ptr = vertex->south;
				if(ptr->status!=1 && ptr->status!=2){
					node_number++;
					ptr->proxy = node_number;
					ptr->status = 1; //visited
					enqueue(node_number);
				}
			}

			if(queueEmpty){
				loop = 0;
			}else{
				next = dequeue();
				hold = next;

				while(1){
					if(head->north->proxy == next){
						head = head->north;
						if (hold == next){
							break;
						}else{
							next = hold;
						}
					}else if(head->east->proxy == next){
						head = head->east;
						if (hold == next){
							break;
						}else{
							next = hold;
						}
					}else if(head->west->proxy == next){
						head = head->west;
						if (hold == next){
							break;
						}else{
							next = hold;
						}
					}else if(head->south->proxy == next){
						head = head->south;
						if (hold == next){
							break;
						}else{
							next = hold;
						}
					}else{
						next = traversal_order[j];
						j++;
					}
				}
			}
		}
	}

	head = start;
}

void maze(int m){
	int i = 0;
	int n = 0;
	int next ;
	int visited[100];

	tos = -1;

	//making the maze border
	setcolor(RED);
	setlinestyle(3, 0, 3);
	rectangle(startx - 10, starty - 10, endx + 10, endy + 10); // encloses a square of dimension 400 x 400

	//making maze path
	setcolor(LIGHTGRAY); // code : 7
	moveto(head->x, head->y);
	visited[n] = head->proxy;
	i++; n++;
	push(head->proxy);

	while(1){
		if(isVisited(head->north->proxy) == 1){

		}else if
	}




	for(i = 0; i < count+1 ; i ++){
		setlinestyle(0, 0, 1);
		key = key_order[count];
		switch (key) {
			case 'w':
			break;

			case 'a':
			break;

			case 's':
			break;

			case 'd':
			break;
		}
	}
}

int bot_color(int x, int y){

	int status;
	circle(x, y, radius);

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

	delay(20);

	return status;
}

void left_wall_algorithm(){
	int find = 1; //controlls the loop below
	int status; //holds the bot status
	int orientation;

	int x = startx; // the start coordinates.
	int y = starty;

	int old_x = x, old_y = y;

	int maze_color = getpixel(x, y); //detect maze color.

	while(find == 1)
	{
		//Traversal of Maze

		orientation = determine_orientation(old_x, old_y, x, y);
		/*
		(1)facing right,
		(2)facing up,
		(-1)facing left,
		(-2)facing down.
		*/
		old_x = x;
		old_y = y;
		switch (orientation)
		{
			case 1: //facing right.
				if(getpixel(x, y - 1) == maze_color){
					y--;
				}else if(getpixel(x + 1, y) == maze_color){
					x++;
				}else if(getpixel(x, y + 1) == maze_color){
					y++;
				}else{ // turn around i.e. dead end found.
					x--;
				}
			break;

			case -1: // facing left.
				if(getpixel(x, y + 1) == maze_color){
					y++;
				}else if(getpixel(x - 1, y) == maze_color){
					x--;
				}else if(getpixel(x, y - 1) == maze_color){
					y--;
				}else{ // turn around i.e. dead end found.
					x++;
				}
			break;

			case 2: // facing up.
				if(getpixel(x-1, y) == maze_color){
					x--;
				}else if(getpixel(x, y-1) == maze_color){
					y--;
				}else if(getpixel(x+1, y) == maze_color){
					x++;
				}else{ // turn around i.e. dead end found.
					y++;
				}
			break;

			case -2: // facing down.
				if(getpixel(x+1, y) == maze_color){
					x++;
				}else if(getpixel(x, y+1) == maze_color){
					y++;
				}else if(getpixel(x-1, y) == maze_color){
					x--;
				}else{ // turn around i.e. dead end found.
					y--;
				}
			break;

			default:;
		}

		status = refresh(x, y);
		if(status == 2 || status == 13)
		{
			break;
		}
	}
}

int main(){
	int gd = DETECT, gm, wait_for_key = 1, n;
	char key;

	initgraph(&gd, &gm, "c:\\turboc3\\bgi");

	// Darwing a maze.
	draw_maze();

	// determining traversal routes, i.e,
	// spanning tree using BFS.
	bfs_span_tree();

	maze();
	refresh(startx, starty);

	while (wait_for_key == 1) {
		key = getch();
		switch(key)
		{
			case 13: //enter
				wait_for_key = 0;
				left_wall_algorithm();
			break;
			case 27: //esc
				wait_for_key = 0;
			break;
			default:
				wait_for_key = 1;
		}
	}

	getch();
	cleardevice();
	closegraph();
	return 0;
}
