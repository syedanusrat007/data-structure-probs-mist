#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} node;

void insert_begning(node *head,int data){
     node *newItem,*temp,*last;
     newItem=( node *)malloc(sizeof( node));
     newItem->data=data;
     if(head==NULL){
          head=newItem;	  head->prev=NULL;
          head->next=NULL;	  last=head;
     }
     else{
         temp=newItem;
         temp->prev=NULL;		temp->next=head;
         head->prev=temp;		head=temp;
     }
}

void insert(node *head, int data)
{
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

    head=head->next;
    while (head != NULL)
    {
        if(head->data==key)
        {
            return 1;
        }
        head=head->next;

    }
     return 0;

}
int insert_after(node *head,int data, int loc){
      node *temp,*newItem,*temp1,*last;
     newItem=( node *)malloc(sizeof(node));
     newItem->data=data;
         if(head==NULL){
           head=newItem;    head->prev=NULL;     head->next=NULL;  }
     else{
           temp=head;
           while(temp!=NULL && temp->data!=loc)
                 temp=temp->next;
           if (temp==NULL)
                printf("\n%d is not present in list ",loc);
           else{
           temp1=temp->next;   temp->next=newItem;   newItem->prev=temp;
          newItem->next=temp1;      temp1->prev=newItem;    }
     }
     last=head;
     while(last->next!=NULL)
           last=last->next;
}

void delete(node *head, int data)
{
     while (head->next != NULL && (head->next)->data != data) {
        head = head->next;
    }
     if(head->next == NULL) {
        printf("\nElement %d is not present in the list\n", data);
        return;
    }
     node *tmp = head->next;
     if(tmp->next == NULL) {
        head->next = NULL;
    } else {
        head->next = tmp->next;
        (head->next)->prev = tmp->prev;
    }
    tmp->prev = head;
     free(tmp);
      printf("\nElement %d has been deleted \n", data);


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
    printf("1. Insertlast\n");
    printf("5. Insertforstst\n");
    printf("6. Insertmid\n");
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
       else  if(query==5)
        {
            int data;
            printf("Provide a value to insert: ");
            scanf("%d",&data);
            insert_begning(start,data);
        }
        else  if(query==6)
        {
            int data,loc;
            printf("Provide a value to insert: ");
            scanf("%d%d",&data,&loc);
           insert_after(start,data,loc);
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
