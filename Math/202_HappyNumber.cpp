#include <set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> unique;
        unique.insert(n);
        while (n != 1) {
            int temp = 0;
            while (n != 0) {
                temp += (n % 10) * (n % 10);
                n /= 10;
            }
            n = temp;
            if (unique.count(n))
                return false;
            unique.insert(n);
        }
        return true;
    }
};