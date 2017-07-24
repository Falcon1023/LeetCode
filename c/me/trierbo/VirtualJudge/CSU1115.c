#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
  int count;
  struct Node *next[26];
}Node;

Node* newNode(){
  Node* node;
  node=(Node*)malloc(sizeof(Node));
  node->count=1;
  for(int i=0;i<26;i++)
    node->next[i]=NULL;
  return node;
}

void insertNode(Node* node,char* name){
  Node* p;
  p=node;
  int len,pos;
  len=strlen(name);
  for(int i=0;i<len;i++){
    pos=name[i]-'a';
    if(p->next[pos]==NULL){
      p->next[pos]=newNode();
      p=p->next[pos];
    }else{
      p=p->next[pos];
      p->count++;
    }
  }
}

int searchNode(Node* node){
  Node* p;
  int sum=0;
  p=node;
  for(int i=0;i<26;i++){
    if(node->next[i]!=NULL){
      p=node->next[i];
      sum+=p->count;
      if(p->count>1)
	sum+=searchNode(p);
    }
  }
  return sum;
}

void freeNode(Node* node){
  if(node!=NULL){
    for(int i=0;i<26;i++)
      if(node->next[i]!=NULL)
	freeNode(node->next[i]);
    free(node);
  }
}

int main(){
  int m,n;
  char name[1000001];
  scanf("%d",&m);
  while (m--) {
    Node* node=newNode();
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      scanf("%s",name);
      insertNode(node,name);
    }
    printf("%d\n",searchNode(node));
    freeNode(node);
  }
}
