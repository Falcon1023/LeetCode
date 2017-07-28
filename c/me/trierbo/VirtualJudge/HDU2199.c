#include <stdio.h>
#include <math.h>

double acc = 0.0001;

double cal(double x, double y) {
  return 8*pow(x,4)+7*pow(x,3)+2*pow(x,2)+3*x+6-y;
}

int main() {
  int t;
  double y;
  scanf("%d",&t);
  while(t--) {
    double min = 0;
    double max = 100;
    scanf("%lf",&y);
    if(cal(min,y) > 0 || cal(max,y) < 0)
      printf("%s\n", "No solution!");
    else {
      double x = (min + max)/2;
      while(fabs(cal(x,y)) > acc) {
        if(cal(x,y) > 0)
          max = x;
        else
          min = x;
        x = (min+max)/2;
      }
      printf("%.4lf\n", x);
    }
  }
  return 0;
}
