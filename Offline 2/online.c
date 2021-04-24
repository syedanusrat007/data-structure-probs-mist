#include <stdio.h>
#include<string.h>
#include "queue.c"
#include "stack.c"
 int main()
 {
     char a[100];
     int i;
     scanf("%s",a);
     printf("%s\n",a);
     int size = strlen(a);
     printf("SiZE %d\n",size);
     for( i = 0 ; i < size ; i++){

        push(a[i]);
        enqueue(a[i]);
    }
    while(!isQueueEmpty()){

         pop();

        display_queue();
        break;


    }
 }
