#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if (m == 0)
            return res;
        int n = matrix[0].size();
        if (n == 0)
            return res;
        for (int i = 0; i < (m+1)/2; ++i) {
            int rowTop = i, rowBottom = m-1-i;
            int colLeft = i, colRight = n-1-i;
            if (colLeft > colRight)
                break;
            for (int j = colLeft; j <= colRight; ++j)
                res.push_back(matrix[rowTop][j]);
            for (int j = rowTop+1; j <= rowBottom; ++j)
                res.push_back(matrix[j][colRight]);
            if (rowTop != rowBottom)
                for (int j = colRight-1; j >= colLeft; --j)
                    res.push_back(matrix[rowBottom][j]);
            if (colLeft != colRight)
                for (int j = rowBottom-1; j >= rowTop+1; --j)
                    res.push_back(matrix[j][colLeft]);
        }
        return res;
    }
};