#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        auto len = nums.size();
        for (decltype(len) i = 0;;) {
            if (i + nums[i] >= len - 1)
                return true;
            
            int max = nums[i];
            int index = i;
            for (decltype(len) j = 1; j <= nums[i]; j++) {
                if (j + nums[i+j] > max) {
                    max = j + nums[i+j];
                    index = i + j;
                }
            }
            if (index == i)
                return false;
            else
                i = index;
            
        }
        return true;
    }
};