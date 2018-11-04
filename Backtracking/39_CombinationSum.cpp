#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> combination;
    void backTracking(vector<int>& candidates, int target, int sum, int prev) {
        if (target == sum) {
            res.push_back(combination);
            return;
        }
        if (target < sum) {
            return;
        }
        for (int i = 0; i < candidates.size(); ++i) {
            if (candidates[i] < prev) {
                continue;
            }
            combination.push_back(candidates[i]);
            sum += candidates[i];
            backTracking(candidates, target, sum, candidates[i]);
            combination.pop_back();
            sum -= candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backTracking(candidates, target, 0, 0);
        return res;
    }
};
