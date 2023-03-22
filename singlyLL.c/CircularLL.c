#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>
struct node
{
    int data;
    struct node *next;
} ;
struct node *head = NULL, *newnode, *temp , *tail , *position ;

struct node *getnode()
{
    struct node *tempnode = (struct node *)malloc(sizeof(struct node));
    // tempnode->next = 0;
    printf("enter data");
    scanf("%d", &tempnode->data);
    return tempnode;
}

void DelFromBeg()
{
    temp = tail = head;
    if (head == NULL)
    {
        printf("nothing to delete");
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        head = temp->next;
        tail->next = head;
        free(temp);
    }
}

void DelFromEnd()
{
    tail = head;
    temp = NULL;
    while (tail->next != head)
    {
        temp = tail;
        tail = tail->next;
    }
    // while (temp->next != tail)
    // {
    //     temp = temp->next;
    // }
    temp->next = head;
    // tail = temp;

    free(tail);
}
void DelFromPos()
{
    position = head;
    int pos, i;
    printf("enter position");
    scanf("%d", &pos);
    for (i = 1; i < pos - 2; i++)
    {
        position = position->next;
    }
    for (i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    position->next = temp->next;
    free(temp);
}

void insertAtBeg()
{
    newnode = getnode();
    if (head == NULL)
    {
        head = newnode;
        head->next=head;
    }
    else
    {
        
         tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = newnode;
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
    newnode = getnode();
   
     tail = head;
    while (tail->next != head)
    {
        tail = tail->next;
    }
    tail->next = newnode;
    newnode->next = head;
    tail = newnode;
    }
}

void insertAtPos()
{
    newnode = getnode();
    temp = head;
    int pos, i = 1;
    printf("enter position");
    scanf("%d",&pos);

    

    while (i < pos - 1)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void display()
{
    if (head == 0) {
        printf("EMpty\n");
        return;
    }
    temp = head;
    do 
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }while (temp != head);
}

int main()
{

    int choice;
    for(;;)
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
            // printf("wrong choice");
            exit(0);
        }
    }
    return 0;
}