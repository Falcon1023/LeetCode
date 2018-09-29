#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int last_zero_row = -1;
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    last_zero_row = i;
                    break;
                }
            }
            if (last_zero_row != -1)
                break;
        }
        
        if (last_zero_row == -1)
            return;
        
        for (int i = 0; i < last_zero_row; i++) {
            bool zero_row = false;
            for (int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[last_zero_row][j] = 0;
                    zero_row = true;
                }
            }
            if (zero_row)
                for (int j = 0; j < n; j++)
                    matrix[i][j] = 0;
        }
        
        for (int j = 0; j < n; j++) {
            if (matrix[last_zero_row][j] == 0)
                for (int i = 0; i < m; i++)
                    matrix[i][j] = 0;
            else
                matrix[last_zero_row][j] = 0;
        }
    }
};