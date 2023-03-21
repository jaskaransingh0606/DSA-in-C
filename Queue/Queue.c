#include<stdio.h>
#include<stdlib.h>
#define N 5
int front=-1;
int rear=-1;
int queue[N];

    void enqueue()
    {
           int x;
        printf("enter element to enqueue");
        scanf("%d",&x);
        if(rear==N-1)
        {
            printf("overflow\n");
        }
        else if(front==-1&&rear==-1)
        {
            front=rear=0;
            queue[rear]=x;
        }
        else
        {   
            rear++;
            queue[rear]=x;
        }
     
    }

    void dequeue()
    {
        if(front==-1&&rear==-1)
        {
            printf("underflow\n");
        }
        else if(front==rear)
        {
            front=rear=-1;
        }
        else{
            front++;
        }
    }

    void display()
    {
        int i;
        if(front==-1&&rear==-1)
        {
            printf("empty\n");
        }
        else
        {
            for(i=front;i<=rear;i++)
            {
                printf("%d\n",queue[i]);
            }
        }
    }

    int main()
{
    int ch;
    for(;;)
    {
        printf("enter 1 for ENQEUE\n");
        printf("enter 2 for DEQEUE\n");
        printf("enter 3 for DISPLAY\n");
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

        default :
        {
            printf("invalid choice");
            exit(0);
        }
        }
    } 
}