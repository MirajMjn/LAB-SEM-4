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

int insertNode(int x_coord, int y_coord, char direction, int identifier = 0)
{
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
    }else{
        //if a node already exists, traverse to that node,
        //else create node
        switch(direction){
            case 'w':
            case 'W':
                if(head->north != NULL && head->north->south == head){
                    head = head->north;
                    status = -1 // indicates traversal was done
                }else if(head->north != NULL && head->north->south != head){
                    temp = head;
                    head = head->north;
                    head->south = temp;
                    temp->north = head;
                    status = -1;
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
                    status = -1;
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
                    status = -1;
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
                    status = -1;
                }else{
                    head->east = new_node;
                    new_node->west = head;
                    head = new_node;
                    status = 0;
                }
            break;

            default: //in case of unexpected entry.
                head = head;
                status = 1; //unexpected entry error.
        }
    }
    return status; //indicates new node created.
}

int deleteNode(char direction){

    /*
    we remove the
    */
    switch(direction){
        case 'w':
        case 'W':
            temp = head;
            head = head->south;
            temp->south == NULL;
            head->north == NULL;
        break;

        case 'a':
        case 'A':
            temp = head;
            head = head->east;
            temp->east == NULL;
            head->west == NULL;
        break;

        case 's':
        case 'S':
            temp = head;
            head = head->north;
            temp->north == NULL;
            head->south == NULL;
        break;

        case 'd':
        case 'D':
            temp = head;
            head = head->west;
            temp->west == NULL;
            head->east == NULL;
        break;

        default:
            return 1; // indicating an deletion issue.
    }
    if(head->north == NULL && head->west == NULL && head->east == NULL && head->south == NULL){
        head = temp;
    }
    if(temp->north == NULL && temp->west == NULL && temp->east == NULL && temp->south == NULL){
        free(temp);
    }

    return 0; //indicating function executed with no forseen issues.
}

//traversal
node* getNode(){

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
