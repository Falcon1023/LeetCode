#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;

char s[1000001];
int dp[1000001];

stack<int> st;

int main() {
  scanf("%s", s+1);
  int len = 0, num = 0, l = strlen(s+1);
  for (int i = 1; i <= l; i++) {
    if (s[i] == '(') st.push(i);
    else {
      if (!st.empty()) {
        int t = st.top();
        st.pop();
        dp[i] = dp[t-1] + i - t + 1;
        if (dp[i] > len) {
          len = dp[i];
          num = 1;
        } else if (dp[i] == len)
          num++;
      }
    }
  }
  if (!len) num = 1;
  printf("%d %d\n", len, num);
  return 0;
}