#include <stdio.h>  
#include <string.h>

char order[50];  
int step[105];  
int main ()  
{  
  int t;  
  scanf("%d",&t);  
  while (t--) {
    memset(step,0,sizeof(step));  
    int n,i,sum=0; 
    scanf("%d",&n);
    for(i=0; i<n; i++) {
      scanf("%s",order);  
      if(order[0]=='L') {
        step[i]=-1;
      } else if(order[0]=='R') {
        step[i]=1;
      }else {
        scanf("%s",order);  
        int num;
        scanf("%d",&num);
        step[i]=step[--num];
      }
      sum += step[i];
    }
    printf("%d\n",sum);
  }
  return 0;
}
