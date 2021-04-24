#include <stdio.h>
#include <stdlib.h>

struct treenode{
  int item;
  struct treenode *parent;
  struct treenode *left;
  struct treenode *right;

};
 struct treenode *root;
  void initree()
  {
      struct treenode *root=0;
  }
  struct treenode *newtreenode(int item){
         struct treenode *node;
         node = (struct treenode *)malloc(sizeof(struct treenode));
         node->item=item;
         node->left=NULL;
         node->right=NULL;
         node->parent=NULL;
         return node;
  };
  struct treenode *inserttree(struct treenode *node,int item)
  {
     struct treenode *p;
	struct treenode *retNode;

	if(node == NULL)  {
	    node = newtreenode(item);
	    node->parent = p;
	    return node;
	}
	if(item <= node->item ) {
	    p = node;
	    node->left = insertTreeNode(node->left,item);
	}
	else {
	    p = node;
	    node->right = insertTreeNode(node->right,item);
	}
	return node;
  };
  int main()
  {
      initree();
      int num;
      scanf("%d",&num);
      inserttree(root,num);
  }
