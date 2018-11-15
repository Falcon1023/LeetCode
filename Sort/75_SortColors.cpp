#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
    }

    void quickSort(vector<int>& nums, int beg, int end) {
        if (beg >= end)
            return;

        int base = nums[beg];
        int p = beg, q = end;
        while (p < q) {
            while (p < q && nums[q] > base)
                --q;
            while (p < q && nums[p] <= base)
                ++p;
            swap(nums, p, q);
        }

        swap(nums, beg, q);
        quickSort(nums, beg, q-1);
        quickSort(nums, q+1, end);
    }

    void swap(vector<int>& nums, int p, int q) {
        int tmp = nums[p];
        nums[p] = nums[q];
        nums[q] = tmp;
    }
};
