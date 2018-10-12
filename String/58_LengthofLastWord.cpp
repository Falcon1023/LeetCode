#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        auto beg = s.begin() -1, end = s.end() - 1;
        while (end != beg && *end == ' ')
            --end;
        int len = 0;
        while (end != beg && *end != ' ') {
            ++len;
            --end;
        }
        return len;
    }
};
