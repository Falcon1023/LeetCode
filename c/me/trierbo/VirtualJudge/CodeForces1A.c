#include <stdio.h>
#include <math.h>

int main() {
  int n,m,a;
  scanf("%d%d%d",&n,&m,&a);
  printf("%ld\n",(long)ceil(1.0*n/a)*(long)ceil(1.0*m/a));
}
