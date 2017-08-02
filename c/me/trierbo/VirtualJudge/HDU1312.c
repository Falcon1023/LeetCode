#include <stdio.h>
#include <string.h>

char map[20][20];
int W, H, account;
int to[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

void dfs(int i,int j)  
{  
    account++;  
    map[i][j] = '#';  
    for(int k = 0; k<4; k++)  
    {  
        int x = i+to[k][0];  
        int y = j+to[k][1];  
        if(x < H && y < W && x >= 0 && y >= 0 && map[x][y] == '.')  
            dfs(x,y);  
    }  
}

int main() {
  int x,y;
  while(scanf("%d%d", &W, &H) == 2) {
    account = 0;
    getchar();
    if (W == 0 && H == 0)
      break;
    for(int i = 0; i < H; i++) {
      for(int j = 0; j < W; j++) {
        scanf("%c",&map[i][j]);
        if(map[i][j] == '@') {
          x = i;
          y = j;
        }
      }
      getchar();
    }
    dfs(x,y);
    printf("%d\n", account);
  }
  return 0;
}
