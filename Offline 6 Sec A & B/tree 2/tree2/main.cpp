#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

static int lookup(struct node* node, int target) {
  // 1. Base case == empty tree
  // in that case, the target is not found so return false
  if (node == NULL) {
    return(false);
  }
  else {
    // 2. see if found here
    if (target == node->data) return(true);
    else {
      // 3. otherwise recur down the correct subtree
      if (target < node->data) return(lookup(node->left, target));
      else return(lookup(node->right, target));
    }
  }
}
void printTree(struct node* node) {
  if (node == NULL) return;
  printTree(node->left);
  printf("%d ", node->data);
  printTree(node->right);
}
void printPostorder(struct node* node) {
  if (node == NULL) return;
  // first recur on both subtrees
  printTree(node->left);
  printTree(node->right);
  // then deal with the node
  printf("%d ", node->data);
}
int hasPathSum(struct node* node, int sum) {
  // return true if we run out of tree and sum==0
  if (node == NULL) {
    return(sum == 0);
  }
  else {
  // otherwise check both subtrees
    int subSum = sum - node->data;
    return(hasPathSum(node->left, subSum) ||
           hasPathSum(node->right, subSum));
  }
}
void mirror(struct node* node) {
  if (node==NULL) {
    return;
  }
  else {
    struct node* temp;
    // do the subtrees
    mirror(node->left);
    mirror(node->right);
    // swap the pointers in this node
    temp = node->left;
    node->left = node->right;
    node->right = temp;
  }
}
void postorder(struct btnode *t)

{

    if (root == NULL)

    {

        printf("No elements in a tree to display ");

        return;

    }

    if (t->l != NULL)

        postorder(t->l);

    if (t->r != NULL)

        postorder(t->r);

    printf("%d -> ", t->value);

}

void
 preOrder(struct node* r)
{
    if(r!=NULL){
        printf("%d ", r->value);
        preOrder(r->left);
        preOrder(r->right);
    }
}

