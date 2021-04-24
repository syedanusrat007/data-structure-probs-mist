#include<stdio.h>
#define MAXSIZE 5

int s[MAXSIZE];
int t=-1;


void push(int value);
int pop();
int isStackEmpty();
int isStackFull();
void display_stack();
int stackSize();




void push(int value)
{
   isStackFull();
   s[++t]= value;


}

int pop()
{
    isStackEmpty();
    t=t-1;
    return s[t];



}

int isStackEmpty()
{
    if (t==-1)
    {
        printf("Error: No element \n");
        return 1;
    }
    else{
        return 0;
    }
}

int isStackFull()
{
      if(t== MAXSIZE-1)
      {
          printf("Error: stack overflow\n");
          return 1;
      }
      else {
        return 0;
      }
}

int stackSize()
{
    return s[t];
}

void display_stack()
{
    int i;
	printf("Stack: ");
	if(t==-1)
    {
        printf("Stack is empty\n");
    }
    else{
	for(i = 0;i<=t;i++)
		printf("%d ",s[i]);
	printf("\n");
    }

}
