#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int p = 0, q = s.size();
        while (p < q) {
            while (p < q && !isalnum(s[p]))
                ++p;
            while (p < q && !isalnum(s[q]))
                --q;
            if (tolower(s[p++]) != tolower(s[q--]))
                return false;
        }
        return true;
    }
};
