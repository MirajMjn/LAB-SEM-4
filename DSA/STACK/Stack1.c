#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAXSIZE 3
int tos = -1;
int stack[MAXSIZE];

int isEmpty()
{
    int status;
    if (tos == -1){
        status = 1; //true
    }
    else{
        status = 0; //false
    }
    return status;
}

int isFull()
{
    int status;
    if (tos == MAXSIZE - 1){
        status = 1; //true
    }
    else{
        status = 0; //false
    }
    return status;
}

void push(int n)
{
    if (isFull()){
        printf("\nSTACK FULL !");
    }
    else{
        tos ++;
        stack[tos] = n;
        printf("\nData Pushed");
    }
}

int pop()
{
    int value = 0;
    if (isEmpty()){
        printf("\nSTACK EMPTY !");
    }
    else{
        value = stack[tos];
        tos--;
    }
    return value; ////
}

int peek()
{
    int value = 0;
    if (isEmpty()){
        printf("\nSTACK EMPTY !");
    }
    else{
        value = stack[tos];
    }
    return value; ////
}

void display(){
    int i;
    for (i = 0; i <= tos; i++){
        printf("\nindex : %d -> %d", i, stack[i]);
    }
}

char prompt()
{
    system("cls");
    char c;
    printf("\nWhat would you like to do ? : \n -> Press <1> to Push \n -> Press <2> to Pop \n -> Press <3> to Peek \n -> Press <4> to check if empty \n -> Press <5> to check if full \n -> Press <6> to Display Stack \n -> Press <ESC> to Exit");
    c = getch();
    return c;
}

int main()
{
    int num = 0, option = 0, loop = 1;
    char c;

    while (loop == 1)
    {
        c = prompt();
        switch(c)
        {
            case 27 :
                exit(0); //properly terminate code.
            break;

            case '1':
                system("cls");
                printf("\nEnter Number to be PUSHED = ");
                scanf("%d", &num);
                push(num);
            break;

            case '2':
                system("cls");
                num = pop();
                printf("\nThe data POPPED from stack = %d", num);
            break;

            case '3':
                system("cls");
                num = peek();
                printf("\nThe data at top from stack = %d", num);
            break;

            case '4':
                system("cls");
                num = isEmpty();
                if(num == 1){
                    printf("\nStack is empty");
                }
                else {
                    printf("\nStack is NOT empty");
                }
            break;

            case '5':
                system("cls");
                num = isFull();
                if(num == 1){
                    printf("\nStack is full");
                }
                else {
                    printf("\nStack is NOT full");
                }
            break;

            case '6':
                system("cls");
                display();
            break;

            default:
                system("cls");
                printf("\nEnter Valid Option \n<Press any key to continue.>");
        }
        getch();
    }
    return 0;
}
