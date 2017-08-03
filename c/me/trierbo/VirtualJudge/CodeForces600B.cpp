#include <stdio.h>
#include <algorithm>
using namespace std;

int n,m;
int a[200000], b[200000];

int compare(const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

int binarySearch(int bi) {
  int low = 0;
  int high = n - 1;
  int middle = 0;
  if (n == 1) {
    if (bi < a[0])
      return 0;
    else
      return 1;
  }
  while (low < high) {
    middle = (low + high) / 2;
    if (a[middle] <= bi) {
      if(a[middle+1] > bi)
        return middle+1;
      if(middle+1 == high)
        return middle+2;
      low = middle;
    } else {
      high  = middle;
    }
  }
  return middle;
}

int main() {
  scanf("%d%d", &n, &m);
  int i = 0;
  int na = n, mb = m;
  while (na--) {
    scanf("%d", &a[i]);
    i++;
  }
  i = 0;
  while (mb--) {
    scanf("%d", &b[i]);
    i++;
  }
  sort(a, a+n);
  i = 0;
  while (m--) {
    printf("%d ", binarySearch(b[i]));
    i++;
  }
  return 0;
}


