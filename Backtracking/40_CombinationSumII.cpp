#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> combination;
    set<int> flag;

    void backTracking(vector<int>& candidates, int target, int sum, int prev) {
        if (flag.size() == candidates.size() || target < sum) {
            if (target == sum) {
                res.push_back(combination);
            }
            return;
        }
        if (target == sum) {
            res.push_back(combination);
            return;
        }
        int cur = 0;
        for (int i = 0; i < candidates.size(); ++i) {
            if (flag.count(i) == 0 && cur < candidates[i] && prev <= candidates[i]) {
                cur = candidates[i];
                combination.push_back(candidates[i]);
                flag.insert(i);
                sum += candidates[i];
                backTracking(candidates, target, sum, candidates[i]);
                combination.pop_back();
                flag.erase(i);
                sum -= candidates[i];
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backTracking(candidates, target, 0, 0);
        return res;
    }
};