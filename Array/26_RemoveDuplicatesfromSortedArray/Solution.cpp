#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0, tmp;
        if (nums.size() == 0)
            return count;
        tmp = nums[0];
        ++count;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != tmp) {
                tmp = nums[count] = nums[i];
                ++count;
            }
        }
        return count;
    }
};