//Code implementation of simple weighted graph where each node is assumed to have 4 branchouts/paths/links.
// (data1)<---(weight)---->(data2)

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node{
    int x;
    int y;

    int front_weight;
    struct node *front_link;

    int right_weight;
    struct node *right_link;

    int left_weight;
    struct node *left_link;

    int back_weight;
    struct node *back_link;
};

struct node *head = NULL;
struct node *ptr = NULL;
struct node *temp = NULL;
struct node *newNode;

void insert(int n, int pos)
{
    newNode = (struct node*) malloc(sizeof(struct node)); // dynamically create a new node
    newNode->data = n; // add the data to the new node.
    int i = 1, position;

    //placing the node in the singly linked list.
    switch (pos)
    {
        case 1:
            newNode->next_data = head; // previously 1st node is now pointed to by the newly made first node.
            head = newNode; // head points to the newly made node.
            newNode->prev_data = NULL; // there is no predecessor of the first data.
        break;

        case 2:
            newNode->next_data = NULL; // previously 1st node is now pointed to by the newly made last node.
            if (head == NULL){
                head = newNode;
                newNode->prev_data = NULL;
            }
            else{
                ptr = head;
                while(ptr->next_data != NULL)
                {
                    ptr = ptr->next_data;
                }

                ptr->next_data = newNode; // make the previously last node point to the newly made last node
                newNode->prev_data = ptr; //the new data at the end will point to prev end data as its predecessor.

            }
        break;

        default:
            system("cls");
            printf("\nInsert at position : ");
            scanf("%d", &position);
            if(position < 1){
                printf("\nPosition begins at 1.");
                break;
            }
            if(position == 1){
                insert(n, 1);
                break;
            }
            ptr = head;
            while(i < position-1)
            {
                ptr = ptr->next_data;
                i++;
            }
            temp = ptr->next_data; // holds the address of current data at pos.
            ptr->next_data = newNode; // makes the newly made data, data number pos.
            newNode->prev_data = ptr; // establishes predecessor of newnode.
            newNode->next_data = temp; // newly made data points to the prev pos data.
            temp->prev_data = newNode; // establishes previous pos data to say that newNode is its predecessor.
    }
}

void delete(int pos)
{
    int position, i = 1;
    switch (pos)
    {
        case 1:
            temp = head;
            head = head->next_data;
            if(head != NULL)
            {
                head->prev_data = NULL; //making the new first element point to null.
            }
            free(temp);
        break;

        case 2:
            ptr = head;
            if(head->next_data == NULL){
                free(ptr);
                head = NULL;
            }
            else{
                while(ptr->next_data != NULL)
                {
                    temp = ptr;
                    ptr = ptr->next_data;
                }
                temp->next_data = NULL;
                free(ptr);
            }
        break;

        default:
            system("cls");
            printf("\nDelete position : ");
            scanf("%d", &position);
            if(position < 1){
                printf("\nPosition begins at 1.");
                break;
            }
            if(position == 1){
                delete(1);
                break;
            }
            ptr = head;
            while(i < position)
            {
                temp = ptr;
                ptr = ptr->next_data;
                i++;
            }
            if(ptr == NULL){
                printf("\nNOT FOUND\n");
                getch();
                break;
            }
            temp->next_data = ptr->next_data;
            temp->next_data->prev_data = temp;
            free(ptr);
    }
}

void display()
{
    system("cls");
    ptr = head;

    if(head == NULL){
        printf("The List is empty.");
        return;
    }

    while(ptr != NULL)
    {
        printf("\n%d", ptr->data);
        ptr = ptr->next_data;
    }
}
