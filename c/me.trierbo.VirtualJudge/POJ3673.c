#include <stdio.h>

int main(){
  int a,b,res=0;
  scanf("%d%d",&a,&b);
  while(a!=0){
    int m=a%10;
    a/=10;
    int temp=b;
    while(temp!=0){
      int n=temp%10;
      temp/=10;
      res+=m*n;
    }
  }
  printf("%d\n", res);
  return 0;
}
