#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (auto end = digits.end()-1, beg = digits.begin(); beg <= end; --end) {
            auto &digit = *end;
            if (digit < 9) {
                digit += 1;
                break;
            } else {
                digit = 0;
                if (end == beg) {
                    digits.insert(beg, 1);
                }
            }
        }
        return digits;
    }
};