#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *head1,*head2;


void insert1(int data)
{
    //ei function e list:-1 er element insert kora hobe...ekhane insert last kora hocche...jekono insert korlei hobe..
     struct node* cur=head1;
     struct node* newitem=(struct node *)malloc(sizeof(struct node));
     newitem->data=data;
     if(head1->next==NULL)     // jodi list empty thake ,tahole ei if() condition e dhukbe.....
     {
         newitem->next=head1->next;
         head1->next=newitem;
         newitem->prev=head1;
     }
     else
     {
         while(cur->next!=NULL)    //last node khuje ber korte hobe....
         {
             cur=cur->next;
         }
         newitem->next=cur->next;  // ekhane cur->next= NULL...bcz cur hocche last node..
         cur->next=newitem;
         newitem->prev=cur;
     }

}


void insert2(int data)
{
    //ei function e list:-2 er element insert kora hobe...ekhane insert last kora hocche...jekono insert korlei hobe..
     struct node* cur=head2;
     struct node* newitem=(struct node *)malloc(sizeof(struct node));
     newitem->data=data;
     if(head2->next==NULL)     // jodi list empty thake ,tahole ei if() condition e dhukbe.....
     {
         newitem->next=head2->next;
         head2->next=newitem;
         newitem->prev=head2;
     }
     else
     {
         while(cur->next!=NULL)    //last node khuje ber korte hobe....
         {
             cur=cur->next;
         }
         newitem->next=cur->next;  // ekhane cur->next= NULL...bcz cur hocche last node..
         cur->next=newitem;
         newitem->prev=cur;
     }

}

void concatenate()
{
    //ei function e list:1 er sathe list:2 k join kore dibo...
    struct node *cur=head1;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->next=head2->next; // list:1 er last node er sathe list:2 er 1st node connect kore dicchi....
}
void sort_()
{
    int temp;
    struct node *cur=head1;  //list:1 & list:2 concatenate korar por shob element list:1 e thakbe ..so list:1 amader final list..tai list:1 k sort kore print korlei hobe...
    struct node *cur1=head1;
    while(cur->next!=NULL)  //bubble sorting..
    {
        cur=cur->next;
        cur1=head1;
        cur1=cur1->next;
        while(cur1->next!=NULL)
        {
            if(cur1->data<=cur1->next->data&&cur1->next!=NULL)
            {
                temp=cur1->data;
                cur1->data=cur1->next->data;
                cur1->next->data=temp;
            }
            cur1=cur1->next;
        }
    }

}
void print()
{
    //head3=head1;
    struct node *cur=head1;
    while(cur->next!=NULL)
    {
       cur=cur->next;
        printf("%d ",cur->data);

    }
}
int main()
{
    head1=(struct node *)malloc(sizeof(struct node)); //head1 list:1 er dummy node..head1 e kono data thakbe na..just 1st node k point korbe...
    head2=(struct node *)malloc(sizeof(struct node));//head2 list:2 er dummy node..head2 e kono data thakbe na..just 1st node k point korbe...
    head1->prev=NULL;
    head1->next=NULL;
    head2->prev=NULL;
    head2->next=NULL;

         printf("1. Insert in list:1 \n");
    printf("2. Insert in list:2\n");
    printf("3. Print\n");
    printf("4. exit\n");
    while(1)
    {
        int query;
        printf("Choose a menu: ");
        scanf("%d",&query);
        if(query==1)
        {
            int data;
            printf("Provide a value to insert in list:-1  : ");
            scanf("%d",&data);
            insert1(data);
        }
        else if(query==2)
        {
            int data;
            printf("Provide a value to insert in list:-2  : ");
            scanf("%d",&data);
            insert2(data);
    }
        else if(query==3)
        {
            concatenate(); //print korar age list:1 er sathe list:2 k join korte hobe..tai concatenate() funtion call kora hoise..
            sort_();       // concatenate korar por list:1 = list:1 + list:2 hobe ...then list:1 sort korte hobe..
            printf("The list is: ");
            print();
            printf("\n");
        }
        else if(query==4)
        {
            break;
        }
    }

}
