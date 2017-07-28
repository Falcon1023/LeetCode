#include <stdio.h>
#include <stdlib.h>

int flag;

typedef struct Node
{
  unsigned int num;
  struct Node *left;
  struct Node *right;
}BSTNode;

void insert(BSTNode **node, unsigned int num) {
  if(*node == NULL) {
    *node = malloc(sizeof(BSTNode));
    (*node)->num = num;
    (*node)->left = NULL;
    (*node)->right = NULL;
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
    if(!flag){
      printf("%u", root->num);
      flag = 1;
    } else
      printf(" %u", root->num);
    preorder(root->left);
    preorder(root->right);
  }
}

void inorder(BSTNode *root) {
  if(root) {
    inorder(root->left);
    if(!flag){
      printf("%u", root->num);
      flag = 1;
    } else
      printf(" %u", root->num);
    inorder(root->right);
  }
}

void postorder(BSTNode *root) {
  if(root) {
    postorder(root->left);
    postorder(root->right);
    if(!flag){
      printf("%u", root->num);
      flag = 1;
    } else
      printf(" %u", root->num);
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
    flag = 0;
    preorder(root);
    printf("\n");
    flag = 0;
    inorder(root);
    printf("\n");
    flag = 0;
    postorder(root);
    printf("\n");
    printf("\n");
  }
}
