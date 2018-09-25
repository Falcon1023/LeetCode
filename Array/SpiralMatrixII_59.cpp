#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> row(n, 0);
        vector<vector<int>> matrix(n, row);
        if (n % 2 == 1)
            matrix[(n+1)/2-1][(n+1)/2-1] = n*n;
        int start = 0;
        for (int i = 0; i < (n + 1) / 2; ++i) {
            int num = n - 1 - i * 2;
            for (int j = 0; j < num * 4; ++j) {
                if (j < num)
                    matrix[i][j+i] = ++start;
                else if (j < num * 2)
                    matrix[j-num+i][num+i] = ++start;
                else if (j < num * 3)
                    matrix[num+i][num*3-j+i] = ++start;
                else
                    matrix[num*4-j+i][i] = ++start;
            }
        }
        return matrix;
    }
};