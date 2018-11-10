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
            }
            if (nums[mid] >= nums[beg]) {
                if (target < nums[mid] && target >= nums[beg])
                    end = mid - 1;
                else
                    beg = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[end])
                    beg = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return res;
    }
};