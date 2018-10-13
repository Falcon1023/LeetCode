#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty())
            return 0;
        return subDecodings(s, s.begin(), s.end());
    }

    int subDecodings(string &s, string::iterator beg, string::iterator end) {
        if (*beg == '0')
            return 0;
        if (beg == end || (beg+1) == end)
            return 1;

        int sub1 = 0, sub2 = 0;
        if (*(beg + 1) != '0')
            sub1 = subDecodings(s, beg+1, end);
        if (((*beg - '0') * 10 + (*(beg + 1) - '0')) <= 26)
            sub2 = subDecodings(s, beg+2, end);

        return sub1 + sub2;
    }
};