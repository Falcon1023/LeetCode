#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        auto beg = s.begin();
        while (beg != s.end()) {
            if (*beg != ' ') {
                auto end = beg;
                for (; end != s.end() && *end != ' '; ++end)
                    continue;
                reverse(beg, end);
                beg = (end == s.end() ? end : end + 1);
            } else {
                beg = s.erase(beg);
            }
        }
        if (*(beg - 1) == ' ')
            s.pop_back();
    }
};

//int main() {
//    Solution solution;
//    string s = "      the   sky is blue   ";
//    solution.reverseWords(s);
//    cout << s << endl;
//}
