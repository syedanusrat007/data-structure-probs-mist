#include<stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

int heap[MAXSIZE]={-99999};
int heapsize;

void initi()
{
    heap[0]=0;
     heapsize=0;
}
int left(int i)
{
    return 2*i;
}
int right(int i)
{
    return 2*i+1;
}
int parent(int i)
{
    return floor(i/2);
}
int deletemin()
{
    int i=heap[1];
    heap[1]=heap[heapsize--];
    percolatedown(1);
    return i;
}
void percolatedown( int hole)
{
    int tmp=heap[hole];
    int target;
    while (2*hole<=heapsize )
    {
        int l=left(hole);
        int r=right(hole);
        if(r<=heapsize && heap[r]<heap[l])
           target=r;
        else
           target=l;
        if(heap[target]<tmp)
        {
            heap[hole]=heap[target];
            hole=target;
        }
       else
            break;
    }
    heap[hole]=tmp;
}
void insert(int x)
{
    int z=++heapsize;
    for(;z>1 && x<heap[z/2];z=z/2)
        heap[z]=heap[z/2];
    heap[z]=x;
}
void inorder(int node)
{
    if(node>heapsize) return;
    inorder(node*2);
    printf("%d ",heap[node]);
    inorder(node*2+1);

}
void preorder(int node)
{
    if(node>heapsize) return;
    printf("%d ",heap[node]);
    inorder(node*2);

    inorder(node*2+1);

}
void postorder(int node)
{
    if(node>heapsize) return;
    inorder(node*2);

    inorder(node*2+1);
    printf("%d ",heap[node]);

}
void buildheap()
{
    int i;
    for(i=heapsize/2;i>=1;i--)
        percolatedown(i);
    inorder(1);
}
void heapsort()
{
    buildheap();
    int m=heapsize,i;
    for(i=m;i<=m-1;i++)
        heap[m-i+1]=deletemin();
    heapsize=m;
    for(i=1;i<=heapsize;i++)
        printf("%d ",heap[i]);
    printf("\n");
}
void insertat(int index,int value)
{
    heap[index]=value;
    percolatedown(index);

}
int deleteany(int index,int data)
{
    int i=heap[index];
    heap[index]=heap[heapsize--];
    percolatedown(index);
    return data;
}

int main()
{
    initi();
    int n=0;
    while(1)
    {
        printf("\n1.insert 2.left node 3.parent node 4.parent node 5.delete \n");
        printf("6.inorder 7.pre order 8.post order 9.buildheap 10.heapsort \n");
        printf("11.insert at 12.delete any\n");

        int a;
        scanf("%d",&a);
        if(a==1)
        {
             printf("Enter the element to be inserted to the list : ");

            scanf("%d", &a);

            insert(a);
            n++;
        }
        else if(a==2)
        {

           int b,c;
           scanf("%d",&c);
           b=left(c);
           printf("%d\n",b);
        }
        else if(a==3)
        {

           int b,c;
           scanf("%d",&c);
           b=right(c);
           printf("%d\n",b);
        }
        else if(a==4)
        {
           int b,c;
           scanf("%d",&c);
           b=parent(c);
           printf("%d \n",b);
        }
        else if(a==5)
        {

             int b=deletemin();
             printf("%d has been deleted\n",b);
       }

         else if(a==6)
        {

             printf("Inorder\n");
             inorder(1);
        }
        else if(a==7)
        {

             printf("preorder\n");
             preorder(1);
        }
        else if(a==8)
        {

             printf("postorder\n");
             postorder(1);
        }
         else if(a==9)
        {

             printf("build heap :\n");
             buildheap();
        }
        else if(a==10)
        {

             printf("heap sort :\n");
             heapsort();
        }
         else if(a==11)
        {

             printf("enter index and value :\n");
             int b,c;
             scanf("%d%d",&b,&c);
             insertat(b,c);
        }
        else if(a==12)
        {

             printf("enter index and value :\n");
             int b,c;
             scanf("%d%d",&b,&c);
             int d=deleteany(b,c);
             printf("%d has been deleted\n",d);
       }
       else
        break;

    }
    return 0;
}
