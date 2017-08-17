#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

long long dp[100005];
long long num[100005];

int main() {
  long long n, tmp, m = 0;
  scanf("%lld", &n);
  memset(num, 0, sizeof(num));
  memset(dp, 0, sizeof(dp));
  
  for (int i = 0; i < n; i++) {
    scanf("%lld", &tmp);
    num[tmp]++;
    if (tmp > m) m = tmp;
  }
  dp[1] = num[1];

  for (int i = 2; i <= m; i++)
    dp[i] = max(dp[i-1], dp[i-2]+i*num[i]);

  printf("%lld\n", dp[m]);
  return 0;
}
