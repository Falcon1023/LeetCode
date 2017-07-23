#include <stdio.h>
#include <string.h>

const int N = 10001*100;

int main(){
  int S[N];
  int t,a,b,c,h,x;
  scanf("%d",&t);
  while(t--){
    memset(S,0,sizeof(S));
    scanf("%d%d%d",&a,&b,&c);
    scanf("%d%d",&h,&x);
    int min=-1;
    for(int i=a; i<=N; i++){
      if(S[i]<S[i-a]+1) S[i]=S[i-a]+1;
    }
    for(int i=b; i<=N; i++){
      if(S[i]<S[i-b]+2) S[i]=S[i-b]+2;
    }
    for(int i=c; i<=N; i++){
      if(S[i]<S[i-c]+5) S[i]=S[i-c]+5;
    }
    for(int i=1; i<=N; i++){
      if(min==-1&&S[i]>=h) min=i;
    }
    printf("%d\n%d\n",min,S[x]);
  }
  return 0;
}
