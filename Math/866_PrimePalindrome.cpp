#include <cmath>

using namespace std;

class Solution {
public:
    int primePalindrome(int N) {
        if (N == 1 || N == 2)
            return 2;
        do {
            if (1e7 <= N and N <= 1e8)
                return 100030001;
            if (isPalindrome(N) && isPrime(N))
                break;
        } while(++N);
        return N;
    }

    bool isPalindrome(int N) {
        int temp = N, res = 0, r = 0;
        while (N != 0) {
            r = N % 10;
            N = N / 10;
            res = res * 10 + r;
        }
        return res == temp;
    }

    bool isPrime(int N) {
        int m = (int)(sqrt(N));
        for (int i = 2; i <= m; ++i) {
            if (N % i == 0) {
                return false;
            }
        }
        return true;
    }
};