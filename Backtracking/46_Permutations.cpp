#include <vector>
#include <set>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> permutation;
    set<int> flag;

    void backTrack(vector<int>& nums) {
        if (flag.size() == nums.size()) {
            res.push_back(permutation);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (flag.count(i) == 0) {
                permutation.push_back(nums[i]);
                flag.insert(i);
                backTrack(nums);
                permutation.pop_back();
                flag.erase(i);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        backTrack(nums);
        return res;
    }
};