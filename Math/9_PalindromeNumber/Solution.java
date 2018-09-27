public class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) return false;
        int tmp = x, res = 0;
        while (x != 0) {
            if (res > Integer.MAX_VALUE / 10) return false;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return tmp == res;
    }
}
