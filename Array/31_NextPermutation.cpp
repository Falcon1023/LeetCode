#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pos = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                pos = i;
            }
        }
        if (pos == 0) {
            reverse(nums.begin(), nums.end());
        } else {
            int nextPos = pos;
            for (int i = pos + 1; i < nums.size(); ++i)
                if (nums[i] > nums[pos - 1] && nums[i] < nums[nextPos])
                    nextPos = i;
            int temp = nums[nextPos];
            nums[nextPos] = nums[pos - 1];
            nums[pos - 1] = temp;
            sort(nums.begin() + pos, nums.end());
        }
    }
};