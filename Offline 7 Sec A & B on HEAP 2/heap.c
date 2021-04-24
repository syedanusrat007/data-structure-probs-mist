#include<stdio.h>
#include <stdlib.h>
//#include <bits/stdc++.h>
#define MAXSIZE 100

int heap[MAXSIZE] = {-99999};
int heapSize;
void init()
{
    heap[0] = 0;
    heapSize = 0;
}
int left(int i)
{
    return 2*i;
    //your code here
}
int right(int i)
{
    return 2*i+1;
    //your code here
}
int parent(int i)
{
    return floor(i/2);
    //your code here
}

int deleteMin()
{
  int x = heap[1];
  heap[1]=heap[heapSize--];
  percolateDown(1);
  return x;
//your code here
}
void percolateDown(int hole)
{
    int tmp=heap[hole];
    int target;
  while (2*hole <= heapSize) {
    int l = left(hole);
    int r = right(hole);
    if (r <= heapSize && heap[r] < heap[l])
       target = r;
    else
      target = l;
    if (heap[target] < tmp) {
      heap[hole] = heap[target];
      hole = target;
    }
    else
      break;
  }
  heap[hole] = tmp;

	//your code here
}

void insert(int x)
{
    int hole = ++heapSize;

  for( ; hole>1 && x < heap[hole/2] ; hole = hole/2)
      heap[hole] = heap[hole/2];
  heap[hole] = x;

   //your code here
}

void preorder(int node)
{
	if(node>heapSize)
    return;
   printf("%d ",heap[node]);
   preorder(node*2);
   preorder(node*2+1);

//your code here
}

void inorder(int node)
{ if(node>heapSize)
        return;
    inorder(node*2);
    printf("%d ",heap[node]);
    inorder(node*2+1);

}

void postorder(int node)
{
   if(node>heapSize)
        return;
    postorder(node*2);
    postorder(node*2+1);
    printf("%d ",heap[node]);

//your code here
}

void buildHeap()
{
    int i;
    for(i=heapSize/2;i>=1;i--)
    {
        percolateDown(i);
    }

   postorder(1);
}

void heapsort()
{
    buildHeap();
   int m=heapSize,i;
   for(i=1;i<=m-1;i++)
   {
       heap[m-i+1]=deleteMin();
   }
   heapSize=m;
   for(i=1;i<=heapSize;i++)
        printf("%d ",heap[i]);
    printf("\n");

//your code here
}
 void display()

{
   int i;
  if (heapSize == 0)

    {

        printf("Heap is empty \n");

        return;

    }

    for (i = 1; i <= heapSize; i++)

        printf("%d ", heap[i]);

    printf("\n");

}
void insertAt(int index,int value)
{

    int p,tmp,i;
    heap[index]=value;
    p=parent(index);
    percolateDown(index);

}


int main()
{
	init();
    int choice, num;

    int n = 0;
    while(1)
    {
        printf("\n1. Insert item. 2. Delete item. 3. Display. \n");
        printf("4. Build heap. 5. heap sort. \n");
        printf("6. PrintPreOrder. 7.PrintInOrder. 8.PrintPostOrder 9.InsertAT 10.exit.\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
          printf("Enter the element to be inserted to the list : ");

            scanf("%d", &num);

            insert(num);
            n++;

        }
        else if(ch==2)
        {
           if(heapSize>=1){
            int b=deleteMin();
            printf(" elements to be deleted from the list: %d\n",b);
           }
           else{
            printf("Error!\n");
           }
        }
        else if(ch==3)
        {
           display();
        }
        else if(ch==4)
        {

            printf("build heap\n");
            buildHeap();
        }
        else if(ch==5)
        {
            printf("Heap sort\n");


            heapsort();
        }
        else if(ch==6)
        {
              printf("preorder\n");
             preorder(1);
        }
          else if(ch==7)
        {

             printf("Inorder\n");
             inorder(1);
        }
         else if(ch==8)
        {
            printf("Postorder\n");
             postorder(1);
        }

         else if(ch==9)
        {
            int a,b;
            printf("Enter index and value");
            scanf("%d%d",&a,&b);
            insertAt(a,b);

        }
         else if(ch==10)
        {

            break;
        }
    }
	return 0;
}

