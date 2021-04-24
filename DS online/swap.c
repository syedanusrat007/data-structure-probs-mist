#include <stdio.h>
#include <stdlib.h>

struct node {
 int data;
 struct node *next;

}*head;
void insert(int data)
{
    struct node *cur,*prev;
    cur= (struct node *)malloc(sizeof(struct node));
    cur->data=data;
    cur->next=NULL;
    prev=head;
    if(head==NULL)
    {
        cur->next=head;
        head=cur;
    }
    else{
    while(prev->next!=NULL)
    {
        prev=prev->next;
    }
    cur->next=NULL;
    prev->next=cur;
    }

}
void pairWiseSwap()
{
    // If linked list is empty or there is only one node in list
    if(head == NULL || head->next == NULL){

    }else{
    struct node *cur = head;
int t1;
while(cur->next != NULL){
    int t2 = cur->data;
    cur->data = cur->next->data;
    cur->next->data=t1;

    cur = cur->next;
    break;
}

  head->data = t1;
    }
}

void print()
{
    if(head==NULL)
    {
        printf("EMPTY\n");
        return;
    }
    struct node *p;
    p=head;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main()
{
   head = NULL;
   while(1)
   {
       printf("1.insert\n");
       printf("2.swap\n");
       printf("3.print\n");
       printf("enter choice :\n");
       int n;
       scanf("%d",&n);
       if(n==1)
       {
           int data;
           printf("insert : \n");
           scanf("%d",&data);
           insert(data);
       }
        else if(n==2)
       {

           pairWiseSwap();
       }
       else if(n==3){
        printf("list: \n");
        print();
       }
   }

    return 0;


}

