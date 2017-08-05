#include <stdio.h>
#include <string.h>

int vis[20];
int cir[20];

int isPrime( int num ) {
  int count = 0;
  for ( int i = 2; i < num-1; i++ ) {
    if ( num % i == 0 )
      count++;
  }
  if ( count == 0 )
    return 1;
  else
    return 0;
}

void dfs(int k, int n) {
  if( k == n + 1 ){
    for (int i=1; i<=n; i++) {
      printf("%d",cir[i]);
      if(i!=n)
        printf(" ");
      else
        printf("\n");
    }
    return;
  }
  for( int i = 2; i <= n; i++ ) {
    if ( vis[i] != 1 && isPrime(cir[k-1]+i)) {
      if ( k == n && !isPrime(i+cir[1])) {
        return;
      }
      vis[i]=1;
      cir[k]=i;
      dfs(k+1,n);
      vis[i]=0;
    }
  }
}

int main() {
  int n;
  int cou = 1;
  while(scanf("%d",&n)==1) {
    memset(vis,20,0);
    cir[1] = 1;
    vis[1] = 1;
    printf("Case %d:\n",cou);
    dfs(2,n);
    printf("\n");
    cou++;
  }
}
