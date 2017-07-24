#include <stdio.h>
#include <math.h>

double derivative(double x,double y){
  return 42*pow(x,6)+48*pow(x,5)+21*pow(x,2)+10*x-y;
}

double F(double x,double y){
  return 6*pow(x,7)+8*pow(x,6)+7*pow(x,3)+5*pow(x,2)-y*x;
}

int main(){
  int t;
  double left,right,middle,y;
  scanf("%d",&t);
  while(t--){
    scanf("%lf",&y);
    if(derivative(100,y)<=0){
      printf("%.4lf\n",F(100,y));
      continue;
    }else if(derivative(0,y)>=0){
      printf("%.4lf\n",F(0,y));
      continue;
    }
    left=0;
    right=100;
    while(right-left>0.00001){
      middle=(right+left)/2;
      if(derivative(middle,y)<0)
	left=middle;
      else
	right=middle;
    }
    printf("%.4lf\n",F(middle,y));
  }
  return 0;
}
