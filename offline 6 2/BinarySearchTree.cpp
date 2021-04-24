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

struct treeNode * root;


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
    else
        return(getSize(node->left)+getSize(node->right)+1);
}
int getMinItem(struct treeNode * root) //returns the minimum item in the tree
{
    struct treeNode *now = root;
    if(now->left==0)
    {
        return now->item;
    }
    else
        return getMinItem(now->left);
    //write your codes here
}

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
            return FALSE_VALUE;
        }
    }
    if(prev==0)
    {
        if(temp->left==0 && temp->right==0)
        {
            root=0;
            return TRUE_VALUE;
        }

        else if(temp->left==0)
        {
            struct treeNode *t=root;
            root=root->right;
            free(t);
            return TRUE_VALUE;
        }

        else if(temp->right==0)
        {
            struct treeNode *t=root;
            root=root->left;
            free(t);
            return TRUE_VALUE;
        }
        else
        {
            int itm=getMinItem(temp->right);
            deleteItem(temp,itm);
            temp->item=itm;
            return TRUE_VALUE;
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
    else
    {
        int itm=getMinItem(temp->right);
        deleteItem(temp,itm);
        temp->item=itm;
        return TRUE_VALUE;
    }
    //write your code here, return TRUE, FALSE
}

int subtree_sum2(struct treeNode *t)
{
    if(t==NULL)
        return 0;
    else
    {
        return t->item + subtree_sum2(t->left) + subtree_sum2(t->right);
    }
}
int subtree_sum(int n)
{
    int l,r;



    struct treeNode*t=searchItem(root,n);
    if(t==NULL)
        return -1;
    else
    {
        return subtree_sum2(t);
    }

}




int getMaxItem(struct treeNode * root) //returns the maximum item in the tree
{
    struct treeNode* now = root;
    if(now->right==0)
    {
        return now->item;
    }
    else
        return getMaxItem(now->right);
    //write your codes here
}

int rangeSearch(struct treeNode * node, int leftBound, int rightBound) //returns number of items in the
{
    int count=0;
    if( node->item >= leftBound && node->item <= rightBound)
    {
        printf("%d ",node->item);
        count++;
    }
    if( node->left!=0 & node->item > leftBound) rangeSearch( node -> left, leftBound , rightBound );
    else if( node->right!=0 & node->item < rightBound )rangeSearch( node -> right, leftBound , rightBound );
    return count; //write your codes here
}


void printInOrder(struct treeNode * node, int height)
{
    if(node==0) return ;

    //print left sub-tree
    printInOrder(node->left, height-1);

    //print item
    for(int i=0; i<height; i++)printf("   ");
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
        printf("6. PrintInOrder. 7.Get Min number. 8.Get Max Number 9.Range search 10.num of node  11.exit.\n");

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
        else if(ch==7)
        {
            int i=getMinItem(root);
            printf("Min num  of tree = %d\n",i);
        }
        else if(ch==8)
        {
            int k= getMaxItem(root);
            printf("Max num  of tree = %d\n",k);
        }
        else if(ch==9)
        {
            // printf("enter left and right boundary\n");
            int a,b;
            scanf("%d",&b);
            //rangeSearch(root,a,b);
            a=subtree_sum(b);
            printf("%d ",a);
        }
        else if(ch==10)
        {

            int a=getSize(root);
            printf("Total num  of node = %d\n",a);
        }
        else if(ch==11)
        {

            break;
        }
    }

}

