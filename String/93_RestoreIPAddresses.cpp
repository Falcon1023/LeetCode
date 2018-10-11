#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> combs;
        string buffer;
        if (s.size() < 4 || s.size() > 12)
            return combs;
        countCombinations(combs, buffer, s, 0, s.begin(), s.end());
        for (string &comb: combs)
            comb.pop_back();
        return combs;
    }
    
    void countCombinations(vector<string> &combs, string &buffer, string &s, int step, string::iterator beg, string::iterator end) {
        string::iterator cur = beg;
        if (beg == end && step == 4)
            combs.push_back(buffer);
        else if (beg != end && step == 4)
            return;
        else {
            string temp;
            int count = 1;
            for (; beg != end && count <= 3; ++beg, ++count) {
                temp += *beg;
                if (temp[0] == '0' && temp.size() > 1) break;
                if (stoi(temp) <= 255) {
                    buffer += temp + ".";
                    countCombinations(combs, buffer, s, step + 1, beg + 1, end);
                    buffer.erase(buffer.end()-count-1, buffer.end());
                }
            }
        }
    }
};

//int main() {
//    Solution solution;
//    vector<string> combs = solution.restoreIpAddresses("010010");
//    for (string &comb: combs)
//        cout << comb << endl;
//}