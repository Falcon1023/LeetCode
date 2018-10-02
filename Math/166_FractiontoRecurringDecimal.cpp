#include <string>
#include <map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";

        string res;
        if (numerator < 0 ^ denominator < 0)
            res += '-';

        long n = labs((long)numerator);
        long d = labs((long)denominator);
        long quotient = n / d;
        res += to_string(quotient);

        long remainder = n % d;
        long temp = 0;
        map<long, unsigned long> nums;

        if (remainder != 0) {
            res += '.';
            while (remainder != 0) {
                nums[remainder] = res.size();
                temp = remainder * 10;
                quotient = temp / d;
                remainder = temp % d;
                res += to_string(quotient);
                if (nums.count(remainder)) {
                    res.insert(nums[remainder], 1, '(');
                    res += ')';
                    break;
                }
            }
        }

        return res;
    }
};

