/*
Assignment designed by Md. Aashikur Rahman Azim, Lecturer, CSE, BUET
For query: aashikazim@gmail.com
*/

/*
Task1:
Complete the functions in stack.c file to run this main function successfully.
You don't need to change this mainStack.c file.
*/

#include<stdio.h>
#include "stack.c"

int main()
{
    int option,n, value;
    printf("C program to implement stack operations\n");
    do
    {
        printf("\n\n 1.Insert an element in stack");
        printf("\n 2.Delete an element from stack");
        printf("\n 3.Display stack");
        printf("\n 4.Exit");
        printf("\n Enter your choice: ");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            printf("\n Insert an element in stack");
            scanf("%d",&n);
            push(n);
            break;
        case 2:
            value = pop();
            printf("\n Popped element is: %d\n", value);
            break;
        case 3:
            display_stack();
            break;
        case 4:
            return 0;
        }

    }
    while(option!=4);

    return 0;
}
