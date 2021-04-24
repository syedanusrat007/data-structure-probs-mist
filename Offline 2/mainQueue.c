/*
Assignment designed by Md. Aashikur Rahman Azim, Lecturer, CSE, BUET
For query: aashikazim@gmail.com
*/

/*
Task2:
Complete the functions in queue.c file to run this main function successfully.
You don't need to change this mainQueue.c file.
*/

#include<stdio.h>
#include "queue.c"

int main()
{
    int option, n, value;
    printf("C program to implement queue operations\n");
    do
    {
        printf("\n 1.Insert an element in queue");
        printf("\n 2.Delete an element from queue");
        printf("\n 3.Display queue");
        printf("\n 4.Exit");
        printf("\n Enter your choice: ");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            printf("\n Insert an element in Queue");
            scanf("%d",&n);
            enqueue(n);
            break;
        case 2:
            value = dequeue();
            printf("\n Dequeued element is: %d\n", value);
            break;
        case 3:
            display_queue();
            break;
        case 4:
            return 0;
        }

    }
    while(option!=4);

    return 0;
}
