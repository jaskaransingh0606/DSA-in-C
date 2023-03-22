#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=0, *newnode;

struct node *getnode()
{
    struct node *tempnode = (struct node *)malloc(sizeof(struct node));
    tempnode->next = 0;
    printf("enter data");
    scanf("%d", &tempnode->data);
    return tempnode;
}

void DelFromBeg()
{
    struct node *temp = head;
    if (head == 0)
    {
        printf("nothing to delete");
    }
    else
    {
        temp = head;
        head = temp->next;
        free(temp);
    }
}


void DelFromEnd()
{
    struct node *temp = head;
    struct node *prev = NULL;
    while (temp->next != NULL)
    {
        prev= temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void DelFromPos()
{
    struct node *temp = head;
    struct node *prev = NULL;
    int pos, i;
    printf("enter position");
    scanf("%d", &pos);
    for (i = 0; i < pos - 1; i++)
    {
        prev= temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
}

void insertAtBeg()
{
    struct node *temp = head;
    newnode = getnode();
    if (head == 0)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}

void insertAtEnd()
{
    if(head==0){
        insertAtBeg();
    }
    else{
    struct node *temp = head;
    int i;
    newnode = getnode();
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    }
}

void insertAtPos()
{
    struct node *temp = head;
    int pos, i = 1;
    newnode = getnode();
    while (i < pos)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void display()
{
    struct node *temp = head;
    while (temp != 0)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

int main()
{

    int choice;
    for (;;)
    {
        printf("enter 1 to insert at the beginning\n");
        printf("enter 2 to insert at the end\n");
        printf("enter 3 to insert at the position\n");
        printf("enter 4 to delete from the beginning\n");
        printf("enter 5 to delete at the end\n");
        printf("enter 6 to delete from specific position\n");
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
            DelFromBeg();
            break;
        case 5:
            DelFromEnd();
            break;
        case 6:
            DelFromPos();
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