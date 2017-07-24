#include <stdio.h>
#include <string.h>
#define N 1000001

int str1[N];
int str2[N];
int next[N];
int m,n;

void getNext()
{
  next[0] = -1;
  int pre = -1;
  for(int i=0;i<n;){
    if(pre==-1 || str2[i]==str2[pre]){
      pre++;
      i++;
      next[i]=pre;
    }else{
      pre=next[pre];
    }
  }
}

int kmp(){
  int i=0;
  int j=0;
  getNext();
  while(i<m&&j<n){
    if(j==-1 || str1[i]==str2[j]){
      i++;
      j++;
    }else
      j=next[j];
  }
  if(j==n)
    return i;
  else
    return -1;
}

int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&m);
    scanf("%d",&n);
    for(int i=0;i<m;i++){
      scanf("%d",&str1[i]);
    }
    for(int i=0;i<n;i++){
      scanf("%d",&str2[i]);
    }
    if(kmp()==-1)
      printf("-1\n");
    else
      printf("%d\n",kmp()-n+1);
  }
  return 0;
}
