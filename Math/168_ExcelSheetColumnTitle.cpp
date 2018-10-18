#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        int r = 0;
        while (n != 0) {
            r = n % 26;
            n = (r == 0 ? n - 26 : n) / 26;
            res += 'A' + (r == 0 ? 25 : r - 1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
