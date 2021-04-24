#include<stdio.h>
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
	//your code here
}

void InOrder(int node)
{
    if(node==0) return ;


    InOrder(left(node));
    display();


   InOrder(right(node));
}

void postorder(int node)
{
   //your code here
}

void buildHeap()
{
    int i;
	for ( i=heapSize/2; i>0; i--){
     percolateDown(i);

	}
	display();

}

void heapsort()
{
    buildHeap();
    int i,m;
    m=heapSize;
   for (i = 1 ;i< heapSize-1;i++){
   	heap[heapSize-i+1] = deleteMin();
     heapSize=m;
    display();

   }
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


int main()
{
	init();
    int choice, num;

    int n = 0;
    while(1)
    {
        printf("1. Insert item. 2. Delete item. 3. Display. \n");
        printf("4. Build heap. 5. heap sort. \n");
        printf("6. PrintPreOrder. 7.PrintInOrder. 8.PrintPostOrder 9.percolateDown 10.num of node  11.exit.\n");

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

            int b=deleteMin();
            printf(" elements to be deleted from the list: %d\n",b);
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
        /*else if(ch==6)
        {
            int h = calcNodeHeight(root);
            printf("\n--------------------------------\n");
            printInOrder(root, h);
            printf("--------------------------------\n");
        }*/
          else if(ch==7)
        {

             printf("InOrder\n");
             InOrder(heap[1]);
        }
        /*  else if(ch==8)
        {
           int k= getMaxItem(root);
             printf("Max num  of tree = %d\n",k);
        }*/
          else if(ch==9)
        {
             printf("Enter the elements to be down from the list: ");

            scanf("%d", &num);

            percolateDown(num);
        }
        /*else if(ch==10)
        {

            int a=getSize(root);
              printf("Total num  of node = %d\n",a);
        }*/
         else if(ch==11)
        {

            break;
        }
    }
	return 0;
}

