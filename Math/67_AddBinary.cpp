#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int aLen = a.size(), bLen = b.size();
        int flag = 0;

        for (int i = 0; i < aLen || i < bLen; ++i) {
            if (i < aLen && i < bLen) {
                if (a[aLen-i-1] == '1' && b[bLen-i-1] == '1') {
                    res.push_back('0'+flag);
                    flag = 1;
                } else if (a[aLen-i-1] == '0' && b[bLen-i-1] == '0') {
                    res.push_back('0'+flag);
                    flag = 0;
                } else {
                    res.push_back('0'+(flag == 0 ? 1 : 0));
                }
            } else if (i < aLen) {
                if (a[aLen-i-1] == '1') {
                    res.push_back('0'+(flag == 1 ? 0 : 1));
                } else {
                    res.push_back('0'+flag);
                    flag = 0;
                }
            } else {
                if (b[bLen-i-1] == '1') {
                    res.push_back('0'+(flag == 1 ? 0 : 1));
                } else {
                    res.push_back('0'+flag);
                    flag = 0;
                }
            }
        }
        if(flag) res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};