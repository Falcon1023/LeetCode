#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int res = 1, count = 1, tmp=nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != tmp) {
                tmp = nums[res++] = nums[i];
                count = 1;
            } else if (count == 1) {
                nums[res++] = nums[i];
                ++count;
            }
        }
        return res;
    }
};