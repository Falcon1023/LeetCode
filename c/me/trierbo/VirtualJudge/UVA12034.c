#include <stdio.h>

int dp[1001][1001];
int res[1001];
int modulo = 10056;

int main() {
  for (int i = 1; i <= 1000; i++)
    dp[i][1] = 1;
  res[1] = 1;
  for (int i = 2; i <= 1000; i++) {
    int sum = 1;
    for (int j = 2; j <= i; j++) {
      dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) * j % modulo;
      sum = (sum + dp[i][j]) % modulo;
    }
    res[i] = sum;
  }
    
  int t;
  int n;

  scanf("%d", &t);

  for(int p = 1; p <= t; p++) {
    scanf("%d", &n);
    printf("Case %d: %d\n", p, res[n]);
  }
  return 0;
}
