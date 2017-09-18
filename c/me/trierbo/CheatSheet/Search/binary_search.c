#include <stdio.h>

typedef int elem_t;

int binary_search(const elem_t a[], const int n, const elem_t x) {
  int left = 0, right = n-1;
  int middle = (left + right) / 2;
  while (right >= left) {
    if (a[middle] == x) {
      return middle;
    } else if (a[middle] > x) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }
    middle = (left + right) / 2;
  }
  return -1;
}

int main() {
  elem_t a[] = {1, 3 , 6 , 8 , 9, 10};
  elem_t x;
  scanf("%d", &x);
  printf("%d\n", binary_search(a, 6, x));
}
