#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int link;
};

struct node *top = 0;

struct node *getnode()
{
    struct node *tempnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data to be pushed");
    tempnode->link = NULL;
    return tempnode;
}

void push()
{
    struct node *newnode = getnode();
    if (top == 0)
    {
        top = newnode;
    }
    else
    {
        newnode->link = top;
        top = newnode;
    }
}

void pop()
{
    struct node *temp = top;
    if (top == 0)
    {
        printf("Nothing to delete\n");
    }
    else
    {
        top = temp->link;
        free(temp);
    }
}

void display()
{
    struct node *temp = top;
    if (top == NULL)
    {
        printf("Nothing to display\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d", temp->data);
            temp = temp->link;
        }
    }
}

void peek()
{
    if (top == 0)
    {
        printf("Nothing to print\n");
    }
    else
    {
        printf("%d", top->data);
    }
}

int main()
{
    int ch;
    for (;;)
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

        default:
        {
            printf("invalid choice");
            exit(0);
        }
        }
    }
}