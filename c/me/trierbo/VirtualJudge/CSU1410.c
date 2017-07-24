#include <stdio.h>

int main(){
  int T;
  long long x,y;
  scanf("%d",&T);
  while(T--){
    long long count = 0;
    scanf("%lld",&x);
    scanf("%lld",&y);
    while(x < y){
      if(x*2 > y){
	count+=y-x;
	y=x;
      }else{
	if(y%2){
	  count+=2;
	  y/=2;
	}else{
	  count++;
	  y/=2;
	}
      }
    }
    printf("%lld\n",count);
  }
}
