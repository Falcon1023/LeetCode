#include <stdio.h>
#include <string.h>

char x[1001];
char y[1001];
int dp[1001][1001];

int main() {
  while(scanf("%s%s", x, y) == 2) {
     int xi = strlen(x);
     int yi = strlen(y);

     for (int i = 1; i <= xi; i++) {
       for (int j = 1; j <= yi; j++) {
         if (*(x+i-1) == *(y+j-1))
           dp[i][j] = dp[i-1][j-1] + 1;
         else {
           if (dp[i-1][j] >= dp[i][j-1])
             dp[i][j] = dp[i-1][j];
           else
             dp[i][j] = dp[i][j-1];
         }
       }
     }
     
     printf("%d\n", dp[xi][yi]);
  }
  return 0;
}
