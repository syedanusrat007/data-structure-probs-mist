#include<stdio.h>
#include<stdlib.h>

#define FALSE_VALUE 0
#define TRUE_VALUE 1


struct treeNode
{
    int item;
    struct treeNode * left; //points to left child
    struct treeNode * right; //points to right child
};
//int v=1,x=0;
struct treeNode * root;

int getMinItem(struct treeNode *node);

void initializeTree()
{
    root = 0;
}


struct treeNode * searchItem(struct treeNode * node, int item)
{
    if(node==0) return 0;
    if(node->item==item) return node; //found, return node
    struct treeNode * t = 0;
    if(item < node->item)
        t = searchItem(node->left, item); //search in the left sub-tree
    else
        t = searchItem(node->right, item); //search in the right sub-tree
    return t;
};


struct treeNode * makeTreeNode(int item)
{
    struct treeNode * node ;
    node = (struct treeNode *)malloc(sizeof(struct treeNode));
    node->item = item;
    node->left = 0;
    node->right = 0;
    return node;
};

struct treeNode * insertItem(struct treeNode * node, int item)
{
    if(node==0) //insert as the root as the tree is empty
    {
        struct treeNode * newNode = makeTreeNode(item);
        root = newNode;
        return newNode;
    }

    if(node->item == item) return 0; //already an item exists, so return NULL

    if(item < node->item && node->left==0) //insert as the left child
    {
        struct treeNode * newNode = makeTreeNode(item);
        node->left = newNode;
        return newNode;
    }

    if(item > node->item && node->right==0) //insert as the right child
    {
        struct treeNode * newNode = makeTreeNode(item);
        node->right = newNode;
        return newNode;
    }

    if(item < node->item)
        return insertItem(node->left, item); //insert at left sub-tree
    else
        return insertItem(node->right, item); //insert at right sub-tree
}



int calcNodeHeight(struct treeNode * node) //return height of a node
{
    if(node==0) return -1;
    int l, r;
    l = calcNodeHeight(node->left);
    r = calcNodeHeight(node->right);
    if(l>r) return l+1;
    else return r+1;
}


int calcHeight(int item) //return height of an item in the tree
{
    struct treeNode * node = 0;
    node = searchItem(root, item);
    if(node==0) return -1; //not found
    else return calcNodeHeight(node);
}

int getSize(struct treeNode * node)
{
    if(node==0)
        return 0;
    int l,r;
    l=getSize(node->left);
    r=getSize(node->right);
    return l+r+1;

}

/*struct treeNode * deleteItem(struct treeNode * node, int item)
{
    if(node==0){
        struct treeNode *s=0;
        v=0;
        return s;
    }


    if( item < node->item){
            //printf("finding 1\n");
        node->left = deleteItem( node->left , item);
    }

    else if( item > node->item){
            //printf("finding 2\n");
        node->right=deleteItem( node->right , item);
    }

    else if(item==node->item){
        if(node->left==0 && node->right==0){
                printf("in case 1\n");
                free(node);
                node=0;
        }

        else if(node->left==0){
            struct treeNode *temp=node;
            //node=node->right;
            node=node->right;
            free(temp);
        }
        else if( node->right == 0){
            struct treeNode *temp=node;
            node=node->left;
             free(temp);
        }
        else{
            struct treeNode *s,*n;
            int min1;
            n=node->right;
            min1=getMinItem(n);
            s=searchItem(n,min1);
            node->item=s->item;
            //printf("min : %d  s->item : %d  node->item : %d",min1,s->item,node->item);
            node->right=deleteItem(n,min1);
        }

    }
    return node;
    //write your code here, return TRUE, FALSE
}
*/

int deleteItem(struct treeNode * node, int item)
{
     struct treeNode *temp=node;
    struct treeNode *prev=0;
    while(temp!=NULL)
    {

        if(temp->item==item)
        {
            break;
        }
        if(temp->item > item )
        {
            prev=temp;
            temp=temp->left;
        }
        else if(temp->item < item )
        {
            prev = temp ;
            temp = temp->right ;
        }
		if(temp==NULL)
		{
			return 0;
		}
    }
    if(prev==0){
        if(temp->left==0 && temp->right==0){
            root=0;
            return 1;
        }

        else if(temp->left==0){
            struct treeNode *t=root;
            root=root->right;
            free(t);
            return 1;
        }

        else if(temp->right==0){
            struct treeNode *t=root;
            root=root->left;
            free(t);
            return 1;
        }
        else{
            int itm=getMinItem(temp->right);
            deleteItem(temp,itm);
            temp->item=itm;
            return 1;
        }
    }
    else if(temp->left==NULL && temp->right == NULL)
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
    else if(temp->left==NULL)
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
    else if(temp->right==NULL)
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
        int itm=getMinItem(temp->right);
        deleteItem(temp,itm);
        temp->item=itm;
        return 1;
    }
    //write your code here, return TRUE, FALSE
}


