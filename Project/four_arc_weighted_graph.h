#include <stdio.h>
#include <stdlib.h>

//Graph Data Structure ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

typedef struct coordinate{
    int x, y; // coordinate values

    int flag; /*
    0 = Standard Path node
    1 = Start node
    2 = Finish node */

    //weighted edges
    int north_weight;
    int east_weight;
    int south_weight;
    int west_weight;

    //pointers to adjacent nodes
    node *north;
    node *east;
    node *south;
    node *west;

} node;

node *head = NULL;
node *ptr = NULL;
node *temp = NULL;
node *new_node = NULL;

//Graph Operations ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int insertNode(int x_coord, int y_coord, char direction, int identifier = 0){
    
    //we simply traverse of the node were trying to get to is already created.
    switch(direction){
        case 'w':
        case 'W':
            if(head->north != NULL){
                head = head->north;
                return -1;
            }
        break;

        case 'a':
        case 'A':
            if(head->west != NULL){
                head = head->west;
                return -1;
            }
        break;

        case 's':
        case 'S':
            if(head->south != NULL){
                head = head->south;
                return -1;
            }
        break;

        case 'd':
        case 'D':
            if(head->east != NULL){
                head = head->east;
                return -1;
            }
        break;

        default:;
    }

    new_node = (node*) malloc(sizeof(node));

    //data
    new_node->x = x_coord;
    new_node->y = y_coord;
    if(identifier == 1 || identifier == 2){
        new_node->flag = identifier;
    }else{
        new_node->flag = 0; // defaults to standard path.
    }

    //pointer
    if(head == NULL){

    }else if(head->x == new_node->x){
        
    }
}

int deleteNode(){

}

//traversal
node* getNode(){

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~