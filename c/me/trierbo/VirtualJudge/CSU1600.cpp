#include <stdio.h>
#include <math.h>

double num[4];
int flag = 0;

int eq(double a, double b) {
  if(fabs(a - b) <= 1e-10)
    return 1;
  return 0;  
}  

void dfs(int n) {
  if (flag || (n == 1 && eq(num[0], 24))) {
    flag = 1;
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      double tmp1 = num[i], tmp2 = num[j];
      num[j] = num[n-1];
      num[i] = tmp1 + tmp2;
      dfs(n-1);
      num[i] = tmp1 - tmp2;
      dfs(n-1);
      num[i] = tmp2 - tmp1;
      dfs(n-1);
      num[i] = tmp1 * tmp2;
      dfs(n-1);
      if (!eq(tmp2 ,0)) {
        num[i] = tmp1 / tmp2;
        dfs(n-1);
      }
      if (!eq(tmp1, 0)) {
        num[i] = tmp2 / tmp1;
        dfs(n-1);
      }
      num[i] = tmp1;
      num[j] = tmp2;
    }
  }
}

int main() {
  while (scanf("%lf%lf%lf%lf", &num[0], &num[1], &num[2], &num[3]) == 4) {
    flag = 0;
    dfs(4);
    printf("%s\n", flag ? "Yes" : "No");
  }
}
