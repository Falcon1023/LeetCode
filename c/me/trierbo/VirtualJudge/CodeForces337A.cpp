#include <stdio.h>
#include <algorithm>

using namespace std;

int f[50];

int main() {
  int n,m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++)
    scanf("%d", &f[i]);
  sort(f, f+m);
  int min = INT_MAX;
  for (int i = 0; i <= m - n; i++)
    if (f[i+n-1] - f[i] < min)
      min = f[i+n-1] - f[i];
  printf("%d\n", min);
  return 0;
}
