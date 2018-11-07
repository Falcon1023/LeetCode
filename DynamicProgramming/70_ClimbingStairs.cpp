class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2)
            return n;
        int steps[n+1];
        for (int i = 0; i <= n; ++i)
            steps[i] = 0;
        steps[1] = 1;
        steps[2] = 2;
        return countWays(steps, n);
    }

    int countWays(int *steps, int n) {
        if (n == 1 || n == 2)
            return steps[n];
        if (steps[n] == 0)
            steps[n] = countWays(steps, n-1) + countWays(steps, n-2);
        return steps[n];
    }
};