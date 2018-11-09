#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size()-1);
    }

    int binarySearch(vector<int>& nums, int target, int beg, int end) {
        int res = -1;
        while (beg <= end) {
            int mid = (beg + end) / 2;
            if (nums[mid] == target) {
                res = mid;
                break;
            } else if (nums[beg] <= nums[end]) {
                if (nums[mid] > target)
                    end = mid - 1;
                else
                    beg = mid + 1;
            } else {
                if (nums[mid] > nums[end] && nums[mid] < nums[beg])
                    break;
                else if ((target >= nums[beg] && (nums[mid] > target || nums[mid] < nums[beg]))
                         || (target <= nums[end] && nums[mid] > target && nums[mid] < nums[beg]))
                    end = mid - 1;
                else
                    beg = mid + 1;
            }
        }
        return res;
    }
};