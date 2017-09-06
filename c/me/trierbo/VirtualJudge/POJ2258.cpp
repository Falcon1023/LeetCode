#include <stdio.h>
#include <string.h>

int flag[25][25];
int road[25][25];
int n, m, max, cur;

void dfs(int node) {
  for (int i = 0; i < n; i++) {
    if (flag[node][i] == 0 && road[node][i] == 1) {
      flag[node][i] = 1;
      flag[i][node] = 1;
      cur++;
      dfs(i);
      flag[node][i] = 0;
      flag[i][node] = 0;
      cur--;
    }
  }
  if (cur > max)
    max = cur;
}

int main() {
  while (scanf("%d%d", &n, &m) == 2 && (n != 0 || m != 0)) {
    memset(flag, 0, sizeof(flag));
    memset(road, 0, sizeof(road));
    max = 0, cur = 0;
    int x, y;
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &x, &y);
      road[x][y] = 1;
      road[y][x] = 1;
    }
    for (int i = 0; i < n; i++) {
      dfs(i);
    }
    printf("%d\n", max);
  }
}
