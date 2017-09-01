#include <stdio.h>
#include <string.h>
#include <bitset>
#include <vector>

using namespace std;

#define MAX 101
vector<int> u[MAX];
bitset<MAX> rea[MAX];
int flag[MAX][MAX], vis[MAX], num, res, n, m;

void reach(int a, int v) {
  rea[a][a] = 1;
  for (size_t i = 0; i < u[a].size(); i++) {
    int b = u[a][i];
    if (b == v)
      continue;
    reach(b, a);
    rea[a] |= rea[b];
  }
}

void dfs(int a, int v) {
  if (a == vis[num])
    num++;
  if (num == m) {
    res = 1;
    return;
  }
  while (num < m) {
    int next = vis[num];
    int now = num;
    for (size_t i = 0; i < u[a].size(); i++) {
      int dot = u[a][i];
      if (dot == v)
        continue;
      if (rea[dot][next] && flag[a][dot]) {
        flag[a][dot] = 0;
        dfs(dot, a);
        break;
      }
    }
    if (num == now)
      break;
  }
}

int main() {
  int t, a, b;
  scanf("%d", &t);
  while (t--) {
    num = res = 0;
    scanf("%d", &n);
    memset(flag, 0, sizeof(flag));
    for (int i = 0; i < MAX; i++) {
      u[i].clear();
      rea[i].reset();
    }
    for (int i = 1; i < n; i++) {
      scanf("%d%d", &a, &b);
      u[a].push_back(b);
      u[b].push_back(a);
      flag[a][b] = flag[b][a] = 1;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
      scanf("%d", &vis[i]);
    reach(1, -1);
    dfs(1, -1);
    if (res)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
