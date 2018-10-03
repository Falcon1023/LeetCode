#include <string>
#include <vector>
using  namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combs;
        string buffer;
        if (digits.empty())
            return combs;
        backTrack(combs, buffer, digits, digits.begin(), digits.end());
        return combs;
    }

    void backTrack(vector<string> &combs, string &buffer, string &digits, string::iterator beg, string::iterator end) {
        if (beg == end) {
            combs.push_back(buffer);
            return;
        }
        int count = 3;
        if (*beg == '7' || *beg == '9')
            count = 4;

        for (int i = 0; i < count; i++) {
            char c = 'a' + i + (*beg - '2') * 3;
            if (*beg > '7')
                c += 1;
            buffer += c;
            backTrack(combs, buffer, digits, beg+1, end);
            buffer.pop_back();
        }
    }
};