#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5

int q[MAXSIZE];
int rear =-1,front=-1;

int isQueueFull()
{
    if((rear+1)%MAXSIZE==front)
    {
        printf("QUEUE is Full\n");
        return 1;
    }
    else{
        return 0;
    }
}
int isQueueEmpty()
{
    if(rear == -1 && front ==-1)
    {
        printf("Queue is empty\n");
        return 1;
    }
    else{
        return 0;
    }
}
int queueSize()
{
    return rear-front;
}
void enqueue(int value)
{
    if(isQueueFull())
    {
        printf("Full\n");
        return;
    }
    if(isQueueEmpty())
    {
        rear=front=0;
    }
    else{
        rear=(rear+1)%MAXSIZE;

    }
    q[rear]=value;

}
int dequeue()
{
    if(isQueueEmpty())
    {
        printf("empty\n");
        return;
    }
    else if(rear==front)
    {
        rear=front=0;
    }
    else{
        front=(front+1)%MAXSIZE;

    }
}
void print()
{
    int index=(rear+MAXSIZE-front)%MAXSIZE+1,i;
    printf("Queue : \n");
    for (i=0;i<index;i++)
    {
        int c=(front+i)%MAXSIZE;
        printf("%d",q[c]);
        printf("\n");
    }
}

int main()
{
    int option,value,n;
    printf("Queue program!\n");

    do{
       printf("1.enquue\n");
    printf("2.dequeue\n");
    printf("3.display\n");
    printf("4.exit\n");
    printf("enter choice : \n");
    scanf("%d",&option);
    switch(option){

 case 1:
     printf("enter value\n");
     scanf("%d",&value);
     enqueue(value);
     break;
 case 2:
     n=dequeue();
     printf("dequeued value : %d\n",n);
     break;
case 3:
     print();
     break;
case 4:
     return 0;

    }

    }while(option!=4);

    return 0;
}
