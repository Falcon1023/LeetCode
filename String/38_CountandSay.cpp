#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string prev = countAndSay(n - 1);
        string res;

        auto beg = prev.begin(), end = prev.end();
        int count = 0;
        char c = *beg;
        for (; beg != end; ++beg) {
            if (*beg == c) {
                ++count;
            } else {
                res += to_string(count) + c;
                count = 1;
                c = *beg;
            }
        }
        res += to_string(count) + c;
        return res;
    }
};
