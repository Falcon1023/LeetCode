import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 3; i++) {
            if (i != 0 && nums[i] == nums[i-1])
                continue;
            for (int j = i + 1; j < nums.length - 2; j++) {
                if (j != i + 1 && nums[j] == nums[j-1])
                    continue;
                int k = j + 1, l = nums.length - 1;
                while (k < l) {
                    if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
                        res.add(Arrays.asList(nums[i], nums[j], nums[k], nums[l]));
                        k++;
                        while (k < l && nums[k] == nums[k-1]) k++;
                        l--;
                        while (k < l && nums[l] == nums[l+1]) l--;
                    } else if (k < l && nums[i] + nums[j] + nums[k] + nums[l] > target) {
                        l--;
                        while (k < l && nums[l] == nums[l+1]) l--;
                    } else {
                        k++;
                        while (k < l && nums[k] == nums[k-1]) k++;
                    }
                }
            }
        }
        return res;
    }
}
