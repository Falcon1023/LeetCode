#include <stdio.h>

typedef struct Node
{
  unsigned int num;
  struct Node *left;
  struct Node *right;
}BSTNode;

void insert(BSTNode **node, unsigned int num) {
  if(*node == NULL) {
    BSTNode root;
    root.num = num;
    root.left = NULL;
    root.right = NULL;
    *node = &root;
  } else {
    if ((*node)->num > num) {
      insert(&((*node)->left),num);
    } else {
      insert(&((*node)->right),num);
    } 
  }
}

void preorder(BSTNode *root) {
  if(root) {
    printf("%u", root->num);
    preorder(root->left);
    preorder(root->right);
  }
}

int main() {
  int t;
  scanf("%d",&t);
  while(t--) {
    int n;
    scanf("%d",&n);
    BSTNode *root = NULL;
    while (n--) {
      unsigned num;
      scanf("%u",&num);
      insert(&root,num);
    }
    preorder(root);
  }
}
