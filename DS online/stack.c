#include<stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

int s[MAXSIZE];
int t=-1;

int isStackFull(){

if(t==MAXSIZE-1)
{
    printf("Stack is full\n");
    return 1;
}
else
    return 0;
}

void push(int value)
{
    isStackFull();
    s[++t]=value;
}
int isStackEmpty()
{
    if(t==-1)
    {
        printf("Stack is empty\n");
        return 1;
    }
    else{
        return 0;
    }
}
int pop(){

   isStackEmpty();
   return s[--t];
}
int stackSize()
{
    return s[t];
}
void print()
{
    printf("stack is : \n");
    int i;
    if(t==-1)
    {
       printf("Stack is empty\n");
    }

    else{
        for(i=0;i<=t;i++)
        {
            printf("%d ",s[i]);
            printf("\n");
        }

    }
}
int main()
{

    int option,n,value;
    printf("Stack program!\n");

    do{
      printf("1.push\n");
      printf("2.pop\n");
      printf("3.print\n");
      printf("4.exit\n");
      printf("enter choice\n");
      scanf("%d",&option);
      switch(option)
      {
      case 1 :
        printf("enter number:\n");
        scanf("%d",&value);
        push(value);
        break;

        case 2 :
           value=pop();
           printf("delete number:\n",value);
        break;

        case 3 :
            print();
            break;

        case 4 :
            return 0;
      }
      }while(option!=4);

      return 0;
    }

