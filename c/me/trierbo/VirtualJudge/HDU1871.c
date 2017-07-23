#include <stdio.h>
#include <string.h>

int map[201][201];
int vis[201],dis[201];
const int MAX = 10000001;
int n,m;

void Dijkstra(int s,int e){
  int pos,min;
  memset(vis,0,sizeof(vis));
  vis[s]=1;
  for(int i=0;i<n;i++)
    dis[i]=map[s][i];
  for(int i=1;i<n;i++){
    min=MAX;
    for(int j=0;j<n;j++){
      if(dis[j]<min&&!vis[j]){
        pos=j;
        min=dis[j];
      }
    }
    vis[pos]=1;
    if(pos==e)
      return;
    for(int j=0;j<n;j++){
      if(dis[j]>dis[pos]+map[pos][j]&&!vis[j])
        dis[j]=dis[pos]+map[pos][j];
    }
  }
}

int main(){
  int a,b,x,s,t;
  while(scanf("%d%d",&n,&m)==2){
    for(int i=0;i<=200;i++){
      for(int j=0;j<=200;j++){
        if(i==j)
          map[i][j]=0;
        else
          map[i][j]=MAX;
      }
    }
    for(int i=0;i<m;i++){
      scanf("%d%d%d",&a,&b,&x);
      if(x<map[a][b])
        map[a][b]=map[b][a]=x;
    }
    scanf("%d%d",&s,&t);
    Dijkstra(s,t);
    printf("%d\n", dis[t]==MAX?-1:dis[t]);
  }
  return 0;
}
