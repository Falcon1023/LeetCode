#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> subset;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backTracking(nums, 0);
        return res;
    }

    void backTracking(vector<int>& nums, int step) {
        res.push_back(subset);
        for (int i = step; i < nums.size(); ++i) {
            if (i != step && nums[i] == nums[i-1])
                continue;
            subset.push_back(nums[i]);
            backTracking(nums, i+1);
            subset.pop_back();
        }
    }
};
