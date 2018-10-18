class Solution {
public:
    int mySqrt(int x) {
        long long min = 0, max = x, mid = (min + max) / 2;
        while (true) {
            if (mid * mid == x)
                return mid;
            if (mid * mid < x)
                min = mid;
            else
                max = mid;
            mid = (min + max) / 2;
            if (mid == min) break;
        }
        return ((mid + 1) * (mid + 1) <= x ? mid + 1 : mid);
    }
};
