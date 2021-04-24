/*
Assignment designed by Md. Aashikur Rahman Azim, Lecturer, CSE, BUET
For query: aashikazim@gmail.com
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} node;


void insert(node *head, int data)
{
    //you code here
    //insert the node always in the last of the list
      node *newItem,*temp,*last;
     newItem=( node *)malloc(sizeof( node));
     newItem->data=data;
     if(head==NULL){
          head=newItem;	  head->prev=NULL;
          head->next=NULL;	  last=head;
     }
     else{
         last=head;
         while(last != NULL){
             temp=last;
             last=last->next;
         }
     last=newItem;	temp->next=last;
     last->prev=temp;	last->next=NULL;
     }

}
int find(node *head, int key)
{
    //your code here
    // if search key is found then return 1 else 0
}
void delete(node *head, int data)
{
    // your code here
    //delete the node which contains 'data'. And show an output to users that the node containing 'data' has been deleted.
    // Otherwise show users that node does not exist with that 'data'.
    node *old;
    if(head == old)
    head = old->next;
  
  
  if(old->next != NULL)
    old->next->prev = old->prev;
  
  
  if(old->prev != NULL)
    old->prev->next = old->next;     
  
  free(old);  
  return;

}
void print(node *head)
{
    if(head==NULL)
    {
        return;
    }
    printf("%d ",head->data);
    print(head->next);
}
int main()
{
    /* start always points to the first node of the linked list.
       temp is used to point to the last node of the linked list.*/
    node *start,*temp;
    start = (node *)malloc(sizeof(node));
    temp = start;
    temp -> next = NULL;
    temp -> prev = NULL;
    /* Here in this code, we take the first node as a dummy node.
       The first node does not contain data, but it used because to avoid handling special cases
       in insert and delete functions.
     */
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Print\n");
    printf("4. Find\n");
    while(1)
    {
        int query;
        printf("Choose a menu: ");
        scanf("%d",&query);
        if(query==1)
        {
            int data;
            printf("Provide a value to insert: ");
            scanf("%d",&data);
            insert(start,data);
        }
        else if(query==2)
        {
            int data;
            printf("Provide a value to delete: ");
            scanf("%d",&data);
            delete(start,data);
        }
        else if(query==3)
        {
            printf("The list is: ");
            print(start->next);
            printf("\n");
        }
        else if(query==4)
        {
            int data;
            printf("Provide a value to find: ");
            scanf("%d",&data);
            int status = find(start,data);
            if(status)
            {
                printf("Element Found\n");
            }
            else
            {
                printf("Element Not Found\n");

            }
        }
    }
    return 0;
}
