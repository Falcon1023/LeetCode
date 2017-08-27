#include <stdio.h>
#include <string.h>

int n,m;
char ch[16][16];
char s[51];

int check(int x, int y, char c) {
  int flag = 0;
  if (c == 'U') {
    if (x-1 >= 1 && (ch[x-1][y] == '.' || ch[x-1][y] == '+')) {
      ch[x-1][y] = ch[x-1][y] == '.' ? 'w' : 'W';
      ch[x][y] = ch[x][y] == 'W' ? '+' : '.';
      flag=1;
    } else if (x-2 >= 1 && (ch[x-1][y] == 'b' || ch[x-1][y] == 'B') &&  (ch[x-2][y] == '.' || ch[x-2][y] == '+')) {
      ch[x-2][y] = ch[x-2][y] == '+' ? 'B' : 'b';
      ch[x-1][y] = ch[x-1][y] == 'B' ? 'W' : 'w';
      ch[x][y] = ch[x][y] == 'W' ? '+' : '.';
      flag=1;
    }
  } else if (c == 'D'){
    if (x+1 <= n && (ch[x+1][y] == '.' || ch[x+1][y] == '+')) {
      ch[x+1][y] = ch[x+1][y] == '.' ? 'w' : 'W';
      ch[x][y] = ch[x][y] == 'W' ? '+' : '.';
      flag = 1;
    } else if (x+2 <= n && (ch[x+1][y] == 'b' || ch[x+1][y] == 'B')&&(ch[x+2][y] == '.' || ch[x+2][y] == '+')) {
      ch[x+2][y] = ch[x+2][y] == '+' ? 'B' : 'b';
      ch[x+1][y] = ch[x+1][y] == 'B' ? 'W' : 'w';
      ch[x][y] = ch[x][y] == 'W' ? '+' : '.';
      flag = 1;
    }
  } else if (c == 'R') {
    if (y+1 <= m && (ch[x][y+1] == '.' || ch[x][y+1] == '+')) {
      ch[x][y+1] = ch[x][y+1] == '.' ? 'w' : 'W';
      ch[x][y] = ch[x][y] == 'W' ? '+' : '.';
      flag = 1;
    } else if (y+2 <= m && (ch[x][y+1] == 'b' || ch[x][y+1] == 'B') && (ch[x][y+2] == '.' || ch[x][y+2] == '+')) {
      ch[x][y+2] = ch[x][y+2] == '+' ? 'B' : 'b';
      ch[x][y+1] = ch[x][y+1] == 'B' ? 'W' : 'w';
      ch[x][y] = ch[x][y] == 'W' ? '+' : '.';
      flag = 1;
    }
  } else if (c == 'L'){
    if (y-1 >= 1 && (ch[x][y-1] == '.' || ch[x][y-1] == '+')) {
      ch[x][y-1] = ch[x][y-1] == '.' ? 'w' : 'W';
      ch[x][y] = ch[x][y] == 'W' ? '+' : '.';
      flag = 1;
    } else if (y-2 >= 1 && (ch[x][y-1] == 'b' || ch[x][y-1] == 'B') && (ch[x][y-2] == '.' || ch[x][y-2] == '+')) {
      ch[x][y-2] = ch[x][y-2] == '+' ? 'B' : 'b';
      ch[x][y-1] = ch[x][y-1] == 'B' ? 'W' : 'w';
      ch[x][y] = ch[x][y] == 'W' ? '+' : '.';
      flag = 1;
    }
  }
  return flag;
}

int judge() {
  int cnt1 = 0, cnt2 = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (ch[i][j] == '+') cnt1++;
      if (ch[i][j] == 'b') cnt2++;
    }
  }
  if (cnt1 || cnt2) return 0;
  return 1;
}

int main() {
  int cnt = 1;
  while(scanf("%d%d", &n, &m) == 2 && (n != 0 || m != 0)) {
    for (int i = 1; i <=n; i++) {
      scanf("%s", ch[i]+1);
    }
    int x, y;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (ch[i][j] == 'w' || ch[i][j] == 'W') {
          x = i;
          y = j;
        }
      }
    }
    scanf("%s", s);
    int comp = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
      int flag = check(x, y, s[i]);
      if (flag) {
        if (s[i] == 'U') x--;
        else if (s[i] == 'D') x++;
        else if (s[i] == 'R') y++;
        else if (s[i] == 'L') y--;
      }
      if (judge()) {
        comp = 1;
        break;
      }
    }
    if (comp) {
      printf("Game %d: complete\n", cnt++);
    } else {
      printf("Game %d: incomplete\n", cnt++);
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        printf("%c", ch[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
