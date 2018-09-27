#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rows(n, -1);
        vector<vector<int>> steps(m, rows);
        return localPathSum(grid, steps, 0, 0, m, n);
    }
    
    int localPathSum(vector<vector<int>> &grid, vector<vector<int>> &steps, int row, int col, int m, int n) {
        
        if (steps[row][col] != -1)
            return steps[row][col];
        
        if (row == m-1 && col == n-1) {
            steps[row][col] = grid[row][col];
        } else if (row == m-1) {
            steps[row][col] =  grid[row][col] + localPathSum(grid, steps, row, col+1, m, n);
        } else if (col == n-1) {
            steps[row][col] = grid[row][col] + localPathSum(grid, steps, row+1, col, m ,n);
        } else {
            int rowPathSum = localPathSum(grid, steps, row+1, col, m, n);
            int colPathSum = localPathSum(grid, steps, row, col+1, m, n);
            steps[row][col] = rowPathSum <= colPathSum ? rowPathSum + grid[row][col] : colPathSum + grid[row][col];
        }
        return steps[row][col];
    }
};