int getMinItem(struct treeNode *node) //returns the minimum item in the tree
{
    int s=getSize(root);
    if(s!=0){
    if(node->left==0)
        return node->item;
    getMinItem(node->left);
    }
    else
    {
        //printf("Tree is empty.\n");
        return 0;
    }
    //write your codes here
}

int getMaxItem(struct treeNode *node) //returns the maximum item in the tree
{
    int s=getSize(root);
    if(s!=0){
    if(node->right==0)
        return node->item;
    getMinItem(node->right);
    }
    else
    {
        //printf("Tree is empty.\n");
        return 0;
    }
    //write your codes here
}

int rangeSearch(struct treeNode * node, int leftBound, int rightBound) //returns number of items in the
{
    if(node->item>=leftBound && node->item<=rightBound && (node->left==0 && node->right==0))
        {
            return 1;
        }

    if((node->item <leftBound || node->item>rightBound)  )
        {
            int l,r;
           if(node->left==0 && node->right==0)
            return 0;

           else if(node->left==0 && node->right!=0){
                r=rangeSearch(node->right,leftBound,rightBound);
                return r;
           }
           else if(node->left!=0 && node->right==0){
                l=rangeSearch(node->left,leftBound,rightBound);
                return l;
           }
           else if(node->left!=0 && node->right!=0){
            l=rangeSearch(node->left,leftBound,rightBound);
            r=rangeSearch(node->right,leftBound,rightBound);
            return l+r;
           }
        }
     if(node->item>=leftBound && node->item<=rightBound && (node->right==0 && node->left!=0))
        {
            int l=rangeSearch(node->left,leftBound,rightBound);
            return l+1;
        }
     if(node->item>=leftBound && node->item<=rightBound && (node->left==0 && node->right!=0))
        {
            int r=rangeSearch(node->right,leftBound,rightBound);
            return r+1;
        }

    if(node->item>=leftBound && node->item<=rightBound ){
        int l,r;
        //printf("node->item = %d  node->left =%d  node->right=%d\n",node->item,node->left,node->right);
        l=rangeSearch(node->left,leftBound,rightBound);
        r=rangeSearch(node->right,leftBound,rightBound);

        //printf("node->item = %d  node->left =%d  node->right=%d\n",node->item,node->left,node->right);
        return l+r+1;
    }

    //write your codes here
}


void printInOrder(struct treeNode * node, int height)
{
    if(node==0) return ;

    //print left sub-tree
    printInOrder(node->left, height-1);

    //print item
    for(int i=0;i<height;i++)printf("   ");
    printf("%03d\n",node->item);

    //print right sub-tree
    printInOrder(node->right, height-1);
}



int main(void)
{
    initializeTree();
    while(1)
    {
        printf("1. Insert item. 2. Delete item. 3. Search item. \n");
        printf("4. Print height of tree. 5. Print height of an item. \n");
        printf("6. PrintInOrder. 7. exit. 8. Get size 9. Get minterm 10. Get maxterm \n11. Delete node 12. Range search\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(root, item);
        }
        else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            deleteItem(root, item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            struct treeNode * res = searchItem(root, item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            int height = calcNodeHeight(root);
            printf("Height of tree = %d\n", height);
        }
        else if(ch==5)
        {
            int item;
            scanf("%d", &item);
            int height = calcHeight(item);
            printf("Height of %d = %d\n", item, height);
        }
        else if(ch==6)
        {
            int h = calcNodeHeight(root);
            printf("\n--------------------------------\n");
            printInOrder(root, h);
            printf("--------------------------------\n");
        }
        else if(ch==6)
        {
            break;
        }
        else if(ch==8){
            printf("Size  : %d\n",getSize(root));
        }
        else if(ch==9){
            int m=getMinItem(root);
            printf("minterm is : %d \n",m);
        }
        else if(ch==10){
            int m=getMaxItem(root);
            printf("maxterm is : %d \n",m);
        }
        else if(ch==11){
                int m,v;
            scanf("%d",&m);
           v = deleteItem(root,m);
            if(v==1)
                printf("found\n");
            else
                printf("not found\n");
        }
        else if(ch==12){
                int l,r,x;
                printf("Enter bounds : \n");
        scanf("%d%d",&l,&r);
           x= rangeSearch(root,l,r);
           printf("%d\n",x);
        }
    }

}

