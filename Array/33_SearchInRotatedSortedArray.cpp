#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
        int cut = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                cut = i + 1;
                break;
            }
        }
        int res = binarySearch(nums, 0, cut - 1, target);
        if (res == -1)
            res = binarySearch(nums, cut, nums.size(), target);
        return res;
    }

    int binarySearch(vector<int>& nums, int beg, int end, int target) {
        int res = -1;
        int mid = (beg + end) / 2;
        while (beg <= end) {
            if (nums[mid] == target) {
                res = mid;
                break;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
            mid = (beg + end) / 2;
        }
        return res;
    }
};