#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> subset;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backTracking(nums, 0);
        return res;
    }

    void backTracking(vector<int>& nums, int step) {
        if (step < nums.size()) {
            subset.push_back(nums[step]);
            backTracking(nums, step+1);
            subset.pop_back();
            backTracking(nums, step+1);
        } else {
            res.push_back(subset);
        }
    }
};
