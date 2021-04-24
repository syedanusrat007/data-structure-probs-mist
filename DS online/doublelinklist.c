#include <stdio.h>
#include <stdlib.h>

struct node{
 int data;
 struct node *next;
 struct node *prev;

}*head,*last;
void insertFirst(int data)
{
    struct node *newiteam,*temp;
    newiteam=(struct node *)malloc(sizeof(struct node));
    if(head == NULL)
    {
        head=newiteam;
         head->prev=NULL;
        head->next=NULL;
        last=head;
    }
    else {
        temp=newiteam;
        temp->prev=NULL;
        temp->next=head;
        head->prev=temp;
        head=temp;

    }

}
void insertlast(int data)
{
    struct node *newiteam,*temp;
    newiteam=(struct node *)malloc(sizeof(struct node));
    if(head == NULL)
    {
        head=newiteam;
         head->prev=NULL;
        head->next=NULL;
        last=head;
    }
  else {
    last=head;
    while(last!=NULL)
    {
        last=temp;
        last=last->next;
    }
  }
  last=newiteam;
  temp->next=last;
  last->prev=temp;
  last->next=NULL;

}
void insertmid(int data)
{
    struct node *newiteam,*temp;
    newiteam=(struct node *)malloc(sizeof(struct node));
    if(head == NULL)
    {
        head=newiteam;
         head->prev=NULL;
        head->next=NULL;
        last=head;
    }
  else {
    last=head;
    while(last!=NULL)
    {
        last=temp;
        last=last->next;
    }
  }
  last=newiteam;
  temp->next=last;
  last->prev=temp;
  last->next=NULL;

}
void print()
{
     struct node *cur;
    cur=head;
    if(head==NULL)
    {
        return;
    }
  while(cur!=NULL){
        cur=cur->next;
        printf("%d ",cur->data);

  }

}

int main()
{
    head =NULL;
     printf("1. Insert first\n");
    printf("2. insert last\n");
     printf("3. insert mid\n");
    printf("4. Print\n");
    printf("5. Find\n");
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
            insertFirst(data);
        }
         else if(query==2)
        {
            int data;
            printf("Provide a value to insert: ");
            scanf("%d",&data);
            insertlast(data);
        }
         else if(query==3)
        {
            int data;
            printf("Provide a value to insert: ");
            scanf("%d",&data);
            insertmid(data);
        }


        else if(query==4)
        {
            printf("The list is: ");
            print();
            printf("\n");
        }

    }
    return 0;
}
