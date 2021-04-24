#include <cstdio>
#include <stdlib.h>
#include <iostream>
struct Tree{
  int data;
  struct Tree *parent;
  struct Tree *left;
  struct Tree *right;
  struct Tree *root;

};
 struct Tree *root;
 void init()
 {
     root=0;
 }

struct Tree *newTreeNode(int data)
{
	Tree *node ;
	node = (struct Tree *)malloc(sizeof(struct Tree));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;

	return node;
}

struct Tree* insertTreeNode(struct Tree *node, int data)
{
   if(node==NULL) {
    struct Tree *newnode=newTreeNode(data);
    root=newnode;
    return newnode;
   }
   if(node->data==data) return node;

   if(data < node->data && node->left==0)
   {
    struct Tree *newnode=newTreeNode(data);
    node->left=newnode;
    return newnode;
   }
	if(data > node->data && node->right==0)
   {
    struct Tree *newnode=newTreeNode(data);
    node->right=newnode;
    return newnode;
   }
   if(data>node->data)
    return insertTreeNode(node->right,data);
   else
    return insertTreeNode(node->left,data);


}
struct Tree *searchnode(struct Tree *node,int data){

 if(node==NULL)
    return 0;
   if(node->data==data) return node;
 if(data>node->data)
    return searchnode(node->right,data);
  else
     return searchnode(node->left,data);
};
void printTreeInOrder(struct Tree *node)
{

	if(node==NULL) return;
	printTreeInOrder(node->left);
	printf("%d ",node->data);

	printTreeInOrder(node->right);

}
int calcnodeheight(struct Tree *node)
{
    if(node==NULL) return -1;
    int r,l;
    l=calcnodeheight(node->left);
    r=calcnodeheight(node->right);
    if(l>r)
        return l+1;
    else
        return r+1;
}
int calcheight(int data){

  struct Tree *node=0;
  node=searchnode(root,data);
  if(node==0) return -1;
  else
    return calcnodeheight(node);

}
int getsize(struct  Tree *node)
{
    if(node==0) return 0;
    else
        return getsize(node->left)+getsize(node->right)+1;
}
int minnode(struct  Tree *root)
{
    struct Tree *node=root;
    if(node->left==0)
        return node->data;
     else
     return minnode(node->left);
}
int maxnode(struct Tree *root)
{
    struct Tree *node=root;
    if(node->right==0){
        return node->data;
    }
    else {
        return maxnode(node->right);
    }
}
int rangesearch(struct Tree *node, int a,int b)
{
    int c=0;
    if(node->data >=a && node->data<=b){
         printf("%d ",node->data);
        c++;
    }
    if(node->left!=0 & node->data >a) rangesearch(node->left,a,b);
    if(node->right!=0 & node->data <b) rangesearch(node->right,a,b);

   return c;
}
void printpreorder(struct Tree *node)
{
    if(node==NULL) return;
    printf("%d ",node->data);
    printpreorder(node->left);
    printpreorder(node->right);
}
void printpostorder(struct Tree *node)
{
    if(node==NULL) return;
   printpostorder(node->left);
    printpostorder(node->right);
    printf("%d ",node->data);
}
int succesorinorder(struct Tree *node)
{

    if(node->right!=NULL) return minnode(node->right);

     struct Tree *y=node->parent;
     if(y==NULL) return NULL;
     while(y!= NULL && node== y->right)
     {
         node=y;
         y=y->parent;
     }
     return y->data;

};
int predecessorinorder(struct Tree *node)
{
    if(node->left!=NULL) return maxnode(node->left);

    struct Tree *y=node->parent;
    while(y!=NULL && node==y->left)
    {
        node=y;
        y=y->parent;
    }
    return y->data;
}
void printreverse(struct Tree *node)
{
    if(node== NULL) return;
    if(node->left == NULL && node->right==NULL)
    {
        printf("%d ",node->data);
        return;
    }
    printreverse(node->right);
    printf("%d ",node->data);
    printreverse(node->left);
}
 int getlevel(struct Tree *node,int elmt,int lvl)
 {
     if(node==NULL) return 0;
     if(elmt==node->data) return lvl;
     else if(elmt>node->data)
        return getlevel(node->right,elmt,lvl+1);
     else if(elmt<node->data)
        return getlevel(node->left,elmt,lvl+1);
 }
 void miror(struct Tree *r)
 {
     if(r==NULL) return;
     miror(r->left);
     miror(r->right);
     struct Tree *tmp;
     tmp= r->right;
     r->right= r->left;
     r->left =tmp;

 }
 int lowestcomnancestor(struct Tree *node,struct Tree *p,struct Tree *q)
 {
     if(node==NULL)return 0;
     if(node->left==p||node->right==p||node->left==q||node->right==q) return node->data;
    int Left,Right;
     Left=lowestcomnancestor(node->left,p,q);
     Right=lowestcomnancestor(node->right,p,q);
     if(Left && Right) return node->data;
     else  return(Left)? Left :Right;
 }
 int calcdeptht(struct Tree *node,int data){


  if(data==node->data) return 0;

 if(data>root->data) return 1+calcdeptht(node->right,data);
  else if(data<root->data) return 1+calcdeptht(node->left,data);

}
int deleteItem(struct Tree * node, int data)
{

	struct Tree *temp=node;
    struct Tree *prev=0;

    if(prev==0){//root
        if(temp->left==0 && temp->right==0){//no child
            root=0;
            return 1;
        }

        else if(temp->left==0){//no left
            struct Tree *t=root;
            root=root->right;
            free(t);
            return 1;
        }

        else if(temp->right==0){ //no right
            struct Tree *t=root;
            root=root->left;
            free(t);
            return 1;
        }
        else{
            int itm=minnode(temp->right);//both child
            deleteItem(temp,itm);
            temp->data=itm;
            return 1;
        }
    }
    else if(temp->left==NULL && temp->right == NULL)//child node
    {
        if(prev->left==temp)
        {
            prev->left=NULL;
        }
        else
        {
            prev->right=NULL;
        }
        free(temp);
    }
    else if(temp->left==NULL)//no right
    {
        if(prev->left==temp)
        {
            prev->left=temp->right;
        }
        else
        {
            prev->right=temp->right;
        }
        free(temp);
    }
    else if(temp->right==NULL)//no left
    {
        if(prev->left==temp)
        {
            prev->left=temp->left;
        }
        else
        {
            prev->right=temp->left;
        }
        free(temp);
    }
    else {
        int itm=minnode(temp->right);//both
        deleteItem(temp,itm);
        temp-> data=itm;
        return 1;
    }
}
int sumofnode(struct Tree *node)
{
    if(node==NULL) return 0;
    else
        return node->data+sumofnode(node->left)+sumofnode(node->right);
}



  int main()

  {
      init();

      int num;
      int choice;
      while(1){
        printf("\n1.insert. 2.search 3.Inorder 4.height of iteam 5.height of node\n");
        printf("\n6.total node. 7.min node 8.max node 9.range search 10.pre order\n");
        printf("\n11.post order 12.successor 13.predecessor 14.reverse 15. level\n");
        printf("\n16.miror 17.LCA 18.delete 19.depth 20.sum\n");
        scanf("%d",&choice);
    if(choice==1){
      scanf("%d",&num);
      insertTreeNode(root,num);
            }
        else if(choice==2)
        {
             int item;
            scanf("%d", &item);
            struct Tree * res = searchnode(root, item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(choice==3)
        {
             printTreeInOrder(root);
        }
        else if(choice==4)
        {
             int item;
            scanf("%d", &item);
          int a = calcheight(item);
             printf("height of %d = %d\n",item,a);

        }
         else if(choice==5)
        {
          int a = calcnodeheight(root);
          int b=2*a-a;
             printf("total height =%d\n",a);

        }
         else if(choice==6)
        {

          int a = getsize(root);
             printf("total size =%d\n",a);

        }
        else if(choice==7)
        {
          int a = minnode(root);
             printf("min node =%d\n",a);

        }
        else if(choice==8)
        {
          int a = maxnode(root);
             printf("max node =%d\n",a);
        }
        else if(choice==9)
        {
            int b,c;
            scanf("%d %d",&b,&c);
           rangesearch(root,b,c);

        }
        else if(choice==10)
        {
             printpreorder(root);
        }
        else if(choice==11)
        {
             printpostorder(root);
        }
         else if(choice==12)
        {
          int b;
          scanf("%d",&b);
          struct Tree *node=searchnode(root,b);
          int a = succesorinorder(node);
           printf("successor =%d\n",a);
        }
        else if(choice==13)
        {
          int c;
          scanf("%d",&c);
          struct Tree *node=searchnode(root,c);
          int b = predecessorinorder(node);
             printf("predeccessor =%d\n",b);
        }
         else if(choice==14)
        {
         printreverse(root);
        }
        else if(choice==15)
        {
             int item;
            scanf("%d", &item);
          int a = getlevel(root,item,0);
             printf("level of %d = %d\n",item,a);

        }
         else if(choice==16)
        {
         miror(root);
        printTreeInOrder(root);
        }
        else if(choice==17)
        {
          int b,c;
          scanf("%d%d",&b,&c);
          struct Tree *node1=searchnode(root,b);
            struct Tree *node2=searchnode(root,c);
          int a = lowestcomnancestor(root,node1,node2);
           printf("LCA =%d\n",a);
        }
         else if(choice==18)
        {
          int b;
          scanf("%d",&b);
           struct Tree * res = searchnode(root, b);
            if(res!=0) {
                int a=deleteItem(root,b);
                printf(" has been deleted");
            }
            else printf("Not found.\n");}
         else if(choice==19)
        {
             int item;
            scanf("%d", &item);
          int a = calcdeptht(root,item);
             printf("height of %d = %d\n",item,a);

        }
       else if(choice==20)
        {
            int iteam;
            scanf("%d",&iteam);
          struct Tree *b;
          b=searchnode(root,iteam);
          int a = sumofnode(b);
             printf("total sum =%d\n",a);
        }
        else
            break;

      }
       return 0;
  }



