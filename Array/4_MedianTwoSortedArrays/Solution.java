public class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums1.length > nums2.length) {
            int[] tmp = nums1;
            nums1 = nums2;
            nums2 = tmp;
        }
        int m = nums1.length;
        int n = nums2.length;
        int start = 0, end = m;
        while (start <= end) {
            int i = (start + end) / 2;
            int j = (m + n + 1) / 2 - i;
            if (i < m && nums1[i] < nums2[j-1]) {
                start = i == end ? end : i+1;
            } else if (i > 0 && nums1[i-1] > nums2[j]) {
                end = i == start ? start : i-1;
            } else {
                int maxLeft;
                if (i == 0) {
                    maxLeft = nums2[j-1];
                } else if (j == 0) {
                    maxLeft = nums1[i-1];
                } else {
                    maxLeft = Math.max(nums1[i-1], nums2[j-1]);
                }
                if ((m + n) % 2 == 1)
                    return maxLeft;
                int minRight;
                if (i == m) {
                    minRight = nums2[j];
                } else if (j == n) {
                    minRight = nums1[i];
                } else  {
                    minRight = Math.min(nums1[i], nums2[j]);
                }
                return  (maxLeft + minRight) / 2.0;
            }
        }
        return 0;
    }
}
