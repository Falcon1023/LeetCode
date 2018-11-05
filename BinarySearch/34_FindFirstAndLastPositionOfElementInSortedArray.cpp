#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if (nums.size() == 0)
            return res;
        int beg = binarySearch(nums, target-0.5);
        int end = binarySearch(nums, target+0.5);
        if (end > beg) {
            res[0] = beg;
            res[1] = end-1;
        }
        return res;
    }

    int binarySearch(vector<int>& nums, double target) {
        int beg = 0, end = nums.size() - 1;

        if (target > nums[end])
            return end+1;

        if (target < nums[beg])
            return beg;

        while (end - beg > 1) {
            int mid = (end + beg) / 2;
            if (nums[mid] > target)
                end = mid;
            else
                beg = mid;

        }
        return end;
    }
};