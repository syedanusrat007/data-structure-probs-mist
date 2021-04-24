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
void rightRotate()

{
    int i;
    if(head == NULL || head->next == NULL){

    }else{
        for(i=0;i<5;i++){
    struct node *cur = head;
int t1 = cur->data;
while(cur->next != NULL){
    int t2 = cur->next->data;
    cur->next->data = t1;
    t1 = t2;

    cur = cur->next;
}
head->data = t1;
    }
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
       printf("2.rotate\n");
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
           int data,i;
           printf("rotate : \n");

           rightRotate();
       }
       else if(n==3){
        printf("list: \n");
        print();
       }
   }

    return 0;


}
