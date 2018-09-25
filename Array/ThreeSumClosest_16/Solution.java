package me.trierbo.LeetCode.ThreeSumClosest_16;

import java.util.Arrays;

public class Solution {
    public static int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int tmp;
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.length - 2; i++) {
            int j = i + 1, k = nums.length - 1;
            while (j < k) {
                tmp = nums[i] + nums[j] + nums[k];
                if (Math.abs(res - target) > Math.abs(tmp - target)) {
                    res = tmp;
                    if (res == target)
                        return res;
                }
                if (tmp > target) k--;
                else j++;
            }
        }
        return res;
    }
}
