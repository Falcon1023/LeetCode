#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> ch;
        vector<int> seq;
        for (int i = 1; i <= 9; i++)
            ch.push_back('0' + i);
        string res;
        for (int i = n-1; i >= 0; --i) {
            int fi = frac(i);
            int pos = int(ceil((double)k / fi) - 1);
            k -= pos * fi;
            seq.push_back(pos);
        }
        for (int i = 0; i < n; i++) {
            res += ch[seq[i]];
            ch.erase(ch.begin() + seq[i]);
        }
        return res;
    }

    int frac(int n) {
        int res = 1;
        for (int i = 1; i <=n; ++i)
            res *= i;
        return res;
    }
};