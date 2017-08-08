#include <stdio.h>

int n;
int a[1000], b[1000];

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    b[0] = 1;
    int max;
    for (int i=1; i<n; i++) {
        max = 0;
        for (int j=0; j<i; j++) {
            if(a[i] > a[j] && b[j] > max)
                max = b[j];
        }
        b[i] = max+1;
    }
    max = 0;
    for (int i=0; i<n; i++) {
      if (b[i] > max)
        max = b[i];
    }
    printf("%d\n", max);
    return 0;
}
