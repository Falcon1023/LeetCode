#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

int dis[8][2]={{1,0},{1,1},{1,-1},{0,1},{0,-1},{-1,0},{-1,1},{-1,-1}};
int flag[8][8];
int r1,c1,r2,c2,r3,c3;

struct Node
{
  int x,y;
  int step;
};

void bfs(Node node){
  queue<Node> q;
  Node cur,next;
  flag[node.x][node.y]=1;
  q.push(node);
  while (!q.empty()) {
    cur=q.front();
    q.pop();
    if(cur.x==r2&&cur.y==c2){
      printf("%d\n", cur.step);
      return;
    }
    for(int i=0;i<8;i++){
      next.x=cur.x+dis[i][0];
      next.y=cur.y+dis[i][1];
      if(!flag[next.x][next.y]&&next.x>=0&&next.x<8&&next.y>=0&&next.y<9){
        
      }
    }
  }
}

int main(){
  while(scanf("%d%d%d%d%d%d",&r1,&c1,&r2,&c2,&r3,&c3)==6){
    memset(flag,0,sizeof(flag));
    
  }
}
