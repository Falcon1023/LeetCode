package me.trierbo.LeetCode.ThreeSum_15;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < nums.length - 2; i++) {
            if(i > 0 && nums[i-1] == nums[i])
                continue;
            int j = i + 1, k = nums.length - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    res.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    j++;
                    while (nums[j] == nums[j-1] && j < k) j++;
                    k--;
                    while (nums[k] == nums[k+1] && j < k) k--;
                } else if (nums[i] + nums[j] +nums[k] > 0) {
                    k--;
                    while (nums[k] == nums[k+1] && j < k) k--;
                } else {
                    j++;
                    while (nums[j] == nums[j-1] && j < k) j++;
                }
            }
        }
        return res;
    }
}
