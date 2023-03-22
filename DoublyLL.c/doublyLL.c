#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
    int data;
    struct node *left, *right;
};

struct node *newnode, *head = 0;

struct node *getnode()
{
    struct node *tempnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data");
    scanf("%d", &tempnode->data);
    tempnode->left = 0;
    tempnode->right = 0;
    return tempnode;
}

void insertAtBeg()
{
    newnode = getnode();
    if (head == 0)
    {
        head = newnode;
    }
    else
    {
        head->left=newnode;
        newnode->right = head;
        head = newnode;
    }
}

void insertAtEnd()
{
    newnode = getnode();
    struct node *temp = head;
    while (temp->right != 0)
    {
        temp = temp->right;
    }

    temp->right = newnode;
    newnode->left = temp;
}

void insertAtPos()
{
    struct node *temp = head;
    newnode = getnode();
    int pos, i;
    printf("enter position to insert");
    scanf("%d", &pos);
    while (i < pos)
    {
        temp = temp->right;
    }
    newnode->right = temp->right;
    temp->right = newnode;
    newnode->left = temp;
}

void display()
{
    struct node *temp = head;
    while (temp != 0)
    {
        printf("%d", temp->data);
        temp = temp->right;
    }
}

void delFromBeg()
{
    struct node *temp = head;
    if (head == 0)
    {
        printf("nothing to delete");
    }
    else
    {
        head = temp->right;
        temp->left = 0;
    }
    free(temp);
}

void delFromEnd()
{
    struct node *temp = head;
    if (head == 0)
    {
        printf("nothing to delete");
        return;
    }
    while (temp->right != 0)
    {

        temp = temp->right;
    }
    temp->left->right = 0;
    free(temp);
}

void delFromPos()
{
    struct node *temp = head;
    int pos, i=1;
    printf("enter position to delete");
    scanf("%d", &pos);
    while (i < pos)
    {
        temp = temp->right;
        i++;
    }
    temp->left->right = temp->right;
    temp->right->left = temp->left;
    free(temp);
}

int main()
{

    int choice;
    for (;;)
    {
        printf("enter 1 to insert at the beginning\n");
        printf("enter 2 to insert at the end\n");
        printf("enter 3 to insert at the position\n");
        printf("enter 4 to delete at the beginning\n");
        printf("enter 5 to delete at the end\n");
        printf("enter 6 to delete at the position\n");
        printf("enter 7 to display data \n");
        printf("enter choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertAtBeg();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAtPos();
            break;

        case 4:
            delFromBeg();
            break;

        case 5:
            delFromEnd();
            break;

        case 6:
            delFromPos();
            break;

        case 7:
            display();
            break;

        default:
            printf("wrong choice");
            exit(0);
        }
    };
    return 0;
}