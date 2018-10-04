#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;
        unordered_map<string, vector<int>> anas;

        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            anas[str].push_back(i);
        }

        for (auto ana: anas) {
            vector<string> group;
            for (auto i: ana.second) {
                group.push_back(strs[i]);
            }
            groups.push_back(group);
        }
        return groups;
    }
};