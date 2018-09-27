#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        auto size = nums.size();
        for (decltype(size) i = 0; i < size; ++i) {
            int temp = nums[i];
            while (temp > 0 && temp <= size && temp != i + 1 && temp != nums[temp-1]) {       
                nums[i] = nums[temp-1];
                nums[temp-1] = temp;
                temp = nums[i];
            }
        }
        for (decltype(size) i = 0; i < size; ++i)
            if (nums[i] != i + 1)
                return i + 1;
        return size + 1;
    }
};