#include <stdio.h>
#include <string.h>

int map[11];
int count;

void dfs(int k,int n){
  if(k==n+1){
    count++;
    return;
  }else{
    for(int i=1;i<=n;i++){
      map[k]=i;
      int flag=1;
      for(int j=1;j<k;j++){
        if(map[j]==i||k-i==j-map[j]||k+i==j+map[j]){
          flag=0;
          break;
        }
      }
      if(flag)
        dfs(k+1,n);
    }
  }
}

int main(){
  int num;
  int t[11];
  for(int i=1;i<=10;i++){
    count=0;
    memset(map,0,sizeof(map));
    dfs(1,i);
    t[i]=count;
  }
  while(scanf("%d",&num),num){
    printf("%d\n", t[num]);
  }
}
