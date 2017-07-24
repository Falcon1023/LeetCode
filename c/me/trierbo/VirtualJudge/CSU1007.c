#include <stdio.h>

int main(){
  int num,px,py,ax,ay,bx,by;
  scanf("%d",&num);
  while(num--){
    scanf("%d",&px);
    scanf("%d",&py);
    scanf("%d",&ax);
    scanf("%d",&ay);
    scanf("%d",&bx);
    scanf("%d",&by);
    if(px > ax && px < bx && py > ay && py < by)
      printf("Inside\n");
    else if(((px == ax || px == bx) && (py >= ay && py <= by)) || ((py == ay || py == by) && (px >= ax && px <= bx)))
      printf("On\n");
    else
      printf("Outside\n");
  }
}
