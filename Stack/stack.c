#include <stdio.h>
#include <stdlib.h>
#define N 5
int top = -1;
int stack[N];

void push()
{
    int x;
    printf("enter number to be pushed in stack\n");
    scanf("%d", &x);
    if (top == N - 1)
    {
        printf("stack overflow\n");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("stack underflow\n");
    }
    else
    {
        top--;
    }
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("stack is empty\n");
    }
    else
    {
        for (i = top; i >= 0; i--)
        {
            printf("%d", stack[i]);
            printf("\n");
        }
    }
}

void peek()
{
    int item;
    if (top == -1)
    {
        printf("nothing to show\n");
    }
    else
    {
        item = stack[top];
        printf("element at the top of the stack is %d\n", item);
    }
}

int main()
{
    int ch;
    for(;;)
    {
        printf("enter 1 for PUSH\n");
        printf("enter 2 for POP\n");
        printf("enter 3 for DISPLAY\n");
        printf("enter 4 for PEEK\n");
        printf("enter your choice\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:

            push();
            break;

        case 2:

            pop();
            break;

        case 3:

            display();
            break;

        case 4:

            peek();
            break;

        default :
        {
            printf("invalid choice");
            exit(0);
        }
        }
    } 
}
