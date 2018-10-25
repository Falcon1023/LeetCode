class Solution {
public:
    int countPrimes(int n) {
        bool *primes = new bool[n];
        int count = 0;
        for (int i = 0; i < n; ++i)
            primes[i] = true;
        for (int i = 2; i < n; ++i) {
            if (primes[i]) {
                ++count;
                for (int j = 2; i * j < n; ++j)
                    primes[i*j] = false;
            }
        }
        delete []primes;
        return count;
    }
};