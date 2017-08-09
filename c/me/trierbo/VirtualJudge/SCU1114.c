#include <stdio.h>

int map[100][100];
int dp[100][100];
int flag[100];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++)
      scanf("%d", &map[i][j]);

  dp[0][0] = map[0][0];

  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j != 0) {
        if (dp[i-1][j-1] >= dp[i-1][j])
          dp[i][j] = dp[i-1][j-1] + map[i][j];
        else
          dp[i][j] = dp[i-1][j] + map[i][j];
      } else
        dp[i][j] = dp[i-1][j] + map[i][j];
    }
  }

  int max = 0;
  int m;
  for (int i = 0; i < n; i++)
    if (dp[n-1][i] > max) {
      max = dp[n-1][i];
      m = i;
    }

  flag[n-1] = map[n-1][m];

  for (int i = n-1; i > 0; i--) {
    if (dp[i][m] - map[i][m] == dp[i-1][m])
      flag[i-1] = map[i-1][m];
    else
      flag[i-1] = map[i-1][--m];
  }

  printf("%d\n", max);

  for (int i = 0; i < n - 1; i++)
    printf("%d ", flag[i]);
  printf("%d\n", flag[n-1]);
  return 0;
}
