#include <stdio.h>

int main(){
  int num,N,D,pre,curr;
  scanf("%d",&num);
  while(num--){
    int count = 0;
    scanf("%d",&N);
    scanf("%d",&D);
    pre = 0;
    while(N--){
      scanf("%d",&curr);
      if(pre == 0 || curr - pre >= D){
	count++;
	pre = curr;
      }
    }
    printf("%d\n",count);
  }
}
