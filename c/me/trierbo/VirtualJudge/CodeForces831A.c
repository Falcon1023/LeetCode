#include <stdio.h>

int a[100];

int main() {
  int n, flag = -1;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  for (int i = 1; i < n; i++) {
    if (flag == -1) {
      if (a[i] == a[i-1])
        flag = 0;
      if (a[i] < a[i-1])
        flag = 1;
    } else if (flag == 0) {
      if (a[i] > a[i-1]) {
        printf("No\n");
        return 0;
      } else if (a[i] < a[i-1])
        flag = 1;
    } else {
      if (a[i] >= a[i-1]) {
        printf("No\n");
        return 0;
      }
    }
  }
  printf("YES\n");
  return 0;
}
