#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front=0, *rear=0;

struct node *getnode(){
    struct node *tempnode=(struct node *)malloc(sizeof(struct node));
    printf("enter data");
    scanf("%d",&tempnode->data);
    tempnode->next=NULL;
    return tempnode;
}

void enqueue(){
    struct node *newnode=getnode();
    if(front==0 && rear==0){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}

void dequeue(){
    struct node *temp=front;
    if(front==NULL && rear==NULL){
        printf("queue is empty\n");
    }
    else{
        front=temp->next;
        free(temp);
    }
}

void display(){
    struct node *temp=front;
    if(front==0 && rear==0){
       printf("queue is empty\n");
    }
    else{
        while(temp!=0){
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}

void peek(){
    if(front==NULL && rear==NULL){
        printf("Queue is empty\n");
    }
    else{
        printf("%d\n",front->data);
    }
}

int main()
{
    int ch;
    for(;;)
    {
        printf("enter 1 for ENQUEUE\n");
        printf("enter 2 for DEQUEUE\n");
        printf("enter 3 for DISPLAY\n");
        printf("enter 4 for PEEK\n");
        printf("enter your choice\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:

            enqueue();
            break;

        case 2:

            dequeue();
            break;

        case 3:

            display();
            break;

        case 4:

            peek();
            break;

        default :
        {
            printf("invalid choice\n");
            exit(0);
        }
        }
    } 
}