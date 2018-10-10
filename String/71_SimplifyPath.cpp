#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> abPathSt;
        string abPath;
        for (auto beg = path.begin(), end = path.end(); beg < end; ++beg) {
            string str;
            for (; beg < end && *beg != '/'; ++beg)
                str += *beg;
            if (str == "..") {
                if (!abPathSt.empty())
                    abPathSt.pop_back();
            }
            else if (str == "." || str.empty()){
                continue;
            } else {
                abPathSt.push_back(str);
            }
        }
        for (auto &st: abPathSt)
            abPath += '/' + st;
        return abPath.empty() ? "/" : abPath;
    }
};