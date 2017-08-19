#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

typedef struct {
  double left;
  double right;
} Point;

Point point[1000];

int cmp(Point a,Point b){
  return a.left<b.left;
}

int main() {
  int n, cas = 1;
  double d, x, y;

  while(scanf("%d %lf", &n, &d) == 2 && (n != 0 || d != 0)) {
    int flag = 0, sum = 1;
    double tmp;
    if (d < 0)
      flag = 1;
    for (int i = 0; i < n; i++) {
      scanf("%lf %lf", &x, &y);
      point[i].left = x - sqrt(d*d - y*y);
      point[i].right = x + sqrt(d*d - y*y);
      if (y > d)
        flag = 1;
    }
    if (flag)
      printf("Case %d: -1\n", cas++);
    else {
      sort(point, point + n, cmp);
      tmp = point[0].right;
      for (int i = 1; i < n; i++) {
        if (tmp > point[i].right) {
          tmp = point[i].right;
        }
        if (point[i].left > tmp) {
          sum++;
          tmp = point[i].right;
        }
      }
      printf("Case %d: %d\n", cas++, sum);
    }
  }
}
