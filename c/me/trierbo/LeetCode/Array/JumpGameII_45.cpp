#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        auto len = nums.size();
        int step = 0;
        for (decltype(len) i = 0; i < len - 1; ) {
            ++step;
            if (i + nums[i] >= len - 1)
                break;
            int max = 0;
            int index = 0;
            for (decltype(len) j = i + 1; j <= i + nums[i]; ++j) {
                if (max < j + nums[j]) {
                    max = j + nums[j];
                    index = j;
                }
            }
            i = index;
        }
        return step;
    }
};