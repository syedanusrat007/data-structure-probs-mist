#include <stdio.h>
#include <stdlib.h>

 struct node{
   int data;
   struct node *next;


}*head;

 void insertFirst(int data)
 {
     struct node *cur;
     cur=(struct node *)malloc(sizeof(struct node));
     cur->data=data;
     cur->next=head;
     head=cur;
}
void insertlast(int data)
 {
     struct node *cur;
     cur=(struct node *)malloc(sizeof(struct node));
     cur->data=data;
     cur->next=NULL;
     struct node *prev=head;
     while(prev->next!=NULL)
     {
         prev=prev->next;
     }
     cur->next=NULL;
     prev->next=cur;
}
void insertmid(int data,int n)
 {
     struct node *cur;
     cur=(struct node *)malloc(sizeof(struct node));
     cur->data=data;
     cur->next=NULL;
     struct node *prev=head;
     while(prev->data!=n)
     {
         prev=prev->next;
     }
     cur->next=prev->next;
     prev->next=cur;
}

 void print()
 {
     struct node *p;
     p=head;
     if(head==NULL)

     {
         printf("empty\n");
     }
     while(p!=NULL)
     {
         printf("%d ",p->data);
         p=p->next;
     }

 }
 void deleteFirst()
 {
     if(head == NULL)
        return;
     struct node *cur;
     cur=head;
     head=head->next;
     free(cur);
}
void deleteLast()
 {
     if(head == NULL)
        return;
     struct node *cur=head;
     struct node *prev=NULL;
     while(cur->next!=NULL){
        prev=cur;
        cur=cur->next;
     }
     if(prev->next!=NULL)
     {
         prev->next=NULL;
     }
     free(cur);
}
void deleteany(int x)
 {
     if(head == NULL)
        return;
    if(head==x)
        deleteFirst();
     struct node *cur=head;
     struct node *prev=NULL;
     while(cur->data!=x){
        prev=cur;
        cur=cur->next;
     }
     if(prev!=NULL)
     {
         prev->next=cur->next;
     }
     free(cur);
}
int find(int x)
 {
     if(head == NULL)
        return;

     struct node *cur=head;
     struct node *prev=NULL;
     while(head!=NULL){
        if(head->data==x)
        {
            return 1;
        }
        head=head->next;

     }
     return 0;


}
 int main()
 {

    head=NULL;
     printf("1. Insert 1st \n");
    printf("2. insert last\n");
    printf("3. insert mid\n");
     printf("4. delete  1st\n");
     printf("5. delete  last\n");
     printf("6. delete  mid\n");
     printf("7. find\n");
    printf("8. Print\n");


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
        else if(query==8)
        {
            printf("The list is: ");
            print();
            printf("\n");
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
            int n;
            printf("Provide a value n pos to insert: ");
            scanf("%d %d",&data,&n);
            insertmid(data,n);
        }
        else if(query==4)
        {
            deleteFirst();
        }
        else if(query==5)
        {
            deleteLast();
        }
        else if(query==6)
        {
            int m;
            scanf("%d",&m);

            deleteany(m);
        }
         else if(query==7)
        {
            int m;
            scanf("%d",&m);

            int a= find(m);
            if(a==1)
            {
                printf("f\n");
            }
            else {
               printf("not f\n");
            }
        }
    }
 }
