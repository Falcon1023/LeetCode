#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string res(num1.size()+num2.size(), '0');
        for(int i = num1.size() - 1; i >= 0; --i) {
            for(int j = num2.size() - 1; j >= 0; --j) {
                int temp = (int(num1[i] - '0')) * (num2[j] - '0') + (res[i+j+1] - '0');
                res[i+j+1] = char(temp % 10 + '0');
                res[i+j] += temp / 10;
            }
        }
        size_t pos = res.find_first_not_of('0');
        return pos == -1 ? "0" : res.substr(pos);
    }
};
