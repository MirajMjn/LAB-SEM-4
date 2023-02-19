// using linked list as a replacement for arrays

#include <stdio.h>
#include <stdlib.h>

void insert(int, int);
void delete(int);
void display();

typedef struct list
{
    char data;
    struct list *next_data;
    struct list *prev_data;
} d_list;

d_list *list_head = NULL;
d_list *new_list_element;
d_list *ptr;
d_list *temp;

char get 

void insert(int n) // insertion at end
{
	newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = n;
    int i = 1, position;

    if (list_head == NULL){
		head = new_list_element;
		new_list_element->prev_data = NULL;
		new_list_element->next_data = NULL;
	}else{
		ptr = head;
		while(ptr->next != NULL){
			ptr = ptr-next_data;
		}
		//at this point the ptr points to last data of list.
		ptr->next = new_list_element;
		new_list_element->prev_data = ptr;
		new_list_element->next_data = NULL;
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


int main(){

	return 0;
}
