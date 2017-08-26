#include <stdio.h>
#include <queue>

using namespace std;

struct node {
  long long num;
  int dep;
  bool operator<(const node &x) const{
    return num > x.num || (num == x.num && dep > x.dep);
  }
};

priority_queue<node> q;

int n,k,num;
long long x, res;
int main() {
  scanf("%d%d", &n, &k);
  num = n;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &x);
    q.push((node){x, 0});
  }
  if ((n - 1) % (k - 1)) {
    num += (k - 1) - (n - 1) % (k - 1);
    for (int i = n; i < num; i++)
      q.push((node){0, 0});
  }
  while (num > 1) {
    long long sum = 0;
    int dep = 0;
    for (int i = 1; i <= k; i++) {
      node node = q.top();
      q.pop();
      sum += node.num;
      dep = max(dep, node.dep);
    }
    res += sum;
    num -= k - 1;
    q.push((node){sum, dep+1});
  }
  printf("%lld\n%d\n", res, q.top().dep);
  return 0;
}
