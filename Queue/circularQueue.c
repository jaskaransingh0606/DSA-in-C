#include<stdio.h>
#include<stdlib.h>
#define N 5
int front=0;
int rear=0;
int queue[N];

    void enqueue()
    {
           int x;
        printf("enter element to enqueue");
        scanf("%d",&x);
        if((rear+1)%N==front)
        {
            printf("overflow\n");
        }
        else if(front==0&&rear==0)
        {
            front++;
            rear++;
            queue[rear]=x;
        }
        else
        {   
            rear=(rear+1)%N;
            queue[rear]=x;
        }
     
    }

    void dequeue()
    {
        if(rear==front)
        {
            printf("underflow\n");
        }
        else if(front==rear)
        {
            front=rear=0;
        }
        else{
            front=(front+1)%N;
        }
    }

    void display()
    {
        int i;
        if(rear==front)
        {
            printf("empty\n");
        }
        else
        {
            for(i=front; (i%N) != rear; i=(i+1)%N)
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