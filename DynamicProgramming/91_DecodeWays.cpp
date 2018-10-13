#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty())
            return 0;
        int flag[s.size()];
        for (int i = 0; i < s.size(); i++)
            flag[i] = -1;
        return subDecodings(s, flag, 0, s.size());
    }

    int subDecodings(string &s, int flag[], int beg, int end) {
        if (s[beg] == '0')
            return 0;
        if (beg == end || (beg+1) == end)
            return 1;

        if (flag[beg] == -1) {
            int sub1 = 0, sub2 = 0;
            if (s[beg + 1] != '0')
                sub1 = subDecodings(s, flag, beg+1, end);
            if (((s[beg] - '0') * 10 + (s[beg + 1] - '0')) <= 26)
                sub2 = subDecodings(s, flag, beg+2, end);
            flag[beg] = sub1 + sub2;
        }
        return flag[beg];
    }
};