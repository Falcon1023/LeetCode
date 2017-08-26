#include <stdio.h>

int n;
int p[20];
int w[20];
int seq[100];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", &p[i]);
    int num = 0;
    for (int i = 0; i < p[0]; i++)
      seq[num++] = 0;
    seq[num++] = 1;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < p[i] - p[i-1]; j++)
        seq[num++] = 0;
      seq[num++] = 1;
    }
    int wnum = 0;
    for (int i = 0; i < num; i++) {
      if (seq[i] == 1) {
        for (int j = i - 1; j >= 0; j--) {
          if (seq[j] == 0) {
            w[wnum++] = (i - j + 1) / 2;
            seq[j] = 1;
            break;
          }
        }
      }
    }
    for(int i = 0; i < wnum; i++)
      printf("%d%c", w[i],i == wnum-1 ? '\n' : ' ' );
  }
  return 0;
}
